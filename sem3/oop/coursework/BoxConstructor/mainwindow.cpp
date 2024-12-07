#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "dialog.h"
#include "exceptions.h"
#include "order.h"
#include <fstream>

#include <QDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QWhatsThis>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , beingSorted(false) {
    materials = { CorrugatedCardboard, SolidCardboard, Wood, Biodegradable, Plastic };
    ui->setupUi(this);

    QString styleSheet = QString(R"(
        QMainWindow {
            background-color: #FFFFFF;
            color: #222222;
        }

        QCheckBox {
            color: #222222;
            spacing: 10px;
        }

        QCheckBox::indicator {
            width: 25px;
            height: 25px;
            border: 2px solid #555;
            background-color: #ccc;
            border-radius: 3px;
        }

        QCheckBox::indicator:unchecked {
            border: 2px solid #555;
            background-color: #FFFFFF;
        }

        QCheckBox::indicator:checked {
            border: 2px solid #555;
            background-color: #559955;
        }

        QLineEdit {
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #CACACA;
            border-radius: 1px;
        }

        QPushButton {
            background-color: #E5E5E5;
            border: 1px solid #CACACA;
            border-radius: 5px;
            padding: 2px 5px;
            font-size: 14px;
            color: #222222;
            font-weight: bold;
        }

        QPushButton:hover {
            background-color: #CACACA;
        }

        QPushButton:pressed {
            background-color: #AAAAAA;
        }

        QMenuBar {
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #CACACA;
        }

        QMenuBar::item:hover {
            background-color: #CACACA;
        }

        QMenuBar::item:selected {
            background-color: #AAAAAA;
        }

        QMenu {
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #CACACA;
        }

        QMenu::item:hover {
            background-color: #CACACA;
        }

        QMenu::item:selected {
            background-color: #AAAAAA;
        }

        QTableWidget {
            gridline-color: #CACACA;
            background-color: #E5E5E5;
            color: #222222;
            border: 1px solid #AAAAAA;
        }

        QTableWidget::item:selected {
            background-color: #CACACA;
            color: #222222;
        }

        QHeaderView {
            background-color: #CACACA;
            font-weight: bold;
            color: #222222;
        }

        QTableCornerButton::section {
            background-color: #CACACA;
            font-weight: bold;
            color: #222222;
        }
    )");
    this->setStyleSheet(styleSheet);

    setupOrders();
    setupPrices();
    ui->tableWidget_template->hide();

    connect(ui->action_exit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_clearData, &QAction::triggered, this, &MainWindow::clearRecord);
    connect(ui->action_fileInput, &QAction::triggered, this, &MainWindow::inputFromFile);
    connect(ui->action_fileOutput, &QAction::triggered, this, &MainWindow::outputToFile);
    connect(ui->action_add, &QAction::triggered, this, &MainWindow::on_pushButton_add_clicked);
    connect(ui->action_edit, &QAction::triggered, this, &MainWindow::on_pushButton_edit_clicked);
    connect(ui->action_delete, &QAction::triggered, this, &MainWindow::on_pushButton_delete_clicked);
    connect(ui->action_cost, &QAction::triggered, this, &MainWindow::on_pushButton_cost_clicked);
    connect(ui->action_whatsThis, &QAction::triggered, this, &QWhatsThis::enterWhatsThisMode);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showErrorMessage(const char *msg) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Помилка!");
    msgBox.setInformativeText(msg);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)msgBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

    QString styleSheet = QString(R"(
        QMessageBox {
            background-color: #FFFFFF;
            color: #222222;
        }

        QLabel {
            background-color: #FFFFFF;
            color: #222222;
        }

        QPushButton {
            background-color: #E5E5E5;
            border: 1px solid #CACACA;
            border-radius: 5px;
            padding: 2px 5px;
            color: #222222;
        }

        QPushButton:hover {
            background-color: #CACACA;
        }

        QPushButton:pressed {
            background-color: #AAAAAA;
        }
    )");
    msgBox.setStyleSheet(styleSheet);

    msgBox.exec();
}

