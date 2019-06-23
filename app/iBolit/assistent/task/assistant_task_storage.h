#ifndef ASSISTANT_TASK_STORAGE_H
#define ASSISTANT_TASK_STORAGE_H

#include <QObject>
#include "assistant_query_task.h"

class AssistantTaskStorage
    : public AssistantQueryTask
{
  Q_OBJECT
  mutable QString         lastQuery;
  QStringList             activateList;
  QList<IAssistantTask *> taskList;
public:
  explicit AssistantTaskStorage();
  virtual ~AssistantTaskStorage() override;

public:
  void setActivateCommands(const QStringList &commands);

public slots:
  void recognition(const QStringList &recognition);

public:
  template<class Task, typename ...Args>
  void addChildTask(Args ...args) {
    IAssistantTask *task  = new Task(args...);
      connect( task,   &IAssistantTask::query,
               [this, task](const QString &query) {
        AssistantQueryTask::query( query );
//        sendQuery( query, [query, task](const QStringList &reply) {
//          task->reply( query, reply );
//        });
      });
      taskList << task;
  }


  // IAssistantTask interface
public:
  QStringList activateCommand() const override;
};

#endif // ASSISTANT_TASK_STORAGE_H
