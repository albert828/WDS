#ifndef GXMAINWINDOW_HH
#define GXMAINWINDOW_HH

#include <QMainWindow>
#include "ui_DxMainWindow.h"


class GxMainWindow: public QMainWindow, public Ui::DxMainWindow {
    Q_OBJECT
  public:
    GxMainWindow(QWidget *pParent = nullptr);
};

#endif
