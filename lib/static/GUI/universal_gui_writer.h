#ifndef UNIVERSAL_GUI_WRITER_H
#define UNIVERSAL_GUI_WRITER_H

class QLineEdit;
class QTextEdit;

#include <QMap>
#include <algorithm>
#include <functional>
#include <interfaces/Iproperty_object.h>

class UniversalGuiWriter
    : public IPropertyObject
{
  using SetMethod = std::function<bool(const QString &text)>;
  using Data      = std::pair<Item, SetMethod>;
  QMap<QString, Data> _content;
public:
  UniversalGuiWriter();
  ~UniversalGuiWriter() override;

public:
  template<class Widget>
  void addSetMethodSingle(const QString &idAndType,  Widget *wid) {
    addSetMethod( idAndType, idAndType, wid );
  }
  void addSetMethod(const QString &id, const QString &type, QLineEdit *wid);
  void addSetMethod(const QString &id, const QString &type, QTextEdit *wid);

  // IPropertyObject interface
public:
  virtual ItemList items() const override;
  virtual bool setItem(const Item &item, const QString &text) override;
};

#endif // UNIVERSAL_GUI_WRITER_H
