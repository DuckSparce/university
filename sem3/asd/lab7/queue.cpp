#include "queue.h"

#include <exception>

Queue::Queue() {
    head = nullptr;
    size = 0;
}

Queue::Queue(Queue &copy) {
    size = copy.getsize();
    head = new double[size];

    for (size_t i = 0; i < size; i++) {
        head[i] = copy.head[i];
    }
}

Queue::~Queue() {}

void Queue::clear() {
    if (size == 0) {
        return;
    }

    delete[] head;
    head = nullptr;
    size = 0;
}

bool Queue::empty() {
    return size == 0;
}

double Queue::peek() {
    if (size == 0) {
        throw std::exception();
    }

    return *head;
}

void Queue::pop() {
    if (size == 0) {
        throw std::exception();
    }

    size--;
    double* new_head = new double[size];

    for (size_t i = 0; i < size; i++) {
        new_head[i] = head[i + 1];
    }

    delete[] head;
    head = new_head;
}

void Queue::push(double elem) {
    double* new_head = new double[size + 1];

    for (size_t i = 0; i < size; i++) {
        new_head[i] = head[i];
    }

    new_head[size] = elem;
    size++;
    delete[] head;
    head = new_head;
}

size_t Queue::getsize() {
    return size;
}

