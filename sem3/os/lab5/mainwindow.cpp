#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <regex>

std::ofstream outputFile;
std::vector<std::string> lines;
std::string wordToFind = "Potter";
int currentLineIndex = 0;

std::vector<HANDLE> threads;
std::vector<bool> isSuspended;

CRITICAL_SECTION cs;
HANDLE mutex;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lineEdit->setText(QString::fromStdString(wordToFind));
    ui->tableWidget->setColumnCount(3);
    QStringList headers;
    headers << "TID" << "Priority" << "Status";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 120);
}

MainWindow::~MainWindow() {
    delete ui;
}

DWORD WINAPI launchThreadsWrapperMu(LPVOID param) {
    MainWindow* mainWindow = reinterpret_cast<MainWindow*>(param);
    mainWindow->createWorkerThreadsMutex();
    return 0;
}

DWORD WINAPI launchThreadsWrapperCS(LPVOID param) {
    MainWindow* mainWindow = reinterpret_cast<MainWindow*>(param);
    mainWindow->createWorkerThreadsCriticalSection();
    return 0;
}

int priorityFromString(const QString& str) {
    if (str == "Idle")
        return THREAD_PRIORITY_IDLE;
    else if (str == "Low")
        return THREAD_PRIORITY_LOWEST;
    else if (str == "Below Normal")
        return THREAD_PRIORITY_BELOW_NORMAL;
    else if (str == "Above Normal")
        return THREAD_PRIORITY_ABOVE_NORMAL;
    else if (str == "High")
        return THREAD_PRIORITY_HIGHEST;
    else
        return THREAD_PRIORITY_NORMAL; //de
}

QString priorityToString(int priority) {
    switch (priority) {
    case THREAD_PRIORITY_NORMAL:
        return "Normal";
    case THREAD_PRIORITY_ABOVE_NORMAL:
        return "Above Normal";
    case THREAD_PRIORITY_BELOW_NORMAL:
        return "Below Normal";
    case THREAD_PRIORITY_HIGHEST:
        return "High";
    case THREAD_PRIORITY_LOWEST:
        return "Low";
    case THREAD_PRIORITY_IDLE:
        return "Idle";
    default:
        return "Unknown";  // Значення за замовчуванням для невідомих пріоритетів
    }
}

DWORD WINAPI mythreadmu(LPVOID) {
    HANDLE timer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (!timer) {
        std::cerr << "Failed to create waitable timer. Error: " << GetLastError() << std::endl;
        return 1;
    }

    LARGE_INTEGER liDueTime;
    liDueTime.QuadPart = -50 * 10 * 1000; // 50 ms

    while (true) {
        WaitForSingleObject(mutex, INFINITE);

        int localLineIndex = currentLineIndex;

        if (localLineIndex >= lines.size()) {
            ReleaseMutex(mutex);
            break;
        }

        currentLineIndex++;
        ReleaseMutex(mutex);

        if (!SetWaitableTimer(timer, &liDueTime, 0, NULL, NULL, FALSE)) {
            std::cerr << "Failed to set waitable timer. Error: " << GetLastError() << std::endl;
            CloseHandle(timer);
            return 1;
        }

        // Wait for the timer
        WaitForSingleObject(timer, INFINITE);

        std::string line = lines[localLineIndex];
        std::regex wordRegex("\\b" + wordToFind + "\\b");

        if (std::regex_search(line, wordRegex)) {
            WaitForSingleObject(mutex, INFINITE);
            outputFile << "Line " << localLineIndex << ": " << line << std::endl;
            ReleaseMutex(mutex);
        }
    }

    CloseHandle(timer); // Close the timer handle
    qDebug() << "Thread is sleeping";

    return 0;
}

