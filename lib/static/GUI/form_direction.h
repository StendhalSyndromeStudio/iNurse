#ifndef FORM_DIRECTION_H
#define FORM_DIRECTION_H

#include <QWidget>
#include "universal_gui_writer.h"
#include <interfaces/iproperty_widget.h>
#include <interfaces/iproperty_form.h>

namespace Ui {
class FormDirection;
}

class FormDirection : public QWidget, public IPropertyWidget
{
    Q_OBJECT

public:
    explicit FormDirection(QWidget *parent = nullptr);
    ~FormDirection();

private:
    Ui::FormDirection *ui;

    // IPropertyWidget interface
public:
    QString type() const;
    void reload();
    void initilize(IPropertyForm *form);
    virtual void print() override;

};

#endif // FORM_DIRECTION_H
