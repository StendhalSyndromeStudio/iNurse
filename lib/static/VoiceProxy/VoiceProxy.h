#pragma once

#include <QMap>
#include <QObject>
#include <QJsonObject>
#include <QUrl>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

struct VoiceProxyClient {
    QWebSocket * voiceSource = nullptr;
    QWebSocket * recognizeHandler = nullptr;
    bool activeRecognition = false;
};

/**
 * @brief The VoiceClient class. Wait for websockets connection, and use it as audio sources. For each audio source, create connection to voice recognition server and proxy its audio streams there.
 */
class VoiceProxy : public QObject
{
    Q_OBJECT
public:
    explicit VoiceProxy(quint16 port, QUrl recognitionService, bool startRecognition = false, bool debug=false, QObject *parent = nullptr);
    ~VoiceProxy();

public slots:
    void setRecognitionActive(bool value);
    bool isRecognitionActive();
    bool isVoiceSourceAvailable();
    bool isRecognitionServiceAvailable();

signals:
    void recognized(QJsonObject result);
    void recognitionActiveChanged(bool prevValue, bool currValue);
    void voiceSourceAvailabilityChanged(bool prevValue, bool currValue);
    void recognitionServiceAvailabilityChanged(bool prevValue, bool currValue);

private slots:
    void onVoiceSourceConnected();
    void processTextMessage(QString message);
    //void processBinaryMessage(QByteArray message);
    void onVoiceSourceDisconnected();

    void onRecognizeHandlerTextMessageReceived(QString message);
    void onRecognizeHandlerConnected();
    void onRecognizeHandlerDisconnected();
    void onRecognizeHandlerBinaryMessageReceived(QByteArray message);
    void initRecognizeHandler();
private:
    bool m_debug;
    QWebSocketServer *m_pWebSocketServer;
    VoiceProxyClient m_client;
    QUrl m_recognitionService;
};

