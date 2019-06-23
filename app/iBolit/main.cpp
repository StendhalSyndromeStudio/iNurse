#include "mainwindow.h"
#include <QApplication>

#include "assistent/assistant.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Assistent::inst();

    return a.exec();
}
