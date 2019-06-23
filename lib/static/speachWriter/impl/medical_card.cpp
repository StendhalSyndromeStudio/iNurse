#include "medical_card.h"
#include "interfaces/iproperty.h"

MedicalCard::MedicalCard()
  : IMedicalCard ()
  , form ( new PropertyForm( "medical_record" ) )
{
  connect( form,  &IPropertyForm::addedProperty,
           this,  &IPropertyForm::addedProperty );

  connect( form,  &IPropertyForm::removedProperty,
           this,  &IPropertyForm::removedProperty );

  connect( form,  &IPropertyForm::changed,
           this,  &IPropertyForm::changed );

  property( "fio", "fio" );
  property( "date_birth_day", "date_birth_day" );
  property( "date_birth_month", "date_birth_month" );
  property( "date_birth_year", "date_birth_year" );
  property( "document_series", "document_series" );
  property( "documnet_number", "documnet_number" );
}

MedicalCard::~MedicalCard()
{

}

QVariant MedicalCard::getValue(const QString &id) const
{
  for ( auto &p: form->properties() )
    if ( p->id() == id )
      return p->valueString();

  return QVariant();
}


QString MedicalCard::id() const
{
  return form->id();
}

QString MedicalCard::type() const
{
  return form->type();
}

QString MedicalCard::name() const
{
  return form->name();
}

QString MedicalCard::description() const
{
  return form->description();
}

QList<IProperty *> MedicalCard::properties() const
{
  return form->properties();
}

IProperty *MedicalCard::property(const QString &id, const QString &type)
{
  return form->property( id, type );
}

QList<IPropertyForm *> MedicalCard::forms() const
{
  return childForms;
}

QString MedicalCard::fio() const
{
  return getValue( "fio" ).toString();
}

QString MedicalCard::dataBirth() const
{
  return getValue( "date_birth_day" ).toString()
      + "-" + getValue( "date_birth_month" ).toString()
      + "-" + getValue( "date_birth_year" ).toString();
}

QString MedicalCard::docSerial() const
{
  return getValue( "document_series" ).toString();
}

QString MedicalCard::docNumber() const
{
  return getValue( "documnet_number" ).toString();
}

void MedicalCard::add(IPropertyForm *form)
{
  if ( !childForms.contains( form ) ) {
    childForms << form;
    emit add( form );
  }
}

void MedicalCard::remove(IPropertyForm *)
{
}
