#ifndef ALG_QUEUE_H
#define ALG_QUEUE_H
#include "node.h"

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();

    bool isEmpty();
    void enqueue(int value);
    int dequeue();
};

#endif //ALG_QUEUE_H
