#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "affinitydialog.h"
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <unistd.h>
#include <QProcess>
#include <iostream>

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
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(process->priority())));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(process->cputime())));
}

void MainWindow::on_pushButton_terminate_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process *p = processes[row];
    kill(p->pid(), SIGCONT);
    kill(p->pid(), SIGTERM);
    int status;
    waitpid(p->pid(), &status, WUNTRACED);
    processes.erase(processes.begin() + row);
    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_suspend_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];
    kill(p->pid(), SIGSTOP);
    // p->setState("Suspended");
    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_continue_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];
    kill(p->pid(), SIGCONT);
    // p->setState("Running");
    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_priority_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    int prio = ui->spinBox->value();
    setpriority(PRIO_PROCESS, processes[row]->pid(), prio);
    // processes[row]->setPriority(prio);

    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_affinity_clicked() {
    int row = ui->tableWidget->currentRow();

    if (row == -1) {
        return;
    }

    Process* p = processes[row];

    cpu_set_t mask;
    CPU_ZERO(&mask);
    sched_getaffinity(p->pid(), sizeof(mask), &mask);

    AffinityDialog dialog(mask);
    dialog.exec();

    cpu_set_t newmask = dialog.mask(); // Store the mask in a local variable
    sched_setaffinity(p->pid(), sizeof(cpu_set_t), &newmask);
    // p->setAffinity(dialog.mask());

    on_pushButton_refresh_clicked();
}

void MainWindow::on_pushButton_refresh_clicked() {
    ui->tableWidget->setRowCount(0);

    for (size_t i = 0; i < processes.size(); i++) {
        Process* p = processes[i];
        int pid =  p->pid();

        int status;
        waitpid(pid, &status, WNOHANG | WUNTRACED); // Non-blocking check

        if (WIFEXITED(status)) {
            p->setState("Terminated");
            continue;
        } else if (WIFSTOPPED(status)) {
            p->setState("Suspended");
        } else {
            p->setState("Running");
        }

        p->setPriority(getpriority(PRIO_PROCESS, pid));

        cpu_set_t mask;
        CPU_ZERO(&mask);
        sched_getaffinity(pid, sizeof(mask), &mask);
        p->setAffinity(mask);

        struct timeval tv;
        gettimeofday(&tv, NULL);
        p->setCputime(tv.tv_sec + tv.tv_usec / 1000000.0);

    }

    for (size_t i = 0; i < processes.size(); i++) {
        if (processes[i]->state() == "Terminated") {
            processes.erase(processes.begin() + i);
            i--;
        } else {
            addProcessToTable(processes[i]);
        }
    }
}

void MainWindow::on_pushButton_create_tab_clicked() {
    Process *p = new Process("/home/artem/OS/Labs/Lab4/process_tab.exe", "process_tab.exe", "1", "100", "300000000", "4");
    processes.push_back(p);
    addProcessToTable(p);
}

void MainWindow::on_pushButton_create_sort_clicked() {
    Process *p = new Process("/home/artem/OS/Labs/Lab4/process_sort.exe", "process_sort.exe");
    processes.push_back(p);
    addProcessToTable(p);
}
