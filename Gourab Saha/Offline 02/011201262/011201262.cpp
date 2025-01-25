#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int binarySearch(T data) {
        int left = 0;
        int right = size - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            Node<T>* curr = head;
            for (int i = 0; i < mid; i++) {
                curr = curr->next;
            }
            if (curr->data == data) {
                return mid;
            }
            else if (curr->data < data) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    void print() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    ifstream fin("input.txt");
    int k;
    fin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        fin >> n;
        DoublyLinkedList<double> dll;
        for (int j = 0; j < n; j++) {
            double data;
            fin >> data;
            dll.add(data);
        }
        double searchValue;
        fin >> searchValue;
        int index = dll.binarySearch(searchValue);
        cout << index << endl;
    }
    return 0;
}
