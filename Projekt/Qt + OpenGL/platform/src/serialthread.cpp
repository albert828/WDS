#include "serialthread.h"
#include "serialoptionsdialog.h"
#include <qserialport.h>
#include <qdebug.h>
#include "constants.h"
#include "Manipulator.hh"
#include <cassert>
#include "GxControlPanel.hh"
#include "GxMainWindow.hh"

SerialThread::SerialThread(QObject *parent) :
    QThread(parent)
{
}

//! [0]
SerialThread::~SerialThread()
{
    if(serial.isOpen())
        serial.close();
    qDebug("Closing serial from destructor");
}

void SerialThread::startSerial(QWidget *pV)
{
    pViever = pV;
    if (!isRunning())
        start();
}

void SerialThread::stopSerial()
{
    if (serial.isOpen())
        serial.close();
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
    uint32_t counter{0};
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
}
