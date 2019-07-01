#include <QApplication>
#include "Viewer.hh"
#include "mainwindow.h"

int main(int argc, char** argv)
{
  QApplication application(argc,argv);
  MainWindow  w;

  w.show();

  return application.exec();
}
