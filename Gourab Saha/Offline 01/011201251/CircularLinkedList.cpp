
#include "CircularLinkedList.h"

template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Node<T>* current = head;
    while (current != NULL) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    length = 0;
}

template <typename T>
void CircularLinkedList<T>::insertAt(Node<T>* newNode, int index)
{
    if (index < 0 || index > length) {
        std::cout << "Invalid index!" << stdcourt::endl;
        return;
    }
 
    if (index == 0) {
        newNode->next = head;
        newNode->prev = tail;
 
        if (head != NULL)
            head->prev = newNode;
        else
            tail = newNode;
 
        head = newNode;
        tail->next = head;
    }
    else if (index == length) {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        head->prev = tail;
    }
    else {
        Node<T>* current = head;
        int counter = 0;
        while (counter < index - 1) {
            current = current->next;
            counter++;
        }
 
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
 
    length++;
}

template <typename T>
void CircularLinkedList<T>::deleteFrom(int index)
{
    if (index < 0 || index >= length || length == 0) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
 
    Node<T>* current = head;
    int counter = 0;
    while (counter < index) {
        current = current->next;
        counter++;
    }
 
    if (current == head) {
        head = head->next;
        if (head != NULL)
            head->prev = tail;
        tail->next = head;
    }
    else if (current == tail) {
        tail = tail->prev;
        if (tail != NULL)
            tail->next = head;
        head->prev = tail;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
 
    delete current;
    length--;
}

template <typename T>
int CircularLinkedList<T>::getLength()
{
    return length;
}

template <typename T>
void CircularLinkedList<T>::printList()
{
    Node<T>* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}