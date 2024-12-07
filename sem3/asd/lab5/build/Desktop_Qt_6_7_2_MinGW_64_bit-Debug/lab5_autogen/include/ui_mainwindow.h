/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1001, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(359, 50, 111, 31));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 221, 31));
        label_2->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 50, 301, 31));
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 130, 451, 501));
        plainTextEdit->setFont(font);
        plainTextEdit->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 251, 21));
        label->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(859, 50, 111, 31));
        pushButton_2->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(520, 370, 221, 31));
        label_5->setFont(font);
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(520, 130, 451, 231));
        plainTextEdit_2->setFont(font);
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(520, 400, 451, 231));
        plainTextEdit_3->setFont(font);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(700, 50, 131, 31));
        lineEdit_3->setFont(font);
        lineEdit_3->setReadOnly(false);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(670, 50, 21, 21));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(700, 20, 131, 21));
        label_7->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 20, 111, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(520, 100, 221, 31));
        label_4->setFont(font);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(520, 50, 131, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setMaxLength(10);
        lineEdit_2->setReadOnly(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1001, 21));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "The steps:", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Array size:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "The result:", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Matrix columns", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Matrix rows", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Initial matrix:", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
