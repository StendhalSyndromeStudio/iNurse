#include "form_medical_record.h"
#include "ui_form_medical_record.h"

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
