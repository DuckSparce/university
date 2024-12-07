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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOption1;
    QAction *action_fileInput;
    QAction *action_fileOutput;
    QAction *action_clearData;
    QAction *action_exit;
    QAction *action_add;
    QAction *action_edit;
    QAction *action_delete;
    QAction *action_cost;
    QAction *action_whatsThis;
    QWidget *centralwidget;
    QTableWidget *tableWidget_orders;
    QTableWidget *tableWidget_template;
    QPushButton *pushButton_add;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_delete;
    QTableWidget *tableWidget_prices;
    QPushButton *pushButton_sort;
    QPushButton *pushButton_income;
    QLineEdit *lineEdit_income;
    QPushButton *pushButton_materialsCost;
    QLineEdit *lineEdit_materialsCost;
    QTableWidget *tableWidget_outcomes;
    QPushButton *pushButton_outcomes;
    QCheckBox *checkBox;
    QPushButton *pushButton_cost;
    QLineEdit *lineEdit_cost;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu;
    QMenu *menu_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1200, 800));
        MainWindow->setMaximumSize(QSize(1200, 800));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setIconSize(QSize(256, 256));
        actionOption1 = new QAction(MainWindow);
        actionOption1->setObjectName("actionOption1");
        action_fileInput = new QAction(MainWindow);
        action_fileInput->setObjectName("action_fileInput");
        action_fileOutput = new QAction(MainWindow);
        action_fileOutput->setObjectName("action_fileOutput");
        action_clearData = new QAction(MainWindow);
        action_clearData->setObjectName("action_clearData");
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName("action_exit");
        action_add = new QAction(MainWindow);
        action_add->setObjectName("action_add");
        action_edit = new QAction(MainWindow);
        action_edit->setObjectName("action_edit");
        action_delete = new QAction(MainWindow);
        action_delete->setObjectName("action_delete");
        action_cost = new QAction(MainWindow);
        action_cost->setObjectName("action_cost");
        action_whatsThis = new QAction(MainWindow);
        action_whatsThis->setObjectName("action_whatsThis");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget_orders = new QTableWidget(centralwidget);
        if (tableWidget_orders->columnCount() < 3)
            tableWidget_orders->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_orders->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_orders->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_orders->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_orders->rowCount() < 1)
            tableWidget_orders->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_orders->setItem(0, 0, __qtablewidgetitem3);
        tableWidget_orders->setObjectName("tableWidget_orders");
        tableWidget_orders->setGeometry(QRect(20, 20, 350, 491));
        tableWidget_orders->setMinimumSize(QSize(350, 450));
        tableWidget_orders->setMaximumSize(QSize(350, 760));
        QFont font;
        font.setPointSize(9);
        tableWidget_orders->setFont(font);
        tableWidget_orders->setToolTipDuration(-1);
        tableWidget_orders->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_orders->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tableWidget_orders->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_orders->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_orders->setSortingEnabled(false);
        tableWidget_orders->setRowCount(1);
        tableWidget_orders->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_orders->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget_orders->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_orders->verticalHeader()->setMinimumSectionSize(30);
        tableWidget_template = new QTableWidget(centralwidget);
        if (tableWidget_template->columnCount() < 5)
            tableWidget_template->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_template->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_template->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_template->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_template->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_template->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        if (tableWidget_template->rowCount() < 6)
            tableWidget_template->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_template->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_template->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_template->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_template->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_template->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_template->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setBackground(brush);
        tableWidget_template->setItem(1, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setBackground(brush);
        tableWidget_template->setItem(2, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setBackground(brush);
        tableWidget_template->setItem(2, 2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setBackground(brush);
        tableWidget_template->setItem(2, 3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setBackground(brush);
        tableWidget_template->setItem(3, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setBackground(brush);
        tableWidget_template->setItem(4, 2, __qtablewidgetitem20);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font1);
        tableWidget_template->setItem(5, 4, __qtablewidgetitem21);
        tableWidget_template->setObjectName("tableWidget_template");
        tableWidget_template->setGeometry(QRect(609, 19, 560, 711));
        tableWidget_template->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_template->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_template->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_template->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        tableWidget_template->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_template->setShowGrid(false);
        tableWidget_template->horizontalHeader()->setVisible(false);
        tableWidget_template->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_template->horizontalHeader()->setDefaultSectionSize(75);
        tableWidget_template->verticalHeader()->setVisible(false);
        tableWidget_template->verticalHeader()->setMinimumSectionSize(10);
        tableWidget_template->verticalHeader()->setDefaultSectionSize(70);
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(400, 260, 181, 41));
        QFont font2;
        font2.setPointSize(12);
        pushButton_add->setFont(font2);
        pushButton_edit = new QPushButton(centralwidget);
        pushButton_edit->setObjectName("pushButton_edit");
        pushButton_edit->setGeometry(QRect(400, 310, 181, 41));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        pushButton_edit->setFont(font3);
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(400, 360, 181, 41));
        pushButton_delete->setFont(font2);
        tableWidget_prices = new QTableWidget(centralwidget);
        if (tableWidget_prices->columnCount() < 2)
            tableWidget_prices->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_prices->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_prices->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        if (tableWidget_prices->rowCount() < 5)
            tableWidget_prices->setRowCount(5);
        QBrush brush1(QColor(218, 172, 64, 255));
        brush1.setStyle(Qt::SolidPattern);
        QFont font4;
        font4.setBold(true);
        font4.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font4);
        __qtablewidgetitem24->setBackground(brush1);
        __qtablewidgetitem24->setForeground(brush);
        __qtablewidgetitem24->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_prices->setItem(0, 0, __qtablewidgetitem24);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setForeground(brush2);
        tableWidget_prices->setItem(0, 1, __qtablewidgetitem25);
        QBrush brush3(QColor(218, 106, 68, 255));
        brush3.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font4);
        __qtablewidgetitem26->setBackground(brush3);
        __qtablewidgetitem26->setForeground(brush);
        __qtablewidgetitem26->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_prices->setItem(1, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_prices->setItem(1, 1, __qtablewidgetitem27);
        QBrush brush4(QColor(145, 108, 65, 255));
        brush4.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font4);
        __qtablewidgetitem28->setBackground(brush4);
        __qtablewidgetitem28->setForeground(brush);
        __qtablewidgetitem28->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_prices->setItem(2, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_prices->setItem(2, 1, __qtablewidgetitem29);
        QBrush brush5(QColor(214, 216, 89, 255));
        brush5.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font4);
        __qtablewidgetitem30->setBackground(brush5);
        __qtablewidgetitem30->setForeground(brush);
        __qtablewidgetitem30->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_prices->setItem(3, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_prices->setItem(3, 1, __qtablewidgetitem31);
        QBrush brush6(QColor(140, 179, 110, 255));
        brush6.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font4);
        __qtablewidgetitem32->setBackground(brush6);
        __qtablewidgetitem32->setForeground(brush);
        __qtablewidgetitem32->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_prices->setItem(4, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_prices->setItem(4, 1, __qtablewidgetitem33);
        tableWidget_prices->setObjectName("tableWidget_prices");
        tableWidget_prices->setGeometry(QRect(400, 20, 181, 171));
        tableWidget_prices->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_prices->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_prices->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tableWidget_prices->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
        tableWidget_prices->setAlternatingRowColors(false);
        tableWidget_prices->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
        tableWidget_prices->setWordWrap(true);
        tableWidget_prices->setRowCount(5);
        tableWidget_prices->horizontalHeader()->setVisible(true);
        tableWidget_prices->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_prices->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget_prices->verticalHeader()->setVisible(false);
        tableWidget_prices->verticalHeader()->setCascadingSectionResizes(false);
        pushButton_sort = new QPushButton(centralwidget);
        pushButton_sort->setObjectName("pushButton_sort");
        pushButton_sort->setGeometry(QRect(400, 210, 181, 41));
        pushButton_sort->setFont(font2);
        pushButton_income = new QPushButton(centralwidget);
        pushButton_income->setObjectName("pushButton_income");
        pushButton_income->setGeometry(QRect(400, 640, 181, 41));
        pushButton_income->setFont(font2);
        lineEdit_income = new QLineEdit(centralwidget);
        lineEdit_income->setObjectName("lineEdit_income");
        lineEdit_income->setEnabled(false);
        lineEdit_income->setGeometry(QRect(400, 690, 181, 41));
        QFont font5;
        font5.setPointSize(16);
        lineEdit_income->setFont(font5);
        lineEdit_income->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_materialsCost = new QPushButton(centralwidget);
        pushButton_materialsCost->setObjectName("pushButton_materialsCost");
        pushButton_materialsCost->setGeometry(QRect(400, 420, 181, 41));
        pushButton_materialsCost->setFont(font2);
        lineEdit_materialsCost = new QLineEdit(centralwidget);
        lineEdit_materialsCost->setObjectName("lineEdit_materialsCost");
        lineEdit_materialsCost->setEnabled(false);
        lineEdit_materialsCost->setGeometry(QRect(400, 470, 181, 41));
        lineEdit_materialsCost->setFont(font5);
        lineEdit_materialsCost->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableWidget_outcomes = new QTableWidget(centralwidget);
        if (tableWidget_outcomes->columnCount() < 2)
            tableWidget_outcomes->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_outcomes->setHorizontalHeaderItem(0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_outcomes->setHorizontalHeaderItem(1, __qtablewidgetitem35);
        if (tableWidget_outcomes->rowCount() < 5)
            tableWidget_outcomes->setRowCount(5);
        QBrush brush7(QColor(218, 172, 64, 255));
        brush7.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font4);
        __qtablewidgetitem36->setBackground(brush7);
        __qtablewidgetitem36->setForeground(brush);
        __qtablewidgetitem36->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_outcomes->setItem(0, 0, __qtablewidgetitem36);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setForeground(brush8);
        tableWidget_outcomes->setItem(0, 1, __qtablewidgetitem37);
        QBrush brush9(QColor(218, 106, 68, 255));
        brush9.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font4);
        __qtablewidgetitem38->setBackground(brush9);
        __qtablewidgetitem38->setForeground(brush);
        __qtablewidgetitem38->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_outcomes->setItem(1, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_outcomes->setItem(1, 1, __qtablewidgetitem39);
        QBrush brush10(QColor(145, 108, 65, 255));
        brush10.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFont(font4);
        __qtablewidgetitem40->setBackground(brush10);
        __qtablewidgetitem40->setForeground(brush);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_outcomes->setItem(2, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_outcomes->setItem(2, 1, __qtablewidgetitem41);
        QBrush brush11(QColor(214, 216, 89, 255));
        brush11.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFont(font4);
        __qtablewidgetitem42->setBackground(brush11);
        __qtablewidgetitem42->setForeground(brush);
        __qtablewidgetitem42->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_outcomes->setItem(3, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_outcomes->setItem(3, 1, __qtablewidgetitem43);
        QBrush brush12(QColor(140, 179, 110, 255));
        brush12.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setFont(font4);
        __qtablewidgetitem44->setBackground(brush12);
        __qtablewidgetitem44->setForeground(brush);
        __qtablewidgetitem44->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable);
        tableWidget_outcomes->setItem(4, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_outcomes->setItem(4, 1, __qtablewidgetitem45);
        tableWidget_outcomes->setObjectName("tableWidget_outcomes");
        tableWidget_outcomes->setEnabled(false);
        tableWidget_outcomes->setGeometry(QRect(20, 590, 351, 141));
        tableWidget_outcomes->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_outcomes->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget_outcomes->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tableWidget_outcomes->setAutoScroll(false);
        tableWidget_outcomes->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
        tableWidget_outcomes->setAlternatingRowColors(false);
        tableWidget_outcomes->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
        tableWidget_outcomes->setWordWrap(true);
        tableWidget_outcomes->setRowCount(5);
        tableWidget_outcomes->horizontalHeader()->setVisible(true);
        tableWidget_outcomes->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_outcomes->horizontalHeader()->setDefaultSectionSize(175);
        tableWidget_outcomes->verticalHeader()->setVisible(false);
        tableWidget_outcomes->verticalHeader()->setCascadingSectionResizes(false);
        pushButton_outcomes = new QPushButton(centralwidget);
        pushButton_outcomes->setObjectName("pushButton_outcomes");
        pushButton_outcomes->setGeometry(QRect(20, 530, 161, 41));
        pushButton_outcomes->setFont(font2);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(200, 530, 171, 40));
        checkBox->setFont(font2);
        checkBox->setIconSize(QSize(16, 16));
        checkBox->setTristate(false);
        pushButton_cost = new QPushButton(centralwidget);
        pushButton_cost->setObjectName("pushButton_cost");
        pushButton_cost->setGeometry(QRect(400, 530, 181, 41));
        pushButton_cost->setFont(font2);
        lineEdit_cost = new QLineEdit(centralwidget);
        lineEdit_cost->setObjectName("lineEdit_cost");
        lineEdit_cost->setEnabled(false);
        lineEdit_cost->setGeometry(QRect(400, 580, 181, 41));
        lineEdit_cost->setFont(font5);
        lineEdit_cost->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        QPalette palette;
        QBrush brush13(QColor(86, 215, 40, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush13);
        menubar->setPalette(palette);
        menu_file = new QMenu(menubar);
        menu_file->setObjectName("menu_file");
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_help = new QMenu(menubar);
        menu_help->setObjectName("menu_help");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(action_fileInput);
        menu_file->addAction(action_fileOutput);
        menu_file->addSeparator();
        menu_file->addAction(action_clearData);
        menu_file->addAction(action_exit);
        menu->addAction(action_add);
        menu->addAction(action_edit);
        menu->addAction(action_delete);
        menu->addAction(action_cost);
        menu_help->addAction(action_whatsThis);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BoxConstructor", nullptr));
        actionOption1->setText(QCoreApplication::translate("MainWindow", "Option1", nullptr));
        action_fileInput->setText(QCoreApplication::translate("MainWindow", "\320\227\321\207\320\270\321\202\320\260\321\202\320\270 \320\267 \321\204\320\260\320\271\320\273\321\203", nullptr));
#if QT_CONFIG(whatsthis)
        action_fileInput->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\227\320\260\320\277\320\270\321\201 \320\267 \321\204\320\260\320\271\320\273\321\203</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\227\321\207\320\270\321\202\321\203\321\224 \320\267 \321\204\320\260\320\271\320\273\321\203 \321\202\320\260\320\261\320\273\320\270\321\206\321\216 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214. \320\232\320\276\320\266\320\275\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267 \320\275\320\276\320\262\320\276\320\263\320\276 \321\200\321\217\320\264\320\272\320\260 \321\203 \321\204\320\276\321\200\320\274\320\260\321\202\321\226: &lt;\320\264\320\276\320\262\320\266\320\270\320\275\320\260&gt;x&lt;\321\202\320\276\320\262\321\211\320\270\320\275\320\260&gt;x&lt;\320\262\320\270\321\201\320\276\321\202\320\260&gt; &lt;\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273&gt; &lt;\320\272\321\226"
                        "\320\273\321\214\320\272\321\226\321\201\321\202\321\214&gt;</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_fileInput->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        action_fileOutput->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\320\270 \321\203 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(whatsthis)
        action_fileOutput->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\227\320\260\320\277\320\270\321\201 \321\203 \321\204\320\260\320\271\320\273</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\227\320\260\320\277\320\270\321\201\321\203\321\224 \321\203 \321\204\320\260\320\271\320\273 \321\202\320\260\320\261\320\273\320\270\321\206\321\216 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214. \320\232\320\276\320\266\320\275\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267 \320\275\320\276\320\262\320\276\320\263\320\276 \321\200\321\217\320\264\320\272\320\260 \321\203 \321\204\320\276\321\200\320\274\320\260\321\202\321\226: &lt;\320\264\320\276\320\262\320\266\320\270\320\275\320\260&gt;x&lt;\321\202\320\276\320\262\321\211\320\270\320\275\320\260&gt;x&lt;\320\262\320\270\321\201\320\276\321\202\320\260&gt; &lt;\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273&gt; &lt;\320\272\321\226\320\273"
                        "\321\214\320\272\321\226\321\201\321\202\321\214&gt;</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_fileOutput->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_clearData->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\320\270 \320\264\320\260\320\275\321\226", nullptr));
#if QT_CONFIG(whatsthis)
        action_clearData->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\236\321\207\320\270\321\211\320\265\320\275\320\275\321\217 \320\264\320\260\320\275\320\270\321\205</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\237\320\276\320\262\320\275\321\226\321\201\321\202\321\216 \320\276\321\207\320\270\321\211\321\203\321\224 \321\202\320\260\320\261\320\273\320\270\321\206\321\216 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_clearData->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        action_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", nullptr));
#if QT_CONFIG(whatsthis)
        action_exit->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\222\320\270\321\205\321\226\320\264</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\237\320\276\320\262\320\275\321\226\321\201\321\202\321\216 \320\267\320\260\320\272\321\200\320\270\320\262\320\260\321\224 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_add->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\275\320\276\320\262\320\265", nullptr));
#if QT_CONFIG(whatsthis)
        action_add->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\224\320\276\320\264\320\260\320\262\320\260\320\275\320\275\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\224\320\276\320\264\320\260\321\224 \320\275\320\276\320\262\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267 \320\267\320\260\320\264\320\260\320\275\320\270\320\274\320\270 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260\320\274\320\270 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214. \320\243 \320\277\320\276\320\264\320\260\320\273\321\214\321\210\320\276\320\274\321\203 \320\274\320\276\320\266\320\265 \320\261\321\203\321\202\320\270 \321\200\320\265\320\264\320\260\320\263\320\276\320\262\320\260\320\275\320\265 \320\260\320\261\320\276 \320\262"
                        "\320\270\320\264\320\260\320\273\320\265\320\275\320\265.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_add->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_edit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270", nullptr));
