#ifndef GRAPHAM_H
#define GRAPHAM_H
#include <QVariant>
#include <algorithm>
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
    QString getNameOf(int index);
    Vertex findClosestVertex(Vertex vertex);
    int getWeightBetween(Vertex vertex1, Vertex vertex2);
    int unvisitedSiblings(Vertex vertex);

    void printGraph();

    QList<QString> getRoute();
    int getDistance();

    QVector<QString> dijkstraAll(QVector<QString> selectedTeams);
    QVector<QString> dijkstra1to1(QString start, QString end);
    QVector<QString> dijkstraRecursive(QVector<QString> selectedTeams);
    int minDistance(int dist[], bool sptSet[]);
    void printPath(int parent[], int j);
    void printSolution(int dist[], int parent[]);
    void print1to1(int dist[], int parent[], QString start, QString end);
    QString teamToStadium(QString teamName);
    QString stadiumToTeam(QString stadiumName);
    QString findClosestSelected(QString startStadiumName, QVector<QString> selectedTeams);

    void primMST();
    void printMST(int parent[]);


private:
    int vertexCount;
    int edgeCount;
    int** adjMatrix;
    Vertex* vertices;
    int travelDistance;
    QString route;
    int startIndex;
    int endIndex;
    int infinity = 99999;

    QList<QString> routeAM;
    QVector<QString> dijkstraRoute;
};

#endif // GRAPHAM_H
