#include "serialthread.h"
#include "serialoptionsdialog.h"
#include <qserialport.h>
#include <qdebug.h>
#include "Manipulator.hh"
#include <cassert>
#include "mainwindow.h"
#include "globals.h"

/**
 * @brief mapf function is used to change the range of vertical rotation values
 * @param[in] x : maped value
 * @param[in] in_min : minimum value of the input variable
 * @param[in] in_max : maximum value of the input variable
 * @param[in] out_min : minimum value of the output variable
 * @param[in] out_max : maximum value of the output variable
 * @return Mapped value between out_min and out_max values 
 */
int mapf(int x, int in_min, int in_max, int out_min, int out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

SerialThread::SerialThread(QObject *parent) :
    QThread(parent), pViever(nullptr),  pwidgetLight(nullptr), pwidgetVoltage(nullptr), pwidgetCurrent(nullptr), pwidgetPower(nullptr)
{
}

//! [0]
SerialThread::~SerialThread()
{
    if(serial.isOpen())
        serial.close();
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
    serial.setBaudRate(static_cast<qint32>(BaudRate));
    serial.setParity(QSerialPort::EvenParity);
    serial.setDataBits(QSerialPort::Data8);
    serial.setStopBits(QSerialPort::OneStop);

    if (!serial.open(QIODevice::ReadOnly))
        qDebug("Can't open serial");
    else {
        serial.readAll();
    }
    int counter = 0;

    while(serial.isOpen())
    {
        QByteArray data;
        if (serial.waitForReadyRead(200))
        {
            data = serial.readLine();
            //while (serial.waitForReadyRead(1))
            //{
                //data += serial.readAll();
            //}
            //decode data and send into function
            if( prepareData( QString::fromLocal8Bit(data), counter ) )
            {
                Manip.SetQ2_deg(V);
                Manip.SetQ0_deg(H);
                pViever->update();
                replot(pwidgetLight, pwidgetVoltage, pwidgetCurrent, pwidgetPower);
            }
            if (counter > 10)
            {
                serial.readAll();
                qDebug() << "Cleaning buffer" << endl;
                counter = 0;
            }
        }
        else
            qDebug() << "Timeout";
    }
}

bool SerialThread::prepareData(const QString &response, int &counter)
{
    using namespace std;
    //prefer std string :)
    qDebug() << "Received data: "<< response << " ";
    string text = response.toStdString();
    //CRC number is 3 chars after "CRC"
    size_t crcPosition = text.find("CRC") + 3;
    uint8_t crc = 0;
    try
    {
        if(crcPosition != string::npos)
            crc = stoi( text.substr(crcPosition) );
        else
        {
            qDebug() << "Error crc stoi" << endl;
            counter++;
            return false;
        }

        //Removing CRC and \n for calculations
        size_t dataEndPosition = text.find_last_of(' ');
        if(dataEndPosition != string::npos)
            text = text.substr(0, dataEndPosition);
        else
        {
            qDebug() << "Error data end position" << endl;
            counter++;
            return false;
        }
        //qDebug() << QString::fromStdString(text )<< endl;
    }
    catch(std::out_of_range)
    {
        qDebug() << "Catched out of range" << endl;
        counter++;
        return false;
    }
    catch(std::invalid_argument)
    {
        qDebug() << "Catched invalid arg in CRC" << endl;
        counter++;
        return false;
    }

    //Cast values
    try
    {
        size_t hPosition, vPosition, lPosition, uPosition, iPosition, pPosition;
        hPosition = text.find('H') + 1;
        if(hPosition != string::npos)
            H = stoi( text.substr(hPosition) );
        else
        {
            qDebug() << "Error hPosition" << endl;
            counter++;
            return false;
        }

        vPosition = text.find('V') + 1;
        if(vPosition != string::npos)
        {
            V = (stoi( text.substr(vPosition) ) );
            V = mapf(V, 0, 180, -60, 60);
        }
        else
        {
            qDebug() << "Error vPosition" << endl;
            counter++;
            return false;
        }

        lPosition = text.find('L') + 1;
        if(lPosition != string::npos)
            L = stoi( text.substr(vPosition) );
        else
        {
            qDebug() << "Error lPosition" << endl;
            counter++;
            return false;
        }

        uPosition = text.find('U') + 1;
        if(uPosition != string::npos)
            U = stoi( text.substr(uPosition) );
        else
        {
            qDebug() << "Error uPosition" << endl;
            counter++;
            return false;
        }

        iPosition = text.find('I') + 1;
        if(iPosition != string::npos)
            I = stoi( text.substr(iPosition) );
        else
        {
            qDebug() << "Error iPosition" << endl;
            counter++;
            return false;
        }

        pPosition = text.find('P') + 1;
        if(pPosition != string::npos)
            P = stoi( text.substr(pPosition) );
        else
        {
            qDebug() << "Error pPosition" << endl;
            counter++;
            return false;
        }

        //Calculating here because in if sometimes is problem
        uint8_t crcCalculated = CRC8(text.c_str(), text.length());
        if(crc == crcCalculated)
            qDebug() << "Splited data: "<< "H" << H << "V" << V
                     << "L" << L << "U" << U << "I" << I << "P" << P
                     << "Checksum correct:" << hex << crc << endl;
        else
        {
            qDebug() << "Checksum error" << endl;
            counter++;
            return false;
        }
    }
    catch(std::invalid_argument)
    {
        qDebug() << "Invalid value from serial to casting by stoi" << endl;
        counter++;
        return false;
    }
    catch(std::out_of_range)
    {
        qDebug() << "Catched out of range" << endl;
        counter++;
        return false;
    }
    counter = 0;
    return true;
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