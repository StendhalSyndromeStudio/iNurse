#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <form_medical_record.h>
#include "maindoctors.h"
#include "QAudioFormat"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //предзагрузка звука ассистента для проигрывания
    WavFile.setFileName(":/res/assistant.wav");
    WavFile.open(QIODevice::ReadOnly);
    QAudioFormat format;
    // Set up the format, eg.
    format.setSampleRate(48000);
    format.setChannelCount(2);
    format.setSampleSize(32);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format)) {
        qDebug() << "Raw audio format not supported by backend, cannot play audio.";
       return;
    }
    Mediaplayer = new QAudioOutput(format, this);
    connect(Mediaplayer, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
    // Создаём Mdi Area в качестве центрального виджета
    _area = new QMdiArea( this );
    _area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    _area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget( _area );

    FormMedicalRecord *widget = new FormMedicalRecord( _area );
    // Добавляем виджет в качестве подокна в Mdi Area
    _area->addSubWindow( widget );
    widget->show();
    widget->print();
}

void MainWindow::handleStateChanged(QAudio::State newState)
{
    switch (newState) {
        case QAudio::IdleState:
            // Finished playing (no more data)
            Mediaplayer->stop();
            break;

        case QAudio::StoppedState:
            // Stopped for other reasons
            if (Mediaplayer->error() != QAudio::NoError) {
                // Error handling
            }
            break;

        default:
            // ... other cases as appropriate
            break;
    }
}

void MainWindow::StartSignal(){
    Mediaplayer->start(&WavFile);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_quit_triggered()
{
    qApp->exit();
}


void MainWindow::on_action_add_doc_triggered()
{
    QWidget *widget = new MainDoctors( _area );
    _area->addSubWindow( widget );
    widget->setWindowState( Qt::WindowState::WindowMaximized );
    widget->show();
}
