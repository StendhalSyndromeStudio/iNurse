#include "change_patient_dialog.h"
#include "ui_change_patient_dialog.h"

ChangePatientDialog::ChangePatientDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ChangePatientDialog)
{
  ui->setupUi(this);
}

ChangePatientDialog::~ChangePatientDialog()
{
  delete ui;
}
