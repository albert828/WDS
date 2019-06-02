#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <serialoptionsdialog.h>
#include <math.h>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionDisconnect->setEnabled(false);
    MainWindow::makeLightPlot();
    MainWindow::makeCurrentPlot();
    MainWindow::makePowerPlot();
    MainWindow::makeVoltagePlot();
    SerialOptionsDialog serialDialog;
    serialDialog.setModal(true);
    serialDialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartSerial(QWidget *pViever, QCustomPlot *pLight, QCustomPlot *pVoltage, QCustomPlot *pCurrent, QCustomPlot *pPower)
{

    ui->actionConnect->setEnabled(false);
    ui->actionSerial->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);
    serial.startSerial(pViever, pLight, pVoltage, pCurrent, pPower);
}

void MainWindow::on_actionConnect_triggered()
{
    StartSerial(ui->_pWidget_Viewer, ui->widgetLight, ui->widgetVoltage, ui->widgetCurrent, ui->widgetPower);
}

void MainWindow::on_actionDisconnect_triggered()
{
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionSerial->setEnabled(true);
    serial.stopSerial();
}

void MainWindow::on_actionSerial_triggered()
{
    SerialOptionsDialog serialDialog;
    serialDialog.setModal(true);
    serialDialog.exec();
}

void MainWindow::makeLightPlot()
{
    ui->widgetLight->addGraph(); // blue line
    ui->widgetLight->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->widgetLight->xAxis->setTicker(timeTicker);
    ui->widgetLight->axisRect()->setupFullAxesBox();
    ui->widgetLight->yAxis->setRange(0, 1.2);
    ui->widgetLight->yAxis->setLabel("L [Lux]");
    ui->widgetLight->xAxis->setLabel("Time [mm:ss]");
}

void MainWindow::makeCurrentPlot()
{
    ui->widgetCurrent->addGraph(); // blue line
    ui->widgetCurrent->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->widgetCurrent->xAxis->setTicker(timeTicker);
    ui->widgetCurrent->axisRect()->setupFullAxesBox();
    ui->widgetCurrent->yAxis->setRange(0, 1.2);
    ui->widgetCurrent->yAxis->setLabel("I [mA]");
    ui->widgetCurrent->xAxis->setLabel("Time [mm:ss]");
}

void MainWindow::makeVoltagePlot()
{
    ui->widgetVoltage->addGraph(); // blue line
    ui->widgetVoltage->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->widgetVoltage->xAxis->setTicker(timeTicker);
    ui->widgetVoltage->axisRect()->setupFullAxesBox();
    ui->widgetVoltage->yAxis->setRange(0, 1.2);
    ui->widgetVoltage->yAxis->setLabel("U [V]");
    ui->widgetVoltage->xAxis->setLabel("Time [mm:ss]");
}

void MainWindow::makePowerPlot()
{
    ui->widgetPower->addGraph(); // blue line
    ui->widgetPower->graph(0)->setPen(QPen(QColor(40, 110, 255)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->widgetPower->xAxis->setTicker(timeTicker);
    ui->widgetPower->axisRect()->setupFullAxesBox();
    ui->widgetPower->yAxis->setRange(0, 1.2);
    ui->widgetPower->yAxis->setLabel("P [mW]");
    ui->widgetPower->xAxis->setLabel("Time [mm:ss]");
}

