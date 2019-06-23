#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <form_medical_record.h>
#include "maindoctors.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаём Mdi Area в качестве центрального виджета
    _area = new QMdiArea( this );
    _area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    _area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget( _area );
    /*
    QWidget *widget = new FormMedicalRecord( _area );
    // Добавляем виджет в качестве подокна в Mdi Area
    _area->addSubWindow( widget );
    widget->show();
    */
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
    widget->showMaximized();
    return true;
  }

  return false;
}

bool MainWindow::closeForm(IPropertyForm *form)
{
  if ( _openedForms.contains( form ) ) {
    auto wid = dynamic_cast<QWidget*>( _openedForms[ form ] );
    if ( wid ) {
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
