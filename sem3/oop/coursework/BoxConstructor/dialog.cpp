#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"
#include "order.h"
#include "exceptions.h"


#include <QGridLayout>
#include <QMessageBox>
#include <QSpacerItem>
#include <QTableWidget>

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    QString styleSheet = QString(R"(
        QDialog {
            background-color: #FFFFFF;
            color: #222222;
        }

        QLabel {
            color: #222222;
        }

        QSpinBox {
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #CACACA;
            border-radius: 5px;
            padding: 2px 5px;
            font-size: 14px;
        }

        QComboBox {
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #CACACA;
            border-radius: 5px;
            padding: 2px 5px;
            font-size: 14px;
        }

        QComboBox QAbstractItemView {
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #CACACA;
            border-radius: 5px;
            padding: 2px 5px;
            font-size: 14px;
        }

        QComboBox QAbstractItemView::item:selected {
            background-color: #AAAAAA;
            color: #222222;
        }

        QComboBox QAbstractItemView::item:hover {
            background-color: #CACACA;
            color: #222222;
        }

        QPushButton {
            background-color: #E5E5E5;
            border: 1px solid #CACACA;
            border-radius: 5px;
            font-size: 12px;
            color: #222222;
            font-weight: bold;
        }

        QPushButton:hover {
            background-color: #CACACA;
        }

        QPushButton:pressed {
            background-color: #AAAAAA;
        }
    )");
    this->setStyleSheet(styleSheet);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_cancel_clicked() {
    reject();
}

void AddDialog::on_pushButton_accept_clicked() {
    length = ui->spinBox_length->value();
    width = ui->spinBox_width->value();
    height = ui->spinBox_height->value();
    count = ui->spinBox_count->value();

    try {
        deduceMaterial();
        accept();
    } catch (InvalidMaterialException exc) {
        MainWindow::showErrorMessage(exc.what());
        reject();
    }
}

void AddDialog::deduceMaterial() {
    switch (ui->comboBox_material->currentIndex()) {
    case 1: material = CorrugatedCardboard; break;
    case 2: material = SolidCardboard; break;
    case 3: material = Wood; break;
    case 4: material = Biodegradable; break;
    case 5: material = Plastic; break;
    default: material = Undefined;
    }

    if (material == Undefined) {
        throw InvalidMaterialException("Ви повинні обрати матеріал.");
    }
}

void AddDialog::fillForOrder(Order* order) {
    ui->spinBox_length->setValue(order->getLength());
    ui->spinBox_width->setValue(order->getWidth());
    ui->spinBox_height->setValue(order->getHeight());
    ui->comboBox_material->setCurrentIndex(order->getMaterial());
    ui->spinBox_count->setValue(order->getCount());
}

unsigned int AddDialog::getLength() const {
    return length;
}

unsigned int AddDialog::getWidth() const {
    return width;
}

unsigned int AddDialog::getHeight() const {
    return height;
}

unsigned int AddDialog::getCount() const {
    return count;
}

Material AddDialog::getMaterial() const {
    return material;
}
