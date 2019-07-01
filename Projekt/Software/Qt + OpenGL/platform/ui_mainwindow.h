/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>
#include "Viewer.hh"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionSerial;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QCustomPlot *widgetLight;
    QCustomPlot *widgetCurrent;
    QCustomPlot *widgetPower;
    QCustomPlot *widgetVoltage;
    Viewer *_pWidget_Viewer;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(928, 652);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionSerial = new QAction(MainWindow);
        actionSerial->setObjectName(QString::fromUtf8("actionSerial"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(100, 100));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetLight = new QCustomPlot(widget);
        widgetLight->setObjectName(QString::fromUtf8("widgetLight"));

        gridLayout->addWidget(widgetLight, 0, 0, 1, 3);

        widgetCurrent = new QCustomPlot(widget);
        widgetCurrent->setObjectName(QString::fromUtf8("widgetCurrent"));

        gridLayout->addWidget(widgetCurrent, 3, 0, 1, 3);

        widgetPower = new QCustomPlot(widget);
        widgetPower->setObjectName(QString::fromUtf8("widgetPower"));

        gridLayout->addWidget(widgetPower, 1, 0, 1, 3);

        widgetVoltage = new QCustomPlot(widget);
        widgetVoltage->setObjectName(QString::fromUtf8("widgetVoltage"));

        gridLayout->addWidget(widgetVoltage, 2, 0, 1, 3);


        horizontalLayout->addWidget(widget);

        _pWidget_Viewer = new Viewer(centralWidget);
        _pWidget_Viewer->setObjectName(QString::fromUtf8("_pWidget_Viewer"));
        _pWidget_Viewer->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(_pWidget_Viewer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 928, 20));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionSerial);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        actionSerial->setText(QApplication::translate("MainWindow", "Serial", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
