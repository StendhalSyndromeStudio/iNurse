#include "property_provider.h"

#include "property/snils_property.h"
#include "property/regexp_property.h"
PropertyProvider::PropertyProvider()
{
  add( "regexp", [](const QString &id)->IProperty* {
    return new RegExpProperty( id );
  } );

  add( "snils", [](const QString &id)->IProperty* {
    return new SnilsProperty( id );
  } );
}

PropertyProvider::~PropertyProvider()
{

}

void PropertyProvider::add(const QString &type, const PropertyProvider::PropertyCreator &creator)
{
  creators[ type ] = creator;
}

#include "property/base_property.h"
IProperty *PropertyProvider::create(const QString &id, const QString &type)
{
  if ( creators.contains( type ) ) {
    try {
      return  creators[ type ]( id );
    } catch (...) { }
  }

  return new BaseProperty( id, type );
}
