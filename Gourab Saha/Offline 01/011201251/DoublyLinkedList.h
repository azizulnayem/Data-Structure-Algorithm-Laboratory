#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertAt(Node<T>* newNode, int index);
    void deleteFrom(int index);
    int getLength();
    void printList();
};

#endif
