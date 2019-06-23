#ifndef MAINDOCTORS_H
#define MAINDOCTORS_H

#include <QMainWindow>
#include "tabwidgetdragdrop.h"

namespace Ui {
class MainDoctors;
}

class MainDoctors : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDoctors(QWidget *parent = nullptr);
    ~MainDoctors();

private:
    Ui::MainDoctors *ui;
    TabWidgetDragDrop* MainWidget;
    QList<QString> _listDocs;

    QList<QString> _listDocs;

public slots:
    void CreateRtf(QString value);
    void CloseTab(int index);
};

#endif // MAINDOCTORS_H
