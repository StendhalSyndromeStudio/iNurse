#include "form_task.h"
#include <impl/speach_writer_provider.h>
#include <interfaces/iproperty.h>
#include "assistent/check_true_pattern.h"

FormTask::FormTask(MainWindow *mw)
  : AssistantQueryTask()
  , mw ( mw )
  , writer ( SpeachWriterProvider().create() )
{
  connect( mw,  &MainWindow::formChanged,
           [this, mw]() {
    writer->setPropertyObj( mw->currentForm() );
  });
}

FormTask::~FormTask()
{

}

QStringList FormTask::activateCommand() const
{
  QStringList activators;

  auto current = mw->currentForm();
  if ( current ) {
    for ( auto &p: current->properties() ) {
      activators.append( p->activateList() );
    }
  }

  return activators;
}

void FormTask::reply(const QString &question, const QStringList &reply)
{
  if ( question.isEmpty() ) {
    auto current = mw->currentForm();
    if ( current ) {

      for ( auto &p: current->properties() ) {
        if ( CheckTruePattern::check( p->activateList(), reply ) ) {
          sendQuery( "Диктуйте!", [p](const QStringList &pattern) {
            p->recognition( pattern.first() );
          } );
          break;
        }
      }

    } else {
      query( "Нет активных окон" );
    }
  } else {
    AssistantQueryTask::reply( question, reply );
  }
}
