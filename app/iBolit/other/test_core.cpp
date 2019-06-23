#include "test_core.h"
#include <QUrl>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

TestCore::TestCore(QObject *parent)
  : QObject(parent)
  , card ( nullptr )
  , voice( new VoiceProxy( 6790, QUrl( "ws://127.0.0.1:6789" ), true ) )
{
  connect( voice,   &VoiceProxy::recognized,
           [](const QJsonObject &obj){
    if ( obj[ "final" ].toBool() ) {
      auto array = obj[ "alternatives" ].toArray();
      QStringList altr;
      for ( int i = 0; i < array.count(); ++i ) {
        altr << array.at( i ).toString();
      }

      qDebug () << altr.join( ";   " );
    } else {
      qDebug() << "wait";
    }

  });
}

TestCore::~TestCore()
{

}

TestCore *TestCore::instance()
{
  static TestCore *inst = nullptr;
  if ( !inst )
    inst = new TestCore();

  return inst;
}

#include <texttospeech.h>
void TestCore::say(const QString &text)
{
  TextToSpeech::instanse()->AddPlay( text );
}
