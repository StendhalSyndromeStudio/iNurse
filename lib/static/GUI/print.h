#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <QFont>

class Print
{
public:
    enum class FontStyle{
        normal,
        italic,
        bold,
        underline
    };

    Print();


    void addLine( QString text, int size = 10, Qt::AlignmentFlag align = Qt::AlignmentFlag::AlignLeft, FontStyle style = FontStyle::normal );

    void addText(QString text, int size = 10, FontStyle style = FontStyle::normal , bool new_line = false);

    void toPrint();

private:
    QStringList _html;

    QString alignString( Qt::AlignmentFlag align );

    QString toStyle( QString text, FontStyle style );
};

#endif // PRINT_H
