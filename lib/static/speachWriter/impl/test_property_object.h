#ifndef TEST_PROPERTY_OBJECT_H
#define TEST_PROPERTY_OBJECT_H

#include <interfaces/Iproperty_object.h>

class TestPropertyObject final
    : public IPropertyObject
{
public:
  TestPropertyObject();
  ~TestPropertyObject() override;

  // IPropertyObject interface
public:
  virtual ItemList items() const override;
  virtual bool setItem(const Item &item, const QString &text) override;
};

#endif // TEST_PROPERTY_OBJECT_H
