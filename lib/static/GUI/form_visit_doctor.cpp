#include "form_visit_doctor.h"
#include "ui_form_visit_doctor.h"

FormVisitDoctor::FormVisitDoctor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVisitDoctor)
{
    ui->setupUi(this);
}


FormVisitDoctor::~FormVisitDoctor()
{
    delete ui;
}


QString FormVisitDoctor::type() const
{
    return "";
}


void FormVisitDoctor::reload()
{

}


void FormVisitDoctor::initilize(IPropertyForm *form)
{

}
