#include <cassert>
#include "GxControlPanel.hh"
#include "Manipulator.hh"

GxControlPanel::GxControlPanel(QWidget *pParent): QWidget(pParent),
						  _pViewerWidget(nullptr)
{
  setupUi(this);
}


void GxControlPanel::on__pSliderQ2_valueChanged(int Val_deg)
{
  //Manip.SetQ2_deg(Val_deg);
  //assert(_pViewerWidget);
  //_pViewerWidget->update();
}


void GxControlPanel::on__pSliderQ0_valueChanged(int Val_deg)
{
  //Manip.SetQ0_deg(Val_deg);
  //assert(_pViewerWidget);
  //_pViewerWidget->update();
}
