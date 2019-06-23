#ifndef PROPERTY_WIDGET_PROVIDER_H
#define PROPERTY_WIDGET_PROVIDER_H

#include <impl/template_property_widget_provider.h>

class PropertyWidgetProvider
    : public TemplatePropertyWidgetProvider
{
public:
  PropertyWidgetProvider();
  ~PropertyWidgetProvider() override;
};

#endif // PROPERTY_WIDGET_PROVIDER_H
