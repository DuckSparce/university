#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

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

private slots:
    void emergencyExit(QString errorMessage);

    void on_pushButtonFill_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonGetValue_clicked();

    void on_pushButtonSetValue_clicked();

    void on_actionRead_triggered();

    void on_actionWrite_triggered();

    void on_actionExit_triggered();

    void on_actionClear_triggered();

    void on_actionFill_triggered();

    void on_actionGetValue_triggered();

    void on_actionSetValue_triggered();

private:
    Ui::MainWindow *ui;

    QString chooseFile();
};


#endif // MAINWINDOW_H
