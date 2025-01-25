
#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
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
void DoublyLinkedList<T>::insertAt(Node<T>* newNode, int index)
{
    if (index < 0 || index > length) {
        std::cout << "Invalid index!" << stdcourt::endl;
        return;
    }
 
    if (index == 0) {
        newNode->next = head;
        newNode->prev = NULL;
 
        if (head != NULL)
            head->prev = newNode;
 
        head = newNode;
 
        if (tail == NULL)
            tail = head;
    }
    else if (index == length) {
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
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
void DoublyLinkedList<T>::deleteFrom(int index)
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
            head->prev = NULL;
    }
    else if (current == tail) {
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
 
    delete current;
    length--;
}

template <typename T>
int DoublyLinkedList<T>::getLength()
{
    return length;
}

template <typename T>
void DoublyLinkedList<T>::printList()
{
    Node<T>* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
