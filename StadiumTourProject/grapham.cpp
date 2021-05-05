#include "grapham.h"

graphAM::graphAM()
{
    loadGraphFromDB();
    travelDistance = 0;
}

void graphAM::loadGraphFromDB()
{
    // ------- Fills a list of each stadium -------
    QSqlQuery* qryStadiums = new QSqlQuery();
    QList<QString> stadiums;
    qryStadiums->prepare("SELECT DISTINCT ORIGINATED_STADIUM FROM Distances");
    qryStadiums->exec();

    // fills a list of stadiums
    while (qryStadiums->next())
        stadiums.push_back(qryStadiums->value(0).toString());
    // --------------------------------------------

    vertexCount = stadiums.size();
    adjMatrix = new int*[vertexCount];
    vertices = new Vertex[stadiums.size()];

    // --------------------------------------------


    for (int row = 0; row < vertexCount; row++)
    {
        // for each row in the adjMatrix, a pointer to an array is
        //   created of the same size (making 2D array)
        adjMatrix[row] = new int[vertexCount];
        // vertices[row]. returns a Vertex struct and we set
        //   the struct's vertex to the respective index of cities[]

        vertices[row].vertex = stadiums[row];


        for (int column = 0; column < vertexCount; column++)
        {
            adjMatrix[row][column] = 0; // gose through each column and sets the weight 0
        }
    }

    // ------- ADDING ALL EDGES -------
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
    // --------------------------------------------
}

void graphAM::addEdge(QString city1, QString city2, int weight)
{
    int start = 0;
    int end = 0;

    // for every element in the list of vertices
    for (int i = 0; i < vertexCount; i++)
    {
        if (city1 == vertices[i].vertex)
        {
            start = i;
        }
        if (city2 == vertices[i].vertex)
        {
            end = i;
        }
    }
    bool foundDodgers = false;

    adjMatrix[start][end] = weight;

    Edge edgeForward = { city1, city2, weight };
    vertices[start].edges.push_back(edgeForward);
}

void graphAM::printGraph()
{

    for (int i = 0; i < vertexCount; i++)
    {
        qDebug() << vertices[i].vertex << vertices[i].edges.length();
        for (int j = 0; j < vertices[i].edges.length(); j++)
        {
            qDebug() << vertices[i].edges[j].end << "(" << vertices[i].edges[j].weight << ")";
        }
        qDebug();
    }
}

void graphAM::breadthFirstSearch(QString start)
{
    route = "";
    travelDistance = 0;
    for (int i = 0; i < vertexCount; i++)
    {
        vertices[i].vTag = UNEXPLORED_VERTEX;

        for (int j = 0; j < vertices[i].edges.size(); j++)
        {
            vertices[i].edges[j].eTag = UNEXPLORED_EDGE;
        }
    }

    breadthFirstHelper(start);

    //qDebug() << route;
    //qDebug() << travelDistance;
}

void graphAM::breadthFirstHelper(QString start)
{
    QList<Vertex> vertexContainer;

    for (int i = 0; i < vertexCount; i++)
    {
        if (start == vertices[i].vertex)
        {
            vertexContainer.push_back(vertices[i]);
            vertices[i].vTag = VISITED_VERTEX;
        }
    }

    vertexContainer[0].vTag = VISITED_VERTEX;

    Vertex currentVertex;

    while (!vertexContainer.empty())
    {
        currentVertex = vertexContainer[0];

        routeAM.push_back(vertexContainer[0].vertex);
        route += vertexContainer[0].vertex + "  ";

        vertexContainer.erase(vertexContainer.begin());

        QQueue<Vertex> nextClosestVertices;

        int unvisitedSibs = unvisitedSiblings(currentVertex);

        for (int i = 0; i < unvisitedSibs; i++)
        {
            Vertex nextClosestUnvistedVertex = findClosestVertex(currentVertex);
            nextClosestVertices.enqueue(nextClosestUnvistedVertex);
            vertices[getLocationOf(nextClosestUnvistedVertex.vertex)].vTag = VISITED_VERTEX;
        }

        for (int i = 0; i < unvisitedSibs; i++)
        {
            vertexContainer.push_back(nextClosestVertices.front());
            nextClosestVertices.dequeue();
        }
    }
}

int graphAM::getLocationOf(QString vertex)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertex == vertices[i].vertex)
        {
            return i;
        }
    }
}

