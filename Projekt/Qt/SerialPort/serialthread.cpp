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

}

void SerialThread::startSerial()
{
    if (!isRunning())
        start();
}

void SerialThread::run()
{
    QSerialPort serial;
    serial.setPortName(PortName);
    serial.setBaudRate(BaudRate);
    if (!serial.open(QIODevice::ReadOnly))
        emit error(tr("Can't open serial"));
    //qDebug("Test");
    serial.close();
}
