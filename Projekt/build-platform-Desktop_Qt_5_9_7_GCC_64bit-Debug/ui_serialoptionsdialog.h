/********************************************************************************
** Form generated from reading UI file 'serialoptionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALOPTIONSDIALOG_H
#define UI_SERIALOPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialOptionsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *Port;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *BaudRate;
    QPushButton *pushButton;

    void setupUi(QDialog *SerialOptionsDialog)
    {
        if (SerialOptionsDialog->objectName().isEmpty())
            SerialOptionsDialog->setObjectName(QStringLiteral("SerialOptionsDialog"));
        SerialOptionsDialog->resize(227, 174);
        verticalLayout_2 = new QVBoxLayout(SerialOptionsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(SerialOptionsDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter->addWidget(label_3);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Port = new QComboBox(layoutWidget);
        Port->setObjectName(QStringLiteral("Port"));

        horizontalLayout->addWidget(Port);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        BaudRate = new QComboBox(layoutWidget);
        BaudRate->setObjectName(QStringLiteral("BaudRate"));

        horizontalLayout_2->addWidget(BaudRate);


        verticalLayout->addLayout(horizontalLayout_2);

        splitter->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter);

        pushButton = new QPushButton(SerialOptionsDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(SerialOptionsDialog);

        QMetaObject::connectSlotsByName(SerialOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *SerialOptionsDialog)
    {
        SerialOptionsDialog->setWindowTitle(QApplication::translate("SerialOptionsDialog", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("SerialOptionsDialog", "Set options:", Q_NULLPTR));
        label->setText(QApplication::translate("SerialOptionsDialog", "Port", Q_NULLPTR));
        label_2->setText(QApplication::translate("SerialOptionsDialog", "Baud rate", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SerialOptionsDialog", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialOptionsDialog: public Ui_SerialOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALOPTIONSDIALOG_H
