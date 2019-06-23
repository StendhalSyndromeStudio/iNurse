#ifndef ASSISTENT_H
#define ASSISTENT_H

#include <QObject>
#include <VoiceProxy.h>
#include "task/assistant_task_storage.h"

class Assistent
    : public QObject
{
  Q_OBJECT
  VoiceProxy            *proxy;
  AssistantTaskStorage  *storage;
public:
  explicit Assistent(QObject *parent = nullptr);
  ~Assistent() override;

public:
  static Assistent *inst();

public slots:
    void say(const QString &text);

};

#endif // ASSISTENT_H
