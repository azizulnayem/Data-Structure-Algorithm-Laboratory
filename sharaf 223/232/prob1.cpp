#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertIntoMid(Node** head, int value) {
    Node* slow = *head;
    Node* fast = *head;
    Node* prev = nullptr;

    if (*head == nullptr) {
        *head = new Node;
        (*head)->data = value;
        (*head)->next = nullptr;
        return;
    }

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    Node* newNode = new Node;
    newNode->data = value;

    if (prev != nullptr) {
        prev->next = newNode;
    } else {
        *head = newNode;
    }
    newNode->next = slow;
}

void addArrayToEnd(Node** head, int arr[], int size) {
    if (*head == nullptr) {
        *head = new Node;
        (*head)->data = arr[0];
        (*head)->next = nullptr;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }

        for (int i = 0; i < size; i++) {
            Node* newNode = new Node;
            newNode->data = arr[i];
            newNode->next = nullptr;
            current->next = newNode;
            current = current->next;
        }
    }
}

void deleteKthElement(Node** head, int k) {
    if (*head == nullptr) {
        return;
    } else if (k == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    } else {
        Node* current = *head;
        for (int i = 0; i < k - 1; i++) {
            current = current->next;
            if (current == nullptr) {
                return;
            }
        }

        Node* temp = current->next;
        if (temp != nullptr) {
            current->next = temp->next;
            delete temp;
        }
    }
}

void replaceLastWithSum(Node** head) {
    if (*head == nullptr) {
        return;
    }

    int sum = 0;
    Node* current = *head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }

    Node* prev = nullptr;
    Node* last = *head;
    while (last->next != nullptr) {
        prev = last;
        last = last->next;
    }

    last->data = sum;
}

vector<int> searchEvenNumbers(Node* head) {
    vector<int> evenNumbers;

    Node* current = head;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            evenNumbers.push_back(current->data);
        }
        current = current->next;
    }

    return evenNumbers;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    Node* head = nullptr;

    insertIntoMid(&head, 3);
    insertIntoMid(&head, 4);
    insertIntoMid(&head, 8);
    cout << "Linked List after insertIntoMid: ";
    printLinkedList(head);

    int arr[] = {1, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    addArrayToEnd(&head, arr, size);
    cout << "Linked List after addArrayToEnd: ";
    printLinkedList(head);

    deleteKthElement(&head, 3);
    cout << "Linked List after deleteKthElement: ";
    printLinkedList(head);


    replaceLastWithSum(&head);
    cout << "Linked List after replaceLastWithSum: ";
    printLinkedList(head);


    vector<int> evenNumbers = searchEvenNumbers(head);
    cout << "Even Numbers in the Linked List: ";
    for (int i = 0; i < evenNumbers.size(); i++) {
        cout << evenNumbers[i] << " ";
    }
    cout << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    return 0;
}
