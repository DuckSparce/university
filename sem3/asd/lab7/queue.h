#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

class Queue {
public:
    Queue();
    Queue(Queue& copy);
    ~Queue();

    void clear();

    bool empty();

    double peek();

    void pop();

    void push(double elem);

    size_t getsize();

private:
    double* head;
    size_t size;
};

#endif // QUEUE_H
