#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)


class WebServer : public QObject
{
    Q_OBJECT
public:
    explicit WebServer(quint16 port, QObject *parent = nullptr);

     ~WebServer();

signals:
    void closed();

public slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer* m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
};

#endif // WEBSERVER_H
