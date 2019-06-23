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
  virtual IPropertyForm *create(const QString &type) const = 0;
};

#endif // IPROPERTY_FORM_PROVIDER_H
