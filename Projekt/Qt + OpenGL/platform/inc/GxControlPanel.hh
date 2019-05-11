#ifndef GXCONTROLPANEL_HH
#define GXCONTROLPANEL_HH

#include "ui_DxControlPanel.h"
#include <QWidget>
#include "Manipulator.hh"


class GxControlPanel: public QWidget, public Ui::DxControlPanel {
   Q_OBJECT
   QWidget  *_pViewerWidget;
  public:
   GxControlPanel(QWidget *pParent = nullptr);

   void SetViewerWidget(QWidget *pViewer) { _pViewerWidget = pViewer; }

  public slots:
   void on__pSliderQ2_valueChanged(int);
   void on__pSliderQ0_valueChanged(int);
};



#endif
