#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "serialthread.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief Main window class
 * 
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * @brief Constructor. It disables disconnect button. Creates plots and
        runs dialog with serial comunication options.
    * 
    */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructor
     * 
     */
    ~MainWindow();
    /**
     * @brief StartSerial : This method changes buttons activity and runs startSerial()
                metod on serial object.
     * @param[in] pViever : pointer to OpenGL viewer widget
     * @param[in] pLight : pointer to Light chart widget
     * @param[in] pVoltage : pointer to Voltage chart widget
     * @param[in] pCurrent : pointer to Current chart widget
     * @param[in] pPower : pointer to Power chart widget
     */
    void StartSerial(QWidget *pViever, QCustomPlot *pLight, QCustomPlot *pVoltage, QCustomPlot *pCurrent, QCustomPlot *pPower);

private slots:
    /**
     * @brief Runs when Connect button clicked. It calls StartSerial() method.
     */
    void on_actionConnect_triggered();
    /**
     * @brief Runs when Dosconnect button clicked. Used to close serial communication.
     Changes button activity and calls stopSerial() method on serial object.
     *
     */
    void on_actionDisconnect_triggered();
    /**
     * @brief Runs when serial options button clicked. Creates new dialog with 
     serial settings
     *
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
     * Enables running serial comunication thread in main windows
     */
    SerialThread serial;
};

#endif // MAINWINDOW_H
