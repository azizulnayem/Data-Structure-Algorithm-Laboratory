#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* LL_insert_to_beginning(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

void LL_insert_to_beginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void LL_insert_after(Node* head, int newData, int target) {
    Node* temp = head;
    while (temp->next != NULL && temp->data != target) {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

void LL_insert_at_end(Node* head, int newData) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    temp->next = newNode;
}

void LL_delete_node(Node** head, int hasValue) {
    Node* temp = *head;
    if (temp->data == hasValue) {
        *head = temp->next;
        free(temp);
        return;
    }
    Node* prevNode;
    while (temp != NULL && temp->data != hasValue) {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode->next = temp->next;
    free(temp);
}

bool LL_search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head;

    head = new Node();
    head->data = 1;

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

    return 0;
}

