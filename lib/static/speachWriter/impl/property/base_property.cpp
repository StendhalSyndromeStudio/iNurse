#include "base_property.h"

BaseProperty::BaseProperty(const QString &id, const QString &type, const QVariant &value)
  : IProperty ()
  , _id ( id )
  , _type ( type )
  , _value ( value )
  , _isActivate ( false )
{

}

BaseProperty::~BaseProperty()
{

}


bool BaseProperty::hasWaitData() const
{
  return  _isActivate;
}

void BaseProperty::recognition(const QString &data)
{
  setValue( data );
}

QString BaseProperty::id() const
{
  return _id;
}

QString BaseProperty::type() const
{
  return _type;
}

QVariant BaseProperty::value() const
{
  return _value;
}

QStringList BaseProperty::activateList() const
{
  return _activateList;
}

bool BaseProperty::activate()
{
  if ( !_isActivate ) {
    _isActivate = true;
    emit activated();
  }

  return _isActivate;
}

bool BaseProperty::deactivate()
{
  if ( _isActivate ) {
    _isActivate = false;
    emit deactivate();
  }

  return !_isActivate;
}

bool BaseProperty::setValue(const QVariant &value)
{
  if ( value != _value.toString() ) {
    _value.setValue( value );
    emit changedValue();
    return true;
  }
  return false;
}
