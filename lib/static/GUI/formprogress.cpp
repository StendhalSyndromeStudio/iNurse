#include "formprogress.h"
#include "ui_formprogress.h"

FormProgress::FormProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormProgress)
{
    ui->setupUi(this);
    connect(&TimeProgress,&QTimer::timeout,this,&FormProgress::Ontimer);
    TimeProgress.start(10);
}

FormProgress::~FormProgress()
{
    delete ui;
}

void FormProgress::SetForm(QWidget *wid){
    this->widget = wid;
}

void FormProgress::Ontimer(){
    if (ui->progressBar->value()<100){
        ui->progressBar->setValue(ui->progressBar->value()+1);
    }
    else{
        TimeProgress.stop();
        this->layout()->addWidget((widget));
        widget->setParent(this);
        ui->progressBar->hide();
    }
}
