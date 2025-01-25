#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

Node* LL_insert_to_beginning(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
    } else {
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}

void LL_insert_to_beginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
    } else {
        newNode->prev = nullptr;
        newNode->next = *head;
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void LL_insert_after(Node* head, int newData, int target) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "The target node is not found in the list." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void LL_insert_at_end(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void LL_delete_node(Node** head, int hasValue) {
    Node* temp = *head;
    while (temp != nullptr && temp->data != hasValue) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "The item doesn't exist in the list." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

bool LL_search(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    head = LL_insert_to_beginning(head, 1);
    head = LL_insert_to_beginning(head, 3);
    LL_insert_to_beginning(&head, 4);
    LL_insert_after(head, 2, 3);
    LL_insert_at_end(head, 0);
    LL_delete_node(&head, 10);

    Node* Cursor = head;
    while (Cursor) {
        cout << Cursor->data << endl;
        Cursor = Cursor->next;
    }

    // Test the search function
    int searchItem = 2;
    bool isPresent = LL_search(head, searchItem);
    cout << searchItem << " is " << (isPresent ? "present" : "not present") << " in the Linked List." << endl;

    // Clean up memory before exit (avoid memory leaks)
    Cursor = head;
    while (Cursor) {
        Node* temp = Cursor;
        Cursor = Cursor->next;
        delete temp;
    }

    return 0;
}
