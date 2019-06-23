#ifndef FORM_TASK_H
#define FORM_TASK_H

#include <QObject>
#include "assistant_query_task.h"
#include <interfaces/ispeach_writer.h>
#include "mainwindow.h"

class FormTask
    : public AssistantQueryTask
{
  Q_OBJECT
  MainWindow    *mw;
  ISpeachWriter *writer;
public:
  explicit FormTask(MainWindow *mw);
  virtual ~FormTask() override;

  // IAssistantTask interface
public:
  virtual QStringList activateCommand() const override;

public slots:
  virtual void reply(const QString &question, const QStringList &reply) override;
};

#endif // FORM_TASK_H
