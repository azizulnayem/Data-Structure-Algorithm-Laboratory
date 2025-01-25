#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "node.h"

template <typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    int length;
public:
    CircularLinkedList() : head(nullptr), length(0) {}

    int GetLength() const {
        return length;
    }

    void InsertAt(Node<T>* newNode, int index) {
        if (index < 0 || index > length) {
            throw std::out_of_range("Index out of range.");
        }

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else if (index == 0) {
            Node<T>* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        else if (index == length) {
            Node<T>* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
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
            head = nullptr;
        }
        else if (index == 0) {
            Node<T>* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            delete head->prev;
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T>* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }
        length--;
    }

    ~CircularLinkedList() {
        if (head != nullptr) {
            Node<T>* current = head;
            Node<T>* next;
            do {
                next = current->next;
                delete current;
                current = next;
            } while (current != head);
        }
    }
};

#endif // CIRCULARLINKEDLIST_H