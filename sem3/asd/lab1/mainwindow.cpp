#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "algorithms.h"

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
    size_t size = ui->lineEdit->text().toLong();
    int* array = new int[size];
    random_fill_array(array, size);

    selection_sort(array, size, ui->plainTextEdit);
    /*
    // Output the array
    for (int i = 0; i < size; i++) {
        ui->plainTextEdit->insertPlainText(QString::number(array[i]) + ' ');
    }

    ui->plainTextEdit->insertPlainText(QString('\n'));
*/
    delete[] array;
}


void MainWindow::on_pushButton_2_clicked() {
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_3->clear();
    size_t rows = ui->lineEdit_2->text().toLong();
    size_t columns = ui->lineEdit_3->text().toLong();
    double** matrix = new double*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[columns];
    }

    random_fill_matrix(matrix, rows, columns);

    // Output initial matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ui->plainTextEdit_2->insertPlainText(QString::number(matrix[i][j]) + ' ');
        }

        ui->plainTextEdit_2->insertPlainText(QString('\n'));
    }

    cube_root_swap(matrix, rows, columns);

    // Output matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ui->plainTextEdit_3->insertPlainText(QString::number(matrix[i][j]) + ' ');
        }

        ui->plainTextEdit_3->insertPlainText(QString('\n'));
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}
