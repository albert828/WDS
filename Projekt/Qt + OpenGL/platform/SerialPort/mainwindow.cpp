#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <serialoptionsdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SerialOptionsDialog serialDialog;
    serialDialog.setModal(true);
    serialDialog.exec();

    //ui->label->setText(PortName+" "+QString::number(BaudRate));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSerial_options_triggered()
{
    SerialOptionsDialog serialDialog;
    serialDialog.setModal(true);
    serialDialog.exec();
    //ui->label->setText(PortName+" "+QString::number(BaudRate));
}


void MainWindow::StartSerial()
{
    ui->actionConnect->setEnabled(false);
    ui->actionSerial_options->setEnabled(false);
    serial.startSerial();
}
void MainWindow::on_actionConnect_triggered()
{
    StartSerial();
}

void MainWindow::on_actionDisconnect_triggered()
{
    ui->actionConnect->setEnabled(true);
    ui->actionSerial_options->setEnabled(true);
    serial.stopSerial();
}
