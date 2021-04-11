#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //Hi this is ryan
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
