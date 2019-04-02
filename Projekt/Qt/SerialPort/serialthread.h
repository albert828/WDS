#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

//#include <QMutex>
#include <QThread>
#include <QWaitCondition>

//! [0]
class SerialThread : public QThread
{
    Q_OBJECT

public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread();

    void startSerial();

signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;

    //QMutex m_mutex;
    //bool m_quit = false;
};

#endif // SERIALTHREAD_H
