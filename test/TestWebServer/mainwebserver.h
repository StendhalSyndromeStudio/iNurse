#ifndef MAINWEBSERVER_H
#define MAINWEBSERVER_H
#include <QMainWindow>
#include "webclient.h"
#include "webserver.h"
#include "texttospeech.h"

namespace Ui {
class MainWebServer;
}

class MainWebServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWebServer(QWidget *parent = nullptr);
    ~MainWebServer();

private:
    Ui::MainWebServer *ui;
    WebClient* web = nullptr;
    WebServer* server = nullptr;
    TextToSpeech* TextToVoice = nullptr;

signals:
    void AddPlay(QString value);
    void StopPlay();

public slots:
    void ClickStartVoice(bool state);
    void RecordValue(QString value);


    void ClickConnect(bool state);//кнопка приконектится (всегда создаст новый экземпляр)
    void ClickMessage(bool state);// кнопка отправить сообщение
    void Log(QString message);//отображение лога

};

#endif // MAINWEBSERVER_H
