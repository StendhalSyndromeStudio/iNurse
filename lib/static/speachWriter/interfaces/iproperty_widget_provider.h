#ifndef IPROPERTY_WIDGET_PROVIDER_H
#define IPROPERTY_WIDGET_PROVIDER_H


class IPropertyForm;
class IPropertyWidget;
class IPropertyWidgetProvider
{
protected:
  IPropertyWidgetProvider();
public:
  virtual ~IPropertyWidgetProvider();
public:
  virtual IPropertyWidget *create(IPropertyForm *form) const = 0;
};

#endif // IPROPERTY_WIDGET_PROVIDER_H
