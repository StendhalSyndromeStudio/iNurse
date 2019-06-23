#ifndef IPROPERTY_FORM_H
#define IPROPERTY_FORM_H

#include <QObject>

class IProperty;
class IPropertyForm : public QObject
{
  Q_OBJECT
public:

protected:
  explicit IPropertyForm();
public:
  virtual ~IPropertyForm() override;

public:
  virtual QString id() const = 0;
  virtual QString type() const = 0;
  virtual QString name() const = 0;
  virtual QString description() const = 0;

public:
  virtual QList<IProperty*> properties() const = 0;
  virtual IProperty *property(const QString &id, const QString &type) = 0;

signals:
  void addedProperty(IProperty *property);
  void removedProperty(IProperty *property);
  void changed(IProperty *property);
};

#endif // IPROPERTY_FORM_H
