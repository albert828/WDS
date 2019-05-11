#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialthread.h"
#include <qthread.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void StartSerial();

private slots:
    void on_actionSerial_options_triggered();

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

private:
    Ui::MainWindow *ui;
    SerialThread serial;
    //QThread *thread = nullptr;
};

#endif // MAINWINDOW_H
