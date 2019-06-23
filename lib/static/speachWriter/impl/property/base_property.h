#ifndef BASE_PROPERTY_H
#define BASE_PROPERTY_H

#include <QMap>
#include <QObject>
#include <QVariant>
#include "interfaces/iproperty.h"

class BaseProperty
    : public IProperty
{
  Q_OBJECT
protected:
  QString                   _id;
  QString                   _type;
  QVariant                  _value;
  bool                      _isActivate;
  QMap<QString, QVariant>   _dataById;
public:
  explicit BaseProperty(const QString &id = ""
                        , const QString &type = ""
                        , const QVariant &value = "");
  virtual ~BaseProperty() override;

  // IVoiceObject interface
public:
  virtual bool hasWaitData() const override;

public slots:
  virtual void recognition(const QString &data) override;

  // IProperty interface
public:
  virtual QString id() const override;
  virtual QString type() const override;
  virtual QVariant value() const override;
  virtual QString valueString() const override;
  virtual QStringList activateList() const override;
  virtual QVariant getById(const QString &id) const override;
  virtual QStringList dataIdList() const override;

public slots:
  virtual bool activate() override;
  virtual bool deactivate() override;
  virtual bool setValue(const QVariant &value) override;
  virtual bool setById(const QString &id, const QVariant &value) override;
};

#endif // BASE_PROPERTY_H
