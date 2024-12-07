/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QPushButton *pushButton_sort;
    QTableWidget *tableWidget;
    QPushButton *pushButton_chart;
    QChartView *widget_lineChart;
    QChartView *widget_pieChart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 800));
        MainWindow->setMaximumSize(QSize(1200, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_sort = new QPushButton(centralwidget);
        pushButton_sort->setObjectName("pushButton_sort");
        pushButton_sort->setGeometry(QRect(850, 25, 321, 91));
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(2, 6, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(3, 5, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(3, 6, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(4, 2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(4, 3, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(4, 4, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(4, 5, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(4, 6, __qtablewidgetitem46);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 20, 785, 222));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setMinimumSectionSize(40);
        tableWidget->verticalHeader()->setDefaultSectionSize(40);
        pushButton_chart = new QPushButton(centralwidget);
        pushButton_chart->setObjectName("pushButton_chart");
        pushButton_chart->setGeometry(QRect(850, 150, 321, 91));
        widget_lineChart = new QChartView(centralwidget);
        widget_lineChart->setObjectName("widget_lineChart");
        widget_lineChart->setGeometry(QRect(20, 260, 661, 521));
        widget_pieChart = new QChartView(centralwidget);
        widget_pieChart->setObjectName("widget_pieChart");
        widget_pieChart->setGeometry(QRect(680, 260, 501, 521));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 21));
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
        pushButton_sort->setText(QCoreApplication::translate("MainWindow", "Start Sorting", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "1024", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "4096", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "16384", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "65536", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "262144", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "1048576", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "4194304", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Shell Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Quick Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Counting Sort", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(0, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(0, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(0, 6);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(1, 2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(1, 4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(1, 5);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(1, 6);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(2, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(2, 1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(2, 2);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(2, 3);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(2, 4);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(2, 5);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(2, 6);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(3, 0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(3, 1);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(3, 2);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(3, 3);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(3, 4);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(3, 5);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(3, 6);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(4, 0);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(4, 1);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(4, 2);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(4, 3);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(4, 4);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(4, 5);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(4, 6);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton_chart->setText(QCoreApplication::translate("MainWindow", "Draw Charts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
