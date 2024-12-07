#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , root(nullptr) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_lineEdit_source_editingFinished() {
    QString inputText = ui->lineEdit_source->text();
    QStringList stringList = inputText.split(" ", Qt::SkipEmptyParts);

    size_t size = stringList.size();

    if (size == 0) {
        return;
    }

    int* inputArray = new int[size];

    for (size_t i = 0; i < size; i++) {
        bool ok;
        int value = stringList.at(i).toInt(&ok);

        if (ok) {
            inputArray[i] = value;
        } else {
            delete[] inputArray;

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Invalid Input");
            msgBox.setText("Please enter valid integers separated by spaces.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            clear();
            return;
        }
    }

    if (root != nullptr) {
        delete root;
    }

    root = new MyTreeNode(inputArray[0], nullptr);

    for (size_t i = 1; i < size; i++) {
        root->toSubtree(inputArray[i]);
    }

    delete[] inputArray;

    ui->lineEdit_traversal->clear();
    root->postorderTraversal(ui->lineEdit_traversal);

    MyTreeNode* third = root->thirdSmallest();

    if (third == nullptr) {
        ui->lineEdit_func->setText("-");
        return;
    }

    ui->lineEdit_func->setText(QString::number(third->getValue()));
}

MyTreeNode* MainWindow::createTree(int array[], size_t size) {
    if (size == 0) {
        return nullptr;
    }

    return new MyTreeNode(array[0], nullptr);
}

void MainWindow::clear() {
    ui->lineEdit_source->clear();
    ui->lineEdit_func->clear();
    ui->lineEdit_isFound->clear();
    ui->lineEdit_left->clear();
    ui->lineEdit_right->clear();
    ui->lineEdit_parent->clear();
    ui->lineEdit_toFind->clear();
    ui->lineEdit_traversal->clear();
}


void MainWindow::on_lineEdit_toFind_editingFinished() {
    bool ok;
    int value = ui->lineEdit_toFind->text().toInt(&ok);

    if (!ok) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Invalid Input");
        msgBox.setText("Please enter valid integer.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        ui->lineEdit_source->clear();
        return;
    }

    ui->lineEdit_parent->setText("-");
    ui->lineEdit_left->setText("-");
    ui->lineEdit_right->setText("-");

    if (root == nullptr) {
        ui->lineEdit_isFound->setText("-");
        return;
    }

    MyTreeNode* node = root->getNode(value);

    if (node == nullptr) {
        ui->lineEdit_isFound->setText("-");
        return;
    }

    ui->lineEdit_isFound->setText("+");

    if (MyTreeNode* parent = node->getParent()) {
        ui->lineEdit_parent->setText(QString::number(parent->getValue()));
    }

    if (MyTreeNode* left = node->getLeftSon()) {
        ui->lineEdit_left->setText(QString::number(left->getValue()));
    }

    if (MyTreeNode* right = node->getRightSon()) {
        ui->lineEdit_right->setText(QString::number(right->getValue()));
    }
}

