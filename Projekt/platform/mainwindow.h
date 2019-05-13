#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "serialthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void StartSerial(QWidget *pViever, QCustomPlot *pLight, QCustomPlot *pVoltage, QCustomPlot *pCurrent, QCustomPlot *pPower);

private slots:
    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();
    void on_actionSerial_triggered();
    void makeLightPlot();
    void makeCurrentPlot();
    void makeVoltagePlot();
    void makePowerPlot();

private:
    Ui::MainWindow *ui;
    SerialThread serial;
};

#endif // MAINWINDOW_H
