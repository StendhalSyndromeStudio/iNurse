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

