#include "template_property_widget_provider.h"

TemplatePropertyWidgetProvider::TemplatePropertyWidgetProvider()
{

}

TemplatePropertyWidgetProvider::~TemplatePropertyWidgetProvider()
{

}


IPropertyWidget *TemplatePropertyWidgetProvider::create(IPropertyForm *form) const
{
  if ( creators.contains( form->type() ) ) {
    try {
      return creators[ form->type() ]( form );
    } catch (...) { }
  }

  return nullptr;
}