DWORD WINAPI mythreadcs(LPVOID) {
    while (true) {
        EnterCriticalSection(&cs);
        int localLineIndex = currentLineIndex;

        if (localLineIndex >= lines.size()) {
            LeaveCriticalSection(&cs);
            break;
        }

        currentLineIndex++;
        LeaveCriticalSection(&cs);

        Sleep(50);

        std::string line = lines[localLineIndex];
        std::regex wordRegex("\\b" + wordToFind + "\\b");

        if (std::regex_search(line, wordRegex)) {
            EnterCriticalSection(&cs);
            outputFile << "Line " << currentLineIndex << ": " << line << std::endl;
            LeaveCriticalSection(&cs);
        }
    }

    qDebug() << "Thread is sleeping";

    return 0;
}

void MainWindow::createWorkerThreadsCriticalSection() {
    InitializeCriticalSection(&cs);

    outputFile.close();
    outputFile.open("C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab5\\output.txt ", std::ios::trunc);
    if (!outputFile.is_open()) return;

    std::ifstream inputFile("C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab5\\input.txt ");
    if (!inputFile) return;

    std::string tempLine;

    while (std::getline(inputFile, tempLine)) {
        lines.push_back(tempLine);
    }

    int n = ui->comboBox->currentText().toInt();

    threads.resize(n);
    isSuspended.resize(0);
    isSuspended.resize(n, false);
    DWORD currentTid;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        threads[i] = CreateThread(NULL, 0, mythreadcs, NULL, 0, &currentTid);
    }

    on_pushButton_refreshTable_clicked();
    WaitForMultipleObjects(n, threads.data(), TRUE, INFINITE);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    qDebug() << "Time elapsed: " << duration.count() << " seconds";

    DeleteCriticalSection(&cs);

    inputFile.close();
    outputFile.close();
}

void MainWindow::createWorkerThreadsMutex() {
    mutex = CreateMutex(NULL, FALSE, NULL);

    outputFile.close();
    outputFile.open("C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab5\\output.txt ", std::ios::trunc);

    if (!outputFile.is_open()) return;

    std::ifstream inputFile("C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab5\\input.txt ");
    if (!inputFile) return;

    std::string tempLine;
    while (std::getline(inputFile, tempLine)) {
        lines.push_back(tempLine);
    }

    int n = ui->comboBox->currentText().toInt();

    threads.resize(n);
    isSuspended.resize(0);
    isSuspended.resize(n, false);

    DWORD currentTid;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        threads[i] = CreateThread(NULL, 0, mythreadmu, NULL, 0, &currentTid);
    }

    on_pushButton_refreshTable_clicked();
    WaitForMultipleObjects(n, threads.data(), TRUE, INFINITE);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    qDebug() << "Time elapsed: " << duration.count() << " seconds";

    CloseHandle(mutex);

    inputFile.close();
    outputFile.close();
}

void MainWindow::on_pushButton_mutex_clicked() {
    for (int i = 0; i < threads.size(); i++) {
        TerminateThread(threads[i], 0);
        CloseHandle(threads[i]);
    }

    threads.clear();
    isSuspended.clear();
    currentLineIndex = 1;
    lines.clear();
    std::string toFindTemp = ui->lineEdit->text().toStdString();

    if (toFindTemp.empty()) {
        QMessageBox::information(this, "Error", "Enter the word, please");
        ui->lineEdit->setText(QString::fromStdString(wordToFind));
        return;
    }

    wordToFind = toFindTemp;

    HANDLE launcherThread = CreateThread(NULL, 0, launchThreadsWrapperMu, (LPVOID)this, 0, NULL);
    if (launcherThread != NULL) {
        CloseHandle(launcherThread);
    } else {
        QMessageBox::information(this, "Error", "Failed to create launcher thread");
    }
}

void MainWindow::on_pushButton_criticalSection_clicked() {
    for (int i = 0; i < threads.size(); i++) {
        TerminateThread(threads[i], 0);
        CloseHandle(threads[i]);
    }

    threads.clear();
    isSuspended.clear();
    currentLineIndex = 1;
    lines.clear();
    std::string toFindTemp = ui->lineEdit->text().toStdString();

    if (toFindTemp.empty()) {
        QMessageBox::information(this, "Error", "Enter the word, please");
        ui->lineEdit->setText(QString::fromStdString(wordToFind));
        return;
    }

    wordToFind = toFindTemp;
    HANDLE launcherThread = CreateThread(NULL, 0, launchThreadsWrapperCS, (LPVOID)this, 0, NULL);

    if (launcherThread != NULL) {
        CloseHandle(launcherThread);
    } else {
        QMessageBox::information(this, "Error", "Failed to create launcher thread");
    }
}

