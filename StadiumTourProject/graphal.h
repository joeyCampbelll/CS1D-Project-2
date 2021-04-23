#ifndef GRAPHAL_H
#define GRAPHAL_H
#include <QVariant>

struct EdgeAL
{

};

class graphAL
{
public:
    graphAL();

private:
    QMap<QString, QVector<EdgeAL>> map;
};

#endif // GRAPHAL_H
