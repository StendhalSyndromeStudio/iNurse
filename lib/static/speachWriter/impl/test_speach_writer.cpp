#include "test_speach_writer.h"
#include "interfaces/iproperty.h"
#include "interfaces/iproperty_form.h"

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
  if ( object ) {
    for ( auto &property: object->properties() )
      disconnectPropery( property );
  }
}

void TestSpeachWriter::activatedProperty()
{
  auto prop = dynamic_cast<IProperty*>( sender() );
  if ( prop && ( object ? object->properties().contains( prop ): false ) ) {
    current = prop;
  }
}

void TestSpeachWriter::deactivatedProperty()
{
  auto prop = dynamic_cast<IProperty*>( sender() );
  if ( ( prop ? prop == current : false ) && ( object ? object->properties().contains( prop ): false ) ) {
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

void TestSpeachWriter::sayFinished(const QString &data)
{
  if ( current )
    current->sayFinished( data );
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

void TestSpeachWriter::connectForm(IPropertyForm *form)
{
  connect( form,    &IPropertyForm::addedProperty,
           this,    &TestSpeachWriter::connectPropery );

  connect( form,    &IPropertyForm::removedProperty,
           this,    &TestSpeachWriter::disconnectPropery );
}

void TestSpeachWriter::disconnectForm(IPropertyForm *form)
{
  disconnect( form,    &IPropertyForm::addedProperty,
              this,    &TestSpeachWriter::connectPropery );

  disconnect( form,    &IPropertyForm::removedProperty,
              this,    &TestSpeachWriter::disconnectPropery );
}

void TestSpeachWriter::connectPropery(IProperty *property)
{
  connect( property,    &IProperty::say,
           this,        &TestSpeachWriter::say );
  connect( property,    &IProperty::activated,
           this,        &TestSpeachWriter::activatedProperty );
  connect( property,    &IProperty::deactivated,
           this,        &TestSpeachWriter::deactivatedProperty );
}

void TestSpeachWriter::disconnectPropery(IProperty *property)
{
  disconnect( property,    &IProperty::say,
              this,        &TestSpeachWriter::say );
  disconnect( property,    &IProperty::activated,
              this,        &TestSpeachWriter::activatedProperty );
  disconnect( property,    &IProperty::deactivated,
              this,        &TestSpeachWriter::deactivatedProperty );
}

IPropertyForm *TestSpeachWriter::form() const
{
  return object;
}

QList<IProperty *> TestSpeachWriter::properties() const
{
  return _properties;
}

#include "property_provider.h"
void TestSpeachWriter::setPropertyObj(IPropertyForm *obj)
{
  if ( object ) {
    disconnectForm( object );
    clearProperty();
  }


  object = obj;

  if ( object ) {
    connectForm( object );

    if ( !object->properties().isEmpty() )
      object->properties().first()->activate();
  }

  emit changed();
}

