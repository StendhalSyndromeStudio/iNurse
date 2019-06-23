#ifndef PROPERTY_FORM_H
#define PROPERTY_FORM_H

#include "interfaces/iproperty_form.h"

class PropertyForm final
    : public IPropertyForm
{
  Q_OBJECT
  IProperty         *_id;
  IProperty         *_type;
  IProperty         *_name;
  IProperty         *_description;
  QList<IProperty*> _propertyList;
  IPropertyForm     *_parent;
public:
  explicit PropertyForm(const QString &type);
  ~PropertyForm() override;

public:
  void initilizeParent(IPropertyForm *form);

  // IPropertyForm interface
public:
  virtual QString id() const override;
  virtual QString type() const override;
  virtual QString name() const override;
  virtual QString description() const override;
  virtual QList<IProperty *> properties() const override;
  virtual IProperty *property(const QString &id, const QString &type) override;
};

#endif // PROPERTY_FORM_H
