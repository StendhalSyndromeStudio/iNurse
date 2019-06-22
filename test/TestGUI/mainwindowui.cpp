#include "mainwindowui.h"
#include "ui_mainwindowui.h"
#include <libjson.h>
#include <QGridLayout>
#include <QLabel>
#include <form_medical_record.h>
#include <form_visit_doctor.h>
#include <form_direction.h>
#include <form_recipe.h>
#include "maindoctors.h"

MainWindowUI::MainWindowUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowUI)
{
    ui->setupUi(this);
    MainDoctors* w = new MainDoctors();
    w->show();
    // Создаём Mdi Area в качестве центрального виджета
    _area = new QMdiArea( this );
    _area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    _area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget( _area );

    LibJson json;
    json.LoadFile( QCoreApplication::applicationDirPath() + "/docs/test.json" );

//    createWindow( GUI::CodeWindow::medical_record );
    createWindow( GUI::CodeWindow::visit_doctor );
    createWindow( GUI::CodeWindow::direction );
    createWindow( GUI::CodeWindow::recipe );
}


MainWindowUI::~MainWindowUI()
{
    delete ui;
}


void MainWindowUI::createWindow(GUI::CodeWindow code)
{
    // Создаём виджет, который будет окном
    QWidget *widget;// = new FormMedicalRecord( _area );
    switch ( code ) {
    case GUI::CodeWindow::medical_record:
//        widget = new FormMedicalRecord( _area );
        break;

    case GUI::CodeWindow::visit_doctor:
        widget = new FormVisitDoctor( _area );
        break;

    case GUI::CodeWindow::direction:
        widget = new FormDirection( _area );
        break;

    case GUI::CodeWindow::recipe:
        widget = new FormRecipe( _area );
        break;
    }

    // Добавляем виджет в качестве подокна в Mdi Area
    _area->addSubWindow( widget );
    widget->show();
}
