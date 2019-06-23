#include "maindoctors.h"
#include "ui_maindoctors.h"
#include "QDebug"
#include <form_medical_record.h>
#include <form_visit_doctor.h>
#include <form_direction.h>
#include <form_recipe.h>
#include <formprogress.h>


MainDoctors::MainDoctors(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDoctors)
{
    ui->setupUi(this);
    MainWidget = new TabWidgetDragDrop(this);
    MainWidget->setTabsClosable(true);
    ui->centralwidget->layout()->addWidget(MainWidget);
    MainWidget->setParent( ui->centralwidget);
    connect(MainWidget,&TabWidgetDragDrop::CreateRtf,this,&MainDoctors::CreateRtf);
    connect(MainWidget,&TabWidgetDragDrop::tabCloseRequested,this, &MainDoctors::CloseTab);
}

void MainDoctors::CloseTab(int index){
    MainWidget->removeTab(index);
}

void MainDoctors::CreateRtf(QString value){
    if ( _listDocs.contains( value ) ) {
        return;
    }
    _listDocs.append( value );
    //qDebug()<< value+" :получил создание";
    QWidget* val;
    if (value=="Медицинская карта.rtf"){
        val = new FormMedicalRecord(  );
    } else
    if (value=="Визит к доктору.rtf"){
        val = new FormVisitDoctor(  );
    } else
    if (value=="Направление к доктору.rtf"){
        val = new FormDirection(  );
    } else
    if (value=="Рецепт.rtf"){
        val = new FormRecipe(  );
    }
    FormProgress* prog = new FormProgress();
    prog->SetForm(val);
    MainWidget->addTab(prog,value);
    MainWidget->setCurrentIndex(MainWidget->count()-1);
}

MainDoctors::~MainDoctors()
{
    delete ui;
}
