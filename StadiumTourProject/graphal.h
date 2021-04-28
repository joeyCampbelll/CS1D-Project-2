#ifndef GRAPHAL_H
#define GRAPHAL_H
#include <QVariant>
#include "database.h"

struct EdgeAL
{
    QString vertex; // holds the key (a.k.a hashKey a.k.a index)
    int weight; // holds the data associated with the key

    EdgeAL(const QString& vertex, const int& weight)
    {
        this->vertex = vertex;
        this->weight = weight;
    }
};


class graphAL
{
public:
    QString dfsRoute;
    int travelDistance;

    graphAL();

    void loadGraphFromDB();

    // Adds an edge in both directions to the adjacency list
    void addEdge(QString vert1, QString vert2, int weight);

    void printGraph();

    EdgeAL buildNode(QString vertex, int weight) { return EdgeAL(vertex, weight); }

    void sortIncidentVertices();

    void depthFirstSearch(QString start);

    void depthFirstHelper(QString currentVertex);
private:
    QMap<QString, QList<EdgeAL>> adjList;
    QMap<QString, bool> isVisitedMap;

};

#endif // GRAPHAL_H
