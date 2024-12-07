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
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_shortest;
    QLabel *label_4;
    QLineEdit *lineEdit_longest;
    QLabel *label_5;
    QLineEdit *lineEdit_toFind;
    QLabel *label_6;
    QLineEdit *lineEdit_found;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_8;
    QLineEdit *lineEdit_prefix;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(793, 568);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(30, 50, 341, 141));
        QFont font;
        font.setPointSize(16);
        plainTextEdit->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 111, 31));
        label->setFont(font);
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(420, 50, 341, 141));
        plainTextEdit_2->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 10, 111, 31));
        label_2->setFont(font);
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(30, 250, 341, 251));
        plainTextEdit_3->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 210, 201, 31));
        label_3->setFont(font);
        lineEdit_shortest = new QLineEdit(centralwidget);
        lineEdit_shortest->setObjectName("lineEdit_shortest");
        lineEdit_shortest->setGeometry(QRect(580, 280, 181, 31));
        lineEdit_shortest->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(420, 280, 151, 31));
        label_4->setFont(font);
        lineEdit_longest = new QLineEdit(centralwidget);
        lineEdit_longest->setObjectName("lineEdit_longest");
        lineEdit_longest->setGeometry(QRect(580, 330, 181, 31));
        lineEdit_longest->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(420, 330, 151, 31));
        label_5->setFont(font);
        lineEdit_toFind = new QLineEdit(centralwidget);
        lineEdit_toFind->setObjectName("lineEdit_toFind");
        lineEdit_toFind->setGeometry(QRect(580, 380, 181, 31));
        lineEdit_toFind->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 380, 151, 31));
        label_6->setFont(font);
        lineEdit_found = new QLineEdit(centralwidget);
        lineEdit_found->setObjectName("lineEdit_found");
        lineEdit_found->setGeometry(QRect(580, 480, 181, 31));
        lineEdit_found->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 480, 151, 31));
        label_7->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 210, 341, 51));
        pushButton->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(420, 430, 141, 31));
        label_8->setFont(font);
        lineEdit_prefix = new QLineEdit(centralwidget);
        lineEdit_prefix->setObjectName("lineEdit_prefix");
        lineEdit_prefix->setGeometry(QRect(580, 430, 181, 31));
        lineEdit_prefix->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 793, 22));
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
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "abcd ab adsfe lfdsk asd fdns gdfoi fdaskfab asd eww vcss fdaskfab", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Text 1", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("MainWindow", "fdsfoi void oasid smallsd ds abfdaskfab adsdse ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Text 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Text 1 - changed", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Shortest word", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Longest word", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Word to find", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Found index", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Prefix function", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
