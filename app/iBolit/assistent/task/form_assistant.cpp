#include "form_assistant.h"
#include "assistent/assistant.h"

FormAssistant::FormAssistant(MainWindow *mw)
  : AssistantQueryTask()
  , mw ( mw )
{

}

FormAssistant::~FormAssistant()
{

}

QStringList FormAssistant::activateCommand() const
{
  return QStringList { "Выбрать карту", "Открыть карту", "Медкарта", "Мед карта" };
}

void FormAssistant::reply(const QString &question, const QStringList &reply)
{
//  auto contains =

  if ( question.isEmpty() ) {



  } else {
    AssistantQueryTask::reply( question, reply );
  }
}
