#include "graphal.h"

graphAL::graphAL()
{
    loadGraphFromDB();
}

void graphAL::loadGraphFromDB()
{
    QSqlQuery* qryOS = new QSqlQuery(); // originated stadium col
    QSqlQuery* qryDS = new QSqlQuery(); // destination stadium col
    QSqlQuery* qryD = new QSqlQuery();  // distances col

    qryOS->prepare("SELECT ORIGINATED_STADIUM FROM Distances");
    qryOS->exec();

    qryDS->prepare("SELECT DESTINATION_STADIUM FROM Distances");
    qryDS->exec();

    qryD->prepare("SELECT DISTANCE FROM Distances");
    qryD->exec();

    while(qryOS->next() && qryDS->next() && qryD->next())
    {
        qDebug() << (qryOS->value(0).toString()) << "    " << (qryDS->value(0).toString()) << "    " << (qryD->value(0).toInt());
    }
}
