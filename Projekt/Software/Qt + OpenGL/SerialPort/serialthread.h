#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

//#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <qserialport.h>

//! [0]
class SerialThread : public QThread
{
    Q_OBJECT

public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread();

    void startSerial();
    void stopSerial();

signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;
    QSerialPort serial;

    char CRC8(const char*,int);
    void prepareData(const QString &);
};

#endif // SERIALTHREAD_H
