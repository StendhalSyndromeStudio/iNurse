#ifndef FORM_VISIT_DOCTOR_H
#define FORM_VISIT_DOCTOR_H

#include <QWidget>
#include "universal_gui_writer.h"
#include <interfaces/iproperty_widget.h>
#include <interfaces/iproperty_form.h>

namespace Ui {
class FormVisitDoctor;
}

class FormVisitDoctor : public QWidget, public IPropertyWidget
{
    Q_OBJECT

public:
    explicit FormVisitDoctor(QWidget *parent = nullptr);
    ~FormVisitDoctor();

private:
    Ui::FormVisitDoctor *ui;

    // IPropertyWidget interface
public:
    QString type() const;
    void reload();
    void initilize(IPropertyForm *form);
    virtual void print() override;
};

#endif // FORM_VISIT_DOCTOR_H
