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
    QLineEdit *lineEdit_size;
    QLabel *label;
    QPushButton *pushButton_start;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_array;
    QLabel *label_3;
    QLineEdit *lineEdit_toFind;
    QLineEdit *lineEdit_comparisons;
    QLabel *label_4;
    QLineEdit *lineEdit_found;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_range;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit_size = new QLineEdit(centralwidget);
        lineEdit_size->setObjectName("lineEdit_size");
        lineEdit_size->setGeometry(QRect(170, 20, 321, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        lineEdit_size->setFont(font);
        lineEdit_size->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 25, 121, 31));
        label->setFont(font);
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setGeometry(QRect(530, 20, 241, 111));
        pushButton_start->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 150, 191, 31));
        label_2->setFont(font);
        plainTextEdit_array = new QPlainTextEdit(centralwidget);
        plainTextEdit_array->setObjectName("plainTextEdit_array");
        plainTextEdit_array->setEnabled(false);
        plainTextEdit_array->setGeometry(QRect(30, 189, 741, 241));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        plainTextEdit_array->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 450, 131, 31));
        label_3->setFont(font);
        lineEdit_toFind = new QLineEdit(centralwidget);
        lineEdit_toFind->setObjectName("lineEdit_toFind");
        lineEdit_toFind->setEnabled(false);
        lineEdit_toFind->setGeometry(QRect(30, 480, 221, 41));
        lineEdit_toFind->setFont(font);
        lineEdit_toFind->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        lineEdit_comparisons = new QLineEdit(centralwidget);
        lineEdit_comparisons->setObjectName("lineEdit_comparisons");
        lineEdit_comparisons->setEnabled(false);
        lineEdit_comparisons->setGeometry(QRect(290, 480, 221, 41));
        lineEdit_comparisons->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 450, 231, 31));
        label_4->setFont(font);
        lineEdit_found = new QLineEdit(centralwidget);
        lineEdit_found->setObjectName("lineEdit_found");
        lineEdit_found->setEnabled(false);
        lineEdit_found->setGeometry(QRect(550, 480, 221, 41));
        lineEdit_found->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(550, 450, 211, 31));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 85, 121, 31));
        label_6->setFont(font);
        lineEdit_range = new QLineEdit(centralwidget);
        lineEdit_range->setObjectName("lineEdit_range");
        lineEdit_range->setGeometry(QRect(170, 80, 321, 41));
        lineEdit_range->setFont(font);
        lineEdit_range->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
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
        lineEdit_size->setInputMask(QString());
        lineEdit_size->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Array size:", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start the program", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Generated array:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Looking for:", nullptr));
        lineEdit_toFind->setInputMask(QString());
        lineEdit_toFind->setText(QString());
        lineEdit_comparisons->setInputMask(QString());
        lineEdit_comparisons->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Comparisons count:", nullptr));
        lineEdit_found->setInputMask(QString());
        lineEdit_found->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Found element index:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Range:", nullptr));
        lineEdit_range->setInputMask(QString());
        lineEdit_range->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
