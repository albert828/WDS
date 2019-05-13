#include "GxMainWindow.hh"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <serialoptionsdialog.h>


GxMainWindow::GxMainWindow(QWidget *pParent): QMainWindow(pParent)
{
  setupUi(this);
  _pWidget_CtrPanel->SetViewerWidget(_pWidget_Viewer);
  SerialOptionsDialog serialDialog;
  serialDialog.setModal(true);
  serialDialog.exec();

}


void GxMainWindow::StartSerial(QWidget *pViever)
{
    actionConnect->setEnabled(false);
    actionSerial_options->setEnabled(false);
    serial.startSerial(pViever);
}

void GxMainWindow::on_actionDisconnect_triggered()
{
    actionConnect->setEnabled(true);
    actionSerial_options->setEnabled(true);
    serial.stopSerial();
}

void GxMainWindow::on_actionSerial_options_triggered()
{
    SerialOptionsDialog serialDialog;
    serialDialog.setModal(true);
    serialDialog.exec();
}

void GxMainWindow::on_actionConnect_triggered()
{
    StartSerial(_pWidget_Viewer);
}
