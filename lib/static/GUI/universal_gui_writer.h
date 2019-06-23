#ifndef UNIVERSAL_GUI_WRITER_H
#define UNIVERSAL_GUI_WRITER_H

class QLineEdit;
class QTextEdit;
class QRadioButton;
class QWidget;

#include <QMap>
#include <algorithm>
#include <functional>
#include <interfaces/iproperty_widget.h>

class UniversalGuiWriter
    : public IPropertyWidget
{
  using SetMethod = std::function<void()>;
  using Data      = std::pair<Item, SetMethod>;
  IPropertyForm       *form;
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
  void addSetMethod(const QString &id, const QString &type, QRadioButton *wid, QWidget* parent);

  // IPropertyWidget interface
public:
  virtual QString type() const override;
  virtual void reload() override;
  virtual void initilize(IPropertyForm *form) override;
  void print() override;
};

#endif // UNIVERSAL_GUI_WRITER_H
