#ifndef GRAPHAL_H
#define GRAPHAL_H
#include <QVariant>
#include "database.h"

struct EdgeAL
{

};

class graphAL
{
public:
    graphAL();
    void loadGraphFromDB();
    // Adds an edge in both directions to the adjacency list
    void addEdge(QString vert1, QString vert2, int weight);

private:
    QMap<QString, QVector<EdgeAL>> map;


};

#endif // GRAPHAL_H
