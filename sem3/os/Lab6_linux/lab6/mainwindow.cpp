#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <regex>
#include <chrono>

std::ofstream outputFile;
std::vector<std::string> lines;
std::string wordToFind = "Potter";
int currentLineIndex = 0;

std::vector<pthread_t> threads;
std::vector<bool> isFinished;

pthread_spinlock_t spinlock;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lineEdit->setText(QString::fromStdString(wordToFind));
    ui->tableWidget->setColumnCount(2);
    QStringList headers;
    headers << "TID" << "Priority";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnWidth(0, 180);
    ui->tableWidget->setColumnWidth(1, 180);
}

MainWindow::~MainWindow() {
    delete ui;
}

void* launchThreadsWrapperSp(void* args) {
    MainWindow* mainWindow = reinterpret_cast<MainWindow*>(args);
    mainWindow->createWorkerThreadsSpinlock();
    return nullptr;
}

void* launchThreadsWrapperCo(void* args) {
    MainWindow* mainWindow = reinterpret_cast<MainWindow*>(args);
    mainWindow->createWorkerThreadsConditionVariable();
    return nullptr;
}

void MainWindow::createWorkerThreadsSpinlock() {
    outputFile.close();
    outputFile.open("/home/artem/OS/Labs/Lab6/lab6/output.txt", std::ios::trunc);
    if (!outputFile.is_open()) return;

    std::ifstream inputFile("/home/artem/OS/Labs/Lab6/lab6/input.txt");
    if (!inputFile) return;

    std::string tempLine;
    while (std::getline(inputFile, tempLine)) {
        lines.push_back(tempLine);
    }

    int n = ui->comboBox->currentText().toInt();
    threads.resize(n);
    isFinished.resize(n, false);
    auto start = std::chrono::high_resolution_clock::now();

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if (ui->checkBox->isChecked()) {
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    } else {
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    }

    for (int i = 0; i < n; ++i) {
        if (pthread_create(&(threads[i]), &attr, mythreadcondition, NULL) != 0) {
            std::cerr << ("Failed to create thread");
            return;
        }
    }

    on_pushButton_refreshTable_clicked();

    for (int i = 0; i < n; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            std::cerr << ("Failed to join thread");
            return;
        }

        isFinished[i] = true;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    qDebug() << "Time elapsed: " << duration.count() << " seconds";

    inputFile.close();
    outputFile.close();
}

void MainWindow::createWorkerThreadsConditionVariable() {
    pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

    outputFile.close();
    outputFile.open("/home/artem/OS/Labs/Lab6/lab6/output.txt", std::ios::trunc);
    if (!outputFile.is_open()) return;

    std::ifstream inputFile("/home/artem/OS/Labs/Lab6/lab6/input.txt");
    if (!inputFile) return;

    std::string tempLine;
    while (std::getline(inputFile, tempLine)) {
        lines.push_back(tempLine);
    }

    int n = ui->comboBox->currentText().toInt();
    threads.resize(n);
    isFinished.resize(n, false);
    auto start = std::chrono::high_resolution_clock::now();

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if (ui->checkBox->isChecked()) {
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    } else {
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    }

    for (int i = 0; i < n; ++i) {
        if (pthread_create(&(threads[i]), &attr, mythreadspinlock, NULL) != 0) {
            std::cerr << ("Failed to create thread");
            return;
        }
    }

    on_pushButton_refreshTable_clicked();

    for (int i = 0; i < n; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            std::cerr << ("Failed to join thread");
            return;
        }

        isFinished[i] = true;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    qDebug() << "Time elapsed: " << duration.count() << " seconds";

    pthread_spin_destroy(&spinlock);

    inputFile.close();
    outputFile.close();
}

void *mythreadspinlock(void *arg) {
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while (true) {
        pthread_spin_lock(&spinlock);

        int localLineIndex = currentLineIndex;

        if (localLineIndex >= lines.size()) {
            pthread_spin_unlock(&spinlock);
            break;
        }

        currentLineIndex++;
        pthread_spin_unlock(&spinlock);

        usleep(50000);

        std::string line = lines[localLineIndex];
        std::regex wordRegex("\\b" + wordToFind + "\\b");

        if (std::regex_search(line, wordRegex)) {
            std::string outputLine = "Line ";
            outputLine += std::to_string(localLineIndex);
            outputLine += ": ";
            outputLine += line;
            outputLine += '\n';
            outputFile << outputLine;
        }
    }

    qDebug() << "Thread is sleeping";

    return nullptr;
}

