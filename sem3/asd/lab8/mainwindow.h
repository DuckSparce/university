#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytree.h"

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
    void on_lineEdit_source_editingFinished();
    void on_lineEdit_toFind_editingFinished();

private:
    MyTreeNode* createTree(int array[], size_t size);
    void clear();

    MyTreeNode* root;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
