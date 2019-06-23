#ifndef TABWIDGETDRAGDROP_H
#define TABWIDGETDRAGDROP_H

#include <QObject>
#include <QTabWidget>

class TabWidgetDragDrop: public QTabWidget
{
    Q_OBJECT
public:
    explicit TabWidgetDragDrop(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);

signals:
    void CreateRtf(QString name);
};

#endif // TABWIDGETDRAGDROP_H
