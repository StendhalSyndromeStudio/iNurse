#include "tabwidgetdragdrop.h"
#include "QDragEnterEvent"
#include "QMimeData"
#include "QDebug"
#include "QFileInfo"

TabWidgetDragDrop::TabWidgetDragDrop(QWidget *parent):QTabWidget (parent)
{
     setAcceptDrops(true);
}

void TabWidgetDragDrop::mousePressEvent(QMouseEvent *event){

}

void TabWidgetDragDrop::mouseMoveEvent(QMouseEvent *event){

}

void TabWidgetDragDrop::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasUrls()){
        QList<QUrl> urlList = event->mimeData()->urls();
                QString text;
                for (int i = 0; i < urlList.size() && i < 32; ++i)
                    text += urlList.at(i).path() + QLatin1Char('\n');
                QString r = text.mid(text.indexOf('.')+1,text.length()-text.indexOf('.')-2);
                if (r=="rtf"){
                    setBackgroundRole(QPalette::Dark);
                    event->acceptProposedAction();
                }
    }
}

void TabWidgetDragDrop::dropEvent(QDropEvent *event){
    if (event->mimeData()->hasUrls()){
        QList<QUrl> urlList = event->mimeData()->urls();
                QString text;
                for (int i = 0; i < urlList.size() && i < 32; ++i)
                    text += urlList.at(i).path() + QLatin1Char('\n');
                QString r = text.mid(text.indexOf('.')+1,text.length()-text.indexOf('.')-2);
                if (r=="rtf"){//наш файл отошлем имя файла (чистое без пути)
                    QFileInfo f(text);
                    QString val = f.fileName().mid(0, f.fileName().length()-1);
                    emit CreateRtf(val);
                }
                qDebug() << text;
    }
}
