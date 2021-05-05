#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <QQueue>
#include <QDebug>

template<class T>
class priorityQueue
{
public:
    priorityQueue()
    {}

    void enqueue(int priority,T value)
    {
        Item<T> item(priority, value);
        for(int i = 0 ; i < queue.count() ; ++i ) {
            const Item<T>& otherItem = queue[i];
            if( priority < otherItem.priority )  {
                queue.insert(i,item);
                return;
            }
        }
        queue.append(item);
    }

    T getShortestTrip()
    {
        return queue.front().value;
    }

    int getLowestPriority()
    {
        return queue.front().priority;
    }

    T dequeue()
    {
        const Item<T>& item = queue.dequeue();
        return item.value;
    }

    int count()
    {
        return queue.count();
    }

    void printQueue()
    {
        QQueue< Item<T > > tempQ = queue;
        while (tempQ.count() > 0)
        {
            qDebug() << "Priority:  " << tempQ.front().priority << "  Value:  " << tempQ.front().value;
            tempQ.dequeue();
        }
    }

private:

    template<class C>
    struct Item
    {
        int priority;
        C value;

        Item(int priority, C value)
        {
            this->priority = priority;
            this->value = value;
        }
    };

    QQueue< Item<T > > queue;
};
#endif // PRIORITYQUEUE_H
