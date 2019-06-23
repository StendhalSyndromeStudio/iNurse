#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QMediaContent>
#include <QMediaPlayer>
#include <QSound>
#include <QProcess>
#include "libjson.h"

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
    void on_pushButton_clicked();
    void sendingFinished();
    void getResponse(QNetworkReply *reply);
    void onChangePlayerState( QProcess::ProcessState state );
    void onProcessFinished( );
    void onChangeCbxTxt( QString val );
private:
    Ui::MainWindow *ui;
    QNetworkRequest _request;
    QMediaContent _mediaContent;
    QMediaPlayer _player;
    QNetworkAccessManager *_mngr;
    int counter;
    QProcess proc;
    LibJson _parser;
};

#endif // MAINWINDOW_H
