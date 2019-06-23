#include "form_visit_doctor.h"
#include "ui_form_visit_doctor.h"
#include "print.h"

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


void FormVisitDoctor::print()
{
    Print printer;
    printer.addText( ui->label->text() , 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->date_visit->text() ), 10, Print::FontStyle::underline );
    printer.addText( "  на приёме, на дому, в фельдерско-акушерском пункте, прочее", 10, Print::FontStyle::bold );

    printer.addText( ui->label_2->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->doctor->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_3->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->complaints->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_4->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->anamnesis->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_5->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->objective_data->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_6->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->diagnosis->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_7->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->complications->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_8->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->accompanying_illnesses->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_9->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->external_reason->toPlainText() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_10->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->health_group->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_11->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->dispensary_observation->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_12->text(), 10, Print::FontStyle::bold, true );
    printer.addText( "   " + ui->label_13->text(), 10, Print::FontStyle::bold );
    //printer.addText( QString( "  %1  " ).arg( ui->destination-> ), 0, Print::FontStyle::underline );

    printer.toPrint();
}
