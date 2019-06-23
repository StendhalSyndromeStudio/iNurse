#include "mainwebserver.h"
#include "ui_mainwebserver.h"
#include <QtWebSockets/QtWebSockets>

MainWebServer::MainWebServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWebServer)
{
    ui->setupUi(this);
    TextToVoice =  TextToSpeech::instanse(this);
    connect(this,&MainWebServer::AddPlay,TextToVoice,&TextToSpeech::AddPlay);
    connect(TextToVoice,&TextToSpeech::EndPlay,this,&MainWebServer::RecordValue);
    connect(ui->StartVoice,&QPushButton::clicked,this,&MainWebServer::ClickStartVoice);
    connect(ui->StopVoice,&QPushButton::clicked,TextToVoice,&TextToSpeech::StopPlay);


    web = new WebClient();
    server = new WebServer(1234);
    connect(web,&WebClient::Log,this,&MainWebServer::Log);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWebServer::ClickConnect);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWebServer::ClickMessage);
}

void MainWebServer::ClickStartVoice(bool state){
    QString str=ui->TextVoice->toPlainText();
    QStringList strList=str.split('\n'); // разбиваем строку из текстедита на отдельные строки
    for (int i=0; i< strList.count();i++){
        emit AddPlay(strList.at(i));
    }
}

void MainWebServer::RecordValue(QString value){
    Log(value);
}

void MainWebServer::ClickConnect(bool state){
    web->inicialize(ui->lineEdit->text());
}

void MainWebServer::ClickMessage(bool state){
    web->SendCommandServer(ui->lineEdit_2->text());
}

void MainWebServer::Log(QString message){
    ui->textEdit->append(message);
}

MainWebServer::~MainWebServer()
{
    delete ui;
}
