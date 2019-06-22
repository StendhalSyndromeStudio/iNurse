#ifndef IPROPERTY_OBJECT_H
#define IPROPERTY_OBJECT_H

#include <QString>

class IPropertyObject
{
public:
  struct Item {


    QString id;
    QString type;
  };
  using ItemList = QList<Item>;

protected:
  IPropertyObject();
public:
  virtual ~IPropertyObject();

public:
  virtual ItemList items() const = 0;
  virtual bool setItem(const Item &item, const QString &text) = 0;
};

#endif // IPROPERTY_OBJECT_H
