#ifndef IPROPERTY_PROVIDER_H
#define IPROPERTY_PROVIDER_H

class QString;
class IProperty;
class IPropertyProvider
{
protected:
    IPropertyProvider();
public:
    virtual ~IPropertyProvider();

public:
    virtual IProperty *create(const QString &id, const QString &type) = 0;
};

#endif // IPROPERTY_PROVIDER_H
