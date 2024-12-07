#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <psapi.h>
#include <tlhelp32.h>
#include <windows.h>
#include <string>
#include <iostream>

#include "affinitydialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addProcessToTable(Process* process) {
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(process->pid())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(process->name()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(process->state()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(process->priority()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(process->cputime())));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(process->workingSet())));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(process->peakWorkingSet())));
}

void MainWindow::on_pushButton_create_tab_clicked() {
    Process *p = new Process(L"C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab3\\x64\\Debug\\lab3.exe 1 1000 20000000 12 ");
    processes.push_back(p);
    addProcessToTable(p);
}

void MainWindow::on_pushButton_create_notion_clicked() {
    Process *p = new Process(L"C:\\WINDOWS\\system32\\cmd.exe");
    processes.push_back(p);
    addProcessToTable(p);
}

void MainWindow::on_pushButton_create_resmon_clicked() {
    Process *p = new Process(L"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Common7\\IDE\\devenv.exe");
    processes.push_back(p);
    addProcessToTable(p);
}

void MainWindow::on_pushButton_create_sort_clicked() {
    Process *p = new Process(L"C:\\Users\\USER\\source\\repos\\university\\sem3\\os\\lab3_sort\\x64\\Debug\\lab3_sort.exe");
    processes.push_back(p);
    addProcessToTable(p);
}

void MainWindow::on_pushButton_refresh_clicked() {
    ui->tableWidget->setRowCount(0);

    for (Process* p : processes) {
        HANDLE handle = p->handle();

        DWORD exitCode;
        if (GetExitCodeProcess(handle, &exitCode)) {
            if (!(exitCode == STILL_ACTIVE)) {
                p->setState("Terminated");
                continue;
            }
        }

        if (p->isSuspended()) {
            p->setState("Suspended");
        } else {
            p->setState("Running");
        }

        // else running

        switch (GetPriorityClass(p->handle())) {
        case IDLE_PRIORITY_CLASS : p->setPriority("Idle"); break;
        case BELOW_NORMAL_PRIORITY_CLASS : p->setPriority("Below normal"); break;
        case NORMAL_PRIORITY_CLASS : p->setPriority("Normal"); break;
        case ABOVE_NORMAL_PRIORITY_CLASS : p->setPriority("Above normal"); break;
        case HIGH_PRIORITY_CLASS : p->setPriority("High"); break;
        case REALTIME_PRIORITY_CLASS : p->setPriority("Realtime"); break;
        }

        DWORD_PTR processAffinity, systemAffinity;
        if (GetProcessAffinityMask(handle, &processAffinity, &systemAffinity)) {
            p->setAffinity(processAffinity);
        } else {
            std::cerr << "Failed to get process affinity mask. Error: " << GetLastError() << std::endl;
        }

        FILETIME creationTime, exitTime, kernelTime, userTime;
        if (GetProcessTimes(handle, &creationTime, &exitTime, &kernelTime, &userTime)) {
            ULARGE_INTEGER kTime, uTime;
            kTime.LowPart = kernelTime.dwLowDateTime;
            kTime.HighPart = kernelTime.dwHighDateTime;
            uTime.LowPart = userTime.dwLowDateTime;
            uTime.HighPart = userTime.dwHighDateTime;

            p->setCputime(kTime.QuadPart / 10000000.0 + uTime.QuadPart / 10000000.0);
        } else {
            std::cerr << "Failed to get process times (" << GetLastError() << ").\n";
        }

        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(handle, &pmc, sizeof(pmc))) {
            p->setWorkingSet(pmc.WorkingSetSize);
            p->setPeakWorkingSet(pmc.PeakWorkingSetSize);
        } else {
            std::cerr << "Failed to get process memory info (" << GetLastError() << ").\n";
        }
    }

    for (int i = 0; i < processes.size(); i++) {
        if (processes[i]->state() == "Terminated") {
            processes.erase(processes.begin() + i);
            i--;
        } else {
            addProcessToTable(processes[i]);
        }
    }
}

void MainWindow::on_pushButton_terminate_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    TerminateProcess(processes[row]->handle(), 0);
    CloseHandle(processes[row]->handle());
    processes.erase(processes.begin() + row);

    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_suspend_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE)
        return;

    THREADENTRY32 te;
    ZeroMemory(&te, sizeof(THREADENTRY32));
    te.dwSize = sizeof(THREADENTRY32);

    if (!Thread32First(hSnapshot, &te)) {
        CloseHandle(hSnapshot);
        return;
    }

    // Suspend all threads of the process
    do {
        if (te.th32OwnerProcessID == p->pid()) {
            HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
            if (hThread == nullptr) {
                std::cerr << "Failed to open thread (" << GetLastError() << ").\n";
            } else {
                DWORD suspendCount = SuspendThread(hThread);

                if (suspendCount == (DWORD)-1) {
                    std::cerr << "Failed to suspend thread (" << GetLastError() << ").\n";
                }

                CloseHandle(hThread);
            }
        }
    } while (Thread32Next(hSnapshot, &te));

    CloseHandle(hSnapshot);
    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_continue_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE)
        return;

    THREADENTRY32 te;
    ZeroMemory(&te, sizeof(THREADENTRY32));
    te.dwSize = sizeof(THREADENTRY32);

    if (!Thread32First(hSnapshot, &te)) {
        CloseHandle(hSnapshot);
        return;
    }

    // Continue all threads of the process
    do {
        if (te.th32OwnerProcessID == p->pid()) {
            HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
            if (hThread == nullptr) {
                std::cerr << "Failed to open thread (" << GetLastError() << ").\n";
            } else {
                DWORD resumeCount = ResumeThread(hThread);

                if (resumeCount == (DWORD)-1) {
                    std::cerr << "Failed to resume thread (" << GetLastError() << ").\n";
                }

                CloseHandle(hThread);
            }
        }
    } while (Thread32Next(hSnapshot, &te));

    CloseHandle(hSnapshot);
    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_priority_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];
    DWORD newPriority;

    switch(ui->comboBox->currentIndex()) {
    case 0: SetPriorityClass(p->handle(), IDLE_PRIORITY_CLASS); break;
    case 1: SetPriorityClass(p->handle(), BELOW_NORMAL_PRIORITY_CLASS); break;
    case 2: SetPriorityClass(p->handle(), NORMAL_PRIORITY_CLASS); break;
    case 3: SetPriorityClass(p->handle(), ABOVE_NORMAL_PRIORITY_CLASS); break;
    case 4: SetPriorityClass(p->handle(), HIGH_PRIORITY_CLASS); break;
    case 5: SetPriorityClass(p->handle(), REALTIME_PRIORITY_CLASS); break;
    }

    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_affinity_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];

    AffinityDialog dialog(p->affinity());
    dialog.exec();

    SetProcessAffinityMask(p->handle(), dialog.mask());
    p->setAffinity(dialog.mask());
}
