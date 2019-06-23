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

QString BaseProperty::valueString() const
{
  return _value.toString();
}

QStringList BaseProperty::activateList() const
{
  return _dataById[ "activation_list" ].toStringList();
}

QVariant BaseProperty::getById(const QString &id) const
{
  return _dataById[ id ].toStringList();
}

QStringList BaseProperty::dataIdList() const
{
  return _dataById.keys();
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

bool BaseProperty::setById(const QString &id, const QVariant &value)
{
  _dataById[ id ] = value;
  return true;
}
