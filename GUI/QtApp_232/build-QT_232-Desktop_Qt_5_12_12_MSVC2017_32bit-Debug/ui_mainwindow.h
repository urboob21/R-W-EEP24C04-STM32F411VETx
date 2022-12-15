/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_tdata;
    QPushButton *pushButton_send;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_pos;
    QPushButton *pushButton_stt;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_vel;
    QPushButton *pushButton_mov;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_led1;
    QCheckBox *checkBox_gpio1;
    QRadioButton *radioButton_tim;
    QRadioButton *radioButton_pol;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_rdata;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *comboBox_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *comboBox_baudrate;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QComboBox *comboBox_datasize;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QComboBox *comboBox_parity;
    QPushButton *pushButton_connect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 442);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_tdata = new QLineEdit(groupBox_3);
        lineEdit_tdata->setObjectName(QString::fromUtf8("lineEdit_tdata"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_tdata->sizePolicy().hasHeightForWidth());
        lineEdit_tdata->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_tdata);

        pushButton_send = new QPushButton(groupBox_3);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_send->sizePolicy().hasHeightForWidth());
        pushButton_send->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(pushButton_send);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit_2);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(pushButton_6);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_5);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_pos = new QPushButton(groupBox_4);
        pushButton_pos->setObjectName(QString::fromUtf8("pushButton_pos"));
        sizePolicy2.setHeightForWidth(pushButton_pos->sizePolicy().hasHeightForWidth());
        pushButton_pos->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pushButton_pos);

        pushButton_stt = new QPushButton(groupBox_4);
        pushButton_stt->setObjectName(QString::fromUtf8("pushButton_stt"));
        sizePolicy2.setHeightForWidth(pushButton_stt->sizePolicy().hasHeightForWidth());
        pushButton_stt->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pushButton_stt);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_vel = new QPushButton(groupBox_4);
        pushButton_vel->setObjectName(QString::fromUtf8("pushButton_vel"));
        sizePolicy2.setHeightForWidth(pushButton_vel->sizePolicy().hasHeightForWidth());
        pushButton_vel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(pushButton_vel);

        pushButton_mov = new QPushButton(groupBox_4);
        pushButton_mov->setObjectName(QString::fromUtf8("pushButton_mov"));
        sizePolicy2.setHeightForWidth(pushButton_mov->sizePolicy().hasHeightForWidth());
        pushButton_mov->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(pushButton_mov);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBox_led1 = new QCheckBox(groupBox_5);
        checkBox_led1->setObjectName(QString::fromUtf8("checkBox_led1"));
        sizePolicy2.setHeightForWidth(checkBox_led1->sizePolicy().hasHeightForWidth());
        checkBox_led1->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(checkBox_led1);

        checkBox_gpio1 = new QCheckBox(groupBox_5);
        checkBox_gpio1->setObjectName(QString::fromUtf8("checkBox_gpio1"));
        sizePolicy2.setHeightForWidth(checkBox_gpio1->sizePolicy().hasHeightForWidth());
        checkBox_gpio1->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(checkBox_gpio1);

        radioButton_tim = new QRadioButton(groupBox_5);
        radioButton_tim->setObjectName(QString::fromUtf8("radioButton_tim"));
        sizePolicy2.setHeightForWidth(radioButton_tim->sizePolicy().hasHeightForWidth());
        radioButton_tim->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(radioButton_tim);

        radioButton_pol = new QRadioButton(groupBox_5);
        radioButton_pol->setObjectName(QString::fromUtf8("radioButton_pol"));
        sizePolicy2.setHeightForWidth(radioButton_pol->sizePolicy().hasHeightForWidth());
        radioButton_pol->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(radioButton_pol);


        gridLayout->addWidget(groupBox_5, 1, 2, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit_rdata = new QTextEdit(groupBox);
        textEdit_rdata->setObjectName(QString::fromUtf8("textEdit_rdata"));
        sizePolicy1.setHeightForWidth(textEdit_rdata->sizePolicy().hasHeightForWidth());
        textEdit_rdata->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(textEdit_rdata);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label);

        comboBox_name = new QComboBox(groupBox_2);
        comboBox_name->setObjectName(QString::fromUtf8("comboBox_name"));
        sizePolicy.setHeightForWidth(comboBox_name->sizePolicy().hasHeightForWidth());
        comboBox_name->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(comboBox_name);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_2);

        comboBox_baudrate = new QComboBox(groupBox_2);
        comboBox_baudrate->setObjectName(QString::fromUtf8("comboBox_baudrate"));
        sizePolicy.setHeightForWidth(comboBox_baudrate->sizePolicy().hasHeightForWidth());
        comboBox_baudrate->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(comboBox_baudrate);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_3);

        comboBox_datasize = new QComboBox(groupBox_2);
        comboBox_datasize->setObjectName(QString::fromUtf8("comboBox_datasize"));
        sizePolicy.setHeightForWidth(comboBox_datasize->sizePolicy().hasHeightForWidth());
        comboBox_datasize->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(comboBox_datasize);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(label_4);

        comboBox_parity = new QComboBox(groupBox_2);
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));
        sizePolicy.setHeightForWidth(comboBox_parity->sizePolicy().hasHeightForWidth());
        comboBox_parity->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBox_parity);


        verticalLayout_3->addLayout(horizontalLayout_9);

        pushButton_connect = new QPushButton(groupBox_2);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        sizePolicy2.setHeightForWidth(pushButton_connect->sizePolicy().hasHeightForWidth());
        pushButton_connect->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(pushButton_connect);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 815, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Send Data", nullptr));
        pushButton_send->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Static", nullptr));
        pushButton_pos->setText(QApplication::translate("MainWindow", "POS", nullptr));
        pushButton_stt->setText(QApplication::translate("MainWindow", "STT", nullptr));
        pushButton_vel->setText(QApplication::translate("MainWindow", "VEL", nullptr));
        pushButton_mov->setText(QApplication::translate("MainWindow", "MOV", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Static", nullptr));
        checkBox_led1->setText(QApplication::translate("MainWindow", "Led1", nullptr));
        checkBox_gpio1->setText(QApplication::translate("MainWindow", "GPIO1", nullptr));
        radioButton_tim->setText(QApplication::translate("MainWindow", "Timer", nullptr));
        radioButton_pol->setText(QApplication::translate("MainWindow", "Polling", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Received Data", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Serial", nullptr));
        label->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Baudrate", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "DataSize", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
