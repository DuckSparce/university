#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <vector>
#include "process.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addProcessToTable(Process* process);

private slots:
    void on_pushButton_terminate_clicked();
    void on_pushButton_suspend_clicked();
    void on_pushButton_continue_clicked();
    void on_pushButton_priority_clicked();
    void on_pushButton_affinity_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_create_tab_clicked();

    void on_pushButton_create_sort_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Process*> processes;
};

#endif // MAINWINDOW_H
