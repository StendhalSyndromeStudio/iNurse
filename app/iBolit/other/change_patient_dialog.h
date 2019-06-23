#ifndef CHANGE_PATIENT_DIALOG_H
#define CHANGE_PATIENT_DIALOG_H

#include <QDialog>

namespace Ui {
  class ChangePatientDialog;
}

class ChangePatientDialog : public QDialog
{
  Q_OBJECT

public:
  explicit ChangePatientDialog(QWidget *parent = nullptr);
  ~ChangePatientDialog();

private:
  Ui::ChangePatientDialog *ui;
};

#endif // CHANGE_PATIENT_DIALOG_H
