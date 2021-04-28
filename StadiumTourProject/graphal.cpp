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
        addEdge((qryOS->value(0).toString()), (qryDS->value(0).toString()), (qryD->value(0).toInt()));
    }
}

void graphAL::addEdge(QString vert1, QString vert2, int weight)
{
    adjList[vert1].push_back(buildNode(vert2, weight));
}

void graphAL::printGraph()
{
    sortIncidentVertices();
    qDebug() << "ADJACENCY LIST" << Qt::endl << Qt::endl;

    QMap<QString, QList<EdgeAL>>::const_iterator itr1 = adjList.constBegin();
    while (itr1 != adjList.constEnd())
    {
        QString vertex = itr1.key();
        QList<EdgeAL> adjVertices = itr1.value();

        QList<EdgeAL>::iterator itr2 = adjVertices.begin();

        qDebug().nospace() << "[ " << vertex << " ]";

        while (itr2 != adjVertices.end())
        {
            int temp = (*itr2).weight;
            QString listItem = (*itr2).vertex + " (" + temp + ")";
            qDebug().nospace() << " -> " << (*itr2).vertex << " (" << temp << ")";
            itr2++;
        }
        itr1++;
        qDebug();
    }
    qDebug();
}

void graphAL::sortIncidentVertices()
{
    QMap<QString, QList<EdgeAL>>::iterator itr1 = adjList.begin();
    while (itr1 != adjList.end())
    {
        int i, j;

        for (i = 0; i < itr1.value().size() - 1; i++)
        {
            for (j = 0; j < itr1.value().size() - i - 1; j++)
            {
                if (itr1.value().at(j).weight > itr1.value().at(j + 1).weight)
                {
                    itr1.value().swapItemsAt(j, j + 1);
                }
            }
        }
        itr1++;
    }
}

void graphAL::depthFirstSearch(QString start)
{
    dfsRoute = "";
    travelDistance = 0;
    sortIncidentVertices();
    QMap<QString, QList<EdgeAL>>::iterator itr1 = adjList.begin();
    while (itr1 != adjList.end())
    {
        QString temp = itr1.key();
        isVisitedMap[temp] = false;
        itr1++;
    }

    depthFirstHelper(start);

    //qDebug() << dfsRoute;
    //qDebug() << travelDistance;
}

void graphAL::depthFirstHelper(QString currentVertex)
{
    dfsRoute += currentVertex + "  ";
    routeAL.push_back(currentVertex);

    isVisitedMap[currentVertex] = true;

    QList<EdgeAL>::iterator itr1 = adjList[currentVertex].begin();

    while (itr1 != adjList[currentVertex].end())
    {
        if (isVisitedMap[(*itr1).vertex] == false)
        {
            travelDistance += (*itr1).weight;
            depthFirstHelper((*itr1).vertex);
        }
        itr1++;
    }
}

QList<QString> graphAL::getRoute()
{
    return routeAL;
}

int graphAL::getDistance()
{
    return travelDistance;
}
