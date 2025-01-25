#include <iostream>

// Definition of a Node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search and print the index of the last occurrence of a specific element
int findLastOccurrenceIndex(Node* head, int target) {
    int lastIndex = -1;
    int currentIndex = 0;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            lastIndex = currentIndex;
        }
        currentIndex++;
        temp = temp->next;
    }

    return lastIndex;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = nullptr;

    // Sample Linked List: 10 -> 11 -> 11 -> 9 -> 11 -> 10 -> 20 -> NULL
    insertNode(head, 10);
    insertNode(head, 11);
    insertNode(head, 11);
    insertNode(head, 9);
    insertNode(head, 11);
    insertNode(head, 10);
    insertNode(head, 20);

    std::cout << "Linked List: ";
    printLinkedList(head);

    int target;
    std::cout << "Enter the value to search: ";
    std::cin >> target;

    int lastIndex = findLastOccurrenceIndex(head, target);
    std::cout << "Last occurrence index of " << target << ": " << lastIndex << std::endl;

    return 0;
}
