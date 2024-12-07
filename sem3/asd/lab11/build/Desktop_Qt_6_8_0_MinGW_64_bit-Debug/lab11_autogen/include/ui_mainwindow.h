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
    QPushButton *pushButton;
    QLineEdit *lineEdit_found;
    QLabel *label_7;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QLineEdit *lineEdit_toFind;
    QLabel *label_9;
    QLineEdit *lineEdit_searchingFor;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(868, 369);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(430, 130, 411, 41));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        lineEdit_found = new QLineEdit(centralwidget);
        lineEdit_found->setObjectName("lineEdit_found");
        lineEdit_found->setGeometry(QRect(570, 270, 271, 41));
        lineEdit_found->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 270, 131, 41));
        label_7->setFont(font);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(30, 60, 361, 251));
        plainTextEdit->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 71, 31));
        label->setFont(font);
        lineEdit_toFind = new QLineEdit(centralwidget);
        lineEdit_toFind->setObjectName("lineEdit_toFind");
        lineEdit_toFind->setGeometry(QRect(620, 60, 221, 41));
        lineEdit_toFind->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(430, 60, 181, 41));
        label_9->setFont(font);
        lineEdit_searchingFor = new QLineEdit(centralwidget);
        lineEdit_searchingFor->setObjectName("lineEdit_searchingFor");
        lineEdit_searchingFor->setGeometry(QRect(570, 200, 271, 41));
        lineEdit_searchingFor->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(430, 200, 131, 41));
        label_10->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 868, 22));
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
        label_7->setText(QCoreApplication::translate("MainWindow", "Found index", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "abcd ab adsfe lfdsk asd fdns gdfoi fdaskfab asd eww vcss fdaskfab", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Enter word to find", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Searching for", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
