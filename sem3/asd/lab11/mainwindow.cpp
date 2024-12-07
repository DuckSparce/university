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
    std::string text = ui->plainTextEdit->toPlainText().toStdString();
    std::string pattern = transform_string(ui->lineEdit_toFind->text().toStdString());

    if (pattern == "") {
        ui->lineEdit_searchingFor->clear();
        ui->lineEdit_found->clear();
        ui->lineEdit_found->setText("Wrond pattern.");
        return;
    }

    ui->lineEdit_searchingFor->clear();
    ui->lineEdit_searchingFor->setText(QString::fromStdString(pattern));

    std::vector<int> result = boyer_moore(pattern, text);
    ui->lineEdit_found->clear();

    if (result.empty()) {
        ui->lineEdit_found->setText("No occurences");
    } else {
        for (int i = 0; i < result.size(); i++) {
            ui->lineEdit_found->insert(QString::number(result[i]) + ' ');
        }
    }
}

std::array<int, 256> create_chars_array(std::string str) {
    std::array<int, 256> result;
    int i;

    for (int i = 0; i < 256; i++) {
        result[i] = -1;
    }

    int size = str.size();

    for (int i = 0; i < size; i++) {
        result[(int)str[i]] = i;
    }

    return result;
}

std::string transform_string(std::string str) {
    int size = str.size();
    std::string result = "";

    if (size == 0) {
        return result;
    }

    std::string block;
    std::string countStr;
    bool insideBlock = false;
    bool insideCount = false;
    int blockLength = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == '(') {
            if (insideBlock || insideCount) {
                return "";
            }

            insideBlock = true;
        } else if (str[i] == ')') {
            if (!insideBlock || insideCount) {
                return "";
            }

            insideBlock = false;
        } else if (str[i] == '{') {
            if (insideBlock || insideCount) {
                return "";
            }

            insideCount = true;
            countStr = "";
        } else if (str[i] == '}') {
            if (insideBlock || !insideCount) {
                return "";
            }

            if (block == "") {
                block.push_back(str[i - countStr.size() - 2]);
                result.pop_back();
            }

            std::string toAppend = "";
            int count = std::stoi(countStr);

            for (int i = 0; i < count; i++) {
                toAppend.append(block);
            }

            result.append(toAppend);

            block = "";
            insideCount = false;
        } else {
            if (insideBlock) {
                block.push_back(str[i]);
            } else if (insideCount) {
                if (!std::isdigit(str[i])) {
                    return "";
                }

                countStr.push_back(str[i]);
            } else {
                result.push_back(str[i]);
            }
        }
    }

    if (insideBlock || insideCount) {
        return "";
    }

    return result;
}

int find(std::string str, char sym) {
    for (int i = str.size() - 1; i >= 0; i++) {
        if (str[i] == sym) {
            return i;
        }
    }

    return -1;
}

std::vector<int> boyer_moore(std::string pat, std::string txt) {
    std::vector<int> result;
    int m = pat.size();
    int n = txt.size();

    if (m > n || m == 0) {
        return result;
    }

    int i = 0;

    while (i <= (n - m)) {
        for (int j = m - 1; j >= 0; j--) {
            if (j == 0) {
                if (pat[j] == txt[i + j]) {
                    result.push_back(i);
                }

                i++;
                break;
            }

            if (pat[j] != txt[i + j]) {
                int k = find(pat, txt[i + j]);

                if (k == -1) {
                    i += m;
                } else if (k < j) {
                    i += j - k;
                } else {
                    i++;
                }

                break;
            }
        }
    }

    return result;
}
