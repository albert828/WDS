#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "serialthread.h"
=
namespace Ui {
class MainWindow;
}
/**
 * @brief Main Window Class
 * 
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Main Window object. It disables disconnect button. Creates plots and
        runs dialog with serial comunication options.
     * 
     * @param[in] parent 
     */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Main Window object
     * 
     */
    ~MainWindow();
    /**
     * @brief StartSerial Sets up Main Window widget. Disables
     * Connect and Options button and enables Disconnect button.
     * On the end calls startSerial() method for serial object.
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
     */
    void on_actionDisconnect_triggered();
    /**
     * @brief Runs when serial options button clicked. Creates new dialog with 
     serial settings
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
