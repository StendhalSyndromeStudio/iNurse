#include "json_builder_mw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  JsonBuilderMw w;
  w.show();

  return a.exec();
}
