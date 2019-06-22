#include "test_speach_writer.h"
#include "interfaces/iproperty.h"
#include "interfaces/Iproperty_object.h"

TestSpeachWriter::TestSpeachWriter()
  : ISpeachWriter ()
  , object ( nullptr )
  , current ( nullptr )
{

}

TestSpeachWriter::~TestSpeachWriter()
{

}

void TestSpeachWriter::clearProperty()
{
  while ( !_properties.isEmpty() )
    delete _properties.takeFirst();
}

void TestSpeachWriter::activatedProperty()
{
  auto prop = dynamic_cast<IProperty*>( sender() );
  if ( prop ) {
    current = prop;
  }
}

void TestSpeachWriter::deactivatedProperty()
{
  auto prop = dynamic_cast<IProperty*>( sender() );
  if ( prop ? prop == current : false ) {
    int index = _properties.indexOf( prop );
    if ( index >= 0 && index + 1 < _properties.count() ) {
      _properties[index + 1]->activate();
    } else if ( index >= 0 && index + 1 >= _properties.count() ) {
      _properties.first()->activate();
    } else if ( index == -1 && !_properties.isEmpty() ) {
        _properties.first()->activate();
    } else {
        current = nullptr;
    }
  }
}


bool TestSpeachWriter::hasWaitData() const
{
  return !!object;
}

void TestSpeachWriter::recognition(const QString &data)
{
  if ( hasWaitData() ) {
    if ( !current && !_properties.isEmpty() ) {
      current = _properties.first();
      current->activate();
    }

    if ( current ) {
      current->recognition( data );
    }
  }
}

IPropertyObject *TestSpeachWriter::obj() const
{
  return object;
}

QList<IProperty *> TestSpeachWriter::properties() const
{
  return _properties;
}

#include "property_provider.h"
void TestSpeachWriter::setPropertyObj(IPropertyObject *obj)
{
  object = obj;

  if ( object ) {
    PropertyProvider provider;
    for ( auto &item: object->items() ) {
      auto property = provider.create( item.id, item.type );
      if ( property ) {
        connect( property,    &IProperty::say,
                 this,        &TestSpeachWriter::say );
        connect( property,    &IProperty::activated,
                 this,        &TestSpeachWriter::activatedProperty );
        connect( property,    &IProperty::deactivated,
                 this,        &TestSpeachWriter::deactivatedProperty );
        _properties << property;
      }
    }

    if ( !_properties.isEmpty() )
      _properties.first()->activate();
  }

  emit changed();
}

