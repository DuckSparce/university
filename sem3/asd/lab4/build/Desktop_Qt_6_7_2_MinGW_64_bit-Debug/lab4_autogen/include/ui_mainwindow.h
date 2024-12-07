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
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(990, 680);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(520, 90, 221, 31));
        QFont font;
        font.setPointSize(14);
        label_4->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 221, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 10, 191, 21));
        label_3->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 251, 21));
        label->setFont(font);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 120, 451, 501));
        plainTextEdit->setFont(font);
        plainTextEdit->setReadOnly(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(349, 40, 111, 31));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(859, 40, 111, 31));
        pushButton_2->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 40, 301, 31));
        lineEdit->setFont(font);
        lineEdit->setReadOnly(false);
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(520, 120, 451, 501));
        plainTextEdit_2->setFont(font);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(520, 40, 301, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setMaxLength(10);
        lineEdit_2->setReadOnly(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 990, 21));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "Individual task:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "The steps:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Arrays size:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Array size:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
