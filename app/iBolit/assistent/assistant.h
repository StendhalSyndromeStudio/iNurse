#ifndef ASSISTENT_H
#define ASSISTENT_H

#include <QObject>
#include <VoiceProxy.h>
#include <impl/medical_card.h>
#include <interfaces/iproperty_form.h>
#include <interfaces/imedical_card.h>
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
  QList<IMedicalCard *> forms;
public:
  explicit Assistent(QObject *parent = nullptr);
  ~Assistent() override;

public:
  virtual void saveCard();
  virtual void closeCard();
  virtual void createCard();
  virtual void openCard(IMedicalCard *card);

public:
  static Assistent *inst();

public slots:
    void say(const QString &text);

};

#endif // ASSISTENT_H
