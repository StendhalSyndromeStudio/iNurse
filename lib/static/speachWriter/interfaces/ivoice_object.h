#ifndef IVOICE_OBJECT_H
#define IVOICE_OBJECT_H

#include <QObject>

class IVoiceObject
    : public QObject
{
  Q_OBJECT
protected:
  explicit IVoiceObject();
public:
  virtual ~IVoiceObject() override;

public:
  virtual bool hasWaitData() const = 0;

public slots:
  virtual void recognition(const QString &data) = 0;

signals:
  void say(const QString &text);
};

#endif // IVOICE_OBJECT_H
