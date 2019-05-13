#include "serialthread.h"
#include "serialoptionsdialog.h"
#include <qserialport.h>
#include <qdebug.h>

SerialThread::SerialThread(QObject *parent) :
    QThread(parent)
{
}

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
            //decode data and send into function
            prepareData( QString::fromLocal8Bit(data) );
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

void SerialThread::prepareData(const QString &response)
{
    using namespace std;
    //prefer std string :)
    string text = response.toStdString();
    //CRC number is 3 chars after "CRC"
    size_t crcPosition = text.find("CRC") + 3;
    uint8_t crc = stoi( text.substr(crcPosition) );

    //Removing CRC and \r\n for calculations
    size_t dataEndPosition = text.find_last_of(' ');
    text = text.substr(0, dataEndPosition);

    //Cast values
    size_t hPosition = text.find('H') + 1;
    uint8_t H = stoi( text.substr(hPosition) );
    size_t vPosition = text.find('V') + 1;
    uint8_t V = stoi( text.substr(vPosition) );
    size_t iPosition = text.find('I') + 1;
    uint8_t I = stoi( text.substr(iPosition) );
    size_t pPosition = text.find('P') + 1;
    uint8_t P = stoi( text.substr(pPosition) );

    //Calculating here because in if sometimes is problem
    uint8_t crcCalculated = CRC8(text.c_str(), text.length());
    if(crc == crcCalculated)
        qDebug() << "Data " << "H" << H << "V" << V
                 << "I" << I << "P" << P
                 << "Checksum correct:" << crc << endl;
    else
        qDebug() << "Checksum error" << endl;
}
