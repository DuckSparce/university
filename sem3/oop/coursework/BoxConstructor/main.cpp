#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("box-flat.ico"));
    w.show();
    return a.exec();
}
