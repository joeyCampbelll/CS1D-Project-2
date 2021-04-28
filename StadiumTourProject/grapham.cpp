#include "grapham.h"

graphAM::graphAM()
{
    loadGraphFromDB();
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

    qDebug() << route;
    qDebug() << travelDistance;
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

int graphAM::getLocationOf(QString vertex) // YES
{
    for (int i = 0; i < vertexCount; i++)
        if (vertex == vertices[i].vertex)
            return i;

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
