#ifndef FORM_MEDICAL_RECORD_H
#define FORM_MEDICAL_RECORD_H

#include <QWidget>

namespace Ui {
class FormMedicalRecord;
}

class FormMedicalRecord : public QWidget
{
    Q_OBJECT

public:
    explicit FormMedicalRecord(QWidget *parent = nullptr);
    ~FormMedicalRecord();


private:
    Ui::FormMedicalRecord *ui;
};

#endif // FORM_MEDICAL_RECORD_H
