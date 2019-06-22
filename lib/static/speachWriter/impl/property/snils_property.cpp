#include "snils_property.h"

SnilsProperty::SnilsProperty(const QString &id)
  : RegExpProperty ( id )
{
  _type = "snils";
  setPattern( {
                "(?!000000000000$)([0-9]{12}$"
                , "(?!000000000 000$)([0-9]{9} [0-9]{3})$"
                , "(?!000\\-000\\-000 000$)([0-9]{3}[-]{1}[0-9]{3}[-]{1}[0-9]{3} [0-9]{3})$" } );
}

SnilsProperty::~SnilsProperty()
{

}

bool SnilsProperty::activate()
{
  bool ok = BaseProperty::activate();
  say( "СНИЛС!" );

  return ok;
}

bool SnilsProperty::deactivate()
{
  return BaseProperty::deactivate();
}

bool SnilsProperty::setValue(const QVariant &value)
{
  bool ok = BaseProperty::setValue( value );
  if ( validate( value.toString() ) && hasWaitData() ) {
      deactivate();
  }

  return ok;
}
