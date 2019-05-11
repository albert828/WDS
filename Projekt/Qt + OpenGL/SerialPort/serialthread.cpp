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
    //if(QThread::currentThread()->isRunning())
        //QThread::currentThread()->exit();
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
            //decode data
            QString response = QString::fromLocal8Bit(data);
            //prefer std methods so std string
            std::string text = response.toStdString();
            //CRC number is 3 chars after "CRC"
            std::size_t crcPosition = text.find("CRC") + 3;
            std::string crcString = text.substr(crcPosition);
            uint8_t crc = std::stoi(crcString);
            //Removing CRC and \r\n
            std::size_t dataEndPosition = text.find_last_of(' ');
            text = text.substr(0, dataEndPosition);
            //Calculating here because in if sometimes is problem
            uint8_t crcCalculated = CRC8(text.c_str(), text.length());
            if(crc == crcCalculated)
                qDebug() << "Data " << QString::fromStdString(text) << "Checksum correct:" << crc << endl;
            else
                qDebug() << "Checksum error" << endl;
        }
        else
            qDebug() << "Timeout";
    }
}

char SerialThread::CRC8(const char *data,int len)
{
   char crc = 0x00;
   char extract;
   char sum;
   for(int i=0;i<len;i++)
   {
      extract = *data;
      for (char tempI = 8; tempI; tempI--)
      {
         sum = (crc ^ extract) & 0x01;
         crc >>= 1;
         if (sum)
            crc ^= 0x8C;
         extract >>= 1;
      }
      data++;
   }
   return crc;
}
