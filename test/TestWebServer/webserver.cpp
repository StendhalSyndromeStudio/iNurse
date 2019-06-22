#include "webserver.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

WebServer::WebServer(quint16 port, QObject *parent) : QObject(parent){
    m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Echo Server"),
                                                QWebSocketServer::NonSecureMode, this);
        if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
                qDebug() << "Echoserver listening on port" << port;
            connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                    this, &WebServer::onNewConnection);
            connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WebServer::closed);
        }
}

WebServer::~WebServer()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

void WebServer::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WebServer::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &WebServer::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &WebServer::socketDisconnected);
    m_clients << pSocket;
}

void WebServer::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Message received:" << message;
    if (pClient) {
        pClient->sendTextMessage(message);
    }
}

void WebServer::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void WebServer::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}


