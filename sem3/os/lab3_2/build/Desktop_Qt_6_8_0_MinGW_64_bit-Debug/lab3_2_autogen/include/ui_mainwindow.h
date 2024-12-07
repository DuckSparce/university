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
    QPushButton *pushButton_priority;
    QPushButton *pushButton_suspend;
    QPushButton *pushButton_affinity;
    QPushButton *pushButton_terminate;
    QPushButton *pushButton_create_resmon;
    QPushButton *pushButton_create_sort;
    QPushButton *pushButton_create_tab;
    QPushButton *pushButton_create_notion;
    QComboBox *comboBox;
    QPushButton *pushButton_refresh;
    QPushButton *pushButton_continue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 800);
        MainWindow->setMinimumSize(QSize(1000, 800));
        MainWindow->setMaximumSize(QSize(1000, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 250, 921, 511));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setColumnCount(7);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        pushButton_priority = new QPushButton(centralwidget);
        pushButton_priority->setObjectName("pushButton_priority");
        pushButton_priority->setGeometry(QRect(240, 30, 81, 81));
        pushButton_suspend = new QPushButton(centralwidget);
        pushButton_suspend->setObjectName("pushButton_suspend");
        pushButton_suspend->setGeometry(QRect(40, 30, 81, 81));
        pushButton_affinity = new QPushButton(centralwidget);
        pushButton_affinity->setObjectName("pushButton_affinity");
        pushButton_affinity->setGeometry(QRect(440, 30, 171, 81));
        pushButton_terminate = new QPushButton(centralwidget);
        pushButton_terminate->setObjectName("pushButton_terminate");
        pushButton_terminate->setGeometry(QRect(640, 30, 171, 81));
        pushButton_create_resmon = new QPushButton(centralwidget);
        pushButton_create_resmon->setObjectName("pushButton_create_resmon");
        pushButton_create_resmon->setGeometry(QRect(440, 140, 171, 81));
        pushButton_create_sort = new QPushButton(centralwidget);
        pushButton_create_sort->setObjectName("pushButton_create_sort");
        pushButton_create_sort->setGeometry(QRect(640, 140, 171, 81));
        pushButton_create_tab = new QPushButton(centralwidget);
        pushButton_create_tab->setObjectName("pushButton_create_tab");
        pushButton_create_tab->setGeometry(QRect(40, 140, 171, 81));
        pushButton_create_notion = new QPushButton(centralwidget);
        pushButton_create_notion->setObjectName("pushButton_create_notion");
        pushButton_create_notion->setGeometry(QRect(240, 140, 171, 81));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(330, 30, 81, 81));
        pushButton_refresh = new QPushButton(centralwidget);
        pushButton_refresh->setObjectName("pushButton_refresh");
        pushButton_refresh->setGeometry(QRect(840, 30, 121, 191));
        pushButton_continue = new QPushButton(centralwidget);
        pushButton_continue->setObjectName("pushButton_continue");
        pushButton_continue->setGeometry(QRect(130, 30, 81, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "CPU time", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Working Set", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Peak Working Set", nullptr));
        pushButton_priority->setText(QCoreApplication::translate("MainWindow", "Set priority", nullptr));
        pushButton_suspend->setText(QCoreApplication::translate("MainWindow", "Suspend", nullptr));
        pushButton_affinity->setText(QCoreApplication::translate("MainWindow", "Set affinity", nullptr));
        pushButton_terminate->setText(QCoreApplication::translate("MainWindow", "Terminate", nullptr));
        pushButton_create_resmon->setText(QCoreApplication::translate("MainWindow", "Create Visual Studio process", nullptr));
        pushButton_create_sort->setText(QCoreApplication::translate("MainWindow", "Create array sort process", nullptr));
        pushButton_create_tab->setText(QCoreApplication::translate("MainWindow", "Create tabulation process", nullptr));
        pushButton_create_notion->setText(QCoreApplication::translate("MainWindow", "Create cmd process", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Idle", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Below normal", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Above normal", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "High", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Realtime", nullptr));

        pushButton_refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        pushButton_continue->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
