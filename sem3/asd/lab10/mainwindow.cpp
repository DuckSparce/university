#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    QStringList list = ui->plainTextEdit->toPlainText().split(' ', Qt::SkipEmptyParts);
    QString min = list[0];
    QString max = list[0];

    for (int i = 1; i < list.size(); i++) {
        if (list[i].size() < min.size()) {
            min = list[i];
            continue;
        }

        if (list[i].size() > max.size()) {
            max = list[i];
        }
    }

    for (int i = 0; i < list.size(); i++) {
        if (list[i] == min) {
            list[i] = max;
            continue;
        }

        if (list[i] == max) {
            list[i] = min;
        }
    }

    QString toFind = min + max;
    ui->lineEdit_shortest->setText(min);
    ui->lineEdit_longest->setText(max);
    ui->lineEdit_toFind->setText(toFind);
    ui->plainTextEdit_3->setPlainText(list.join(' '));

    std::string pattern = toFind.toStdString();
    ui->lineEdit_prefix->clear();
    std::vector<int> D(pattern.length());
    constructD(pattern, D);
    QString prefixOutput = "";
    // Output prefix function
    for (int &elem : D) {
        prefixOutput += QString::number(elem);
    }
    ui->lineEdit_prefix->insert(prefixOutput);

    std::string text = ui->plainTextEdit_2->toPlainText().toStdString();

    // std::vector<int> result = kmp(pattern, text);
    ui->lineEdit_found->clear();

    // if (result.empty()) {
    // ui->lineEdit_found->setText("No occurences");
    // } else {
    // for (int i = 0; i < result.size(); i++) {
    ui->lineEdit_found->insert(QString::number(kmp(pattern, text)));
        // }
    // }
}

void constructD(std::string &pat, std::vector<int> &D) {
    int len = 0;
    D[0] = 0;

    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            D[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = D[len - 1];
            } else {
                D[i] = 0;
                i++;
            }
        }
    }
}

int kmp(std::string &pat, std::string &txt) {
    int n = txt.length();
    int m = pat.length();

    std::vector<int> D(m);
    constructD(pat, D);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;

            if (j == m) {
                return i - j;
            }
        } else {
            if (j != 0) {
                i += j - D[j - 1];
            } else {
                i++;
            }

            j = 0;
        }
    }

    return -1;
}
