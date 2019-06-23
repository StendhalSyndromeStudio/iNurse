#include "webclient.h"
#include "QDebug"

WebClient::WebClient(QObject *parent) : QObject(parent)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &WebClient::Connect);
     connect(&m_webSocket, &QWebSocket::textMessageReceived,this, &WebClient::Received);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &WebClient::CloseSocket);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &WebClient::Disconnects);
    connect(&m_webSocket,&QWebSocket::close, this, &WebClient::Disconnects);
}

void WebClient::inicialize(const QUrl &url){
     m_url = url;
    m_webSocket.close();
     m_webSocket.open(QUrl(url));
}

void WebClient::Connect(){
    Log( "WebSocket connected");
}

void WebClient::Disconnects(){
    Log("соединение разорвано");
}

void  WebClient::Received(QString message){
    Log("ReceiveMessage: "+message);
    ReceiveMessage(message);
}

bool WebClient::SendCommandServer(QString value){
    if ((m_webSocket.state() == QAbstractSocket::SocketState::ConnectedState) || (m_webSocket.state() == QAbstractSocket::SocketState::ConnectingState)){
        m_webSocket.sendTextMessage(value);
        Log("SentMessage: "+value);
        return  true;
    }
    else{
        Log("сбой отправки");
        return  false;
    }
}

void WebClient::CloseSocket(){
     m_webSocket.close();
}