void MainWindow::on_pushButton_refreshTable_clicked() {
    ui->tableWidget->setRowCount(0);

    for (int i = 0; i < threads.size(); ++i) {
        HANDLE hThread = threads[i];
        DWORD exitCode;

        if (GetExitCodeThread(hThread, &exitCode)) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem* tid = new QTableWidgetItem(QString::number(GetThreadId(hThread)));
            ui->tableWidget->setItem(i, 0, tid);

            int currentPriority = GetThreadPriority(hThread);
            QTableWidgetItem* priority = new QTableWidgetItem(priorityToString(currentPriority));
            ui->tableWidget->setItem(i, 1, priority);

            if (exitCode == STILL_ACTIVE) {
                QTableWidgetItem* status = new QTableWidgetItem(isSuspended[i] ? "Suspended" : "Running");
                ui->tableWidget->setItem(i, 2, status);
            } else {
                ui->tableWidget->removeRow(i);
                CloseHandle(hThread);

                threads.erase(threads.begin() + i);
                isSuspended.erase(isSuspended.begin() + i);
                --i;
            }
        }
    }
}

void MainWindow::on_pushButton_terminate_clicked() {
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0 && selectedRow < threads.size()) {
        HANDLE hThread = threads[selectedRow];

        if (hThread != NULL) {
            TerminateThread(hThread, 0);
            CloseHandle(hThread);

            ui->tableWidget->removeRow(selectedRow);
            threads.erase(threads.begin() + selectedRow);
            isSuspended.erase(isSuspended.begin() + selectedRow);
        } else {
            QMessageBox::information(this, "Error", "Invalid thread handle.");
        }
    } else {
        QMessageBox::information(this, "Error", "No thread selected.");
    }
}

void MainWindow::on_pushButton_suspend_clicked() {
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0 && selectedRow < threads.size()) {
        HANDLE hThread = threads[selectedRow];
        if (hThread != NULL && !isSuspended[selectedRow]) {
            SuspendThread(hThread);
            isSuspended[selectedRow] = true;
        } else {
            QMessageBox::information(this, "Error", "Thread is already paused or handle is invalid.");
        }
    } else {
        QMessageBox::information(this, "Error", "No thread selected.");
    }

    on_pushButton_refreshTable_clicked();
}

void MainWindow::on_pushButton_resume_clicked() {
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow >= 0 && selectedRow < threads.size()) {
        HANDLE hThread = threads[selectedRow];
        if (hThread != NULL && isSuspended[selectedRow]) {
            ResumeThread(hThread);
            isSuspended[selectedRow] = false;
        } else {
            QMessageBox::information(this, "Error", "Thread is not paused or invalid handle.");
        }
    } else {
        QMessageBox::information(this, "Error", "No thread selected or invalid selection.");
    }

    on_pushButton_refreshTable_clicked();
}

void MainWindow::on_pushButton_priority_clicked() {
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0 && selectedRow < threads.size()) {
        HANDLE hThread = threads[selectedRow];
        int newPriority = priorityFromString(ui->comboBox_priority->currentText());
        SetThreadPriority(hThread, newPriority);
    } else {
        QMessageBox::information(this, "Error", "No thread selected or invalid selection.");
    }

    on_pushButton_refreshTable_clicked();
}

bool isRunning(HANDLE hThread) {
    DWORD exitCode;

    if (GetExitCodeThread(hThread, &exitCode)) {
        if (exitCode == STILL_ACTIVE) {
            return true;
        } else {
            return false;
        }
    } else {
        std::cerr << "Failed to get thread exit code." << std::endl;
        return false;
    }
}
