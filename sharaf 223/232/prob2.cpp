#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtK(Node** head, int value, int k) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (*head == nullptr || k == 1) {
        newNode->next = *head;
        if (*head != nullptr)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int count = 1;
    while (count < k - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }

    if (count < k - 1) {
        current->next = newNode;
        newNode->prev = current;
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != nullptr)
        current->next->prev = newNode;
    current->next = newNode;
}

void insertAtSecondLast(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    if ((*head)->next == nullptr) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}
int findMaximum(Node* head) {
    int maximum = INT_MIN;
    Node* current = head;
    while (current != nullptr) {
        if (current->data > maximum) {
            maximum = current->data;
        }
        current = current->next;
    }

    return maximum;
}

void deleteOddElements(Node** head) {
    Node* current = *head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        if (current->data % 2 != 0) {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                *head = current->next;

            if (current->next != nullptr)
                current->next->prev = current->prev;

            delete current;
        }

        current = nextNode;
    }
}

int searchOccurrences(Node* head, int value) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            count++;
        }
        current = current->next;
    }

    return count;
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}
void deleteList(Node** head) {
    Node* current = *head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    *head = nullptr;
}

int main() {
    Node* head = nullptr;


    insertAtK(&head, 15, 1);
    insertAtK(&head, 20, 2);
    insertAtK(&head, 35, 2);
    insertAtK(&head, 50, 3);
    insertAtK(&head, 40, 3);
    cout << "List after inserting at k-th position: ";
    printList(head);


    insertAtSecondLast(&head, 50);
    cout << "List after inserting at the second last position: ";
    printList(head);


    int maximum = findMaximum(head);
    cout << "Maximum element in the list: " << maximum << endl;

    deleteOddElements(&head);
    cout << "List after deleting odd elements: ";
    printList(head);

    int count = searchOccurrences(head, 50);
    cout << "Occurrences of 50 in the list: " << count << endl;

    deleteList(&head);

    return 0;
}
