/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_refreshTable;
    QPushButton *pushButton_condition;
    QPushButton *pushButton_spinlock;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_cancel;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton_priority;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_refreshTable = new QPushButton(centralwidget);
        pushButton_refreshTable->setObjectName("pushButton_refreshTable");
        pushButton_refreshTable->setGeometry(QRect(460, 20, 301, 71));
        QFont font;
        font.setPointSize(12);
        pushButton_refreshTable->setFont(font);
        pushButton_condition = new QPushButton(centralwidget);
        pushButton_condition->setObjectName("pushButton_condition");
        pushButton_condition->setGeometry(QRect(620, 170, 141, 71));
        pushButton_condition->setFont(font);
        pushButton_spinlock = new QPushButton(centralwidget);
        pushButton_spinlock->setObjectName("pushButton_spinlock");
        pushButton_spinlock->setGeometry(QRect(460, 170, 141, 71));
        pushButton_spinlock->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(520, 110, 241, 41));
        lineEdit->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 260, 141, 16));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 380, 111, 16));
        label_2->setFont(font);
        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(620, 460, 141, 71));
        pushButton_cancel->setFont(font);
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 20, 391, 511));
        tableWidget->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 110, 61, 41));
        label_3->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(460, 280, 301, 41));
        comboBox->setFont(font);
        pushButton_priority = new QPushButton(centralwidget);
        pushButton_priority->setObjectName("pushButton_priority");
        pushButton_priority->setGeometry(QRect(460, 460, 141, 71));
        pushButton_priority->setFont(font);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(530, 320, 161, 51));
        checkBox->setFont(font);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(460, 400, 301, 41));
        spinBox->setMinimum(1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_refreshTable->setText(QCoreApplication::translate("MainWindow", "Refresh table", nullptr));
        pushButton_condition->setText(QCoreApplication::translate("MainWindow", "Execute\n"
"Condition Vars", nullptr));
        pushButton_spinlock->setText(QCoreApplication::translate("MainWindow", "Execute\n"
"Spinlock", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Number of threads:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Priority to set:", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "To Find", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "16", nullptr));

        pushButton_priority->setText(QCoreApplication::translate("MainWindow", "Set priority", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Create Detached", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
