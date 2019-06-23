#ifndef PROPERTY_FORM_PROVIDER_H
#define PROPERTY_FORM_PROVIDER_H

#include "interfaces/iproperty_form_provider.h"

class PropertyFormProvider final
    : public IPropertyFormProvider
{
public:
  PropertyFormProvider();
  ~PropertyFormProvider() override;

  // IPropertyFormProvider interface
public:
  virtual IPropertyForm *create(const QString &type) const override;
};

#endif // PROPERTY_FORM_PROVIDER_H
