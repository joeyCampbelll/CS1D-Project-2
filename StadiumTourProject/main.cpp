#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    QVector<QString> test;

    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery();

    qry->prepare("SELECT ORIGINATED_STADIUM FROM Distances");
    qry->exec();

    while(qry->next())
    {
        qDebug() << (qry->value(0).toString());
    }

    return a.exec();

}
