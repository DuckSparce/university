#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <cstdlib>
#include <vector>

int comparisons;
int range;

void randomFillArray(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = std::rand() % range;
    }
}

int binarySearch(std::vector<int>& vec, int toFind) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        comparisons++;

        int mid = low + (high - low) / 2;

        if (vec[mid] > toFind) {
            high = mid - 1;
            continue;
        }

        if (vec[mid] < toFind) {
            low = mid + 1;
            continue;
        }

        return mid;
    }

    return -1;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_start_clicked() {
    const size_t size = ui->lineEdit_size->text().toLong();

    if (size == 0) {
        return;
    }

    range = ui->lineEdit_range->text().toInt();


    if (range == 0) {
        return;
    }

    comparisons = 0;

    ui->plainTextEdit_array->clear();
    ui->lineEdit_found->clear();
    ui->lineEdit_comparisons->clear();

    std::vector<int> vec(size);
    randomFillArray(vec);
    std::sort(vec.begin(), vec.end());

    for (size_t i = 0; i < size; i++) {
        ui->plainTextEdit_array->insertPlainText(QString::number(vec[i]) + "   ");
    }

    int toFind = vec.back() - vec.front();
    ui->lineEdit_toFind->setText(QString::number(toFind));
    int result = binarySearch(vec, toFind);
    ui->lineEdit_found->setText(QString::number(result));
    ui->lineEdit_comparisons->setText(QString::number(comparisons));
}
