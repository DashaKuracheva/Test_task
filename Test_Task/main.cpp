#include "mainwindow.h"
#include <ctime>
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
