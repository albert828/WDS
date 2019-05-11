#include "GxMainWindow.hh"
//#include <QSerialPortInfo>
//#include <QSerialPort>
#include <serialoptionsdialog.h>


GxMainWindow::GxMainWindow(QWidget *pParent): QMainWindow(pParent)
{
  setupUi(this);
  _pWidget_CtrPanel->SetViewerWidget(_pWidget_Viewer);
  SerialOptionsDialog serialDialog;
  serialDialog.setModal(true);
  serialDialog.exec();

}
