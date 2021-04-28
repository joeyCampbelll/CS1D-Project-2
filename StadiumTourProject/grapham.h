#ifndef GRAPHAM_H
#define GRAPHAM_H
#include <QVariant>
#include "database.h"

enum vertexTag
{
    VISITED_VERTEX,
    UNEXPLORED_VERTEX
};

enum edgeTag
{
    UNEXPLORED_EDGE,
    DISCOVERY_EDGE,
    CROSS_EDGE
};

struct Edge
{
    QString start; // the vertex at one end of the edge
    QString end;   // the vertex at the other end of the edge
    int weight;    // weight between two vertices
    edgeTag eTag;
};

// Each Vertex has a vector of adjacent edges
struct Vertex
{
    QString vertex;
    QList<Edge> edges;
    vertexTag vTag;

//    void setVertex(const QString vertex) { this->vertex = vertex; }
};

class graphAM
{
public:
    graphAM();
    void loadGraphFromDB();
    void addEdge(QString city1, QString city2, int weight);

    void breadthFirstSearch(QString start);
    void breadthFirstHelper(QString start);

    int getLocationOf(QString vertex);
    Vertex findClosestVertex(Vertex vertex);
    int getWeightBetween(Vertex vertex1, Vertex vertex2);
    int unvisitedSiblings(Vertex vertex);

    void printGraph();


private:
    int vertexCount;
    int edgeCount;
    int** adjMatrix;
    Vertex* vertices;
//    QList<Vertex> vertices;
    int travelDistance;
    QString route;
};

#endif // GRAPHAM_H
