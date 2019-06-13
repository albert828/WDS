/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(928, 652);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionSerial = new QAction(MainWindow);
        actionSerial->setObjectName(QStringLiteral("actionSerial"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(100, 100));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widgetLight = new QCustomPlot(widget);
        widgetLight->setObjectName(QStringLiteral("widgetLight"));

        gridLayout->addWidget(widgetLight, 0, 0, 1, 3);

        widgetCurrent = new QCustomPlot(widget);
        widgetCurrent->setObjectName(QStringLiteral("widgetCurrent"));

        gridLayout->addWidget(widgetCurrent, 3, 0, 1, 3);

        widgetPower = new QCustomPlot(widget);
        widgetPower->setObjectName(QStringLiteral("widgetPower"));

        gridLayout->addWidget(widgetPower, 1, 0, 1, 3);

        widgetVoltage = new QCustomPlot(widget);
        widgetVoltage->setObjectName(QStringLiteral("widgetVoltage"));

        gridLayout->addWidget(widgetVoltage, 2, 0, 1, 3);


        horizontalLayout->addWidget(widget);

        _pWidget_Viewer = new Viewer(centralWidget);
        _pWidget_Viewer->setObjectName(QStringLiteral("_pWidget_Viewer"));
        _pWidget_Viewer->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(_pWidget_Viewer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 928, 20));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        actionSerial->setText(QApplication::translate("MainWindow", "Serial", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
