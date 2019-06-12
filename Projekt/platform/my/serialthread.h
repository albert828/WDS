#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

//#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <qserialport.h>
#include "qcustomplot.h"

/**
 * @brief The SerialThread class. Creates serial comunnication object in separated thread.
 */
class SerialThread : public QThread
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Serial Thread object
     * 
     * @param parent 
     */
    explicit SerialThread(QObject *parent = nullptr);
    /**
     * @brief Destroy the Serial Thread object. Closes serial port if was opened and 
     * quits thread
     * 
     */
    ~SerialThread() override;
    /**
     * @brief Runs serial comunication thread
     * @param pV : pointer to OpenGL viewer widget
     * @param pwidgetLight : pointer to Light chart widget
     * @param pwidgetVoltage : pointer to Voltage chart widget
     * @param pwidgetCurrent : pointer to Current chart widget
     * @param pwidgetPower : pointer to Power chart widget
     */
    void startSerial(QWidget *pV, QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower);
    /**
     * @brief Closes serial communication
     */
    void stopSerial();

signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    /**
     * @brief Runs serial comunication thread. It's overrided from Qthread class-------
     * ----------------------- dopisać co robi. 
     */
    void run() override;
    /**
     * @brief Updates Light Widget
     * @param pwidgetLight : pointer to Light widget
     * @param key : x axis time value
     */
    void replotLightWidget(QCustomPlot *pwidgetLight, double key);
    /**
     * @brief Updates Power Widget
     * @param pwidgetPower : pointer to Power widget
     * @param key : x axis time value
     */
    void replotPowerWidget(QCustomPlot *pwidgetPower, double key);
    /**
     * @brief Updates Voltage Widget
     * @param pwidgetVoltage : pointer to Voltage widget
     * @param key : x axis time value
     */
    void replotVoltageWidget(QCustomPlot *pwidgetVoltage, double key);
    /**
     * @brief Updates Current Widget
     * @param pwidgetCurrent : pointer to Current widget
     * @param key : x axis time value
     */
    void replotCurrentWidget(QCustomPlot *pwidgetCurrent, double key);
    /**
     * @brief Runs all replot methods
     * @param pwidgetLight : pointer to Light widget
     * @param pwidgetVoltage : pointer to Voltage widget
     * @param pwidgetCurrent : pointer to Current widget
     * @param pwidgetPower : pointer to Power widget
     */
    void replot(QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower);
    /**
     * @brief CRC8 - function for calculating CRC8 checksum
     * @return value of the checksum
     */
    char CRC8(const char*,int);
    /**
     * @brief prepareData function is used for decoding data from serial port
     * @param response data to prepare from serial port
     * @param counter numer of errors
     * @return true if decoding was succesful else returns false
     */
    bool prepareData(const QString &response, int &counter);
    /**
     * @brief serial cominnication object
     * 
     */
    QSerialPort serial;
    /**
     * @brief pViever - pointer to OpenGLwidget
     */
    QWidget *pViever;
    /**
     * @brief pwidgetLight - pointer to Light plot
     */
    QCustomPlot *pwidgetLight;
    /**
     * @brief pwidgetVoltage - pointer to Voltage plot
     */
    QCustomPlot *pwidgetVoltage;
    /**
     * @brief pwidgetCurrent - - pointer to Current plot
     */
    QCustomPlot *pwidgetCurrent;
    /**
     * @brief pwidgetPower - pointer to Power plot
     */
    QCustomPlot *pwidgetPower;

    bool flag = false;
};

#endif // SERIALTHREAD_H
