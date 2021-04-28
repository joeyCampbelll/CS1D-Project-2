#include "mainwindow.h"
#include "graphal.h"
#include "grapham.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    graphAL testAL;
//    testAL.printGraph();
//    testAL.depthFirstSearch("Oracle Park");
    graphAM testAM;
//    int test = testAM.getLocationOf("Angel Stadium");
    testAM.breadthFirstSearch("Oracle Park");


    return a.exec();
}
