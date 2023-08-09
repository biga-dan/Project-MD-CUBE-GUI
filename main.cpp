
#include "mainwindow.h"
#include "version.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("MD-Cube");
    QCoreApplication::setApplicationVersion(VERSION_NUMBER);
    MainWindow w;
    w.show();
    return a.exec();
}
