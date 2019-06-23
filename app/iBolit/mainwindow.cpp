#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <form_medical_record.h>
#include <form_visit_doctor.h>
#include <form_direction.h>
#include <form_recipe.h>
#include "maindoctors.h"
#include "QAudioFormat"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , current ( nullptr )
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
/*
    FormVisitDoctor *widget = new FormVisitDoctor( _area );
    // Добавляем виджет в качестве подокна в Mdi Area
    _area->addSubWindow( widget );
    widget->show();
    widget->print();
    */
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

IPropertyForm *MainWindow::currentForm() const
{
  return current;
}

QList<IPropertyForm *> MainWindow::openedForms() const
{
  return _openedForms.keys();
}

bool MainWindow::contains(IPropertyForm *form) const
{
  return _openedForms.contains( form );
}

#include <property_widget_provider.h>
bool MainWindow::openForm(IPropertyForm *form)
{
  auto widget = dynamic_cast<QWidget*>( PropertyWidgetProvider().create( form ) );
  if ( widget ) {
    _area->addSubWindow( widget );
    widget->showNormal();
    current = form;
    emit formChanged();
    return true;
  }

  return false;
}

bool MainWindow::closeForm(IPropertyForm *form)
{
  if ( _openedForms.contains( form ) ) {
    auto wid = dynamic_cast<QWidget*>( _openedForms[ form ] );
    if ( wid ) {
      if ( current == form ) {
         current = _openedForms.isEmpty()
             ? nullptr
             : _openedForms.lastKey();

         if ( current )
           dynamic_cast<QWidget*>( _openedForms[ current ] )->showNormal();
      }

      _openedForms.remove( form );
      delete  wid;
    }
  }

  return false;
}

bool MainWindow::closeCurrentForm()
{
  if ( current ) {
    return closeForm( current );
  }
  return false;
}

bool MainWindow::setCurrentForm(IPropertyForm *form)
{
  if ( _openedForms.contains( form ) ) {
    auto wid = dynamic_cast<QWidget*>( _openedForms[ form ] );
    if ( wid ) {
     _area->showMaximized();
     current = form;
     return true;
    }
  }

  return false;
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

void MainWindow::changePatcient()
{

}
