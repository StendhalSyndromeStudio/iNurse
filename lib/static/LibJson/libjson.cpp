#include "libjson.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

LibJson::LibJson()
{
}


bool LibJson::LoadFile(QString path)
{
    QFile file( path );
    //qDebug() << QString( "path [%1]" ).arg( path );
    if ( !file.exists() ) {
        qDebug() << QString( "Error. File not found [%1]" ).arg( path );
        return false;
    }

    if ( !file.open( QIODevice::ReadOnly ) ) {
        qDebug() << QString( "Error. File not open [%1]" ).arg( path );
        return false;
    }
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson( file.readAll(), &error );
    _json = doc.object();
    loadObject( _json );
    return true;
}


void LibJson::loadObject(QJsonObject &jObject)
{
    qDebug() << "is object";
    foreach (QJsonValue value, jObject) {
        loadValue( value );
    }
    /*
    for ( auto it = jObject.begin(); it != jObject.end(); ++it ) {
        QJsonValue value = it.value();
        loadValue( value );
    }
    */
}


void LibJson::loadArray(QJsonArray &jArray)
{
    qDebug() << "is array";
    for ( int i = 0; i < jArray.size(); ++i ) {
        QJsonValue value = jArray[i];
        loadValue( value );
    }
}


void LibJson::loadValue(QJsonValue &value)
{
    if ( value.isObject() ) {
        QJsonObject element = value.toObject();
        loadObject( element );
    } else {
        if ( value.isArray() ) {
            QJsonArray element = value.toArray();
            loadArray( element );
        } else {
            if ( value.isString() ) {
                qDebug() << QString( "[%1]=[%2]").arg( "string" ).arg( value.toString() );
            } else {
                if ( value.isBool() ) {
                    qDebug() << QString( "[%1]=[%2]").arg( "bool" ).arg( value.toBool() );
                } else {
                    qDebug() << QString( "[%1]=[%2]").arg( "int" ).arg( value.toInt() );
                }
            }
        }
    }
}
