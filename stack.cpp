#include "stack.h"
#include "iostream"
using namespace std;

void Stack::push(int data) {
    list.addToStart(data);
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return 0;
    }

    int topValue = list.searchByPos(1);
    list.removeByPosition(1);
    return topValue;
}
int Stack::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return 0;
    }

    return list.searchByPos(1);
}


bool Stack::isEmpty() {
    return list.isEmpty();
}