Vertex graphAM::findClosestVertex(Vertex vertex)
{
    int indexToCompare;
    int tempWeight = 0;
    int currWeight = 100000;
    int q;
    int edgeMarker;
    QList<Edge> tempEdges = vertex.edges;

    // Finds the next incident vertex with the lowest weight
    for (int i = 0; i < tempEdges.size(); i++)
    {
        q = getLocationOf(tempEdges[i].end);

        if(vertices[getLocationOf(tempEdges[i].end)].vTag != VISITED_VERTEX)
        {
            tempWeight = getWeightBetween(vertex, vertices[q]);

            if (tempWeight < currWeight)
            {
                currWeight = tempWeight;

                indexToCompare = getLocationOf(vertices[q].vertex);
                edgeMarker = i;
            }
        }
    }

    travelDistance += currWeight;

    vertices[getLocationOf(vertex.vertex)].edges[edgeMarker].eTag = DISCOVERY_EDGE;

    return vertices[indexToCompare];
}

int graphAM::getWeightBetween(Vertex vertex1, Vertex vertex2) // YES
{

    QList<Edge> temp1 = vertex1.edges;
    //QList<Edge> temp2 = vertex2.edges;
    for (int i = 0; i < temp1.size(); i++)
    {
        if (temp1[i].end == vertex2.vertex)
        {
            return temp1[i].weight;
        }
    }
    return -999;
}

int graphAM::unvisitedSiblings(Vertex vertex)
{
    QList<Edge> tempEdges = vertex.edges;
    int count = 0;

    for (int i = 0; i < tempEdges.size(); i++)
        if (vertices[getLocationOf(tempEdges[i].end)].vTag == UNEXPLORED_VERTEX)
            count++;

    return count;
}

QList<QString> graphAM::getRoute()
{
    return routeAM;
}

int graphAM::getDistance()
{
    return travelDistance;
}

