#ifndef PROPERTY_PROVIDER_H
#define PROPERTY_PROVIDER_H

#include <QMap>
#include <functional>
#include "interfaces/iproperty_provider.h"

class PropertyProvider final
    : public IPropertyProvider
{
  using PropertyCreator = std::function<IProperty*(const QString &id)>;
  QMap<QString, PropertyCreator> creators;
public:
  PropertyProvider();
  ~PropertyProvider() override;

public:
  void add(const QString &type, const PropertyCreator &creator);

  // IPropertyProvider interface
public:
  virtual IProperty *create(const QString &id, const QString &type) override;
};

#endif // PROPERTY_PROVIDER_H
