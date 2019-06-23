#include "property_widget_provider.h"

#include "form_medical_record.h"

PropertyWidgetProvider::PropertyWidgetProvider()
{
  addWidget<FormMedicalRecord>( "medical_record" );
}

PropertyWidgetProvider::~PropertyWidgetProvider()
{

}