#if QT_CONFIG(whatsthis)
        action_edit->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\240\320\265\320\264\320\260\320\263\321\203\321\224 \320\262\320\270\320\261\321\200\320\260\320\275\320\265 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217. \320\236\320\275\320\276\320\262\320\273\321\217\321\224 \320\264\320\260\320\275\321\226 \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\275\320\276 \320\264\320\276 \320\267\320\260\320\264\320\260\320\275\320\270\321\205 \320\275\320\276\320\262\320\270\321\205 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\226\320\262 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217.</span></"
                        "p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_edit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_delete->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
#if QT_CONFIG(whatsthis)
        action_delete->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\222\320\270\320\264\320\260\320\273\320\265\320\275\320\275\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\222\320\270\320\264\320\260\320\273\321\217\321\224 \320\262\320\270\320\261\321\200\320\260\320\275\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267 \321\202\320\260\320\261\320\273\320\270\321\206\321\226.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_delete->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+D", nullptr));
#endif // QT_CONFIG(shortcut)
        action_cost->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\205\321\203\320\262\320\260\321\202\320\270 \321\206\321\226\320\275\321\203 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
#if QT_CONFIG(whatsthis)
        action_cost->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\246\321\226\320\275\320\260 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\237\321\226\320\264\321\200\320\260\321\205\320\276\320\262\321\203\321\224 \320\272\321\226\320\275\321\206\320\265\320\262\321\203 \321\206\321\226\320\275\321\203 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \320\262\321\200\320\260\321\205\320\276\320\262\321\203\321\216\321\207\320\270 \321\206\321\226\320\275\321\203 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\203, \321\200\320\276\320\267\320\274\321\226\321\200\320\270, \320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214, \320\260 \321\202\320\260\320\272\320\276\320\266 \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\216 \320\276\320\261\320\273\320\260\320\264\320\275\320\260\320\275"
                        "\320\275\321\217, \320\277\320\276\320\264\320\260\321\202\320\272\320\270 \321\226 10% \320\264\320\276\321\205\320\276\320\264\321\203.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_cost->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_whatsThis->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \"\320\251\320\276\320\246\320\265?\"", nullptr));
