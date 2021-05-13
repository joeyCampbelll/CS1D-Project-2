#ifndef GRAPHAL_H
#define GRAPHAL_H
#include <QVariant>
#include "database.h"

/**
* @brief Struct for Adjacency List Edges
*/
struct EdgeAL
{
    /**
    * @brief Name of Stadium
    */
    QString vertex;

    /**
    * @brief weight of edge
    */
    int weight;

    /**
    * @brief struct constructor
    *
    * copies parameters into current struct
    *
    * @param vertex
    * @param weight
    */
    EdgeAL(const QString& vertex, const int& weight)
    {
        this->vertex = vertex;
        this->weight = weight;
    }
};


class graphAL
{
public:
    /**
    * @brief holds route for DFS
    */
    QString dfsRoute;

    /**
    * @brief Holds travel distance for DFS
    */
    int travelDistance;

    /**
    * @brief Adjacency List cosntructor
    */
    graphAL();

    /**
    * @brief loads graph from database
    *
    * takes information from database and
    * loads it into adjacency list
    *
    */
    void loadGraphFromDB();

    /**
    * @brief adds edge to graph
    *
    * Adds edge to graph with given
    * vertices and edge weight
    *
    * @param vert1
    * @param vert2
    * @param weight
    */
    void addEdge(QString vert1, QString vert2, int weight);

    /**
    * @brief prints graph
    *
    * prints out adjacency list
    *
    */
    void printGraph();

    /**
    * @brief creates graph node
    *
    * Creates a node for the adjacency list
    *
    * @param vertex
    * @param weight
    *
    * @returns newly created node for graph
    */
    EdgeAL buildNode(QString vertex, int weight) { return EdgeAL(vertex, weight); }


    /**
    * @brief sorts incident vertices
    *
    * sorts incident vertices by distance
    *
    */
    void sortIncidentVertices();

    /**
    * @brief performs DFS
    *
    * Performs a DFS starting at passed in
    * starting node
    *
    * @param start
    */
    void depthFirstSearch(QString start);

    /**
    * @brief assists depthFirstSearch() function
    *
    * Assists depthFirstSearch() function in
    * performing the DFS
    *
    * @param currentVertex
    */
    void depthFirstHelper(QString currentVertex);

    /**
    * @brief gets route for DFS
    *
    * Gets route for DFS
    *
    * @returns route for DFS
    */
    QList<QString> getRoute();

    /**
    * @brief gets distance for DFS
    *
    * Gets distance for DFS
    *
    * @returns distance for DFS
    */
    int getDistance();

private:
    /**
    * @brief map that stores adjacency list
    */
    QMap<QString, QList<EdgeAL>> adjList;

    /**
    * @brief map that keeps track of visited vertices
    */
    QMap<QString, bool> isVisitedMap;

    /**
    * @brief list that stores route
    */
    QList<QString> routeAL;
};

#endif // GRAPHAL_H
