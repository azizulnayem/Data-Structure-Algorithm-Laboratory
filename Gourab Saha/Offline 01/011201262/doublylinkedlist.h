#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "node.h"

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    int GetLength() const {
        return length;
    }

    void InsertAt(Node<T>* newNode, int index) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of range.");
        }

        if (head == nullptr) {
            head = tail = newNode;
        }
        else if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (index == length) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
        length++;
    }

    void DeleteFrom(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range.");
        }

        if (length == 1) {
            delete head;
            head = tail = nullptr;
        }
        else if (index == 0) {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        else if (index == length - 1) {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T>* toDelete = current->next;
            current->next = toDelete->next;
            toDelete->next->prev = current;
            delete toDelete;
        }
        length--;
    }

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

#endif // DOUBLYLINKEDLIST_H