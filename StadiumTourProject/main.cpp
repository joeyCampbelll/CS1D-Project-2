#include "mainwindow.h"
#include "graphal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    graphAL test;
//    test.printGraph();
    test.depthFirstSearch("Oracle Park");
    return a.exec();
}
