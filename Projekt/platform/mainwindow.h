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
    /**
     * @brief StartSerial Runs serial comunication
     * @param pViever : pointer to OpenGL viewer widget
     * @param pLight : pointer to Light chart widget
     * @param pVoltage : pointer to Voltage chart widget
     * @param pCurrent : pointer to Current chart widget
     * @param pPower : pointer to Power chart widget
     */
    void StartSerial(QWidget *pViever, QCustomPlot *pLight, QCustomPlot *pVoltage, QCustomPlot *pCurrent, QCustomPlot *pPower);

private slots:
    /**
     * @brief Runs when Connect button clicked
     *
     * Runs serial comunication
     */
    void on_actionConnect_triggered();
    /**
     * @brief Runs when Doscconect button clicked
     *
     * Closes serial comunication
     */
    void on_actionDisconnect_triggered();
    /**
     * @brief Runs when serial options button clicked
     *
     * Opens serial options dialog
     */
    void on_actionSerial_triggered();
    /**
     * @brief Makes light plot
     */
    void makeLightPlot();
    /**
     * @brief Makes Current plot
     */
    void makeCurrentPlot();
    /**
     * @brief Makes Voltage plot
     */
    void makeVoltagePlot();
    /**
     * @brief Makes Power plot
     */
    void makePowerPlot();

private:
    Ui::MainWindow *ui;
    /**
     * @brief Serial communication object
     *
     * Enables running serial comunication thread in main window
     */
    SerialThread serial;
};

#endif // MAINWINDOW_H
