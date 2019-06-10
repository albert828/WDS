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
    serial.setParity(QSerialPort::NoParity);
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
    uint8_t crc;
    if(crcPosition != string::npos)
        crc = stoi( text.substr(crcPosition) );
    else
        qDebug() << "Error crc stoi" << endl;

    //Removing CRC and \r\n for calculations
    size_t dataEndPosition = text.find_last_of(' ');
    if(dataEndPosition != string::npos)
        text = text.substr(0, dataEndPosition);
    else
        qDebug() << "Error data end position" << endl;
    //qDebug() << QString::fromStdString(text )<< endl;

    //Cast values
    size_t hPosition, vPosition, lPosition, uPosition, iPosition, pPosition;
    uint8_t H, V, L, U, I, P;
    try
    {
        hPosition = text.find('H') + 1;
        H = stoi( text.substr(hPosition) );

        vPosition = text.find('V') + 1;
        V = stoi( text.substr(vPosition) );

        lPosition = text.find('L') + 1;
        L = stoi( text.substr(vPosition) );

        uPosition = text.find('U') + 1;
        U = stoi( text.substr(uPosition) );

        iPosition = text.find('I') + 1;
        I = stoi( text.substr(iPosition) );

        pPosition = text.find('P') + 1;
        P = stoi( text.substr(pPosition) );

        //Calculating here because in if sometimes is problem
        uint8_t crcCalculated = CRC8(text.c_str(), text.length());
        if(crc == crcCalculated)
            qDebug() << "H" << H << "V" << V
                     << "U" << U << "L" << L << "I" << I << "P" << P
                     << "Checksum correct:" << hex << crc << endl;
        else
            qDebug() << "Checksum error" << endl;
    }
    catch(std::invalid_argument)
    {
        qDebug() << "Invalid value from serial to casting by stoi" << endl;
    }

}
