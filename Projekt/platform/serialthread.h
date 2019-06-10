#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

//#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <qserialport.h>
#include "qcustomplot.h"

//! [0]
class SerialThread : public QThread
{
    Q_OBJECT

public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread() override;
    /**
     * @brief Runs serial comunication
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
     * @brief Runs thread
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
     * @return checksum
     */
    char CRC8(const char*,int);
    /**
     * @brief prepareData - function for preaparing data from serial port
     */
    void prepareData(const QString &);

    QSerialPort serial;

    QWidget *pViever;
    QCustomPlot *pwidgetLight;
    QCustomPlot *pwidgetVoltage;
    QCustomPlot *pwidgetCurrent;
    QCustomPlot *pwidgetPower;

    bool flag = false;
};

#endif // SERIALTHREAD_H
