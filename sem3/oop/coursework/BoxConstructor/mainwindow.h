#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "order.h"

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

    static void showErrorMessage(const char* msg);

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_edit_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_cost_clicked();
    void on_tableWidget_orders_cellClicked(int row, int column);
    void on_pushButton_sort_clicked();
    void on_tableWidget_prices_itemChanged(QTableWidgetItem *item);
    void on_pushButton_income_clicked();
    void on_pushButton_outcomes_clicked();

    void on_pushButton_materialsCost_clicked();

private:
    void inputFromFile();
    void outputToFile();
    void setupOrders();
    void setupPrices();
    int getCurrentRow();
    void setTemplateColor(unsigned int color);
    void addOrderToTable(Order* order);
    void clearRecord();

private:
    Ui::MainWindow* ui;
    MonthlyRecord* monthlyRecord;
    std::vector<Material> materials;
    bool beingSorted;
};


#endif // MAINWINDOW_H
