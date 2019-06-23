#ifndef ASSISTENT_H
#define ASSISTENT_H

#include <QObject>
#include <VoiceProxy.h>
#include <impl/medical_card.h>
#include "task/assistant_task_storage.h"
#include <mainwindow.h>

class Assistent
    : public QObject
{
  Q_OBJECT
  VoiceProxy            *proxy;
  AssistantTaskStorage  *storage;
  MainWindow            mw;
  IMedicalCard          *card;
public:
  explicit Assistent(QObject *parent = nullptr);
  ~Assistent() override;

public:
  virtual void createCard();

public:
  static Assistent *inst();

public slots:
    void say(const QString &text);

};

#endif // ASSISTENT_H
