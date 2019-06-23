#ifndef ASSISTANT_QUERY_TASK_H
#define ASSISTANT_QUERY_TASK_H

#include <QMultiMap>
#include <functional>
#include "assistent/assistant_task.h"

class AssistantQueryTask
    : public IAssistantTask
{
  Q_OBJECT
public:
  using ReplyMethod = std::function<void(const QStringList &reply)>;

private:
  bool                        isActiveTask;
  QMap<QString, ReplyMethod>  waitReplyHandlers;
protected:
  explicit AssistantQueryTask();
public:
  ~AssistantQueryTask() override;

public:
  void sendQuery(const QString &query, const ReplyMethod &method, int timeout = 5000 );

  // IAssistantTask interface
public:
  virtual bool isActive() const override;
  virtual QStringList activateCommand() const override;

public slots:
  virtual void start() override;
  virtual void stop() override;
  virtual void reply(const QString &question, const QStringList &reply) override;
};

#endif // ASSISTANT_QUERY_TASK_H