void MainWindow::setupOrders() {
    ui->tableWidget_orders->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget_orders->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget_orders->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget_orders->verticalHeader()->setFixedWidth(50);

    unsigned int columnsCount = ui->tableWidget_orders->columnCount();
    unsigned int columnWidth = (ui->tableWidget_orders->width() - 50) / columnsCount;

    for (unsigned int i = 0; i < 3; i++) {
        ui->tableWidget_orders->setColumnWidth(i, columnWidth);
    }

    ui->tableWidget_orders->setSpan(0, 0, 3, 1);
    ui->tableWidget_orders->item(0, 0)->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget_orders->setRowCount(0);

    monthlyRecord = new MonthlyRecord();
}

void MainWindow::setupPrices() {
    ui->tableWidget_prices->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_prices->resizeRowsToContents();
}


int MainWindow::getCurrentRow() {
    int row = ui->tableWidget_orders->currentRow();

    if (row == -1) {
        throw NoSelectedException("Щоб працювати з замовленням, ви повинні обрати рядок в таблиці.");
    }

    return row;
}

void MainWindow::setTemplateColor(unsigned int color) {
    ui->tableWidget_template->item(2, 1)->setBackground(QBrush(QColor(color)));
    ui->tableWidget_template->item(1, 2)->setBackground(QBrush(QColor(color)));
    ui->tableWidget_template->item(2, 2)->setBackground(QBrush(QColor(color)));
    ui->tableWidget_template->item(3, 2)->setBackground(QBrush(QColor(color)));
    ui->tableWidget_template->item(4, 2)->setBackground(QBrush(QColor(color)));
    ui->tableWidget_template->item(2, 3)->setBackground(QBrush(QColor(color)));
}

void MainWindow::addOrderToTable(Order* order) {
    QTableWidget* table = ui->tableWidget_orders;
    int rowCount = table->rowCount();
    table->insertRow(rowCount);

    QString str = QString::number(order->getLength()) + 'x' +
                  QString::number(order->getWidth()) + 'x' +
                  QString::number(order->getHeight());
    table->setItem(rowCount, 0, new QTableWidgetItem(str));

    switch (order->getMaterial()) {
    case CorrugatedCardboard: str = "Гофрокартон"; break;
    case SolidCardboard: str = "Палітурний картон"; break;
    case Wood: str = "Деревина"; break;
    case Biodegradable: str = "Біорозкладний матеріал"; break;
    case Plastic: str = "Пластик"; break;
    default: throw InvalidMaterialException("Матеріал коробки невизначений.");
    }

    table->setItem(rowCount, 1, new QTableWidgetItem(str));
    table->setItem(rowCount, 2, new QTableWidgetItem(QString::number(order->getCount())));
}

void MainWindow::clearRecord() {
    ui->tableWidget_orders->setRowCount(0);
    monthlyRecord->clearRecord();

    ui->lineEdit_income->clear();
    ui->lineEdit_cost->clear();
    ui->lineEdit_materialsCost->clear();
    ui->tableWidget_orders->clearSelection();

    ui->tableWidget_outcomes->setItem(0, 1, new QTableWidgetItem("2500"));
    ui->tableWidget_outcomes->setItem(1, 1, new QTableWidgetItem("0"));
    ui->tableWidget_outcomes->setItem(2, 1, new QTableWidgetItem("0"));
    ui->tableWidget_outcomes->setItem(3, 1, new QTableWidgetItem("0"));

    ui->tableWidget_template->hide();
}

void MainWindow::on_pushButton_add_clicked() {
    AddDialog dialog(this);
    int result = dialog.exec();

    if (result == QDialog::Accepted) {
        Order* order = new Order(dialog.getLength(),
                                 dialog.getWidth(),
                                 dialog.getHeight(),
                                 dialog.getMaterial(),
                                 dialog.getCount());

        addOrderToTable(order);
        monthlyRecord->addOrder(order);

        ui->lineEdit_income->clear();
    }

    ui->lineEdit_income->clear();
    ui->tableWidget_orders->clearSelection();
}

