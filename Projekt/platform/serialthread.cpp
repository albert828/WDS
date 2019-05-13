#include "serialthread.h"
#include "serialoptionsdialog.h"
#include <qserialport.h>
#include <qdebug.h>
#include "Manipulator.hh"
#include <cassert>
#include "mainwindow.h"
#include "globals.h"

#define SERIAL_WHILE 0

SerialThread::SerialThread(QObject *parent) :
    QThread(parent), pViever(nullptr), pwidgetCurrent(nullptr), pwidgetLight(nullptr),
    pwidgetPower(nullptr), pwidgetVoltage(nullptr)
{
}

//! [0]
SerialThread::~SerialThread()
{
    if(serial.isOpen())
        serial.close();
    flag = false;
    quit();
    qDebug("Closing serial from destructor");
}

void SerialThread::startSerial(QWidget *pV,  QCustomPlot *pwidgetL,  QCustomPlot *pwidgetV,
                               QCustomPlot *pwidgetC, QCustomPlot *pwidgetP)
{
    pViever = pV;
    pwidgetCurrent = pwidgetC;
    pwidgetLight = pwidgetL;
    pwidgetPower = pwidgetP;
    pwidgetVoltage = pwidgetV;
    if (!isRunning())
        start();
    flag = true;
}

void SerialThread::stopSerial()
{
    if (serial.isOpen())
        serial.close();
    flag = false;
    qDebug("Closing serial");
}

void SerialThread::run()
{
    //QSerialPort serial;
    serial.setPortName(PortName);
    serial.setBaudRate(BaudRate);
    serial.setParity(QSerialPort::EvenParity);
    serial.setDataBits(QSerialPort::Data8);
    serial.setStopBits(QSerialPort::OneStop);

    if (!serial.open(QIODevice::ReadOnly))
        emit error(tr("Can't open serial"));
    qDebug("M from Thread");
    //serial.close();
    //uint32_t counter{0};
#if SERIAL_WHILE == 1
    while(serial.isOpen())
    {
        ++H;
        --V;
        Manip.SetQ2_deg(H);
        assert(pViever);
        pViever->update();
        /*
        QByteArray data;
        if (serial.waitForReadyRead(1000))
        {
            data = serial.readLine();
            while (serial.waitForReadyRead(100))
            {
                data += serial.readAll();
            }
            qDebug() << counter++;
            QString response = QString::fromUtf8(data);
            qDebug() << response << endl;
        }
        else
            qDebug() << "Timeout";
            */
        sleep(1);
    }
#endif
    while(flag)
    {
        ++H;
        ++V;
        ++(L %= 100);
        ++(U %= 200);
        ++(I %= 300);
        P = I * U;
        Manip.SetQ2_deg(H);
        Manip.SetQ0_deg(V);
        assert(pViever);
        pViever->update();
        replot(pwidgetLight, pwidgetVoltage, pwidgetCurrent, pwidgetPower);
        msleep(50);
    }
}

void SerialThread::replot(QCustomPlot *pwidgetLight, QCustomPlot *pwidgetVoltage, QCustomPlot *pwidgetCurrent, QCustomPlot *pwidgetPower)
{
    static QTime time(QTime::currentTime());
    // calculate new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start in seconds

    replotLightWidget(pwidgetLight, key);
    replotPowerWidget(pwidgetPower, key);
    replotCurrentWidget(pwidgetCurrent, key);
    replotVoltageWidget(pwidgetVoltage, key);
}

void SerialThread::replotLightWidget(QCustomPlot *pwidgetLight, double key)
{
    // add data to lines:
    pwidgetLight->graph(0)->addData(key, L);
    // rescale value (vertical) axis to fit the current data:
    pwidgetLight->graph(0)->rescaleValueAxis(false);

    // make key axis range scroll with the data (at a constant range size of 8):
    pwidgetLight->xAxis->setRange(key, 8, Qt::AlignRight);
    pwidgetLight->replot();
}

void SerialThread::replotVoltageWidget(QCustomPlot *pwidgetVoltage, double key)
{
    // add data to lines:
    pwidgetVoltage->graph(0)->addData(key, U);
    // rescale value (vertical) axis to fit the current data:
    pwidgetVoltage->graph(0)->rescaleValueAxis(false);

    // make key axis range scroll with the data (at a constant range size of 8):
    pwidgetVoltage->xAxis->setRange(key, 8, Qt::AlignRight);
    pwidgetVoltage->replot();
}

void SerialThread::replotCurrentWidget(QCustomPlot *pwidgetCurrent, double key)
{
    // add data to lines:
    pwidgetCurrent->graph(0)->addData(key, I);
    // rescale value (vertical) axis to fit the current data:
    pwidgetCurrent->graph(0)->rescaleValueAxis(false);

    // make key axis range scroll with the data (at a constant range size of 8):
    pwidgetCurrent->xAxis->setRange(key, 8, Qt::AlignRight);
    pwidgetCurrent->replot();
}

void SerialThread::replotPowerWidget(QCustomPlot *pwidgetPower, double key)
{
    // add data to lines:
    pwidgetPower->graph(0)->addData(key, P);
    // rescale value (vertical) axis to fit the current data:
    pwidgetPower->graph(0)->rescaleValueAxis(false);

    // make key axis range scroll with the data (at a constant range size of 8):
    pwidgetPower->xAxis->setRange(key, 8, Qt::AlignRight);
    pwidgetPower->replot();
}
