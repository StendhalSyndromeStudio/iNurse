#ifndef FORM_ASSISTANT_H
#define FORM_ASSISTANT_H

#include "assistant_query_task.h"
#include "mainwindow.h"

class FormAssistant
    : public AssistantQueryTask
{
  Q_OBJECT
  MainWindow *mw;
public:
  explicit FormAssistant(MainWindow *mw);
  ~FormAssistant() override;

  // IAssistantTask interface
public:
  virtual QStringList activateCommand() const override;

public slots:
  virtual void reply(const QString &question, const QStringList &reply) override;
};

#endif // FORM_ASSISTANT_H
