#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , queue()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished() {
    QStringList dataStringList = ui->lineEdit->text().split(" ", Qt::SkipEmptyParts);
    queue.clear();
    ui->plainTextEdit_queue->clear();
    ui->plainTextEdit_size->clear();
    ui->plainTextEdit_min->clear();
    ui->plainTextEdit_max->clear();
    ui->plainTextEdit_3rd->clear();
    ui->plainTextEdit_2nd->clear();
    ui->plainTextEdit_beforemin->clear();
    ui->plainTextEdit_aftermax->clear();
    ui->plainTextEdit_found->clear();
    ui->plainTextEdit_combined->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    for (const QString& str : dataStringList) {
        bool ok;
        double num = str.toDouble(&ok);

        if (ok) {
            queue.push(num);
        } else {
            queue.clear();
            ui->lineEdit->clear();
            QMessageBox::warning(nullptr, "Invalid Input", "Please enter valid numbers separated by spaces.");
            return;
        }
    }

    if (queue.getsize() == 0) {
        ui->lineEdit->clear();
        QMessageBox::warning(nullptr, "Invalid Input", "The queue size can't be zero.");
        return;
    }

    Queue copy1(queue);
    int size = copy1.getsize();

    ui->plainTextEdit_queue->insertPlainText("head-> ");
    for (int i = 0; i < size; i++) {
        ui->plainTextEdit_queue->insertPlainText(QString::number(copy1.peek()) + ' ');
        copy1.pop();
    }
    ui->plainTextEdit_queue->insertPlainText("<-tail");

    ui->plainTextEdit_size->insertPlainText(QString::number(queue.getsize()));

    Queue copy2(queue);
    double min = copy2.peek();
    double premin = NAN;
    double max = copy2.peek();
    double postmax = NAN;
    copy2.pop();
    double prev = max;
    double post = NAN;

    if (size != 1) {
        post = copy2.peek();

        for (int i = 1; i < size; i++) {
            double elem = post;

            if (elem < min) {
                min = elem;
                premin = prev;
            }

            prev = elem;
            copy2.pop();

            if (i == size - 1) {
                post = NAN;
            } else {
                post = copy2.peek();
            }

            if (elem > max) {
                max = elem;
                postmax = post;
            }
        }
    }

    ui->plainTextEdit_min->insertPlainText(QString::number(min));
    ui->plainTextEdit_max->insertPlainText(QString::number(max));
    ui->plainTextEdit_beforemin->insertPlainText(QString::number(premin));
    ui->plainTextEdit_aftermax->insertPlainText(QString::number(postmax));

    ui->plainTextEdit_2nd->insertPlainText(QString::number(NAN));
    ui->plainTextEdit_3rd->insertPlainText(QString::number(NAN));
    Queue copy3(queue);
    for (int i = 0; i < size; i++) {
        if (i == 2) {
            ui->plainTextEdit_3rd->clear();
            ui->plainTextEdit_3rd->insertPlainText(QString::number(copy3.peek()));
        }

        if (i == size - 2) {
            ui->plainTextEdit_2nd->clear();
            ui->plainTextEdit_2nd->insertPlainText(QString::number(copy3.peek()));
        }

        copy3.pop();
    }

}


void MainWindow::on_lineEdit_2_editingFinished() {
    ui->plainTextEdit_found->clear();

    Queue copy(queue);
    int size = queue.getsize();
    double toFind = ui->lineEdit_2->text().toDouble();

    for (int i = 0; i < size; i++) {
        double el = copy.peek();

        if (el == toFind) {
            ui->plainTextEdit_found->insertPlainText(QString::number(i));
            break;
        }

        copy.pop();
    }

    if (ui->plainTextEdit_found->toPlainText().isEmpty()) {
        ui->plainTextEdit_found->insertPlainText(QString::number(-1));
    }
}


void MainWindow::on_lineEdit_3_editingFinished() {
    ui->plainTextEdit_queue_2->clear();
    ui->plainTextEdit_combined->clear();

    QStringList dataStringList = ui->lineEdit_3->text().split(" ", Qt::SkipEmptyParts);
    Queue toCombine;

    for (const QString& str : dataStringList) {
        bool ok;
        double num = str.toDouble(&ok);

        if (ok) {
            toCombine.push(num);
        } else {
            toCombine.clear();
            ui->lineEdit_3->clear();
            QMessageBox::warning(nullptr, "Invalid Input", "Please enter valid numbers separated by spaces.");
            return;
        }
    }

    if (toCombine.getsize() == 0) {
        ui->lineEdit_3->clear();
        QMessageBox::warning(nullptr, "Invalid Input", "The queue size can't be zero.");
        return;
    }

    Queue combined(queue);
    Queue copy1(toCombine);
    int size = copy1.getsize();

    ui->plainTextEdit_queue_2->insertPlainText("head-> ");
    for (int i = 0; i < size; i++) {
        double el = copy1.peek();
        ui->plainTextEdit_queue_2->insertPlainText(QString::number(el) + ' ');
        combined.push(el);
        copy1.pop();
    }
    ui->plainTextEdit_queue_2->insertPlainText("<-tail");

    Queue copy2(combined);
    size = copy2.getsize();

    ui->plainTextEdit_combined->insertPlainText("head-> ");
    for (int i = 0; i < size; i++) {
        double el = copy2.peek();
        ui->plainTextEdit_combined->insertPlainText(QString::number(el) + ' ');
        combined.push(el);
        copy2.pop();
    }
    ui->plainTextEdit_combined->insertPlainText("<-tail");
}

