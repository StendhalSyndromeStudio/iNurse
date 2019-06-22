#include "universal_gui_writer.h"
#include <QLineEdit>
#include <QTextEdit>

UniversalGuiWriter::UniversalGuiWriter()
  : IPropertyObject()
{

}

UniversalGuiWriter::~UniversalGuiWriter()
{

}

void UniversalGuiWriter::addSetMethod(const QString &id, const QString &type, QLineEdit *wid)
{
  Item item { id, type };
  _content[ id ] = std::make_pair( item, [wid](const QString &text)->bool {
    if ( text != wid->text() ) {
      wid->setText( text );
      return true;
    }
    return false;
  });
}

void UniversalGuiWriter::addSetMethod(const QString &id, const QString &type, QTextEdit *wid)
{
  Item item { id, type };
  _content[ id ] = std::make_pair( item, [wid](const QString &text)->bool {
    if ( text != wid->toPlainText() ) {
      wid->setText( text );
      return true;
    }
    return false;
  });
}


IPropertyObject::ItemList UniversalGuiWriter::items() const
{
  ItemList result;

  for ( auto &data: _content )
    result << data.first;

  return result;
}

bool UniversalGuiWriter::setItem(const IPropertyObject::Item &item, const QString &text)
{
  if ( _content.contains( item.id ) ) {
    try {
        return _content[ item.id ].second( text );
    } catch (...) { }
  }
  return false;
}
