#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "Tuple.h"


template<typename T>
class Queue {
public:
    Queue(unsigned capacity = 100);

    unsigned size() const;
    bool empty() const;
    bool full() const;

    const T& front() const;

    void enqueue(const T& val);
    T dequeue();

    void print() const;

private:
    T* data;
    unsigned queueSize; //the actual number of elements in the queue
    unsigned capacity; //the max number of elements in the queue
    int frnt; //the index storing the front of the queue
    int bck;  //the index storing the back of the queue
};

#endif