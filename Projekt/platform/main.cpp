#include <QApplication>
#include "Viewer.hh"
#include "mainwindow.h"

int main(int argc, char** argv)
{
  // Read command lines arguments.
  QApplication application(argc,argv);
  MainWindow  w;

  w.show();


  return application.exec();
}
