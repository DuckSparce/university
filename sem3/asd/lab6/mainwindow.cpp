#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QLogValueAxis>
#include <QtWidgets>

#include <chrono>

#include "algorithms.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->widget_lineChart->setLayout(new QVBoxLayout());
    ui->widget_pieChart->setLayout(new QVBoxLayout());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_chart_clicked() {
    while (QLayoutItem* item = ui->widget_lineChart->layout()->takeAt(0)) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    while (QLayoutItem* item = ui->widget_pieChart->layout()->takeAt(0)) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    // LINE CHART
    QChart* lineChart = new QChart();
    lineChart->legend()->setVisible(true);
    lineChart->setTitle("Sorting algorithms effectiveness chart");

    QLogValueAxis *axisX = new QLogValueAxis();
    axisX->setTitleText("Size");

    QLogValueAxis *axisY = new QLogValueAxis();
    axisY->setTitleText("Time");

    axisX->setMin(800);
    axisX->setMax(sizes[6] * 1.5);
    axisY->setMin(0);
    axisY->setMax(ui->tableWidget->item(0, 4)->text().toDouble() * 2);

    lineChart->addAxis(axisX, Qt::AlignBottom);
    lineChart->addAxis(axisY, Qt::AlignLeft);


    for (int i = 0; i < 5; i++) {
        QLineSeries* series = new QLineSeries();
        series->setName(names[i]);
        series->setPointsVisible(true);

        for (int j = 0; j < 7; j++) {
            // Just for the selection sort
            if (i == 0 && j == 5) {
                break;
            }

            series->append(sizes[j], ui->tableWidget->item(i, j)->text().toInt());
        }

        lineChart->addSeries(series);
        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    QChartView *lineChartView = new QChartView(lineChart);
    lineChartView->setRenderHint(QPainter::Antialiasing);

    ui->widget_lineChart->setLayout(new QVBoxLayout());
    ui->widget_lineChart->layout()->addWidget(lineChartView);

    // PIE CHART
    QPieSeries *pieSeries = new QPieSeries();

    for (int i = 0; i < 5; i++) {
        pieSeries->append(names[i], ui->tableWidget->item(i, 4)->text().toInt());
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Diagram of sorting algorithms execution time for the largest array");
    pieChart->legend()->setVisible(true);
    pieChart->legend()->setAlignment(Qt::AlignRight);

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);

    ui->widget_pieChart->setLayout(new QVBoxLayout());
    ui->widget_pieChart->layout()->addWidget(pieChartView);
}


void MainWindow::on_pushButton_sort_clicked() {
    this->setCursor(Qt::WaitCursor);

    std::vector<int> array1_1(1024);
    std::vector<int> array2_1(4096);
    std::vector<int> array3_1(16384);
    std::vector<int> array4_1(65536);
    std::vector<int> array5_1(262144);
    std::vector<int> array6_1(1048576);
    std::vector<int> array7_1(4194304);

    random_fill_array(array1_1, 1024);
    write_array_to_file("array1024.txt", array1_1);
    random_fill_array(array2_1, 4096);
    write_array_to_file("array4096.txt", array2_1);
    random_fill_array(array3_1, 16384);
    write_array_to_file("array16384.txt", array3_1);
    random_fill_array(array4_1, 65536);
    write_array_to_file("array65536.txt", array4_1);
    random_fill_array(array5_1, 262144);
    write_array_to_file("array262144.txt", array5_1);
    random_fill_array(array6_1, 1048576);
    write_array_to_file("array1048576.txt", array6_1);
    random_fill_array(array7_1, 4194304);
    write_array_to_file("array4194304.txt", array7_1);

    std::vector<int> array1_2(array1_1);
    std::vector<int> array1_3(array1_1);
    std::vector<int> array1_4(array1_1);
    std::vector<int> array1_5(array1_1);

    std::vector<int> array2_2(array2_1);
    std::vector<int> array2_3(array2_1);
    std::vector<int> array2_4(array2_1);
    std::vector<int> array2_5(array2_1);

    std::vector<int> array3_2(array3_1);
    std::vector<int> array3_3(array3_1);
    std::vector<int> array3_4(array3_1);
    std::vector<int> array3_5(array3_1);

    std::vector<int> array4_2(array4_1);
    std::vector<int> array4_3(array4_1);
    std::vector<int> array4_4(array4_1);
    std::vector<int> array4_5(array4_1);

    std::vector<int> array5_2(array5_1);
    std::vector<int> array5_3(array5_1);
    std::vector<int> array5_4(array5_1);
    std::vector<int> array5_5(array5_1);

    std::vector<int> array6_2(array6_1);
    std::vector<int> array6_3(array6_1);
    std::vector<int> array6_4(array6_1);
    std::vector<int> array6_5(array6_1);

    std::vector<int> array7_2(array7_1);
    std::vector<int> array7_3(array7_1);
    std::vector<int> array7_4(array7_1);
    std::vector<int> array7_5(array7_1);

    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    selection_sort(array1_1, 1024);
    std::chrono::time_point end = std::chrono::high_resolution_clock::now();
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array1_2, 1024);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array1_3, 0, 1023);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array1_4, 0, 1023);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array1_5, 1024);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    selection_sort(array2_1, 4096);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array2_2, 4096);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array2_3, 0, 4095);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array2_4, 0, 4095);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array2_5, 4096);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    selection_sort(array3_1, 16384);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array3_2, 16384);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array3_3, 0, 16383);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array3_4, 0, 16383);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 2, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array3_5, 16384);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 2, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    selection_sort(array7_1, 65536);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array4_2, 65536);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array4_3, 0, 65535);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 3, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array4_4, 0, 65535);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 3, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array4_5, 65536);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 3, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    selection_sort(array5_1, 262144);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array5_2, 262144);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 4, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array5_3, 0, 262143);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 4, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array5_4, 0, 262143);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 4, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array5_5, 262144);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 4, new QTableWidgetItem(QString::number(microseconds)));

    // start = end;
    // selection_sort(array6_1, 1048576);
    // end = std::chrono::high_resolution_clock::now();
    // microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array6_2, 1048576);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 5, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array6_3, 0, 1048575);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 5, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array6_4, 0, 1048575);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 5, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array6_5, 1048576);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 5, new QTableWidgetItem(QString::number(microseconds)));

    // start = end;
    // selection_sort(array7_1, 4194304);
    // end = std::chrono::high_resolution_clock::now();
    // microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // ui->tableWidget->setItem(0, 6, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    shell_sort(array7_2, 4194304);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(1, 6, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    quick_sort(array7_3, 0, 4194303);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(2, 6, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    merge_sort(array7_4, 0, 4194303);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(3, 6, new QTableWidgetItem(QString::number(microseconds)));

    start = end;
    counting_sort(array7_5, 4194304);
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    ui->tableWidget->setItem(4, 6, new QTableWidgetItem(QString::number(microseconds)));

    this->setCursor(Qt::ArrowCursor);
}
