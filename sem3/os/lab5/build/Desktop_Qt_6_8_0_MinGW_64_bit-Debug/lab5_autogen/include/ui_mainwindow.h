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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QPushButton *pushButton_criticalSection;
    QPushButton *pushButton_refreshTable;
    QPushButton *pushButton_terminate;
    QPushButton *pushButton_suspend;
    QPushButton *pushButton_resume;
    QPushButton *pushButton_priority;
    QPushButton *pushButton_mutex;
    QComboBox *comboBox_priority;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 30, 391, 511));
        QFont font;
        font.setPointSize(12);
        tableWidget->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(460, 270, 301, 41));
        comboBox->setFont(font);
        pushButton_criticalSection = new QPushButton(centralwidget);
        pushButton_criticalSection->setObjectName("pushButton_criticalSection");
        pushButton_criticalSection->setGeometry(QRect(460, 170, 141, 61));
        pushButton_criticalSection->setFont(font);
        pushButton_refreshTable = new QPushButton(centralwidget);
        pushButton_refreshTable->setObjectName("pushButton_refreshTable");
        pushButton_refreshTable->setGeometry(QRect(460, 30, 301, 61));
        pushButton_refreshTable->setFont(font);
        pushButton_terminate = new QPushButton(centralwidget);
        pushButton_terminate->setObjectName("pushButton_terminate");
        pushButton_terminate->setGeometry(QRect(620, 480, 141, 61));
        pushButton_terminate->setFont(font);
        pushButton_suspend = new QPushButton(centralwidget);
        pushButton_suspend->setObjectName("pushButton_suspend");
        pushButton_suspend->setGeometry(QRect(460, 330, 141, 61));
        pushButton_suspend->setFont(font);
        pushButton_resume = new QPushButton(centralwidget);
        pushButton_resume->setObjectName("pushButton_resume");
        pushButton_resume->setGeometry(QRect(620, 330, 141, 61));
        pushButton_resume->setFont(font);
        pushButton_priority = new QPushButton(centralwidget);
        pushButton_priority->setObjectName("pushButton_priority");
        pushButton_priority->setGeometry(QRect(460, 480, 141, 61));
        pushButton_priority->setFont(font);
        pushButton_mutex = new QPushButton(centralwidget);
        pushButton_mutex->setObjectName("pushButton_mutex");
        pushButton_mutex->setGeometry(QRect(620, 170, 141, 61));
        pushButton_mutex->setFont(font);
        comboBox_priority = new QComboBox(centralwidget);
        comboBox_priority->addItem(QString());
        comboBox_priority->addItem(QString());
        comboBox_priority->addItem(QString());
        comboBox_priority->addItem(QString());
        comboBox_priority->addItem(QString());
        comboBox_priority->addItem(QString());
        comboBox_priority->setObjectName("comboBox_priority");
        comboBox_priority->setGeometry(QRect(460, 420, 301, 41));
        comboBox_priority->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 250, 141, 16));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 400, 111, 16));
        label_2->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(520, 110, 241, 41));
        lineEdit->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 110, 61, 41));
        label_3->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "16", nullptr));

        pushButton_criticalSection->setText(QCoreApplication::translate("MainWindow", "Execute\n"
"Critical Section", nullptr));
        pushButton_refreshTable->setText(QCoreApplication::translate("MainWindow", "Refresh table", nullptr));
        pushButton_terminate->setText(QCoreApplication::translate("MainWindow", "Terminate", nullptr));
        pushButton_suspend->setText(QCoreApplication::translate("MainWindow", "Suspend", nullptr));
        pushButton_resume->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        pushButton_priority->setText(QCoreApplication::translate("MainWindow", "Set priority", nullptr));
        pushButton_mutex->setText(QCoreApplication::translate("MainWindow", "Execute\n"
"Mutex", nullptr));
        comboBox_priority->setItemText(0, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBox_priority->setItemText(1, QCoreApplication::translate("MainWindow", "Idle", nullptr));
        comboBox_priority->setItemText(2, QCoreApplication::translate("MainWindow", "Low", nullptr));
        comboBox_priority->setItemText(3, QCoreApplication::translate("MainWindow", "Below Normal", nullptr));
        comboBox_priority->setItemText(4, QCoreApplication::translate("MainWindow", "Above Normal", nullptr));
        comboBox_priority->setItemText(5, QCoreApplication::translate("MainWindow", "High", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Number of threads:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Priority to set:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "To Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
