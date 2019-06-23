#include "mainwebserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWebServer w;
    w.show();

    return a.exec();
}
