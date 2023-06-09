#ifndef ALG_LINKEDLIST_H
#define ALG_LINKEDLIST_H

#include "node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void addToEnd(int data);
    void addToStart(int data);
    void add(int data, int pos);
    void removeByValue(int data);
    void removeByPosition(int pos);
    int searchByValue(int value);
    int searchByPos(int pos);
    void printList();
    bool isEmpty();
};

#endif //ALG_LINKEDLIST_H
