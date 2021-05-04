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
        Item<T> item(priority,value);
        for(int i = 0 ; i < _queue.count() ; ++i ) {
            const Item<T>& otherItem = _queue[i];
            if( priority < otherItem._priority )  {
                _queue.insert(i,item);
                return;
            }
        }
        _queue.append(item);
    }

    T getShortestTrip()
    {
        return _queue.front()._value;
    }

    T dequeue()
    {
        const Item<T>& item = _queue.dequeue();
        return item._value;
    }

    int count()
    {
        return _queue.count();
    }

    void printQueue()
    {
        QQueue< Item<T > > tempQ = _queue;
        while (tempQ.count() > 0)
        {
            qDebug() << "Priority:  " << tempQ.front()._priority << "  Value:  " << tempQ.front()._value;
            tempQ.dequeue();
        }
    }

private:

    template<class C>
    struct Item
    {
        int _priority;
        C _value;

        Item(int priority, C value)
        {
            _priority = priority;
            _value = value;
        }
    };

    QQueue< Item<T > > _queue;
};
#endif // PRIORITYQUEUE_H
