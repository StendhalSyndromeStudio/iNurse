#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QFile>
#include <QAudioOutput>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_quit_triggered();
    void on_action_add_doc_triggered();    
    void handleStateChanged(QAudio::State);

public slots:
    void StartSignal();//старт сигнала разговора

private:
    Ui::MainWindow *ui;
    QMdiArea* _area;
    QFile WavFile;
    QAudioOutput* Mediaplayer;

};

#endif // MAINWINDOW_H
