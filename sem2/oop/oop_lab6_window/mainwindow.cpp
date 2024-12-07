#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QShortcut>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonFill_clicked() {
    ui->tableWidget->clear();

    int size = ui->spinBoxSize->value();
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(size);

    int cellHeight = (ui->tableWidget->height()/size)-5;
    int cellWidth = (ui->tableWidget->width()/size)-5;

    for (int i = 0; i < size*size; ++i) {
        ui->tableWidget->setRowHeight(i, cellHeight);
        ui->tableWidget->setColumnWidth(i, cellWidth);
    }

    // Fill cells
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            QTableWidgetItem * item = new QTableWidgetItem(col % 2 == 0 ? "1" : "0");
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row, col, item);
        }
    }
}


void MainWindow::on_pushButtonClear_clicked() {
    ui->tableWidget->clear();
}


void MainWindow::on_pushButtonGetValue_clicked() {
    int row = ui->spinBoxI->value() - 1;
    int col = ui->spinBoxJ->value() - 1;

    if (row > ui->tableWidget->columnCount() || col > ui->tableWidget->rowCount()) {
        QMessageBox::warning(this, "Warning", "Index is out of range.");
        ui->lineEditCurrent->setText("-");
    } else {
        QTableWidgetItem* item = ui->tableWidget->item(row, col);
        if (item == nullptr) {
            QMessageBox::warning(this, "Warning", "The cell is empty.");
            ui->lineEditCurrent->setText("-");
        } else {
            ui->lineEditCurrent->setText(item->text());
        }
    }
}


void MainWindow::on_pushButtonSetValue_clicked() {
    int row = ui->spinBoxI->value() - 1;
    int col = ui->spinBoxJ->value() - 1;

    int newValue = ui->spinBoxNew->value();
    if (row > ui->tableWidget->columnCount() || col > ui->tableWidget->rowCount()) {
        QMessageBox::warning(this, "Warning", "Index is out of range.");
    } else {
        QTableWidgetItem * item = new QTableWidgetItem(QString::number(newValue));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, col, item);
    }
}


void MainWindow::on_actionRead_triggered() {
    QFile file(MainWindow::chooseFile());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file";
        QMessageBox::warning(this, "Warning", "Failed to open the file.");
        return;
    }

    QTextStream in(&file);
    bool check = false;

    // Read matrix size
    QString sizeStr = in.readLine();

    if (sizeStr == nullptr) {
        file.close();
        QMessageBox::warning(this, "Error", "The table size is smaller than declared. The process failed.");
        return;
    }

    int size = sizeStr.toInt(&check, 10);

    if (!check || size > 100 || size < 1) {
        QMessageBox::warning(this, "Warning", "The table size must be an integer between 1 and 99.");
        return;
    }

    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(size);

    int cellSize = ui->tableWidget->height() / size - 5;

    for (int i = 0; i < size; ++i) {
        ui->tableWidget->setRowHeight(i, cellSize);
        ui->tableWidget->setColumnWidth(i, cellSize);
    }

    // Fill the table
    for (int i = 0; i < size; ++i) {
        QString data = in.readLine();

        if (data == nullptr) {
            file.close();
            emergencyExit("The table size is smaller than declared. The process failed.");
            return;
        }

        QStringList row = data.split(" ");

        if (row.size() < size) {
            file.close();
            emergencyExit("The table size is smaller than declared. The process failed.");
            return;
        }

        for (int j = 0; j < size; ++j) {
            if (row[j].toInt(&check, 10) > 999999  || row[j].toInt(&check, 10) < -999999) {
                file.close();
                emergencyExit("The cell data must be between -1000000 and 1000000. The process failed.");
                return;
            }

            if (!check) {
                file.close();
                emergencyExit("The file can only contain integers. The process failed.");
                return;
            }

            QTableWidgetItem * item = new QTableWidgetItem(row[j]);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i, j, item);
        }
    }

    file.close();
}

void MainWindow::on_actionWrite_triggered() {
    QFile file(chooseFile());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the output file";
        QMessageBox::warning(this, "Warning", "Failed to open the output file");
        return;
    }
    QTextStream os(&file);

    int size = ui->tableWidget->rowCount();
    os << size << '\n';
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            QTableWidgetItem* item = ui->tableWidget->item(row, column);
            if (item != nullptr) {
                os << item->text();
                if (column < size - 1){
                    os << ' ';
                } else {
                    os << '\n';
                }
            }
        }
    }

    file.close();
    qDebug() << "File successfully written!";
    QMessageBox::information(this, "Success", "File successfully written!");
}

QString MainWindow::chooseFile() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select File", QDir::homePath());
    return filePath;
}

void MainWindow::emergencyExit(QString errorMessage) {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    QMessageBox::warning(this, "Error", errorMessage);
}

void MainWindow::on_actionExit_triggered() {
    close();
}

void MainWindow::on_actionClear_triggered() {
    on_pushButtonClear_clicked();
}

void MainWindow::on_actionFill_triggered() {
    on_pushButtonFill_clicked();
}

void MainWindow::on_actionGetValue_triggered() {
    on_pushButtonGetValue_clicked();
}

void MainWindow::on_actionSetValue_triggered() {
    on_pushButtonSetValue_clicked();
}
