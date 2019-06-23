#include "print.h"
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QDebug>

Print::Print()
{

}


void Print::addLine(QString text, int size, Qt::AlignmentFlag align, FontStyle style)
{
    QString str = toStyle( text, style );
    _html.append( QString( "<div align=%1 >" ).arg( alignString( align ) ) );
    _html.append( QString( "<p style='font-size:%1px;'>%2</p>" ).arg( size ).arg( str ) );
    _html.append( QString( "</div>" ) );
}


void Print::addText(QString text, int size, FontStyle style, bool new_line)
{
    QString str = toStyle( text, style );
    if ( new_line ) {
        _html.append( "<br>" );
    }
    _html.append( QString( "<font style='font-size:%1px;'>%2</font>" ).arg( size ).arg( str ) );
}


void Print::createTable(QString id, QPoint size_dimension, QPoint size_cells)
{
    //_tables[ id ]
}


void Print::setCellText(QPoint position, QString text)
{

}


void Print::saveTable(QString id)
{

}


void Print::toPrint()
{
    QTextDocument document;
    qDebug() << _html.join( "" );
    document.setHtml( _html.join( "" ) );
    QPrinter printer( QPrinter::PrinterResolution );
    printer.setOutputFormat( QPrinter::PdfFormat );
    printer.setPaperSize ( QPrinter::A4 );
    printer.setOutputFileName( "test.pdf" );
    printer.setPageMargins( QMarginsF(15, 15, 15, 15) );
    document.print( &printer );
}


QString Print::alignString(Qt::AlignmentFlag align)
{
    QString result = "left";
    switch ( align ) {
    case Qt::AlignmentFlag::AlignLeft:
        result = "left";
        break;

    case Qt::AlignmentFlag::AlignCenter:
        result = "center";
        break;

    case Qt::AlignmentFlag::AlignRight:
        result = "right";
        break;
    }
    return result;
}


QString Print::toStyle(QString text, Print::FontStyle style)
{
    QString result = text;
    switch ( style ) {
    case FontStyle::normal:

        break;

    case FontStyle::italic:
        result = "<i>" + text + "</i>";
        break;

    case FontStyle::bold:
        result = "<b>" + text + "</b>";
        break;

    case FontStyle::underline:
        result = "<u>" + text + "</u>";
        break;
    }
    return result;
}
