#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <QFont>
#include <QMap>
#include <QPoint>

class Print
{
public:
    enum class FontStyle{
        normal,
        italic,
        bold,
        underline
    };


    class Table {
    public:
        Table( QPoint size_dimension, QPoint size_cells)
            : size( size_dimension )
            , cells( size_cells )
        {

        }
        QPoint size;
        QPoint cells;

    };

    Print();


    void addLine( QString text, int size = 10, Qt::AlignmentFlag align = Qt::AlignmentFlag::AlignLeft, FontStyle style = FontStyle::normal );

    void addText(QString text, int size = 10, FontStyle style = FontStyle::normal , bool new_line = false);

    void createTable( QString id, QPoint size_dimension, QPoint size_cells );

    void setCellText( QPoint position,  QString text );

    void saveTable( QString id );

    void toPrint();

private:
    QStringList _html;


    QMap<int, QString> coll;
    QMap<int, QMap<int, QString>> cells2;
    QMap<QString, QMap<int, QMap<int, QString>>> _tables;

private:
    QString alignString( Qt::AlignmentFlag align );

    QString toStyle( QString text, FontStyle style );
};

#endif // PRINT_H
