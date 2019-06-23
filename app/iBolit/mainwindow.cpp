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


void MainWindow::on_action_quit_triggered()
{
    qApp->exit();
}


void MainWindow::on_action_add_doc_triggered()
{
    QWidget* widget = new MainDoctors( _area );
    _area->addSubWindow( widget );
    widget->setWindowState( Qt::WindowState::WindowMaximized );
    widget->show();
}
