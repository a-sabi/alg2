#ifndef ALG_STACK_H
#define ALG_STACK_H
#include "LinkedList.h"

class Stack {
private:
    LinkedList list;

public:
    void push(int value);
    int pop();
    int top();
    bool isEmpty();
};
#endif //ALG_STACK_H