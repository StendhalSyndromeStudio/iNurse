#include "assistant_query_task.h"

AssistantQueryTask::AssistantQueryTask()
  : IAssistantTask()
  , isActiveTask ( false )
{

}

AssistantQueryTask::~AssistantQueryTask()
{

}

#include <QTimer>
void AssistantQueryTask::sendQuery(const QString &query, const AssistantQueryTask::ReplyMethod &method, int timeout)
{
  auto timer    = new QTimer();
  auto handler  = [this, query, timer, method](const QStringList &reply) {
    delete timer;
    try {
      method( reply );
      waitReplyHandlers.remove( query );
    } catch (...) { }
  };

  auto con = connect( timer,    &QTimer::timeout,
                  [this, method, query]() {
    try {
      waitReplyHandlers.remove( query );
      method( QStringList { } );
    } catch (...) { }
  });

  connect( this,  &QObject::destroyed,
           [this, con](){
    this->disconnect( con );
  });
  waitReplyHandlers[ query ] = handler;

  IAssistantTask::query( query );
  if ( timeout > 0 )
  timer->start( timeout );
}


bool AssistantQueryTask::isActive() const
{
  return isActiveTask;
}

QStringList AssistantQueryTask::activateCommand() const
{
  return QStringList{ };
}

void AssistantQueryTask::start()
{
  if ( !isActiveTask ) {
    isActiveTask = true;
    emit started();
  }
}

void AssistantQueryTask::stop()
{
  if ( isActiveTask ) {
    isActiveTask = false;
    emit finished();
  }
}

void AssistantQueryTask::reply(const QString &question, const QStringList &reply)
{
  if ( isActive() ) {
    if ( waitReplyHandlers.contains( question ) ) {
      try {
        waitReplyHandlers[ question ]( reply );
      } catch (...) { }
    }
  } else {
    if ( waitReplyHandlers.contains( question ) ) {
      try {
        waitReplyHandlers.remove( question );
      } catch (...) { }
    }
  }
}
