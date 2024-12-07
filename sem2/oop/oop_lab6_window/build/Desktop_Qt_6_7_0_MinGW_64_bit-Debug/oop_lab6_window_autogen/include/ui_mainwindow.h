/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRaead;
    QAction *actionWrite;
    QAction *actionFill;
    QAction *actionGetValue;
    QAction *actionClear;
    QAction *actionExit;
    QAction *actionSetValue;
    QAction *actionRead;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QFrame *frame;
    QLabel *labelSize;
    QPushButton *pushButtonFill;
    QLabel *labelI;
    QLabel *labelJ;
    QPushButton *pushButtonSetValue;
    QPushButton *pushButtonGetValue;
    QLabel *labelCurrent;
    QLabel *labelNew;
    QLineEdit *lineEditCurrent;
    QSpinBox *spinBoxSize;
    QSpinBox *spinBoxI;
    QSpinBox *spinBoxJ;
    QSpinBox *spinBoxNew;
    QPushButton *pushButtonClear;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuRead;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(763, 394);
        MainWindow->setMinimumSize(QSize(450, 345));
        MainWindow->setMaximumSize(QSize(1200, 800));
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        actionRaead = new QAction(MainWindow);
        actionRaead->setObjectName("actionRaead");
        actionRaead->setCheckable(true);
        actionWrite = new QAction(MainWindow);
        actionWrite->setObjectName("actionWrite");
        actionWrite->setCheckable(false);
        actionFill = new QAction(MainWindow);
        actionFill->setObjectName("actionFill");
        actionGetValue = new QAction(MainWindow);
        actionGetValue->setObjectName("actionGetValue");
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setCheckable(false);
        actionSetValue = new QAction(MainWindow);
        actionSetValue->setObjectName("actionSetValue");
        actionRead = new QAction(MainWindow);
        actionRead->setObjectName("actionRead");
        actionRead->setCheckable(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(100, 100));
        tableWidget->setMaximumSize(QSize(1000, 1000));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift SemiBold")});
        font.setPointSize(12);
        font.setBold(true);
        tableWidget->setFont(font);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setGridStyle(Qt::NoPen);

        horizontalLayout->addWidget(tableWidget);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(200, 280));
        frame->setMaximumSize(QSize(200, 280));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelSize = new QLabel(frame);
        labelSize->setObjectName("labelSize");
        labelSize->setGeometry(QRect(10, 20, 31, 21));
        labelSize->setFont(font);
        pushButtonFill = new QPushButton(frame);
        pushButtonFill->setObjectName("pushButtonFill");
        pushButtonFill->setGeometry(QRect(119, 10, 71, 31));
        pushButtonFill->setFont(font);
        labelI = new QLabel(frame);
        labelI->setObjectName("labelI");
        labelI->setGeometry(QRect(10, 120, 31, 16));
        labelI->setFont(font);
        labelJ = new QLabel(frame);
        labelJ->setObjectName("labelJ");
        labelJ->setGeometry(QRect(110, 120, 31, 16));
        labelJ->setFont(font);
        pushButtonSetValue = new QPushButton(frame);
        pushButtonSetValue->setObjectName("pushButtonSetValue");
        pushButtonSetValue->setGeometry(QRect(10, 230, 81, 31));
        pushButtonSetValue->setFont(font);
        pushButtonGetValue = new QPushButton(frame);
        pushButtonGetValue->setObjectName("pushButtonGetValue");
        pushButtonGetValue->setGeometry(QRect(110, 230, 81, 31));
        pushButtonGetValue->setFont(font);
        labelCurrent = new QLabel(frame);
        labelCurrent->setObjectName("labelCurrent");
        labelCurrent->setGeometry(QRect(10, 160, 61, 16));
        labelCurrent->setFont(font);
        labelNew = new QLabel(frame);
        labelNew->setObjectName("labelNew");
        labelNew->setGeometry(QRect(10, 200, 51, 16));
        labelNew->setFont(font);
        lineEditCurrent = new QLineEdit(frame);
        lineEditCurrent->setObjectName("lineEditCurrent");
        lineEditCurrent->setEnabled(true);
        lineEditCurrent->setGeometry(QRect(80, 150, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift SemiBold")});
        font1.setPointSize(14);
        font1.setBold(true);
        lineEditCurrent->setFont(font1);
        lineEditCurrent->setMaxLength(7);
        lineEditCurrent->setFrame(true);
        lineEditCurrent->setReadOnly(true);
        spinBoxSize = new QSpinBox(frame);
        spinBoxSize->setObjectName("spinBoxSize");
        spinBoxSize->setGeometry(QRect(50, 10, 61, 41));
        spinBoxSize->setFont(font);
        spinBoxSize->setWrapping(false);
        spinBoxSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxSize->setMinimum(1);
        spinBoxSize->setValue(1);
        spinBoxI = new QSpinBox(frame);
        spinBoxI->setObjectName("spinBoxI");
        spinBoxI->setGeometry(QRect(40, 110, 51, 31));
        spinBoxI->setFont(font);
        spinBoxI->setWrapping(false);
        spinBoxI->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxI->setMinimum(1);
        spinBoxI->setValue(1);
        spinBoxJ = new QSpinBox(frame);
        spinBoxJ->setObjectName("spinBoxJ");
        spinBoxJ->setGeometry(QRect(140, 110, 51, 31));
        spinBoxJ->setFont(font);
        spinBoxJ->setWrapping(false);
        spinBoxJ->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxJ->setMinimum(1);
        spinBoxJ->setValue(1);
        spinBoxNew = new QSpinBox(frame);
        spinBoxNew->setObjectName("spinBoxNew");
        spinBoxNew->setGeometry(QRect(80, 190, 111, 31));
        spinBoxNew->setFont(font);
        spinBoxNew->setWrapping(false);
        spinBoxNew->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBoxNew->setMinimum(-1000000);
        spinBoxNew->setMaximum(1000000);
        spinBoxNew->setSingleStep(1);
        spinBoxNew->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinBoxNew->setValue(1);
        pushButtonClear = new QPushButton(frame);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setGeometry(QRect(120, 50, 71, 31));
        pushButtonClear->setFont(font);

        horizontalLayout->addWidget(frame, 0, Qt::AlignTop);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 763, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuRead = new QMenu(menubar);
        menuRead->setObjectName("menuRead");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuRead->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionRead);
        menuFile->addAction(actionWrite);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuRead->addAction(actionFill);
        menuRead->addAction(actionGetValue);
        menuRead->addAction(actionSetValue);
        menuRead->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRaead->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
#if QT_CONFIG(shortcut)
        actionRaead->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWrite->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
#if QT_CONFIG(shortcut)
        actionWrite->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFill->setText(QCoreApplication::translate("MainWindow", "Fill", nullptr));
        actionFill->setIconText(QCoreApplication::translate("MainWindow", "Fill", nullptr));
#if QT_CONFIG(shortcut)
        actionFill->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGetValue->setText(QCoreApplication::translate("MainWindow", "Get value", nullptr));
#if QT_CONFIG(shortcut)
        actionGetValue->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSetValue->setText(QCoreApplication::translate("MainWindow", "Set value", nullptr));
#if QT_CONFIG(shortcut)
        actionSetValue->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRead->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
#if QT_CONFIG(shortcut)
        actionRead->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        labelSize->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        pushButtonFill->setText(QCoreApplication::translate("MainWindow", "Fill", nullptr));
        labelI->setText(QCoreApplication::translate("MainWindow", "row", nullptr));
        labelJ->setText(QCoreApplication::translate("MainWindow", "col", nullptr));
        pushButtonSetValue->setText(QCoreApplication::translate("MainWindow", "Set value", nullptr));
        pushButtonGetValue->setText(QCoreApplication::translate("MainWindow", "Get Value", nullptr));
        labelCurrent->setText(QCoreApplication::translate("MainWindow", "Current", nullptr));
        labelNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuRead->setTitle(QCoreApplication::translate("MainWindow", "Table", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
