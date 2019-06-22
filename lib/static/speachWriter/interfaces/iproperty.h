#ifndef IPROPERTY_H
#define IPROPERTY_H

#include <QVariant>
#include "ivoice_object.h"


class IProperty
    : public IVoiceObject
{
  Q_OBJECT
protected:
  IProperty();
public:
  virtual ~IProperty() override;

public:
  virtual QString id() const = 0;
  virtual QString type() const = 0;
  virtual QVariant value() const = 0;
  virtual QString valueString() const = 0;
  virtual QStringList activateList() const = 0;

public slots:
  virtual bool activate() = 0;
  virtual bool deactivate() = 0;
  virtual bool setValue(const QVariant &value) = 0;

signals:
  void activated();
  void deactivated();
  void changedValue();

};

#endif // IPROPERTY_H
