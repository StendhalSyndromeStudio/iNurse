#ifndef SNILS_PROPERTY_H
#define SNILS_PROPERTY_H

#include "regexp_property.h"

class SnilsProperty
    : public RegExpProperty
{
  Q_OBJECT
public:
  explicit SnilsProperty(const QString &id);
  ~SnilsProperty() override;

  // IProperty interface
public slots:
  virtual bool activate() override;
  virtual bool deactivate() override;
  virtual bool setValue(const QVariant &value) override;
};

#endif // SNILS_PROPERTY_H
