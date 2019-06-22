#include "test_property_object.h"
#include <QtDebug>

TestPropertyObject::TestPropertyObject()
  : IPropertyObject ()
{

}

TestPropertyObject::~TestPropertyObject()
{

}


IPropertyObject::ItemList TestPropertyObject::items() const
{
  return { Item { "1", "regexp" }, Item { "2", "snils" } };
}

bool TestPropertyObject::setItem(const Item &item, const QString &text)
{
  qDebug() << item.id << item.type << text;
  return true;
}
