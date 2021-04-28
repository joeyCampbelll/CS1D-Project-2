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
//    QVector<QString> test;

//    QSqlQuery* qry = new QSqlQuery();

//    qry->prepare("SELECT DESTINATION_STADIUM FROM Distances");
//    qry->exec();

//    while(qry->next())
//    {
//        qDebug() << (qry->value(0).toString());
//    }

    return a.exec();

}