void *mythreadcondition(void *arg) {
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while (true) {
        int localLineIndex;
        pthread_mutex_lock(&mutex);

        while (currentLineIndex >= lines.size()) {
            pthread_cond_wait(&cond, &mutex);
        }

        localLineIndex = currentLineIndex++;
        pthread_mutex_unlock(&mutex);

        usleep(5000);

        std::string line = lines[localLineIndex];
        std::regex wordRegex("\\b" + wordToFind + "\\b");

        if (std::regex_search(line, wordRegex)) {
            std::string outputLine = "Line ";
            outputLine += std::to_string(localLineIndex);
            outputLine += ": ";
            outputLine += line;
            outputLine += '\n';
            outputFile << outputLine;
        }
    }

    qDebug() << "Thread is sleeping";
    return nullptr;
}

void MainWindow::on_pushButton_spinlock_clicked() {
    std::string toFindTemp = ui->lineEdit->text().toStdString();

    if (toFindTemp.empty()) {
        QMessageBox::information(this, "Error", "Enter the word, please");
        ui->lineEdit->setText(QString::fromStdString(wordToFind));
        return;
    }

    for (size_t i = 0; i < threads.size(); i++) {
        pthread_cancel(threads[i]);
    }

    threads.clear();
    isFinished.clear();
    currentLineIndex = 1;
    lines.clear();
    wordToFind = toFindTemp;
    pthread_t launcherThread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if (pthread_create(&launcherThread, &attr, launchThreadsWrapperSp, static_cast<void*>(this)) != 0) {
        std::cerr << ("Failed to create thread");
        return;
    }

    pthread_attr_destroy(&attr);
}

void MainWindow::on_pushButton_condition_clicked() {
    std::string toFindTemp = ui->lineEdit->text().toStdString();

    if (toFindTemp.empty()) {
        QMessageBox::information(this, "Error", "Enter the word, please");
        ui->lineEdit->setText(QString::fromStdString(wordToFind));
        return;
    }

    for (size_t i = 0; i < threads.size(); i++) {
        pthread_cancel(threads[i]);
    }

    threads.clear();
    isFinished.clear();
    currentLineIndex = 1;
    lines.clear();
    wordToFind = toFindTemp;
    pthread_t launcherThread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if (pthread_create(&launcherThread, &attr, launchThreadsWrapperCo, static_cast<void*>(this)) != 0) {
        std::cerr << ("Failed to create thread");
        return;
    }

    pthread_attr_destroy(&attr);
}

void MainWindow::on_pushButton_refreshTable_clicked() {
    ui->tableWidget->setRowCount(0);

    for (size_t i = 0; i < threads.size(); ++i) {
        pthread_t thread = threads[i];

        // Check if thread is finished
        if (isFinished[i]) {
            threads.erase(threads.begin() + i);
            isFinished.erase(isFinished.begin() + i);
            --i;
            continue;
        }

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem* tid = new QTableWidgetItem(QString::number(thread));
        ui->tableWidget->setItem(i, 0, tid);

        int policy;
        struct sched_param param;

        if (pthread_getschedparam(thread, &policy, &param) != 0) {
            std::cerr << "Failed to get thread priority.";
            return;
        }

        QTableWidgetItem* priority = new QTableWidgetItem(QString::number(param.sched_priority));
        ui->tableWidget->setItem(i, 1, priority);

        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);

        if (pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset) != 0) {
            std::cerr << "Failed to get thread affinity.";
            return;
        }

        QString affinity = "";

        for (int i = 0; i < CPU_SETSIZE; i++) {
            if (CPU_ISSET(i, &cpuset)) {
                affinity += QString::number(i);
                affinity += ' ';
            }
        }

        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(affinity));
    }
}

void MainWindow::on_pushButton_cancel_clicked() {
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0 && selectedRow < threads.size()) {
        if (pthread_cancel(threads[selectedRow]) != 0) {
            std::cerr << "Failed to cancel thread.";
            return;
        }

        isFinished[selectedRow] = true;
        on_pushButton_refreshTable_clicked();
    } else {
        QMessageBox::information(this, "Error", "No thread selected.");
    }
}

void MainWindow::on_pushButton_priority_clicked() {
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0 && selectedRow < threads.size()) {
        int priority = ui->spinBox->value();

        if ((priority < 1) || (priority > 99)) {
            QMessageBox::information(this, "Error", "Wrong priority value (must be betwen 1 and 99).");
        }

        struct sched_param param;
        param.sched_priority = priority;
        int policy = SCHED_RR;

        if (pthread_setschedparam(threads[selectedRow], policy, &param) != 0) {
            std::cerr << "Failed to change thread priority for thread.\n";
        }
    } else {
        QMessageBox::information(this, "Error", "No thread selected or invalid selection.");
    }

    on_pushButton_refreshTable_clicked();
}
