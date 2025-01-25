#include<bits/stdc++.h>
using namespace std;

struct Node {  // single linked list
    int data;
    Node* next;  ///new node
};

Node* head = NULL; // Head akta new node ja 1st a null



void insert1st(int data)
{
    Node* newNode = new Node; // create a new node     10|address
    newNode->data = data; // set its data
    newNode->next = head; // make its next point to the current head
    head = newNode; // update the head to point to the new node

}


void insertMiddle(int data, int position) {
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







void insert(int data) {    // data insert

    Node* temp = new Node;    ///new akta node create
    Node * temp1 = head;/// head er vitor joto data chilo oi gula copy hoye temp1 a save

    ///new je node add
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp; ///new je temp node oi ta e 1st node ba head
    }

     else
    {
        while(temp1->next != NULL) /// last node find
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;  /// append kora new node er shate
    }

}

void remove(int data) { /// remove
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != data) {       ///head jodi null hoye thake ...empty node kinah ba not find data   ///
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Element not found" << endl;
        return;
    }

    if (prev == NULL) {    /// 1st element delete
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

void display() {  /// Display or print kora
    Node* temp = head;  //
    while (temp != NULL) {          ///jokokhn pojonto null nah pabo data gula print korte thakbo
        cout << temp->data << "->";
        temp = temp->next;
    }


    cout << "NULL\n";
}

int main() {
    int choice, data;

    while(1){
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cout << "5. Insert 1st Node" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data to insert: ";
                cin >> data;
                insert(data);
                break;

            case 2:
                cout << "Enter the data to remove: ";
                cin >> data;
                remove(data);
                break;

            case 3:
                display();
                break;

            case 4:
                break;
            case 5:
                cout << "Enter the data to insert 1st Node: ";
                cin >> data;
                insert1st(data);
                break;


            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

