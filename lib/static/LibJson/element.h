#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QVariant>

class Element
{

public:
    enum class InputType{
        line_edit,
        combo_box,
    };


    enum class ValueType{
        number,
        string,
        boolean,
    };

    Element();


public:
    QString id;

    QString caption;

    InputType input;

    ValueType data_type;

    int min;

    int max;

    QStringList values;

    QVariant value;

};

#endif // ELEMENT_H
