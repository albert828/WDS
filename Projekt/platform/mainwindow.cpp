#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <serialoptionsdialog.h>

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

void MainWindow::StartSerial(QWidget *pViever)
{
    ui->actionConnect->setEnabled(false);
    ui->actionSerial->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);
    serial.startSerial(pViever);
}

void MainWindow::on_actionConnect_triggered()
{
    StartSerial(ui->_pWidget_Viewer);
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
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widgetLight->addGraph();
    ui->widgetLight->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widgetLight->plotLayout()->insertRow(0);
    ui->widgetLight->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widgetLight, "Light"));
    ui->widgetLight->xAxis->setLabel("Samples");
    ui->widgetLight->yAxis->setLabel("Lux");
    // set axes ranges, so we see all data:
    ui->widgetLight->xAxis->setRange(-1, 1);
    ui->widgetLight->yAxis->setRange(0, 2);
    ui->widgetLight->replot();
}

void MainWindow::makeCurrentPlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widgetCurrent->addGraph();
    ui->widgetCurrent->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widgetCurrent->plotLayout()->insertRow(0);
    ui->widgetCurrent->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widgetCurrent, "Current"));
    ui->widgetCurrent->xAxis->setLabel("Samples");
    ui->widgetCurrent->yAxis->setLabel("I [mA]");
    // set axes ranges, so we see all data:
    ui->widgetCurrent->xAxis->setRange(-1, 1);
    ui->widgetCurrent->yAxis->setRange(0, 2);
    ui->widgetCurrent->replot();
}

void MainWindow::makeVoltagePlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widgetVoltage->addGraph();
    ui->widgetVoltage->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widgetVoltage->plotLayout()->insertRow(0);
    ui->widgetVoltage->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widgetVoltage, "Voltage"));
    ui->widgetVoltage->xAxis->setLabel("Samples");
    ui->widgetVoltage->yAxis->setLabel("U [V]");
    // set axes ranges, so we see all data:
    ui->widgetVoltage->xAxis->setRange(-1, 1);
    ui->widgetVoltage->yAxis->setRange(0, 2);
    ui->widgetVoltage->replot();
}
void MainWindow::makePowerPlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widgetPower->addGraph();
    ui->widgetPower->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widgetPower->plotLayout()->insertRow(0);
    ui->widgetPower->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widgetPower, "Power"));
    ui->widgetPower->xAxis->setLabel("Samples");
    ui->widgetPower->yAxis->setLabel("P [W]");
    // set axes ranges, so we see all data:
    ui->widgetPower->xAxis->setRange(-1, 1);
    ui->widgetPower->yAxis->setRange(0, 2);
    ui->widgetPower->replot();
}

