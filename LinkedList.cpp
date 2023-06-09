#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::addToEnd(int data) {
    Node *newNode = new Node(data); //Создается новый узел newNode с переданным значением data

    if (head == nullptr) { //Если список пуст, то новый узел становится головой списка.
        head = newNode;
        return;
    }

    Node *currNode = head; //создание указателя на головной элемент списка currNode.
    while (currNode->next != nullptr) { //цикл проходит по списку до тех пор, пока не найдется последний элемент.
        currNode = currNode->next; //переход к следующему элементу списка.
    }
    currNode->next = newNode; //добавление нового элемента newNode в конец списка
}

// Добавление элемента в начало списка
void LinkedList::addToStart(int data) {
    Node *newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head; //Если список не пуст, то указатель next на новый узел устанавливается на текущую голову списка
    head = newNode; //Головой списка становится новый узел
}

// Добавление элемента в заданную позицию
void LinkedList::add(int data, int pos) {
    Node *newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    //Проверяется, является ли позиция равной 0.
    // Если да, то новый узел становится головой списка, а его следующим элементом становится предыдущая голова.
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *currNode = head; //создание указателя на головной элемент списка currNode.
    //Этот цикл который проходит через узлы до позиции, переданной в параметрах функции.
    // Если достигнут конец списка, цикл прерывается.
    for (int i = 0; i < pos - 1; i++) {
        if (currNode->next == nullptr) {
            break;
        }
        currNode = currNode->next; //если current не пустой то переходит на след. элемент
    }

    newNode->next = currNode->next;//Присваивает следующий указатель нового узла следующему узлу текущего узла.
    currNode->next = newNode; //добавление нового элемента newNode в конец списка
}

// Удаление элемента по значению
void LinkedList::removeByValue(int data) {
    //Проверяет, есть ли элементы в списке.
    // Если голова списка равна NULL, значит список пуст, поэтому выходим из функции.
    if (head == nullptr) {
        return;
    }
    //Проверяет, является ли голова списка элементом, который нужно удалить.
    // Если да, то изменяем голову на следующий элемент списка и выходим из функции.
    if (head->data == data) {
        head = head->next;
        return;
    }

    Node *currNode = head; //Создаём указатель на текущий узел, начиная с головы списка.
    //Ищем элемент со значением data в списке, пока не дойдём до конца списка или не найдём элемент с нужным значением.
    while (currNode->next != nullptr && currNode->next->data != data) {
        currNode = currNode->next; //Переходим к следующему узлу.
    }
    //Если элемент со значением data найден, то удаляем его,
    // переключив указатель предыдущего элемента на следующий элемент после удаляемого.
    if (currNode->next != nullptr) {
        currNode->next = currNode->next->next; //Удаляем элемент путём перенаправления указателя предыдущего элемента на следующий элемент после удаляемого.
    }
}

// Удаление элемента по номеру позиции
void LinkedList::removeByPosition(int position) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Поиск элемента по значению
int LinkedList::searchByValue(int value) {
    if (head == nullptr) { //Проверяется, есть ли хотя бы один элемент в списке, если нет, то функция возвращает -1.
        return -1;
    }
    Node *temp = head; //Создается указатель temp, который указывает на начало списка
    int pos = 0;
    //На каждой итерации цикла проверяется значение data текущего узла, на которое указывает temp,
    // с искомым значением value. Если они равны, то функция возвращает текущую позицию pos.
    while (temp != nullptr) {
        if (temp->data == value) {
            return pos;
        }
        //Если значения не совпадают, то переменная pos увеличивается на 1 и указатель temp сдвигается на следующий узел списка.
        pos++;
        temp = temp->next;
    }
    return -1;
}
//Поиск элемента через позицию.
int LinkedList::searchByPos(int pos) {
    if (pos <= 0) {
        return -1;
    }

    Node* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < pos) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        return -1;
    }

    return current->data;
}

void LinkedList::printList() {
    if (head == nullptr) { //проверяем, пуст ли связный список. Если head равен NULL, то список пуст.
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head; //создаём указатель temp, который будет использоваться для обхода списка. Изначально он указывает на голову списка head.
    while (temp != nullptr) {
        cout << temp->data << " "; //выводим значение текущего узла на экран консоли.
        temp = temp->next; //переходим к следующему узлу списка, обновляя значение указателя temp.
    }
    cout << endl;
}
bool LinkedList::isEmpty() {
    return head == nullptr;
}