#ifndef TEMPLATE_PROPERTY_WIDGET_PROVIDER_H
#define TEMPLATE_PROPERTY_WIDGET_PROVIDER_H

#include <QMap>
#include <functional>
#include "interfaces/iproperty_form.h"
#include "interfaces/iproperty_widget_provider.h"

class TemplatePropertyWidgetProvider
    : public IPropertyWidgetProvider
{
protected:
  using Creator = std::function<IPropertyWidget*(IPropertyForm*)>;
  QMap<QString, Creator> creators;
public:
  TemplatePropertyWidgetProvider();
  ~TemplatePropertyWidgetProvider() override;

public:
  template<class Widget>
  void addWidget(const QString &type) {
    creators[ type ] = [](const IPropertyForm *form) {
      auto widget = new Widget();
      widget->initilize( form );
      return widget;
    };
  }

  // IPropertyWidgetProvider interface
public:
  virtual IPropertyWidget *create(IPropertyForm *form) const override;
};

#endif // TEMPLATE_PROPERTY_WIDGET_PROVIDER_H
