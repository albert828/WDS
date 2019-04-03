#include "serialthread.h"
#include "serialoptionsdialog.h"
//#include <qserialport.h>
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
    //if(QThread::currentThread()->isRunning())
        //QThread::currentThread()->exit();
}

void SerialThread::run()
{
    //QSerialPort serial;
    serial.setPortName(PortName);
    serial.setBaudRate(BaudRate);
    if (!serial.open(QIODevice::ReadOnly))
        emit error(tr("Can't open serial"));
    qDebug("M from Thread");
    //serial.close();
    while(serial.isOpen())
    {
        QByteArray data;
        //while (serial.waitForReadyRead(600))
             //data += serial.readLine();
        //QByteArray data = serial.readLine();
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
