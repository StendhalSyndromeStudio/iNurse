#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrlQuery>
#include <QDebug>
#include <QByteArray>
#include <QFile>
#include <QProcess>
#include<QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _request{ QUrl{ "https://tts.api.cloud.yandex.net/speech/v1/tts:synthesize" } },
    _mngr{ new QNetworkAccessManager( this ) },
    counter{ 0 }
{
    ui->setupUi( this );
    _request.setRawHeader( "Authorization",QString( "Api-Key AQVN34_yEdZJee7cfPzS6K9YdteELO09HLrSuUTT" ).toLocal8Bit( ) );

    connect( _mngr, SIGNAL( finished( QNetworkReply* ) ), SLOT( getResponse( QNetworkReply* ) ) );
    connect( ui->comboBox, SIGNAL(currentTextChanged(QString)), SLOT(onChangeCbxTxt(QString)));

    _parser.LoadFile( "D:\\Sourse\\build-INurse-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\app\\Speaker\\test.json" );
    ui->comboBox->addItems( _parser.getKeys( ) );
    qDebug( ) << _parser.getValue( "_1" );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::on_pushButton_clicked( ) {
    QUrlQuery params;

    params.addQueryItem( "text", ui->plainTextEdit->toPlainText( ) );
    params.addQueryItem( "lang", "ru-RU" );
    params.addQueryItem( "voice", "ermil" );
    params.addQueryItem( "folderId", "b1g1dl29edi1ks5ohb3v" );
//    params.addQueryItem( "emotion", "evil" );
//    params.addQueryItem( "format","lpcm");
//    params.addQueryItem( "sampleRateHertz","48000");
    QByteArray data;
    data.append( params.toString( ) );

    QNetworkReply *reply = _mngr->post( _request, data );
    connect( reply, SIGNAL( finished( ) ), SLOT( sendingFinished( ) ) );
}

void MainWindow::sendingFinished( ) {
//    qDebug( ) << "sendingFinished";
}

void MainWindow::getResponse( QNetworkReply *reply ) {
    qDebug( ) << "error" << reply->errorString( ) << reply->isFinished();
    proc.terminate( );
    proc.waitForFinished( 100 );

    QString path{ "D:\\Sourse\\build-INurse-Desktop_Qt_5_11_3_MinGW_32bit-Debug\\app\\Speaker\\voice\\" + QString::number( counter++ ) + ".ogg" };
    QFile f( path );
    f.open( QIODevice::WriteOnly );
    f.write( reply->readAll( ) );
    f.waitForBytesWritten( 100 );
    f.close( );

    proc.start( "C:/Program Files (x86)/AIMP3/AIMP3.exe", { path } );
}

void MainWindow::onChangePlayerState(QProcess::ProcessState state)
{
//    qDebug( ) << "state:" << state;
}

void MainWindow::onProcessFinished()
{
//    qDebug( ) << "delete";
}

void MainWindow::onChangeCbxTxt( QString val ) {
//    qDebug( ) << "change";
    ui->plainTextEdit->setPlainText( _parser.getValue( val ) );
}
