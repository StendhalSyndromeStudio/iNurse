#include "universal_gui_writer.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QRadioButton>

#include "interfaces/iproperty.h"
#include "interfaces/iproperty_form.h"

UniversalGuiWriter::UniversalGuiWriter()
    : IPropertyWidget()
{

}


UniversalGuiWriter::~UniversalGuiWriter()
{

}


void UniversalGuiWriter::addSetMethod(const QString &id, const QString &type, QLineEdit *wid)
{
    Item item { id, type };
    auto method = std::make_pair( item, [wid, this, id, type] {
        auto property = form->property( id, type );
        auto text = property->valueString();

        if ( text != wid->text() ) {
            wid->setText( property->valueString() );
        }
    });

    _content[ "id" ] = method;

    auto property = form->property( id, type );
    property->connect( property,  &IProperty::changedValue, method.second );
}


void UniversalGuiWriter::addSetMethod(const QString &id, const QString &type, QTextEdit *wid)
{
    Item item { id, type };
    auto method = std::make_pair( item, [wid, this, id, type]()->bool {
        auto property = form->property( id, type );
        auto text = property->valueString();

        if ( text != wid->toPlainText() ) {
            wid->setText( property->valueString() );
            return true;
        }
        return false;
    });


    _content[ "id" ] = method;

    auto property = form->property( id, type );
    property->connect( property,  &IProperty::changedValue, method.second );
}


void UniversalGuiWriter::addSetMethod(const QString &id, const QString &type, QRadioButton *wid, QWidget *parent)
{

    QList<QRadioButton*> list = parent->findChildren<QRadioButton*>();
    for ( auto child: list ) {
        child->setChecked( false );
    }
    Item item { id, type };
    auto method = std::make_pair( item, [wid, this, id, type]()->bool {
        auto property = form->property( id, type );
        auto text = property->value();
        wid->setChecked( property->value().toBool() );
        return true;
        /*
        if ( text != wid->toPlainText() ) {
            wid->setText( property->valueString() );
            return true;
        }
        return false;
        */
    });


    _content[ "id" ] = method;

    auto property = form->property( id, type );
    property->connect( property,  &IProperty::changedValue, method.second );
}


QString UniversalGuiWriter::type() const
{
    return "";
}


void UniversalGuiWriter::reload()
{
    for ( auto &data: _content ) {
        try {
            data.second();
        } catch (...) { }
    }
}


void UniversalGuiWriter::initilize(IPropertyForm *form)
{
    UniversalGuiWriter::form = form;
}
