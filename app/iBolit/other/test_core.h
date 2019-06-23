#ifndef TEST_CORE_H
#define TEST_CORE_H

#include <QObject>
#include <VoiceProxy.h>
#include <interfaces/imedical_card.h>

class TestCore
    : public QObject
{
  Q_OBJECT
public:
  VoiceProxy      *voice;
  IMedicalCard    *card;
public:
  explicit TestCore(QObject *parent = nullptr);
  ~TestCore() override;

public:
  static TestCore *instance();

public slots:
  void say(const QString &text);

signals:

};

#endif // TEST_CORE_H