void MainWindow::on_pushButton_edit_clicked() {
    QTableWidget* table = ui->tableWidget_orders;
    int row;

    try {
        row = getCurrentRow();
    } catch (NoSelectedException exc) {
        MainWindow::showErrorMessage(exc.what());
        return;
    }

    AddDialog dialog(this);
    dialog.fillForOrder(monthlyRecord->getOrder(row));
    dialog.setWindowTitle("Редагувати замовлення");
    int result = dialog.exec();

    if (result == QDialog::Accepted) {
        Order* order = monthlyRecord->getOrder(row);
        order->setLength(dialog.getLength());
        order->setWidth(dialog.getWidth());
        order->setHeight(dialog.getHeight());
        order->setMaterial(dialog.getMaterial());
        order->setCount(dialog.getCount());

        QString str = QString::number(dialog.getLength()) + 'x' +
                      QString::number(dialog.getWidth()) + 'x' +
                      QString::number(dialog.getHeight());
        table->setItem(row, 0, new QTableWidgetItem(str));

        str = QString::fromStdString(materialToString(dialog.getMaterial()));

        table->setItem(row, 1, new QTableWidgetItem(str));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(dialog.getCount())));

        ui->lineEdit_income->clear();
    }

    ui->lineEdit_income->clear();
    ui->tableWidget_orders->clearSelection();
}

void MainWindow::on_pushButton_delete_clicked() {
    QTableWidget* table = ui->tableWidget_orders;
    int row;

    try {
        row = getCurrentRow();
    } catch (NoSelectedException exc) {
        MainWindow::showErrorMessage(exc.what());
        return;
    }

    table->removeRow(row);
    monthlyRecord->removeOrder(row);

    ui->lineEdit_income->clear();
    ui->tableWidget_orders->clearSelection();
}

void MainWindow::on_tableWidget_orders_cellClicked(int row, int column) {
    QTableWidget* templ = ui->tableWidget_template;
    templ->show();
    Order* order = monthlyRecord->getOrder(row);

    switch (order->getMaterial()) {
    case CorrugatedCardboard: setTemplateColor(0xdaac40); break;
    case SolidCardboard: setTemplateColor(0xda6a44); break;
    case Wood: setTemplateColor(0x916c41); break;
    case Biodegradable: setTemplateColor(0xd6d859); break;
    case Plastic: setTemplateColor(0x8cb36e); break;
    default: throw InvalidMaterialException("Матеріал коробки невизначений.");
    }

    QTableWidgetItem *countItem = new QTableWidgetItem("x" + QString::number(order->getCount()));
    countItem->setTextAlignment(Qt::AlignBottom | Qt::AlignRight);
    QFont font = countItem->font();
    font.setPointSize(28);
    countItem->setFont(font);
    templ->setItem(5, 4, countItem);

    templ->setRowHeight(1, order->getHeight());
    templ->setRowHeight(3, order->getHeight());
    templ->setColumnWidth(1, order->getHeight());
    templ->setColumnWidth(3, order->getHeight());

    templ->setRowHeight(2, order->getLength());
    templ->setRowHeight(4, order->getLength());

    templ->setColumnWidth(2, order->getWidth());

    int bufferHeight = (templ->height() - templ->rowHeight(1) * 2 - templ->rowHeight(2) * 2) / 2;
    int bufferWidth = (templ->width() - templ->columnWidth(1) * 2 - templ->columnWidth(2)) / 2;
    templ->setColumnWidth(0, bufferWidth);
    templ->setColumnWidth(4, bufferWidth);
    templ->setRowHeight(0, bufferHeight);
    templ->setRowHeight(5, bufferHeight);
}

void MainWindow::on_pushButton_sort_clicked() {
    beingSorted = true;
    QTableWidget* table = ui->tableWidget_prices;
    int size = table->rowCount();

    if (size == 0 || size == 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        int min = i;

        for (int j = i + 1; j < size; j++) {
            if (table->item(j, 1)->data(Qt::DisplayRole).toDouble() < table->item(min, 1)->data(Qt::DisplayRole).toDouble()) {
                min = j;
            }
        }

        if (i == min) {
            continue;
        }

        for (int column = 0; column < table->columnCount(); ++column) {
            QTableWidgetItem* item1 = table->takeItem(i, column);
            QTableWidgetItem* item2 = table->takeItem(min, column);

            table->setItem(i, column, item2);
            table->setItem(min, column, item1);
        }

        Material temp = materials[i];
        materials[i] = materials[min];
        materials[min] = temp;
    }

    beingSorted = false;
    ui->tableWidget_orders->clearSelection();
}

