#include <iostream>
#include <cstring>

template <typename T>
class Node {
public:
  T data;
  Node<T>* next;
  Node<T>* prev;
  Node(T data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

template <typename T>
class DoublyLinkedList {
private:
  Node<T>* head;
  Node<T>* tail;

public:
  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void insert(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  void update(T oldData, T newData) {
    Node<T>* current = head;
    while (current != NULL) {
      if (current->data == oldData) {
        current->data = newData;
        break;
      }
      current = current->next;
    }
  }

  void deleteNode(T data) {
    Node<T>* current = head;
    while (current != NULL) {
      if (current->data == data) {
        if (current->prev != NULL) {
          current->prev->next = current->next;
        }
        if (current->next != NULL) {
          current->next->prev = current->prev;
        }
        if (current == head) {
          head = current->next;
        }
        if (current == tail) {
          tail = current->prev;
        }
        delete current;
        break;
      }
      current = current->next;
    }
  }

  void add(T data) {
    Node<T>* current = head;
    while (current != NULL) {
      current->data += data;
      current = current->next;
    }
  }

  void printList() {
    Node<T>* current = head;
    while (current != NULL) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  DoublyLinkedList<int> list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert('Cat');
  list.printList();

  list.update(2, 5);
  list.printList();

  list.deleteNode(4);
  list.printList();

  list.add(1);
  list.printList();

  return 0;
}
///////////////////////////////
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node *next;
    Node *prev;

    Node(T data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertFirst(T data) {
        Node<T> *node = new Node<T>(data);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        size++;
    }

    void insertMiddle(
