#ifndef FORM_VISIT_DOCTOR_H
#define FORM_VISIT_DOCTOR_H

#include <QWidget>

namespace Ui {
class FormVisitDoctor;
}

class FormVisitDoctor : public QWidget
{
    Q_OBJECT

public:
    explicit FormVisitDoctor(QWidget *parent = nullptr);
    ~FormVisitDoctor();

private:
    Ui::FormVisitDoctor *ui;
};

#endif // FORM_VISIT_DOCTOR_H
