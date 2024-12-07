#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createWorkerThreadsCriticalSection();
    void createWorkerThreadsMutex();

private slots:
    void on_pushButton_criticalSection_clicked();
    void on_pushButton_refreshTable_clicked();
    void on_pushButton_terminate_clicked();
    void on_pushButton_suspend_clicked();
    void on_pushButton_resume_clicked();
    void on_pushButton_priority_clicked();
    void on_pushButton_mutex_clicked();

private:
    Ui::MainWindow *ui;
};

DWORD WINAPI launchThreadsWrapperMu(LPVOID param);
DWORD WINAPI launchThreadsWrapperCS(LPVOID param);
int ConvertPriority(const QString& str);
QString ConvertPriorityToString(int priority);
DWORD WINAPI mythreadMu(LPVOID);
DWORD WINAPI mythreadcs(LPVOID);

#endif // MAINWINDOW_H
