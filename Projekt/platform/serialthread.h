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

    void startSerial(QWidget *pV, QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower);
    void stopSerial();

signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;
    void replotLightWidget(QCustomPlot *pwidgetLight, double key);
    void replotPowerWidget(QCustomPlot *pwidgetPower, double key);
    void replotVoltageWidget(QCustomPlot *pwidgetVoltage, double key);
    void replotCurrentWidget(QCustomPlot *pwidgetCurrent, double key);
    void replot(QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower);

    QSerialPort serial;

    QWidget *pViever;
    QCustomPlot *pwidgetLight;
    QCustomPlot *pwidgetVoltage;
    QCustomPlot *pwidgetCurrent;
    QCustomPlot *pwidgetPower;

    bool flag = false;
};

#endif // SERIALTHREAD_H
