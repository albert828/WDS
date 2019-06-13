#include "serialoptionsdialog.h"
#include "ui_serialoptionsdialog.h"
#include <QSerialPortInfo>
#include <serialoptionsdialog.h>
#include "serialthread.h"

/**
 * @brief Contains serial port name
 * 
 */
QString PortName{};
uint32_t BaudRate{};

SerialOptionsDialog::SerialOptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialOptionsDialog)
{
    ui->setupUi(this);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->Port->addItem(info.portName());
    constexpr uint32_t tBauds[] = {9600, 115200, 500000, 1000000, 2000000};
    for(auto i : tBauds)
        ui->BaudRate->addItem(QString::number(i));
}

SerialOptionsDialog::~SerialOptionsDialog()
{
    delete ui;
}

void SerialOptionsDialog::on_pushButton_clicked()
{
    PortName = ui->Port->currentText();
    BaudRate = (ui->BaudRate->currentText()).toInt();
    close();
}
