#include "thread_builder.h"
#include "json_builder_mw.h"

#include <thread>
#include <QApplication>

ThreadBuilder::ThreadBuilder(JsonBuilderMw *mw)
  : QThread ()
  , mw ( mw )
  , runing ( false )
  , aborting ( false )
{

}

ThreadBuilder::~ThreadBuilder()
{
  if ( isWork() )
    abort();
}

bool ThreadBuilder::isWork() const
{
  return runing.load();
}

void ThreadBuilder::start(const QString &in, const QString &out, const QStringList &fields)
{
  ThreadBuilder::in     = in;
  ThreadBuilder::out    = out;
  ThreadBuilder::fields = fields;
  aborting.store( false );
  ThreadBuilder::run();
}

void ThreadBuilder::abort()
{
  aborting.store( true );

  while ( runing.load() ) {
    std::this_thread::sleep_for( std::chrono::milliseconds ( 50 ) );
  }
}


#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
void ThreadBuilder::run()
{
  runing.store( true );
  mw->started();
  mw->changeProgress( 0.0 );
  mw->changeStatusStr( "Opening input file" );
  qApp->processEvents();
  qApp->processEvents();

  QFile f ( QDir::fromNativeSeparators( in ) );
  if ( f.open( QIODevice::ReadOnly ) ) {
    mw->changeProgress( 2.0 );
    mw->changeStatusStr( "Building" );

    double step = 80.0 / f.size();
    double progress = 20.0;

    QJsonArray array;
    int empty = 0;
    while ( !aborting.load() /*&& progress < 100.0*/  ) {
      auto data = f.readLine();
      if ( data.isEmpty() )
        ++empty;
      else
        empty = 0;

      if ( empty > 3 )
        break;

      QStringList items = QString::fromUtf8( data ).split( "###" );
      if ( items.count() == fields.count() ) {
        QJsonObject obj;
        for ( int i = 0; i < fields.count(); ++i ) {
          obj[ fields[ i ] ] = items[ i ].trimmed();
        }
        array.append( obj );

      } else {
        mw->changeStatusStr( "Skip: " + QString::number( items.count() ) + " " + QString::fromUtf8( data ) );
      }

      progress += step * data.size();
      mw->changeProgress( progress );
      qApp->processEvents();
    }
    f.close();

    mw->changeStatusStr( "Builded: " + QString::number( array.count() ) );
    qApp->processEvents();
    if ( !array.isEmpty() ) {
      QFile f ( out );
      if ( f.open( QIODevice::WriteOnly  ) ) {
        f.write( QJsonDocument( array ).toJson( ) );
        f.close();

        mw->changeStatusStr( "Writed: " + QString::number( f.size() / 1024.0 ) + " kb" );
      } else {
        mw->changeStatusStr( "Error open output file: " + f.errorString() );
      }
    }

  } else {
    mw->changeStatusStr( "Error open input file: " + f.errorString() );
  }

  mw->changeProgress( 100.0 );

  mw->finished();
  qApp->processEvents();
  runing.store( false );
}
