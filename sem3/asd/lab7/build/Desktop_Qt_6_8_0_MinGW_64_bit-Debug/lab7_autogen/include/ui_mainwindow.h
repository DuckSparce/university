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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_queue;
    QPlainTextEdit *plainTextEdit_size;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_min;
    QPlainTextEdit *plainTextEdit_max;
    QPlainTextEdit *plainTextEdit_3rd;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_2nd;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPlainTextEdit *plainTextEdit_beforemin;
    QPlainTextEdit *plainTextEdit_aftermax;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QPlainTextEdit *plainTextEdit_found;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QPlainTextEdit *plainTextEdit_combined;
    QLabel *label_13;
    QPlainTextEdit *plainTextEdit_queue_2;
    QLabel *label_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 741, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 50, 741, 41));
        QFont font1;
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 90, 741, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        plainTextEdit_queue = new QPlainTextEdit(centralwidget);
        plainTextEdit_queue->setObjectName("plainTextEdit_queue");
        plainTextEdit_queue->setGeometry(QRect(30, 120, 741, 41));
        plainTextEdit_queue->setFont(font1);
        plainTextEdit_queue->setReadOnly(true);
        plainTextEdit_queue->setOverwriteMode(false);
        plainTextEdit_size = new QPlainTextEdit(centralwidget);
        plainTextEdit_size->setObjectName("plainTextEdit_size");
        plainTextEdit_size->setGeometry(QRect(100, 280, 91, 41));
        plainTextEdit_size->setFont(font1);
        plainTextEdit_size->setReadOnly(true);
        plainTextEdit_size->setOverwriteMode(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 280, 61, 41));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        plainTextEdit_min = new QPlainTextEdit(centralwidget);
        plainTextEdit_min->setObjectName("plainTextEdit_min");
        plainTextEdit_min->setGeometry(QRect(100, 180, 91, 41));
        plainTextEdit_min->setFont(font1);
        plainTextEdit_min->setReadOnly(true);
        plainTextEdit_min->setOverwriteMode(false);
        plainTextEdit_max = new QPlainTextEdit(centralwidget);
        plainTextEdit_max->setObjectName("plainTextEdit_max");
        plainTextEdit_max->setGeometry(QRect(100, 230, 91, 41));
        plainTextEdit_max->setFont(font1);
        plainTextEdit_max->setReadOnly(true);
        plainTextEdit_max->setOverwriteMode(false);
        plainTextEdit_3rd = new QPlainTextEdit(centralwidget);
        plainTextEdit_3rd->setObjectName("plainTextEdit_3rd");
        plainTextEdit_3rd->setGeometry(QRect(360, 180, 91, 41));
        plainTextEdit_3rd->setFont(font1);
        plainTextEdit_3rd->setReadOnly(true);
        plainTextEdit_3rd->setOverwriteMode(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 180, 61, 41));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 230, 61, 41));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(220, 180, 141, 41));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        plainTextEdit_2nd = new QPlainTextEdit(centralwidget);
        plainTextEdit_2nd->setObjectName("plainTextEdit_2nd");
        plainTextEdit_2nd->setGeometry(QRect(360, 230, 91, 41));
        plainTextEdit_2nd->setFont(font1);
        plainTextEdit_2nd->setReadOnly(true);
        plainTextEdit_2nd->setOverwriteMode(false);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(220, 230, 141, 41));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(490, 230, 191, 41));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(490, 180, 191, 41));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        plainTextEdit_beforemin = new QPlainTextEdit(centralwidget);
        plainTextEdit_beforemin->setObjectName("plainTextEdit_beforemin");
        plainTextEdit_beforemin->setGeometry(QRect(680, 180, 91, 41));
        plainTextEdit_beforemin->setFont(font1);
        plainTextEdit_beforemin->setReadOnly(true);
        plainTextEdit_beforemin->setOverwriteMode(false);
        plainTextEdit_aftermax = new QPlainTextEdit(centralwidget);
        plainTextEdit_aftermax->setObjectName("plainTextEdit_aftermax");
        plainTextEdit_aftermax->setGeometry(QRect(680, 230, 91, 41));
        plainTextEdit_aftermax->setFont(font1);
        plainTextEdit_aftermax->setReadOnly(true);
        plainTextEdit_aftermax->setOverwriteMode(false);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(220, 280, 361, 41));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(590, 280, 71, 41));
        lineEdit_2->setFont(font1);
        plainTextEdit_found = new QPlainTextEdit(centralwidget);
        plainTextEdit_found->setObjectName("plainTextEdit_found");
        plainTextEdit_found->setGeometry(QRect(700, 280, 71, 41));
        plainTextEdit_found->setFont(font1);
        plainTextEdit_found->setReadOnly(true);
        plainTextEdit_found->setOverwriteMode(false);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(660, 280, 41, 41));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 340, 741, 31));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(30, 370, 741, 41));
        lineEdit_3->setFont(font1);
        plainTextEdit_combined = new QPlainTextEdit(centralwidget);
        plainTextEdit_combined->setObjectName("plainTextEdit_combined");
        plainTextEdit_combined->setGeometry(QRect(30, 510, 741, 41));
        plainTextEdit_combined->setFont(font1);
        plainTextEdit_combined->setReadOnly(true);
        plainTextEdit_combined->setOverwriteMode(false);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 480, 741, 31));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        plainTextEdit_queue_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_queue_2->setObjectName("plainTextEdit_queue_2");
        plainTextEdit_queue_2->setGeometry(QRect(30, 440, 741, 41));
        plainTextEdit_queue_2->setFont(font1);
        plainTextEdit_queue_2->setReadOnly(true);
        plainTextEdit_queue_2->setOverwriteMode(false);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 410, 741, 31));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
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
        label->setText(QCoreApplication::translate("MainWindow", "Enter a data sequence", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Built structure (queue)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "3rd from head", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "2nd from tail", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Element after max", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Element before min", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Find element's first occurence position", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Enter the second data sequence to combine with the first one", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Combined structure (queue)", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Built structure (queue #2)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
