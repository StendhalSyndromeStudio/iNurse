#include "assistant_task_storage.h"

#include <QDebug>

AssistantTaskStorage::AssistantTaskStorage()
  : AssistantQueryTask()
{

}

AssistantTaskStorage::~AssistantTaskStorage()
{

}

void AssistantTaskStorage::setActivateCommands(const QStringList &commands)
{
  activateList = commands;
}

void AssistantTaskStorage::recognition(const QStringList &recognition)
{
  if ( !lastQuery.isEmpty() ) {
    auto tmp = lastQuery;
    lastQuery.clear();
    qDebug() << "to reply " << tmp << recognition.join( "; " );
    AssistantQueryTask::reply( tmp, recognition );
  } else {
    double max              = 0.0;
    IAssistantTask *current = nullptr;
    for ( auto &item: taskList ) {

      double itemMax = 0.0;
      for ( auto &activ: item->activateCommand() ) {
        for ( auto &r: recognition ) {
          int pos = activ.trimmed().toLower().indexOf( r.trimmed().toLower() );
          if ( pos > 0 ) {
            itemMax = std::max ( itemMax, static_cast<double>( r.length() ) / activ.length() );
          }
        }

        if ( itemMax >= 0.5 ) {
          if ( max < itemMax ) {
            max = itemMax;
            current = item;
          }
        }
      }
    }
    if ( current ) {
      current->reply( "", recognition );
      qDebug() << "to recognition" <<recognition.join( "; " );
    }
  }
}


QStringList AssistantTaskStorage::activateCommand() const
{
  return activateList;
}
