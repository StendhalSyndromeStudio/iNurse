#include <QCoreApplication>
#include <QJsonDocument>
#include <QUrl>
#include <VoiceProxy.h>
#include <functional>
#include <QDebug>
#include <iostream>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif

    VoiceProxy proxy(6790,QUrl("ws://127.0.0.1:6789"),true, false);

    QObject::connect(&proxy, &VoiceProxy::recognized, [](QJsonObject data){
        qDebug() << "from main";
        std::cout << QString::fromUtf8(QJsonDocument(data).toJson()).toLocal8Bit().data();
    });

    return a.exec();
}
