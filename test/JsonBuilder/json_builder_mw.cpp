#include "json_builder_mw.h"
#include "ui_json_builder_mw.h"
#include <cmath>
#include <QFileDialog>
#include <QMessageBox>
#include <thread_builder.h>

JsonBuilderMw::JsonBuilderMw(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::JsonBuilderMw)
  , builder ( new ThreadBuilder( this ) )
{
  ui->setupUi(this);
  updateGui();

  progress.setMaximum( 10000 );

  ui->statusBar->addWidget( &status, 3 );
  ui->statusBar->addWidget( &progress, 2 );

  connect( this,    &JsonBuilderMw::changeProgress,
           [this](double progress){
    this->progress.setValue( static_cast<int>(
                               std::round( this->progress.maximum() / 100.0 * progress ) ) );
  });

  connect( this,    &JsonBuilderMw::changeStatusStr,
           [this](const QString status){
    auto tmp = status;
    if ( tmp.length() > 32 )
      tmp = tmp.mid( 0, 32 );

    this->status.setText( tmp );
//    ui->log.
  });

  connect( this,    &JsonBuilderMw::started,
           this,    &JsonBuilderMw::updateGui );

  connect( this,    &JsonBuilderMw::finished,
           this,    &JsonBuilderMw::updateGui );
}

JsonBuilderMw::~JsonBuilderMw()
{
  delete builder;
  delete ui;
}

void JsonBuilderMw::updateGui()
{
  bool ok = builder->isWork();

  ui->inputFile->setEnabled( !ok );
  ui->outputFile->setEnabled( !ok );
  ui->bInput->setEnabled( !ok );
  ui->bOutput->setEnabled( !ok );

  ui->bCompile->setText( ok ? "stop" : "compile" );
}

void JsonBuilderMw::on_bInput_clicked()
{
  auto text = QFileDialog::getOpenFileName( this
                                            , tr ( "Input file" ) );
  if ( !text.isEmpty() ) {
    ui->inputFile->setText( text );
  }
}

void JsonBuilderMw::on_bOutput_clicked()
{
  auto text = QFileDialog::getSaveFileName( this
                                            , tr ( "Output file" ) );
  if ( !text.isEmpty() ) {
    ui->outputFile->setText( text );
  }
}

void JsonBuilderMw::on_bCompile_clicked()
{
  if ( builder->isWork() ) {
    builder->abort();
  } else {

    auto input = ui->inputFile->text();
    auto output = ui->outputFile->text();
    auto fields = ui->lines->toPlainText().split( "\n" );

    if ( !input.isEmpty() && !output.isEmpty() && !fields.isEmpty() ) {
//      ui->log->clear();
      builder->start( input, output, fields );
      updateGui();
    } else {
      QMessageBox::warning( this
                            , tr ( "Error" )
                            , tr ( "Write all fields!" ) );
    }
  }
}
