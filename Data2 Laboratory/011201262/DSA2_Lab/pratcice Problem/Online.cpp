#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* previous;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void insertAt(Node<T>* newNode, int index) {
        if (index < 0 || index > length) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            insertAtBeginning(newNode);
        } else if (index == length) {
            insertAtEnd(newNode);
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->previous = current;
            current->next->previous = newNode;
            current->next = newNode;
            length++;
        }
    }

    void deleteFrom(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            deleteFromBeginning();
        } else if (index == length - 1) {
            deleteFromEnd();
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->previous->next = current->next;
            current->next->previous = current->previous;
            length--;
        }
    }

    int getLength() {
        return length;
    }

private:
    void insertAtBeginning(Node<T>* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        length++;
    }

    void insertAtEnd(Node<T>* newNode) {
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            throw out_of_range("List is empty");
        } else if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->previous = nullptr;
        }
        length--;
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            throw out_of_range("List is empty");
        } else if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->previous;
            tail->next = nullptr;
        }
        length--;
    }
};



