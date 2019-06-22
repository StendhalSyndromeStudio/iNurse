#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include <QObject>
#include <QtWebSockets/QtWebSockets>

class WebClient : public QObject
{
    Q_OBJECT
public:
    explicit WebClient(QObject *parent = nullptr);
    bool SendCommandServer(QString value);//отправка данных серверу
    void inicialize(const QUrl &url);//попытка конекта по URL
    void CloseSocket();

private:
        QWebSocket m_webSocket;//объект сокета
        QUrl m_url;//url сервера

signals:
    void CloseSockets();
    void Log(QString message);
    void ReceiveMessage(QString message);

public slots:
    void Connect();//конект успешен
    void Received(QString message);//что-то пришло
    void Disconnects();
};

#endif // WEBCLIENT_H
