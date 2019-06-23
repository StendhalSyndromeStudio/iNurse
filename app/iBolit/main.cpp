#include "mainwindow.h"
#include <QApplication>
#include <QFile>

#include "assistent/assistant.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*
    QFile file(":/res/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);
    */
    w.show();

    Assistent::inst();

    return a.exec();
}
