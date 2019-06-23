#include "property_form.h"
#include "interfaces/iproperty.h"

PropertyForm::PropertyForm(const QString &type)
  : IPropertyForm ()
  , _parent ( nullptr )
{
  _id           = property( "id", "text" );
  _type         = property( "type", "text" ); _type->setValue( type );
  _name         = property( "name", "text" );
  _description  = property( "description", "text" );
}

PropertyForm::~PropertyForm()
{

}

void PropertyForm::initilizeParent(IPropertyForm *form)
{
    _parent = form;
}


QString PropertyForm::id() const
{
  return _id->value().toString();
}

QString PropertyForm::type() const
{
  return _type->value().toString();
}

QString PropertyForm::name() const
{
  return _name->value().toString();
}

QString PropertyForm::description() const
{
  return _description->value().toString();
}

QList<IProperty *> PropertyForm::properties() const
{
  return _propertyList;
}

#include "property_provider.h"
IProperty *PropertyForm::property(const QString &id, const QString &type)
{
  static const QStringList only_local = { "id", "type", "name", "description" };

  auto contains = [](const QList<IProperty*> props, const QString &id)->bool {
    for ( auto &prop: props ) {
      if ( prop->id() == id )
        return  true;
    }
    return false;
  };

  if ( _parent ? contains( _parent->properties(), id ) && !only_local.contains( id ) : false ) {
    return _parent->property( id, type );
  }

  for ( auto &p: _propertyList )
    if ( p->id() == id )
      return p;

  auto p = PropertyProvider().create( id, type );
  if ( p ) {
    connect( p,   &IProperty::changedValue,
             [this, p]() { emit changed( p ); });
    _propertyList << p;
    emit addedProperty( p );
  }

  return p;
}
