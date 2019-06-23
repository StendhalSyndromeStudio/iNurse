#include "property_form_provider.h"
#include "property_form.h"

PropertyFormProvider::PropertyFormProvider()
{

}

PropertyFormProvider::~PropertyFormProvider()
{

}


IPropertyForm *PropertyFormProvider::create(const QString &type) const
{
  return new PropertyForm( type );
}
