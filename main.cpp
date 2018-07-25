#include "mainwindow.h"
#include <QApplication>
#include "system.h"

class System;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    System::initialize();



    MainWindow w;
    w.show();

    return a.exec();
}