//-----------------Dijkastras-----------------//
QVector<QString> graphAM::dijkstraAll(QVector<QString> selectedTeams)
{
    dijkstraRoute.clear();
    travelDistance = 0;

    //convert selected teams to stadiums
    for(int i = 0; i < selectedTeams.size(); i++)
    {
        selectedTeams[i] = teamToStadium(selectedTeams[i]);
    }
    int dist[vertexCount];
    bool sptSet[vertexCount];
    int parent[vertexCount];

    for (int i = 0; i < vertexCount; i++)
    {
        parent[i] = -1;
        dist[i] = infinity;
        sptSet[i] = false;
    }

    startIndex = getLocationOf(selectedTeams[0]);

    dist[startIndex] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < vertexCount; v++)
        {
            if (!sptSet[v] && adjMatrix[u][v] &&
                dist[u] + adjMatrix[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    printSolution(dist, parent);
    QVector<QString> temp = dijkstraRoute;

    return temp;
}

QVector<QString> graphAM::dijkstra1to1(QString start, QString end)
{
    dijkstraRoute.clear();
    travelDistance = 0;
    start = teamToStadium(start);
    end = teamToStadium(end);
    int dist[vertexCount];
    bool sptSet[vertexCount];
    int parent[vertexCount];

    for (int i = 0; i < vertexCount; i++)
    {
        parent[i] = -1;
        dist[i] = infinity;
        sptSet[i] = false;
    }

    startIndex = getLocationOf(start);

    dist[startIndex] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < vertexCount; v++)
        {
            if (!sptSet[v] && adjMatrix[u][v] &&
                dist[u] + adjMatrix[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    print1to1(dist, parent, start, end);

//     NOT GOING TO APPEND THE DISTANCE ONTO THE LIST, USE GET DISTANCE INSTEAD
//    dijkstraRoute.push_front("Distance: " + (QString::number(travelDistance)));
//    QVector<QString> temp = dijkstraRoute;

    return dijkstraRoute;
}


QVector<QString> graphAM::dijkstraRecursive(QVector<QString> selectedTeams)
{
    QVector<QString> temp;

    QString start = teamToStadium(selectedTeams[0]);
    QString end = teamToStadium(selectedTeams[1]);

    qDebug() << selectedTeams << Qt::endl;
    int dist[vertexCount];
    bool sptSet[vertexCount];
    int parent[vertexCount];

    for (int i = 0; i < vertexCount; i++)
    {
        parent[i] = -1;
        dist[i] = infinity;
        sptSet[i] = false;
    }

    startIndex = getLocationOf(start);

    dist[startIndex] = 0;

    for (int i = 0; i < vertexCount - 1; i++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < vertexCount; v++)
        {
            if (!sptSet[v] && adjMatrix[u][v] &&
                dist[u] + adjMatrix[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    print1to1(dist, parent, start, end);
    selectedTeams.pop_front();

    if(selectedTeams.size() > 1)
    {
        dijkstraRecursive(selectedTeams);
    }
    if(selectedTeams.size() == 1)
    {
        dijkstraRoute.push_front("Distance: " + (QString::number(travelDistance)));
    }
    temp = dijkstraRoute;

    return temp;
}

int graphAM::minDistance(int dist[], bool sptSet[])
{
    int min = infinity;
    int minIndex = -1;

    for (int v = 0; v < vertexCount; v++)
    {
        if(sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void graphAM::printPath(int parent[], int j)
{
    bool found = false;
    QString searchKey;

    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    searchKey = stadiumToTeam(vertices[j].vertex);

    for(int i = 0; i < dijkstraRoute.size(); i++)
    {
        if(dijkstraRoute[i] == searchKey)
        {
            found = true;
        }
    }

    if(!(found))
    {
        dijkstraRoute.push_back(stadiumToTeam(vertices[j].vertex));
    }
}

void graphAM::printSolution(int dist[], int parent[])
{
    //Use push front to add distance to front of vector
    //dijkstraRoute.push_back(QString::number(dist[selectedTeams.size() - 1]));
    for (int i = 1; i < vertexCount; i++)
    {
        dijkstraRoute.push_back(stadiumToTeam(vertices[startIndex].vertex));
        //dijkstraRoute.push_back(stadiumToTeam(vertices[startIndex].vertex) + "(" + (vertices[startIndex].vertex) + ")");
        //qDebug() << vertices[startIndex].vertex << " -> " << vertices[i].vertex << dist[i] <<  vertices[startIndex].vertex << "  ";
        printPath(parent, i);
    }
}

void graphAM::print1to1(int dist[], int parent[], QString start, QString end)
{
    startIndex = getLocationOf(start);
    int endIndex = getLocationOf(end);
    //qDebug() << "Here: " << endIndex;
    bool found = false;
    QString searchKey;

    for (int i = 0; i < vertexCount; i++)
    {
        if(i == endIndex)
        {
            travelDistance += dist[i];

            searchKey = stadiumToTeam(vertices[startIndex].vertex);

            for(int j = 0; j < dijkstraRoute.size(); j++)
            {
                if(dijkstraRoute[j] == searchKey)
                {
                    found = true;
                }
            }

            if(!(found))
            {
                dijkstraRoute.push_back(stadiumToTeam(vertices[startIndex].vertex));
            }

            printPath(parent, i);
        }
    }
}

QString graphAM::teamToStadium(QString teamName)
{
    QString stadiumName;
    QSqlQuery* query = new QSqlQuery();

    query->prepare("SELECT STADIUM_NAME FROM MLB_Information WHERE TEAM_NAME = :teamName");

    //binds values
    query->bindValue(":teamName", teamName);

    //executes query
    query->exec();

    if(query->next())
    {
        stadiumName = query->value(0).toString();
    }

    return stadiumName;
}

QString graphAM::stadiumToTeam(QString stadiumName)
{
    QString teamName;
    QSqlQuery* query = new QSqlQuery();

    query->prepare("SELECT TEAM_NAME FROM MLB_Information WHERE STADIUM_NAME = :stadiumName");

    //binds values
    query->bindValue(":stadiumName", stadiumName);

    //executes query
    query->exec();

    if(query->next())
    {
        teamName = query->value(0).toString();
    }

    return teamName;
}

void graphAM::primMST()
{
    int parent[vertexCount];
    int key[vertexCount];
    bool mstSet[vertexCount];

    for (int i = 0; i < vertexCount; i++)
    {
        key[i] = infinity;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < vertexCount - 1; i++)
    {
        int u = minDistance(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < vertexCount; v++)
        {
            if (adjMatrix[u][v] && mstSet[v] == false && adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    printMST(parent);
}

void graphAM::printMST(int parent[])
{
//    ===== THIS CODE PRINTS TO THE CONSOLE =====
    int totalDistance = 0;

    for (int i = 1; i < vertexCount; i++)
    {
        qDebug() << parent[i];
    }

    for (int i = 1; i < vertexCount - 1; i++)
    {
        totalDistance += adjMatrix[i][parent[i]];
        QString s = vertices[parent[i]].vertex + " - " + vertices[i].vertex;
        qDebug() << s << " -> " << adjMatrix[i][parent[i]] << Qt::endl;
    }

    qDebug() << "\nTotal Distance: " << totalDistance;
//    =============================================

//    int totalDistance = 0;
//    for (int i = 1; i < vertexCount; i++)
//    {
//        totalDistance += adjMatrix[i][parent[i]];
//        QString s = vertices[parent[i]].vertex + " - " + vertices[i].vertex;
//        routeAM += s + " (" + QString::number(adjMatrix[i][parent[i]]) + ")";
//    }
//    travelDistance = totalDistance;
}
