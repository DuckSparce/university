#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "algorithms.h"
#include <vector>

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
    std::vector<int> vec(size);
    random_fill_array(vec);

    array_output(vec, ui->plainTextEdit);

    merge_sort(vec, 0, size - 1, ui->plainTextEdit);
}

void MainWindow::on_pushButton_2_clicked() {
    ui->plainTextEdit_2->clear();

    const size_t size = ui->lineEdit_2->text().toLong();
    std::vector<int> vec1(size), vec2(size), res;

    for (int i = 0; i < size; i++) {
        vec1[i] = std::rand() % 100;
        vec2[i] = std::rand() % 100;
    }

    ui->plainTextEdit_2->appendPlainText("First array:\n");
    array_output(vec1, ui->plainTextEdit_2);
    ui->plainTextEdit_2->appendPlainText("Second array:\n");
    array_output(vec2, ui->plainTextEdit_2);

    mix_arrays(vec1, vec2, size, res);

    ui->plainTextEdit_2->appendPlainText("Mixed array:\n");
    array_output(res, ui->plainTextEdit_2);

    merge_sort(res, 0, res.size() - 1, nullptr);

    ui->plainTextEdit_2->appendPlainText("Sorted mixed array:\n");
    array_output(res, ui->plainTextEdit_2);
}

