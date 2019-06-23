#ifndef IPROPERTY_WIDGET_H
#define IPROPERTY_WIDGET_H

#include <QString>

class IPropertyForm;
class IPropertyWidget
{
public:
    struct Item {


        QString id;
        QString type;
    };
    using ItemList = QList<Item>;

protected:
    IPropertyWidget();
public:
    virtual ~IPropertyWidget();

public:
    virtual QString type() const = 0;

public:
    virtual void reload() = 0;
    virtual void initilize(IPropertyForm *form) = 0;
    virtual void print() = 0;
};

#endif // IPROPERTY_WIDGET_H
