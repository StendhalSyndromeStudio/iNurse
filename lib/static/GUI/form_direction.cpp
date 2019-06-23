#include "form_direction.h"
#include "ui_form_direction.h"

FormDirection::FormDirection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDirection)
{
    ui->setupUi(this);
}


FormDirection::~FormDirection()
{
    delete ui;
}


QString FormDirection::type() const
{
    return "";
}


void FormDirection::reload()
{

}


void FormDirection::initilize(IPropertyForm *form)
{

}


void FormDirection::print()
{

}
