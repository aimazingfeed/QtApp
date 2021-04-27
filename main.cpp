#include <QPushButton>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1280, 720);
    w.setWindowTitle("App");
    w.show();
    return a.exec();
}
