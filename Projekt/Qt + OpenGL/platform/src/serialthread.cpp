#include "serialthread.h"
#include "serialoptionsdialog.h"
#include <qserialport.h>
#include <qdebug.h>

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

void SerialThread::startSerial()
{
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
    while(serial.isOpen())
    {
        QByteArray data;

        if (serial.waitForReadyRead(1000))
        {
            data = serial.readLine();
            while (serial.waitForReadyRead(100))
            {
                data += serial.readAll();
            }
            qDebug() << "Data ready";
            QString response = QString::fromUtf8(data);
            qDebug() << "Data " << response << endl;
        }
        else
            qDebug() << "Timeout";
    }
}
