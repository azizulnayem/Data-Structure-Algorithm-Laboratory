#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertFirst(T data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertLast(T data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    void insertMiddle(T data, int position) {
        Node* newNode = new Node;
        newNode->data = data;

        Node* current = head;
        for (int i = 1; i < position && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFirst() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        delete current->next;
        current->next = NULL;
    }

    void deleteMiddle(int position) {
        if (head == NULL) {
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        for (int i = 1; i < position && current != NULL; i++) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedList<int> myList; // create a new linked list of integers

    myList.insertLast(5); // insert some nodes
    myList.insertLast(7);
    myList.insertFirst(3);
    myList.insertMiddle(6, 2);

    myList.display(); // display the contents of the list

    myList.deleteFirst(); // delete some nodes
    myList.deleteLast();
    myList.deleteMiddle(1);

    myList.display(); // display the contents of the updated list


    cout << "Char type data..................\n";

    LinkedList <char> charlist;

    charlist.insertFirst('a');
    charlist.insertLast('b');
    charlist.insertFirst('d');

    charlist.display();

    charlist.deleteFirst();
    charlist.display();

    return 0;
}

