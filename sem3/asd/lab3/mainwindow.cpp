#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "algorithms.h"

#include <QString>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    ui->plainTextEdit->clear();
    const size_t size = ui->lineEdit->text().toLong();
    int* array = new int[size];
    random_fill_array(array, size);

    quick_sort(array, size, 0, size - 1, ui->plainTextEdit);

    array_output(array, size, ui->plainTextEdit);

    delete[] array;
}

void MainWindow::on_pushButton_2_clicked() {
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_3->clear();

    const size_t size = ui->lineEdit_2->text().toLong();
    // randomly fill an array
    int* array = new int[size];
    for (size_t i = 0; i < size; i++) {
        if (std::rand() % 2) {
            array[i] = - std::rand() % 100;
        } else {
            array[i] = std::rand() % 100;
        }
    }

    array_output(array, size, ui->plainTextEdit_2);
    sort_between_negatives(array, size);
    array_output(array, size, ui->plainTextEdit_3);
}

