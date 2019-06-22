#ifndef IPROPERTY_FORM_PROVIDER_H
#define IPROPERTY_FORM_PROVIDER_H

#include <QList>

class IPropertyForm;
class IPropertyFormProvider
{
protected:
  IPropertyFormProvider();
public:
  virtual ~IPropertyFormProvider();

public:
  virtual IPropertyForm *create() const = 0;
  virtual QList<IPropertyForm *> loadAll() const = 0;
};

#endif // IPROPERTY_FORM_PROVIDER_H
