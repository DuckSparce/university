/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QPushButton *pushButton_cancel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_accept;
    QSpinBox *spinBox_length;
    QSpinBox *spinBox_width;
    QSpinBox *spinBox_height;
    QSpinBox *spinBox_count;
    QComboBox *comboBox_material;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName("AddDialog");
        AddDialog->resize(300, 350);
        AddDialog->setMinimumSize(QSize(300, 350));
        AddDialog->setMaximumSize(QSize(300, 350));
        pushButton_cancel = new QPushButton(AddDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(170, 300, 111, 31));
        label = new QLabel(AddDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 81, 21));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(AddDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 81, 21));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_3 = new QLabel(AddDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 81, 21));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(AddDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 180, 81, 21));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_5 = new QLabel(AddDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 230, 81, 21));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        pushButton_accept = new QPushButton(AddDialog);
        pushButton_accept->setObjectName("pushButton_accept");
        pushButton_accept->setGeometry(QRect(20, 300, 111, 31));
        spinBox_length = new QSpinBox(AddDialog);
        spinBox_length->setObjectName("spinBox_length");
        spinBox_length->setGeometry(QRect(110, 30, 170, 25));
        QFont font;
        font.setStyleStrategy(QFont::NoAntialias);
        spinBox_length->setFont(font);
        spinBox_length->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        spinBox_length->setAccelerated(true);
        spinBox_length->setMinimum(10);
        spinBox_length->setMaximum(150);
        spinBox_length->setValue(100);
        spinBox_width = new QSpinBox(AddDialog);
        spinBox_width->setObjectName("spinBox_width");
        spinBox_width->setGeometry(QRect(110, 80, 170, 25));
        spinBox_width->setFont(font);
        spinBox_width->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        spinBox_width->setAccelerated(true);
        spinBox_width->setMinimum(10);
        spinBox_width->setMaximum(150);
        spinBox_width->setValue(100);
        spinBox_height = new QSpinBox(AddDialog);
        spinBox_height->setObjectName("spinBox_height");
        spinBox_height->setGeometry(QRect(110, 130, 170, 25));
        spinBox_height->setFont(font);
        spinBox_height->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        spinBox_height->setAccelerated(true);
        spinBox_height->setMinimum(10);
        spinBox_height->setMaximum(150);
        spinBox_height->setValue(100);
        spinBox_count = new QSpinBox(AddDialog);
        spinBox_count->setObjectName("spinBox_count");
        spinBox_count->setGeometry(QRect(110, 230, 171, 25));
        spinBox_count->setFont(font);
        spinBox_count->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        spinBox_count->setAccelerated(true);
        spinBox_count->setMinimum(1);
        spinBox_count->setMaximum(1000);
        spinBox_count->setValue(1);
        comboBox_material = new QComboBox(AddDialog);
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->addItem(QString());
        comboBox_material->setObjectName("comboBox_material");
        comboBox_material->setGeometry(QRect(110, 180, 171, 24));

        retranslateUi(AddDialog);

        pushButton_accept->setDefault(true);


        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QCoreApplication::translate("AddDialog", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("AddDialog", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("AddDialog", "\320\224\320\276\320\262\320\266\320\270\320\275\320\260 (\321\201\320\274)", nullptr));
        label_2->setText(QCoreApplication::translate("AddDialog", "\320\250\320\270\321\200\320\270\320\275\320\260 (\321\201\320\274)", nullptr));
        label_3->setText(QCoreApplication::translate("AddDialog", "\320\222\320\270\321\201\320\276\321\202\320\260 (\321\201\320\274)", nullptr));
        label_4->setText(QCoreApplication::translate("AddDialog", "\320\234\320\260\321\202\320\265\321\200\321\226\320\260\320\273", nullptr));
        label_5->setText(QCoreApplication::translate("AddDialog", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("AddDialog", "\320\237\321\200\320\270\320\271\320\275\321\217\321\202\320\270", nullptr));
        comboBox_material->setItemText(0, QCoreApplication::translate("AddDialog", "<\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273>", nullptr));
        comboBox_material->setItemText(1, QCoreApplication::translate("AddDialog", "\320\223\320\276\321\204\321\200\320\276\320\272\320\260\321\200\321\202\320\276\320\275", nullptr));
        comboBox_material->setItemText(2, QCoreApplication::translate("AddDialog", "\320\237\320\260\320\273\321\226\321\202\321\203\321\200\320\275\320\270\320\271 \320\272\320\260\321\200\321\202\320\276\320\275", nullptr));
        comboBox_material->setItemText(3, QCoreApplication::translate("AddDialog", "\320\224\320\265\321\200\320\265\320\262\320\270\320\275\320\260", nullptr));
        comboBox_material->setItemText(4, QCoreApplication::translate("AddDialog", "\320\221\321\226\320\276\321\200\320\276\320\267\320\272\320\273\320\260\320\264\320\275\320\270\320\271 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273", nullptr));
        comboBox_material->setItemText(5, QCoreApplication::translate("AddDialog", "\320\237\320\273\320\260\321\201\321\202\320\270\320\272", nullptr));

        comboBox_material->setCurrentText(QCoreApplication::translate("AddDialog", "<\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
