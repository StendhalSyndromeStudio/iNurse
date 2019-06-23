#include "form_medical_record.h"
#include "ui_form_medical_record.h"
#include "print.h"

static int _guid = 0;

FormMedicalRecord::FormMedicalRecord(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormMedicalRecord)
    , writer ( new UniversalGuiWriter() )
{
    ui->setupUi(this);
}


FormMedicalRecord::~FormMedicalRecord()
{
    delete writer;
    delete ui;
}



QString FormMedicalRecord::type() const
{
    return "medical_record";
}


void FormMedicalRecord::reload()
{

}


void FormMedicalRecord::initilize(IPropertyForm *form)
{
    Q_UNUSED(form);
    writer->initilize( form );
    writer->addSetMethodSingle( "fio", ui->fio );
    writer->addSetMethodSingle( "sex", ui->sex );
    writer->addSetMethod( "date_birth_day", "date_birth_day", ui->date_birth_day );
    writer->addSetMethod( "date_birth_month", "date_birth_month", ui->date_birth_month );
    writer->addSetMethod( "date_birth_year", "date_birth_year", ui->date_birth_year );
    writer->addSetMethod( "address_subject", "address_subject", ui->address_subject );
    writer->addSetMethod( "address_area", "address_area", ui->address_area );
    writer->addSetMethod( "address_city", "address_city", ui->address_city );
    writer->addSetMethod( "address_locality", "address_locality", ui->address_locality );
    writer->addSetMethod( "address_street", "address_street", ui->address_street );
    writer->addSetMethod( "address_house", "address_house", ui->address_house );
    writer->addSetMethod( "address_apartment", "address_apartment", ui->address_apartment );
    writer->addSetMethod( "tel", "tel", ui->tel );
    writer->addSetMethod( "locality_city", "locality", ui->locality_city, ui->widget_06 );
    writer->addSetMethod( "locality_village", "locality", ui->locality_village, ui->widget_06 );
    writer->addSetMethod( "polis_series", "polis_series", ui->polis_series );
    writer->addSetMethod( "polis_number", "polis_number", ui->polis_number );
    writer->addSetMethod( "snils", "snils", ui->snils );
    writer->addSetMethod( "medical_organization", "medical_organization", ui->medical_organization );
    writer->addSetMethod( "concession_code", "concession_code", ui->concession_code );
    writer->addSetMethod( "documnet", "documnet", ui->documnet );
    writer->addSetMethod( "document_series", "document_series", ui->documnet_series );
    writer->addSetMethod( "documnet_number", "documnet_number", ui->documnet_number );
    //    writer->addSetMethod( "marital_status", "marital_status", ui );
    //    writer->addSetMethod( "education", "education", ui );
    //    writer->addSetMethod( "employment", "employment", ui );
    writer->addSetMethod( "disability", "disability", ui->disability );
    writer->addSetMethod( "work_place", "work_place", ui->work_place );
    writer->addSetMethod( "work_post", "work_post", ui->work_post );
    writer->addSetMethod( "blood_group", "blood_group", ui->blood_group );
    writer->addSetMethod( "blood_rh", "blood_rh", ui->blood_rh );
    writer->addSetMethod( "allegic_reactions", "allegic_reactions", ui->allegic_reactions );
    //    writer->addSetMethod( "", "", ui );
}


void FormMedicalRecord::print()
{
    Print printer;
    printer.addLine( ui->label->text(), 14, Qt::AlignmentFlag::AlignCenter );
    printer.addText( ui->label_2->text(), 14, Print::FontStyle::normal, true );
    printer.addText( QString( "  %1  " ).arg( ui->card_number->text() ), 14, Print::FontStyle::underline );
    printer.addText( ui->label_3->text(), 10, Print::FontStyle::normal, true );
    printer.addText( QString( "  %1  " ).arg( ui->creation_date_day->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_4->text() );
    printer.addText( QString( "  %1  " ).arg( ui->creation_date_month->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_5->text() );
    printer.addText( QString( "  %1  " ).arg( ui->creation_date_year->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_6->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->fio->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_7->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->sex->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_8->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->date_birth_day->text(), 10, ' ' ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_9->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->date_birth_month->text(), 10, ' ' ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_10->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->date_birth_year->text(), 10, ' ' ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_11->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->address_subject->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_12->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->address_area->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_13->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->address_city->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_14->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->address_locality->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_15->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->address_street->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_16->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->address_house->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_17->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->address_apartment->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_18->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->tel->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_19->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->locality_city->isChecked() ? "городская" : "сельская" ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_20->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->polis_series->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_21->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->polis_number->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_22->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->snils->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_23->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->medical_organization->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_24->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->concession_code->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_25->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->documnet->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_26->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->documnet_series->text() ), 10, Print::FontStyle::underline );
    printer.addText( ui->label_27->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->documnet_number->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_28->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( "неизвестно" ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_29->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( "неизвестно" ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_31->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( "прочее" ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_32->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->disability->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_33->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->work_place->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_34->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->work_post->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_35->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->blood_group->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_36->text(), 10, Print::FontStyle::bold );
    printer.addText( QString( "  %1  " ).arg( ui->blood_rh->text() ), 10, Print::FontStyle::underline );

    printer.addText( ui->label_37->text(), 10, Print::FontStyle::bold, true );
    printer.addText( QString( "  %1  " ).arg( ui->allegic_reactions->text() ), 10, Print::FontStyle::underline );

    printer.toPrint();
}
