#ifndef LIBJSON_H
#define LIBJSON_H
#include <QObject>
#include <QJsonObject>
#include <QMap>
#include "element.h"

class LibJson
{

public:
    LibJson();

    ///
    /// \brief Загрузка фала
    /// \return
    ///
    bool LoadFile( QString path );


private:
    ///
    /// \brief Объект с данными
    ///
    QJsonObject _json;

    ///
    /// \brief Словарь идентификаторов
    ///
    QMap<QString, Element> mapElements;

private:
    ///
    /// \brief Чтение параметров объекта
    /// \param jObject
    ///
    void loadObject( QJsonObject &jObject );

    ///
    /// \brief Чтение содержимого массива
    /// \param jArray
    ///
    void loadArray( QJsonArray &jArray );

    ///
    /// \brief Чтение значения
    /// \param value
    ///
    void loadValue(QJsonValue &value );
};

#endif // LIBJSON_H
