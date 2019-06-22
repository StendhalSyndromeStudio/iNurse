#include "form_medical_record.h"
#include "ui_form_medical_record.h"

FormMedicalRecord::FormMedicalRecord(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::FormMedicalRecord)
  , writer ( new UniversalGuiWriter() )
{
    ui->setupUi(this);
    writer->addSetMethod( "fio", "fio", ui->fio );
//    writer->addSetMethodSingle( "fio", ui->fio );
}

FormMedicalRecord::~FormMedicalRecord()
{
  delete writer;
    delete ui;
}


IPropertyObject::ItemList FormMedicalRecord::items() const
{
    return writer->items();
}


bool FormMedicalRecord::setItem(const IPropertyObject::Item &item, const QString &text)
{
    return writer->setItem( item, text );
}

