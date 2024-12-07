#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>

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

private slots:
    void on_pushButton_chart_clicked();

    void on_pushButton_sort_clicked();

private:
    void setupCharts();

    static constexpr unsigned int sizes[] = { 1024, 4096, 16384, 65536, 262144, 1048576, 4194304 };
    std::array<QString, 5> names = { "Selection", "Shell", "Quick", "Merge", "Counting" };

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