#if QT_CONFIG(whatsthis)
        action_whatsThis->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\240\320\265\320\266\320\270\320\274 &quot;\320\251\320\276\320\246\320\265?&quot;</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\224\320\276\320\277\320\276\320\274\320\260\320\263\320\260\321\224 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207\321\203 \320\267\321\200\320\276\320\267\321\203\320\274\321\226\321\202\320\270 \321\226\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270. \320\243\320\262\321\226\320\274\320\272\320\275\321\203\320\262\321\210\320\270 \321\206\320\265\320\271 \321\200\320\265\320\266\320\270\320\274, \320\262\320\270\320\261\320\265\321\200\321\226\321\202\321\214 \320\277\320\276\321\202\321\200\321\226\320\261\320\275\320\270\320\271 \320\265\320\273\320\265\320\274\320\265\320\275\321\202 \321\202\320\260 \320\276\321\202\321\200\320\270\320\274\320\260\320\271\321\202\320"
                        "\265 \321\226\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\216 \320\277\321\200\320\276 \320\275\321\214\320\276\320\263\320\276.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(shortcut)
        action_whatsThis->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        QTableWidgetItem *___qtablewidgetitem = tableWidget_orders->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\267\320\274\321\226\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_orders->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\321\226\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_orders->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", nullptr));

        const bool __sortingEnabled = tableWidget_orders->isSortingEnabled();
        tableWidget_orders->setSortingEnabled(false);
        tableWidget_orders->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        tableWidget_orders->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tableWidget_orders->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:10pt; font-weight:700;\">\320\242\320\260\320\261\320\273\320\270\321\206\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\267\320\261\320\265\321\200\321\226\320\263\320\260\321\216\321\202\321\214\321\201\321\217 \320\262\321\201\321\226 \320\264\320\276\320\264\320\260\320\275\321\226 \321\202\320\260 \320\267\321\207\320\270\321\202\320\260\320\275\321\226 \320\267 \321\204\320\260\320\271\320\273\321\203 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217. \320\222\320\262\320\260\320\266\320\260\321\224\321\202\321\214\321\201\321\217, \321\211\320\276 \321\206\320\265 \320\267\320\260\320\277\320\270\321\201 \320\262\321\201\321\226\321\205 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214 \320\267\320\260 \320\277\320\265\320\262\320\275\320\270\320\271 \320\274\321"
                        "\226\321\201\321\217\321\206\321\214. \320\241\321\216\320\264\320\270 \320\274\320\276\320\266\320\275\320\260 \320\264\320\276\320\264\320\260\320\262\320\260\321\202\320\270 \320\275\320\276\320\262\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \321\200\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \321\202\320\260 \320\262\320\270\320\264\320\260\320\273\321\217\321\202\320\270 \320\262\320\266\320\265 \320\262\320\270\320\261\321\200\320\260\320\275\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \320\264\321\226\320\267\320\275\320\260\321\202\320\270\321\201\321\217 \320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\262\320\270\320\264\321\226\320\273\320\265\320\275\320\276\320\263\320\276 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \321\202\320\260 \320\276\320\261\321\200\320\260\321\205\321\203\320\262\320\260\321\202\320\270 \320\274"
                        "\321\226\321\201\321\217\321\207\320\275\320\270\321\205 \320\264\320\276\321\205\321\226\320\264, \320\262\321\200\320\260\321\205\320\276\320\262\321\203\321\216\321\207\320\270, \321\211\320\276 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\274\321\226\321\201\321\202\321\217\321\202\321\214\321\201\321\217 \320\262\321\201\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267\320\260 \320\274\321\226\321\201\321\217\321\206\321\214. \320\242\320\260\320\272\320\276\320\266 \320\274\320\276\320\266\320\275\320\260 \320\267\321\207\320\270\321\202\320\260\321\202\320\270 \320\267\320\260\320\277\320\270\321\201 \320\267\320\260 \320\274\321\226\321\201\321\217\321\206\321\214 \320\267 \320\262\320\270\320\261\321\200\320\260\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\321\203 \321\202\320\260 \320\267\320\260\320\277\320\270\321\201\320\260\321\202\320\270 \320\271\320\276\320\263\320\276 \321\202\321\203\320\264\320\270"
                        ".</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_template->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Buffer", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_template->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_template->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_template->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_template->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Buffer", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_template->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Buffer", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_template->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_template->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_template->verticalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_template->verticalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Height", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_template->verticalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Buffer", nullptr));

        const bool __sortingEnabled1 = tableWidget_template->isSortingEnabled();
        tableWidget_template->setSortingEnabled(false);
        tableWidget_template->setSortingEnabled(__sortingEnabled1);

