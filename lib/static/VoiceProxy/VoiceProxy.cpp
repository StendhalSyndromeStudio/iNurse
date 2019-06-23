#include "VoiceProxy.h"

#include <QJsonDocument>
#include <QWebSocket>
#include <QWebSocketServer>


VoiceProxy::VoiceProxy(quint16 port, QUrl recognitionService, bool startRecognition, bool debug, QObject *parent) :
QObject(parent),
    m_debug(debug),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("VoiceProxy"),
                                            QWebSocketServer::NonSecureMode, this)),
     m_recognitionService(recognitionService) {
    m_client.activeRecognition = startRecognition;
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
            if (m_debug)
                qDebug() << "VoiceClient listening on port" << port;
            connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                    this, &VoiceProxy::onVoiceSourceConnected);
            //connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &VoiceProxy::closed);
    }
    initRecognizeHandler();
}

VoiceProxy::~VoiceProxy()
{
    if( m_pWebSocketServer ) m_pWebSocketServer->close();
    if( m_client.voiceSource ) m_client.voiceSource->deleteLater();
    if( m_client.recognizeHandler ) m_client.recognizeHandler->deleteLater();
}

void VoiceProxy::initRecognizeHandler() {
    if(m_client.recognizeHandler) m_client.recognizeHandler->deleteLater();
    m_client.recognizeHandler = nullptr;
    m_client.recognizeHandler = new QWebSocket();
    connect(m_client.recognizeHandler, &QWebSocket::connected, this, &VoiceProxy::onRecognizeHandlerConnected);
    connect(m_client.recognizeHandler, &QWebSocket::disconnected, this, &VoiceProxy::onRecognizeHandlerDisconnected);
    //m_client.recognizeHandler->open(QUrl("ws://127.0.0.1:6789"));
    m_client.recognizeHandler->open(m_recognitionService);
}

void VoiceProxy::onRecognizeHandlerConnected()
{
    if (m_debug){
        qDebug() << " RecognizeWebSocket connected";
    }
    connect(m_client.recognizeHandler, &QWebSocket::textMessageReceived,
            this, &VoiceProxy::onRecognizeHandlerTextMessageReceived);
    emit recognitionServiceAvailabilityChanged(false,true);
}

void VoiceProxy::onRecognizeHandlerDisconnected()
{
    if (m_debug){
        qDebug() << "Recognize WebSocket disconnected";
    }
    emit recognitionServiceAvailabilityChanged(true,false);
    initRecognizeHandler();
}

void VoiceProxy::onRecognizeHandlerTextMessageReceived(QString message)
{
    if (m_debug){
        qDebug() << "recognized text";
        qDebug() << message;
    }
    emit recognized(QJsonDocument::fromJson(message.toUtf8()).object());
}

void VoiceProxy::onRecognizeHandlerBinaryMessageReceived(QByteArray message)
{
    if (m_debug){
        qDebug() << "recognized binary";
        qDebug() << message;
    }
    emit recognized(QJsonDocument::fromJson(message).object());
}

void VoiceProxy::setRecognitionActive(bool value)
{
    auto prev = m_client.activeRecognition;
    m_client.activeRecognition = value;
    emit recognitionActiveChanged(prev,value);
}

bool VoiceProxy::isRecognitionActive()
{
    return m_client.activeRecognition;
}

bool VoiceProxy::isVoiceSourceAvailable()
{
    return !!m_client.voiceSource;
}

bool VoiceProxy::isRecognitionServiceAvailable()
{
    return !!m_client.recognizeHandler;
}

void VoiceProxy::onVoiceSourceConnected()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    
    connect(pSocket, &QWebSocket::textMessageReceived, this, &VoiceProxy::processTextMessage);
    //connect(pSocket, &QWebSocket::binaryMessageReceived, this, &VoiceProxy::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &VoiceProxy::onVoiceSourceDisconnected);
    auto prevSource = m_client.voiceSource;
    m_client.voiceSource = pSocket;
    if(prevSource){
        prevSource->deleteLater();
    } else {
        emit voiceSourceAvailabilityChanged(false,true);
    }
}

void VoiceProxy::processTextMessage(QString message)
{
    //QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "Message received:" << "message";
    if (m_client.recognizeHandler && m_client.activeRecognition) {
        m_client.recognizeHandler->sendTextMessage(message);
    }
}

//void VoiceProxy::processBinaryMessage(QByteArray message)
//{
//    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
//    if (m_debug)
//        qDebug() << "Binary Message received:" << message;
//    if (pClient) {
//        pClient->sendBinaryMessage(message);
//    }
//}

void VoiceProxy::onVoiceSourceDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "source socket disconnected:" << pClient;
    if (m_client.voiceSource && (m_client.voiceSource == pClient)) {
        m_client.voiceSource = nullptr;
        pClient->deleteLater();
        emit voiceSourceAvailabilityChanged(true,false);
    }
}
