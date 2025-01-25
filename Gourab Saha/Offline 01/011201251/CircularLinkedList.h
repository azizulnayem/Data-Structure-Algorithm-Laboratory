
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"

template <typename T>
class CircularLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insertAt(Node<T>* newNode, int index);
    void deleteFrom(int index);
    int getLength();
    void printList();
};

#endif
