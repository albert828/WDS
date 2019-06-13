#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QWaitCondition>
#include <qserialport.h>
#include "qcustomplot.h"

/**
 * @brief The SerialThread class. Used to create serial comunnication object in separated thread.
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
     * @param[in] pV : pointer to OpenGL viewer widget
     * @param[in] pwidgetLight : pointer to Light chart widget
     * @param[in] pwidgetVoltage : pointer to Voltage chart widget
     * @param[in] pwidgetCurrent : pointer to Current chart widget
     * @param[in] pwidgetPower : pointer to Power chart widget
     */
    void startSerial(QWidget *pV, QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower);
    /**
     * @brief Closes serial communication
     */
    void stopSerial();

//signals:
    //void request(const QString &s);
    //void error(const QString &s);
    //void timeout(const QString &s);

private:
    /**
     * @brief Runs serial comunication thread. It's overrided from Qthread class.
              Reads data from serial port and calls preapareData() method. If decoding
              was succesful, it changes values of the rotation angles, updates OpenGl and 
              updates plots widgets. If comunication goes wrong 10 times it clears serial port buffer. 
     */
    void run() override;
    /**
     * @brief Updates Light Widget
     * @param[in] pwidgetLight : pointer to Light widget
     * @param[in] key : x axis time value
     */
    void replotLightWidget(QCustomPlot *pwidgetLight, double key);
    /**
     * @brief Updates Power Widget
     * @param[in] pwidgetPower : pointer to Power widget
     * @param[in] key : x axis time value
     */
    void replotPowerWidget(QCustomPlot *pwidgetPower, double key);
    /**
     * @brief Updates Voltage Widget
     * @param[in] pwidgetVoltage : pointer to Voltage widget
     * @param[in] key : x axis time value
     */
    void replotVoltageWidget(QCustomPlot *pwidgetVoltage, double key);
    /**
     * @brief Updates Current Widget
     * @param[in] pwidgetCurrent : pointer to Current widget
     * @param[in] key : x axis time value
     */
    void replotCurrentWidget(QCustomPlot *pwidgetCurrent, double key);
    /**
     * @brief Calls all replot methods
     * @param[in] pwidgetLight : pointer to Light widget
     * @param[in] pwidgetVoltage : pointer to Voltage widget
     * @param[in] pwidgetCurrent : pointer to Current widget
     * @param[in] pwidgetPower : pointer to Power widget
     */
    void replot(QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower);
    /**
     * @brief CRC8 - function for calculating CRC8 checksum
    *  @param[in] data : pointer to c string for which the checksum will be counted 
    * @param[in] len : length of the c string
     * @return value of the checksum
     */
    char CRC8(const char *data, int len);
    /**
     * @brief prepareData : function is used for decoding data from serial port and split it into 
            variables
     * @param response[in] : data to prepare from serial port
     * @param counter[in] : numer of errors
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
};

#endif // SERIALTHREAD_H
