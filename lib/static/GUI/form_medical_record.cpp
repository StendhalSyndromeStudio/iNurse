#include "form_medical_record.h"
#include "ui_form_medical_record.h"

FormMedicalRecord::FormMedicalRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMedicalRecord)
{
    ui->setupUi(this);

}

FormMedicalRecord::~FormMedicalRecord()
{
    delete ui;
}


IPropertyObject::ItemList FormMedicalRecord::items() const
{
    ItemList list;// = new ItemList();
    Item item;
    item.id = "fio";
    item.type = "fio";
    list.append( item );
    return list;
}


bool FormMedicalRecord::setItem(const IPropertyObject::Item &item, const QString &text)
{
    if ( item.id == "fio" ) {
        ui->fio->setText( text );
        return true;
    }
    return false;
}