#if QT_CONFIG(whatsthis)
        tableWidget_template->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\241\321\205\320\265\320\274\320\260 \320\272\320\276\321\200\320\276\320\261\320\272\320\270</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\262\320\270\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \321\201\321\205\320\265\320\274\320\260 \321\200\320\276\320\267\320\263\320\276\321\200\321\202\320\272\320\270 \320\262\320\270\320\261\321\200\320\260\320\275\320\276\321\227 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\272\320\276\321\200\320\276\320\261\320\272\320\270. \320\241\321\205\320\265\320\274\320\260 \320\274\320\260\321\224 \320\277\321\200\320\276\320\277\320\276\321\200\321\206\321\226\320\271\320\275\321\226 \321\200\320\276\320\267\320\274\321\226\321\200\320\270, \320\272\320\276\320\273\321\226\321\200, \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\275\320\270\320\271 \320\264\320\276 \320\274\320\260\321\202"
                        "\320\265\321\200\321\226\320\260\320\273\321\203 \321\202\320\260 \320\267\320\260\320\277\320\270\321\201\320\260\320\275\321\203 \320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\272\320\276\321\200\320\276\320\261\320\276\320\272 \320\262 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\226 \320\262 \320\275\320\270\320\266\320\275\321\214\320\276\320\274\321\203 \320\277\321\200\320\260\320\262\320\276\320\274\321\203 \320\272\321\203\321\202\321\226.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        pushButton_add->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\224\320\276\320\264\320\260\320\262\320\260\320\275\320\275\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\224\320\276\320\264\320\260\321\224 \320\275\320\276\320\262\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267 \320\267\320\260\320\264\320\260\320\275\320\270\320\274\320\270 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260\320\274\320\270 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214. \320\243 \320\277\320\276\320\264\320\260\320\273\321\214\321\210\320\276\320\274\321\203 \320\274\320\276\320\266\320\265 \320\261\321\203\321\202\320\270 \321\200\320\265\320\264\320\260\320\263\320\276\320\262\320\260\320\275\320\265 \320\260\320\261\320\276 \320\262"
                        "\320\270\320\264\320\260\320\273\320\265\320\275\320\265.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_edit->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\240\320\265\320\264\320\260\320\263\321\203\321\224 \320\262\320\270\320\261\321\200\320\260\320\275\320\265 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217. \320\236\320\275\320\276\320\262\320\273\321\217\321\224 \320\264\320\260\320\275\321\226 \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\275\320\276 \320\264\320\276 \320\267\320\260\320\264\320\260\320\275\320\270\321\205 \320\275\320\276\320\262\320\270\321\205 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\226\320\262 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217.</span></"
                        "p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_edit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_delete->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\222\320\270\320\264\320\260\320\273\320\265\320\275\320\275\321\217 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\222\320\270\320\264\320\260\320\273\321\217\321\224 \320\262\320\270\320\261\321\200\320\260\320\275\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267 \321\202\320\260\320\261\320\273\320\270\321\206\321\226.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_prices->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\321\226\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_prices->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\320\246\321\226\320\275\320\260 \320\267\320\260 1 \320\274.\320\272\320\262.", nullptr));

        const bool __sortingEnabled2 = tableWidget_prices->isSortingEnabled();
        tableWidget_prices->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_prices->item(0, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\204\321\200\320\276\320\272\320\260\321\200\321\202\320\276\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_prices->item(0, 1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "0.99", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_prices->item(1, 0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\273\321\226\321\202\321\203\321\200\320\275\320\270\320\271 \320\272\320\260\321\200\321\202\320\276\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_prices->item(1, 1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "2.49", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_prices->item(2, 0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_prices->item(2, 1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "8.99", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_prices->item(3, 0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "\320\221\321\226\320\276\321\200\320\276\320\267\320\272\320\273\320\260\320\264\320\275\320\270\320\271 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_prices->item(3, 1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "3.99", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_prices->item(4, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\260\321\201\321\202\320\270\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_prices->item(4, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "1.79", nullptr));
        tableWidget_prices->setSortingEnabled(__sortingEnabled2);

#if QT_CONFIG(whatsthis)
        tableWidget_prices->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\242\320\260\320\261\320\273\320\270\321\206\321\217 \321\206\321\226\320\275</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\275\320\260\320\277\320\270\321\201\320\260\320\275\321\226 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\320\270, \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\275\321\226 \321\227\320\274 \320\272\320\276\320\273\321\214\320\276\321\200\320\270 \321\202\320\260 \321\206\321\226\320\275\320\270. \320\227\320\260 \320\264\320\276\320\277\320\276\320\274\320\276\320\263\320\276\321\216 \320\272\320\276\320\273\321\214\320\276\321\200\321\203 \320\274\320\276\320\266\320\275\320\260 \320\262\320\270\320\267\320\275\320\260\321\207\320\270\321\202\320\270 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273 \320\272\320\276\321\200\320\276\320\261\320\272\320\270 \320\275\320\260 \321\227\321\227 \321\201\321\205\320"
                        "\265\320\274\321\226, \321\211\320\276 \320\267\320\276\320\261\321\200\320\260\320\266\321\203\321\224\321\202\321\214\321\201\321\217 \321\201\320\277\321\200\320\260\320\262\320\260, \321\217\320\272 \321\202\321\226\320\273\321\214\320\272\320\270 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207 \320\262\320\270\320\261\320\265\321\200\320\265 \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\275\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226. \320\246\321\226\320\275\320\260 \320\272\320\276\321\200\320\276\320\261\320\272\320\270 \320\262\321\200\320\260\321\205\320\276\320\262\321\203\321\224\321\202\321\214\321\201\321\217 \320\277\321\226\320\264 \321\207\320\260\321\201 \320\276\320\261\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\217 \321\206\321\226\320\275\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275"
                        "\320\275\321\217 \321\202\320\260 \320\267\320\260\320\263\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\274\321\226\321\201\321\217\321\207\320\275\320\276\320\263\320\276 \320\264\320\276\321\205\320\276\320\264\321\203.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        pushButton_sort->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\232\320\275\320\276\320\277\320\272\320\260 \321\201\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\241\320\276\321\200\321\202\321\203\321\224 \321\202\320\260\320\261\320\273\320\270\321\206\321\216 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262 \321\226 \321\227\321\205 \321\206\321\226\320\275 \320\267\320\260 \320\267\321\200\320\276\321\201\321\202\320\260\320\275\320\275\321\217\320\274 \321\206\321\226\320\275\320\270.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_sort->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\321\201\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \321\206\321\226\320\275\320\270", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_income->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\234\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\264\320\276\321\205\321\226\320\264</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\240\320\260\321\205\321\203\321\224 \320\274\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\264\320\276\321\205\321\226\320\264, \320\262\320\262\320\260\320\266\320\260\321\216\321\207\320\270, \321\211\320\276 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\277\320\270\321\201\320\260\320\275\321\226 \320\262\321\201\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\267\320\260 \320\274\321\226\321\201\321\217\321\206\321\214. \320\222\321\200\320\260\321\205\320\276\320\262\321\203\321\224 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\320\276\321\201\321\202\321\226 \320\262\321\201\321\226\321\205 \320\267\320\260\320\274\320\276\320\262\320\273\320\265"
                        "\320\275\321\214 + 10% \320\264\320\276\321\205\320\276\320\264\321\203.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_income->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\205\321\203\320\262\320\260\321\202\320\270\n"
"\320\274\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\264\320\276\321\205\321\226\320\264", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_income->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\237\320\276\320\273\320\265 \320\262\320\270\320\262\320\276\320\264\321\203 \320\274\321\226\321\201\321\217\321\207\320\275\320\276\320\263\320\276 \320\264\320\276\321\205\320\276\320\264\321\203</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\262\320\270\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \320\262\320\270\321\200\320\260\321\205\321\203\320\262\320\260\320\275\320\270\320\271 \320\274\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\264\320\276\321\205\321\226\320\264 \320\267\320\260\320\273\320\265\320\266\320\275\320\276 \320\262\321\226\320\264 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_income->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_materialsCost->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\241\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\237\321\226\320\264\321\200\320\260\321\205\320\276\320\262\321\203\321\224 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262, \321\217\320\272\321\226 \320\262\320\270\321\202\321\200\320\260\321\207\320\265\320\275\321\226 \320\275\320\260 \320\262\320\270\320\264\321\226\320\273\320\265\320\275\320\265 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \320\262\321\200\320\260\321\205\320\276\320\262\321\203\321\216\321\207\320\270 \321\206\321\226\320\275\321"
                        "\203 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\203, \321\200\320\276\320\267\320\274\321\226\321\200\320\270 \321\226 \320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214.</span></p><p align=\"justify\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_materialsCost->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262\n"
"\320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_materialsCost->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\237\320\276\320\273\320\265 \320\262\320\270\320\262\320\276\320\264\321\203 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\320\276\321\201\321\202\321\226 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\262\320\270\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \320\277\321\226\320\264\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\260 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262 \320\262\320\270\320\261\321\200\320\260\320\275\320\276\320\263\320\276 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_materialsCost->setText(QString());
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_outcomes->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\202\321\200\320\260\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_outcomes->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "\320\262 \320\263\321\200\320\275", nullptr));

        const bool __sortingEnabled3 = tableWidget_outcomes->isSortingEnabled();
        tableWidget_outcomes->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_outcomes->item(0, 0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\321\203\320\275\320\260\320\273\321\214\320\275\321\226 \320\277\320\276\321\201\320\273\321\203\320\263\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_outcomes->item(0, 1);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "2500", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_outcomes->item(1, 0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\277\320\273\320\260\321\202a", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_outcomes->item(1, 1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_outcomes->item(2, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\260\321\202\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_outcomes->item(2, 1);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_outcomes->item(3, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 \320\276\320\261\320\273\320\260\320\264\320\275\320\260\320\275\320\275\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_outcomes->item(3, 1);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        tableWidget_outcomes->setSortingEnabled(__sortingEnabled3);

#if QT_CONFIG(whatsthis)
        tableWidget_outcomes->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\242\320\260\320\261\320\273\320\270\321\206\321\217 \320\262\320\270\321\202\321\200\320\260\321\202</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\262\320\270\320\262\320\276\320\264\321\217\321\202\321\214\321\201\321\217 \320\277\321\226\320\264\321\200\320\260\321\205\320\276\320\262\320\260\320\275\321\226 \320\262\320\270\321\202\321\200\320\260\321\202\320\270 \320\275\320\260 \320\272\320\276\320\274\321\203\320\275\320\260\320\273\321\214\320\275\321\226 \320\277\320\276\321\201\320\273\321\203\320\263\320\270, \320\267\320\260\321\200\320\277\320\273\320\260\321\202\321\203, \320\277\320\276\320\264\320\260\321\202\320\272\320\270, \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\216 \320\276\320\261\320\273\320\260\320\264\320\275\320\260\320\275\320\275\321\217.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        pushButton_outcomes->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\236\320\261\321\200\320\260\321\205\321\203\320\275\320\276\320\272 \320\262\320\270\321\202\321\200\320\260\321\202</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\237\321\226\320\264\321\200\320\260\321\205\320\276\320\262\321\203\321\224 \320\262\320\270\321\202\321\200\320\260\321\202\320\270 \320\275\320\260 \320\272\320\276\320\274\321\203\320\275\320\260\320\273\321\214\320\275\321\226 \320\277\320\276\321\201\320\273\321\203\320\263\320\270, \320\267\320\260\321\200\320\277\320\273\320\260\321\202\321\203, \320\277\320\276\320\264\320\260\321\202\320\272\320\270 \321\226 \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\216 \320\276\320\261\320\273\320\260\320\264\320\275\320\260\320\275\320\275\321\217 \320\267\320\260\320\273\320\265\320\266\320\275\320\276 \320\262\321\226\320\264 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\321\214 \321\226 \320\262"
                        "\320\270\320\262\320\276\320\264\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\270 \321\203 \320\262\321\226\320\264\320\277\320\276\320\262\321\226\320\264\320\275\321\203 \321\202\320\260\320\261\320\273\320\270\321\206\321\216.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_outcomes->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\200\320\260\321\205\321\203\320\262\320\260\321\202\320\270 \320\262\320\270\321\202\321\200\320\260\321\202\320\270", nullptr));
#if QT_CONFIG(whatsthis)
        checkBox->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\227\320\260\320\277\320\270\321\201 \320\276\320\261\321\207\320\270\321\201\320\273\320\265\320\275\321\214 \321\203 \321\204\320\260\320\271\320\273</span></p><p align=\"justify\">\320\222\320\270\320\261\320\265\321\200\321\226\321\202\321\214 \321\206\320\265\320\271 \320\277\321\200\320\260\320\277\320\276\321\200\320\265\321\206\321\214, \321\217\320\272\321\211\320\276 \320\261\320\260\320\266\320\260\321\224\321\202\320\265, \321\211\320\276\320\261 \320\276\320\261\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\217 (\320\262\320\273\320\260\321\201\320\275\320\260 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214, \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262  \321\226 \321\206\321\226\320\275\320\260 \320\272\320\276\320\266\320\275\320"
                        "\276\320\263\320\276 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \320\260 \321\202\320\260\320\272\320\276\320\266 \320\267\320\260\320\263\320\260\320\273\321\214\320\275\321\226 \320\262\320\270\321\202\321\200\320\260\321\202\320\270 \321\226 \320\272\321\226\320\275\321\206\320\265\320\262\320\270\320\271 \320\274\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\277\321\200\320\270\320\261\321\203\321\202\320\276\320\272) \321\202\320\260\320\272\320\276\320\266 \320\262\320\270\320\262\320\276\320\264\320\270\320\273\320\270\321\201\321\214 \321\203 \321\204\320\260\320\271\320\273.</p><p align=\"justify\">\320\222\321\201\321\226 \320\264\320\260\320\275\321\226 \320\277\321\200\320\276 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\262\320\270\320\262\320\276\320\264\321\217\321\202\321\214\321\201\321\217 \320\277\321\226\321\201\320\273\321\217 \320\271\320\276\320\263\320\276 \321\205\320\260\321\200\320\260\320\272"
                        "\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272: (\320\234 - \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262, \320\241 - \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \321\201\320\260\320\274\320\276\320\263\320\276 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \320\246 - \320\262\320\270\321\200\320\260\321\205\321\203\320\262\320\260\320\275\320\260 \321\206\321\226\320\275\320\260 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217 \320\264\320\273\321\217 \321\201\320\277\320\276\320\266\320\270\320\262\320\260\321\207\320\260). \320\227\320\260\320\263\320\260\320\273\321\214\320\275\321\226 \320\274\321\226\321\201\321\217\321\207\320\275\321\226 \320\276\320\261\321\200\320\260\321\205\321\203\320\275\320\272\320\270 \320\262\320\270\320\262\320"
                        "\276\320\264\321\217\321\202\321\214\321\201\321\217 \320\262 \320\272\321\226\320\275\321\206\321\226 \321\204\320\260\320\271\320\273\321\203.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201 \320\276\320\261\321\207\320\270\321\201\320\273\320\265\320\275\321\214\n"
"\321\203 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_cost->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\241\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\237\321\226\320\264\321\200\320\260\321\205\320\276\320\262\321\203\321\224 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217, \320\262\321\200\320\260\321\205\320\276\320\262\321\203\321\216\321\207\320\270 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\226\320\262 \321\226 \321\226\320\275\321\210\321\226 \320\262\320\270\321\202\321\200\320\260\321\202\320\270: \320\272\320\276\320\274\321\203\320\275\320\260\320\273\321\214\320\275\321\226 \320\277\320"
                        "\276\321\201\320\273\321\203\320\263\320\270, \320\267\320\260\321\200\320\277\320\273\320\260\321\202\321\203, \320\277\320\276\320\264\320\260\321\202\320\272\320\270, \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\216 \320\276\320\261\320\273\320\260\320\264\320\275\320\260\320\275\320\275\321\217.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_cost->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214\n"
"\320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_cost->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">\320\237\320\276\320\273\320\265 \320\262\320\270\320\262\320\276\320\264\321\203 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\320\276\321\201\321\202\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217</span></p><p align=\"justify\"><span style=\" font-size:10pt;\">\320\242\321\203\321\202 \320\262\320\270\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \320\277\321\226\320\264\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\260 \321\201\320\276\320\261\321\226\320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214 \320\262\320\270\320\261\321\200\320\260\320\275\320\276\320\263\320\276 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_cost->setText(QString());
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\274\320\276\320\263\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
