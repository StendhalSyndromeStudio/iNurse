#include "form_medical_record.h"
#include "ui_form_medical_record.h"

FormMedicalRecord::FormMedicalRecord(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::FormMedicalRecord)
  , writer ( new UniversalGuiWriter() )
{
    ui->setupUi(this);
//    writer->addSetMethod( "fio", "fio", ui->fio );
//    writer->addSetMethodSingle( "fio", ui->fio );
}

FormMedicalRecord::~FormMedicalRecord()
{
  delete writer;
    delete ui;
}



QString FormMedicalRecord::type() const
{
  return "";
}

void FormMedicalRecord::reload()
{

}

void FormMedicalRecord::initilize(IPropertyForm *form)
{
  Q_UNUSED(form);
}
