#ifndef ASSISTANT_TASK_H
#define ASSISTANT_TASK_H

#include <QObject>

class IAssistantTask
    : public QObject
{
  Q_OBJECT
protected:
  explicit IAssistantTask(QObject *parent = nullptr);
public:
  virtual ~IAssistantTask() override;

public:
    virtual bool isActive() const = 0;
    virtual QStringList activateCommand() const = 0;

public slots:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reply(const QString &question, const QStringList &reply) = 0;

signals:
    void started();
    void finished();
    void query(const QString &question);

};

#endif // ASSISTANT_TASK_H
