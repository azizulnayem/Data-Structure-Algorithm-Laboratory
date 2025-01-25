#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>
class CircularLinkedList {
private:
    Node<T> *head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertFirst(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T> *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertMiddle(T data, T afterData) {
        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        while (temp->data != afterData)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertLast(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T> *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void updateFirst(T data) {
        head->data = data;
    }

    void updateMiddle(T data, T afterData) {
        Node<T> *temp = head;
        while (temp->data != afterData)
            temp = temp->next;
        temp->next->data = data;
    }

    void updateLast(T data) {
        Node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->data = data;
    }

    void deleteFirst() {
        Node<T> *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        head = head->next;
        delete temp;
    }

    void deleteMiddle(T data) {
        Node<T> *temp = head;
        Node<T> *prev = NULL;
        while (temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }

    void deleteLast() {
        Node<T> *temp = head;
        Node<T> *prev = NULL;
        while (temp->next != head) {
                prev = temp;
                temp = temp->next;}
        prev->next = head;
        delete temp;
        }
    void display() {
    Node<T> *temp = head;
    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
};

int main() {
CircularLinkedList<int> cll;
cll.insertFirst(5);
cll.insertFirst(4);
cll.insertFirst(3);
cll.insertLast(6);
cll.insertMiddle(7, 6);
cll.display();
cll.updateFirst(10);
cll.updateMiddle(20, 7);
cll.updateLast(30);
cll.display();
cll.deleteFirst();
cll.deleteMiddle(20);
cll.deleteLast();
cll.display();
return 0;
}






