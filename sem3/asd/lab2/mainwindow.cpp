#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "algorithms.h"

#include <QString>


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

    shell_sort(array, size, ui->plainTextEdit);

    delete[] array;
}

void MainWindow::on_pushButton_2_clicked() {
    ui->plainTextEdit_3->clear();

    size_t size = ui->lineEdit_2->text().toLong();

    std::vector<QString> students(size);
    std::vector<double> marks(size);

    QString data = ui->textEdit->toPlainText();
    QStringList lines = data.split("\n", Qt::SkipEmptyParts);

    if (lines.size() != size) {
        qWarning() << "Number of lines doesn't match the number of students!";
        return;
    }

    for (int i = 0; i < size; ++i) {
        QStringList tokens = lines[i].split(" ");

        students[i] = tokens[0] + " " + tokens[1];
        marks[i] = tokens[2].toDouble();
    }

    sort_student_list(students, marks, size);

    for (size_t i = 0; i < size; i++) {
        ui->plainTextEdit_3->insertPlainText(students[i] + ' ' + QString::number(marks[i]) + '\n');
    }
}

