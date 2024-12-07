#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void createWorkerThreadsSpinlock();
    void createWorkerThreadsConditionVariable();

private slots:
    void on_pushButton_spinlock_clicked();
    void on_pushButton_condition_clicked();
    void on_pushButton_refreshTable_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_priority_clicked();

private:
    Ui::MainWindow *ui;
};

void* launchThreadsWrapperSp(void* args);
void* launchThreadsWrapperCo(void* args);

void* mythreadspinlock(void* arg);
void* mythreadcondition(void* arg);

#endif // MAINWINDOW_H