void MainWindow::inputFromFile() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Обрати файл", "../..", "Text Files (*.txt);;All Files (*)");

    std::ifstream file(fileName.toStdString());

    if (file.is_open()) {
        try {
            monthlyRecord->calculateOutcomes();
            monthlyRecord->getIncome();
            file >> *monthlyRecord;
            ui->tableWidget_orders->setRowCount(0);

            for (Order* order : monthlyRecord->getOrders()) {
                addOrderToTable(order);
            }

            ui->lineEdit_income->clear();
        } catch (WrongFormatException& exc) {
            MainWindow::showErrorMessage(exc.what());
        }
    } else {
        MainWindow::showErrorMessage("Не вдалося відкрити файл.");
    }

    ui->lineEdit_income->clear();
    ui->tableWidget_orders->clearSelection();
}

void MainWindow::outputToFile() {
    if (ui->tableWidget_orders->rowCount() == 0) {
        showErrorMessage("Неможливо записати пусту таблицю в файл.");
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Обрати файл", "../..", "Text Files (*.txt);;All Files (*)");
    std::ofstream file(fileName.toStdString(), std::ios::trunc);

    if (file.is_open()) {
        monthlyRecord->setOutputCalculations(ui->checkBox->isChecked());
        monthlyRecord->getIncome();
        file << *monthlyRecord;

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Успіх!");
        msgBox.setInformativeText("Дані успішно записано у файл " + fileName);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        QSpacerItem* horizontalSpacer = new QSpacerItem(300, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        QGridLayout* layout = (QGridLayout*)msgBox.layout();
        layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
        msgBox.exec();
    } else {
        MainWindow::showErrorMessage("Не вдалося відкрити файл.");
    }

    ui->tableWidget_orders->clearSelection();
}

void MainWindow::on_pushButton_income_clicked() {
    ui->lineEdit_income->setText(QString::number(monthlyRecord->getIncome()) + " грн");
}

void MainWindow::on_pushButton_materialsCost_clicked() {
    int row;

    try {
        row = getCurrentRow();
    } catch (NoSelectedException exc) {
        MainWindow::showErrorMessage(exc.what());
        return;
    }

    ui->lineEdit_materialsCost->setText(QString::number(monthlyRecord->getOrder(row)->getMaterialCost()) + " грн");
}

void MainWindow::on_pushButton_cost_clicked() {
    int row;

    try {
        row = getCurrentRow();
    } catch (NoSelectedException exc) {
        MainWindow::showErrorMessage(exc.what());
        return;
    }

    ui->lineEdit_cost->setText(QString::number(monthlyRecord->getOrder(row)->getCost()) + " грн");
}

void MainWindow::on_tableWidget_prices_itemChanged(QTableWidgetItem *item) {
    if (beingSorted) {
        return;
    }

    bool ok = false;
    double newPrice = item->text().toDouble(&ok);

    if (!ok) {
        item->setText(QString::number(Order::getPrice(materials[item->row()])));
        showErrorMessage("Неправильний формат вводу ціни, введіть будь ласка десятковий дріб.");
        return;
    }

    newPrice = std::round(newPrice * 100.0) / 100.0;
    item->setText(QString::number(newPrice));
    Order::setPrice(materials[item->row()], newPrice);
    ui->tableWidget_orders->clearSelection();
}


void MainWindow::on_pushButton_outcomes_clicked() {
    monthlyRecord->calculateOutcomes();
    ui->tableWidget_outcomes->setItem(0, 1, new QTableWidgetItem(QString::number(monthlyRecord->getCommunalServices())));
    ui->tableWidget_outcomes->setItem(1, 1, new QTableWidgetItem(QString::number(monthlyRecord->getSalaries())));
    ui->tableWidget_outcomes->setItem(2, 1, new QTableWidgetItem(QString::number(monthlyRecord->getTax())));
    ui->tableWidget_outcomes->setItem(3, 1, new QTableWidgetItem(QString::number(monthlyRecord->getAmortization())));
}


