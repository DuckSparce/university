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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_toFind;
    QLabel *label_source;
    QLineEdit *lineEdit_source;
    QLabel *label_built;
    QLineEdit *lineEdit_traversal;
    QLabel *label_built_2;
    QLabel *label_built_3;
    QLineEdit *lineEdit_isFound;
    QLineEdit *lineEdit_right;
    QLineEdit *lineEdit_left;
    QLineEdit *lineEdit_parent;
    QLabel *label_built_4;
    QLabel *label_built_5;
    QLabel *label_built_6;
    QLabel *label_built_7;
    QLineEdit *lineEdit_func;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 500);
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit_toFind = new QLineEdit(centralwidget);
        lineEdit_toFind->setObjectName("lineEdit_toFind");
        lineEdit_toFind->setGeometry(QRect(560, 230, 91, 40));
        lineEdit_toFind->setFont(font);
        label_source = new QLabel(centralwidget);
        label_source->setObjectName("label_source");
        label_source->setGeometry(QRect(30, 20, 741, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Courier New")});
        font1.setPointSize(16);
        label_source->setFont(font1);
        label_source->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_source = new QLineEdit(centralwidget);
        lineEdit_source->setObjectName("lineEdit_source");
        lineEdit_source->setGeometry(QRect(30, 50, 741, 41));
        lineEdit_source->setFont(font);
        label_built = new QLabel(centralwidget);
        label_built->setObjectName("label_built");
        label_built->setGeometry(QRect(30, 130, 741, 31));
        label_built->setFont(font1);
        label_built->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_traversal = new QLineEdit(centralwidget);
        lineEdit_traversal->setObjectName("lineEdit_traversal");
        lineEdit_traversal->setGeometry(QRect(30, 160, 741, 41));
        lineEdit_traversal->setFont(font);
        label_built_2 = new QLabel(centralwidget);
        label_built_2->setObjectName("label_built_2");
        label_built_2->setGeometry(QRect(30, 230, 511, 41));
        label_built_2->setFont(font1);
        label_built_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_built_3 = new QLabel(centralwidget);
        label_built_3->setObjectName("label_built_3");
        label_built_3->setGeometry(QRect(650, 230, 81, 41));
        label_built_3->setFont(font1);
        label_built_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_isFound = new QLineEdit(centralwidget);
        lineEdit_isFound->setObjectName("lineEdit_isFound");
        lineEdit_isFound->setGeometry(QRect(730, 230, 41, 41));
        lineEdit_isFound->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_isFound->setReadOnly(true);
        lineEdit_right = new QLineEdit(centralwidget);
        lineEdit_right->setObjectName("lineEdit_right");
        lineEdit_right->setGeometry(QRect(680, 300, 91, 40));
        lineEdit_right->setFont(font);
        lineEdit_right->setReadOnly(true);
        lineEdit_left = new QLineEdit(centralwidget);
        lineEdit_left->setObjectName("lineEdit_left");
        lineEdit_left->setGeometry(QRect(410, 300, 91, 40));
        lineEdit_left->setFont(font);
        lineEdit_left->setReadOnly(true);
        lineEdit_parent = new QLineEdit(centralwidget);
        lineEdit_parent->setObjectName("lineEdit_parent");
        lineEdit_parent->setGeometry(QRect(150, 300, 91, 40));
        lineEdit_parent->setFont(font);
        lineEdit_parent->setReadOnly(true);
        label_built_4 = new QLabel(centralwidget);
        label_built_4->setObjectName("label_built_4");
        label_built_4->setGeometry(QRect(40, 300, 121, 41));
        label_built_4->setFont(font1);
        label_built_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_built_5 = new QLabel(centralwidget);
        label_built_5->setObjectName("label_built_5");
        label_built_5->setGeometry(QRect(280, 300, 141, 41));
        label_built_5->setFont(font1);
        label_built_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_built_6 = new QLabel(centralwidget);
        label_built_6->setObjectName("label_built_6");
        label_built_6->setGeometry(QRect(540, 300, 141, 41));
        label_built_6->setFont(font1);
        label_built_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_built_7 = new QLabel(centralwidget);
        label_built_7->setObjectName("label_built_7");
        label_built_7->setGeometry(QRect(40, 380, 511, 41));
        label_built_7->setFont(font1);
        label_built_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_func = new QLineEdit(centralwidget);
        lineEdit_func->setObjectName("lineEdit_func");
        lineEdit_func->setGeometry(QRect(560, 380, 211, 41));
        lineEdit_func->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_func->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        lineEdit_toFind->setText(QString());
        label_source->setText(QCoreApplication::translate("MainWindow", "Enter a data sequence (integers)", nullptr));
        label_built->setText(QCoreApplication::translate("MainWindow", "Postorder traversal", nullptr));
        label_built_2->setText(QCoreApplication::translate("MainWindow", "Check whether the tree has this value:", nullptr));
        label_built_3->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        lineEdit_right->setText(QString());
        lineEdit_left->setText(QString());
        lineEdit_parent->setText(QString());
        label_built_4->setText(QCoreApplication::translate("MainWindow", "Parent", nullptr));
        label_built_5->setText(QCoreApplication::translate("MainWindow", "Left son", nullptr));
        label_built_6->setText(QCoreApplication::translate("MainWindow", "Right son", nullptr));
        label_built_7->setText(QCoreApplication::translate("MainWindow", "Individual task - 3rd smallest element:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
