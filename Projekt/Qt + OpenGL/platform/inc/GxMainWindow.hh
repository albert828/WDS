#ifndef GXMAINWINDOW_HH
#define GXMAINWINDOW_HH

#include <QMainWindow>
#include "ui_DxMainWindow.h"
#include "serialthread.h"
#include <qthread.h>


class GxMainWindow: public QMainWindow, public Ui::DxMainWindow {
    Q_OBJECT
  public:
    GxMainWindow(QWidget *pParent = nullptr);
    void StartSerial(QWidget *pViever);
  private:
    SerialThread serial;
private slots:
    void on_actionDisconnect_triggered();
    void on_actionSerial_options_triggered();
    void on_actionConnect_triggered();
};

#endif
