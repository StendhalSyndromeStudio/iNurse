#include <QCoreApplication>
#include <QJsonDocument>
#include <QUrl>
#include <VoiceProxy.h>
#include <functional>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    VoiceProxy proxy(6790,QUrl("ws://127.0.0.1:6789"),true, false);

    QObject::connect(&proxy, &VoiceProxy::recognized, [](QJsonObject data){
        qDebug() << "from main";
        qDebug() << QString::fromUtf8(QJsonDocument(data).toJson());
    });

    return a.exec();
}
