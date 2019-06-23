#ifndef JSON_BUILDER_MW_H
#define JSON_BUILDER_MW_H

#include <QLabel>
#include <QMainWindow>
#include <QProgressBar>
#include "thread_builder.h"

namespace Ui {
  class JsonBuilderMw;
}

class JsonBuilderMw
    : public QMainWindow
{
  Q_OBJECT
  Ui::JsonBuilderMw *ui;
  ThreadBuilder     *builder;
  QLabel            status;
  QProgressBar      progress;
public:
  explicit JsonBuilderMw(QWidget *parent = nullptr);
  ~JsonBuilderMw() override;

public slots:
  void updateGui();

private slots:
  void on_bInput_clicked();
  void on_bOutput_clicked();
  void on_bCompile_clicked();

signals:
  void changeStatusStr(const QString &status);
  void changeProgress(double progress);
  void started();
  void finished();
};

#endif // JSON_BUILDER_MW_H
