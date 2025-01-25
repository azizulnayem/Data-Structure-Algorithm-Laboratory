#include <iostream>
#include "doublylinkedlist.h"
#include "circularlinkedlist.h"

int main() {
    // Doubly linked list
    DoublyLinkedList<double> dList;

    // Insert at the beginning
    Node<double>* n1 = new Node<double>(1.0);
    dList.InsertAt(n1, 0);

    // Insert at the end
    Node<double>* n2 = new Node<double>(2.0);
    dList.InsertAt(n2, 1);

    // Insert at index 1
    Node<double>* n3 = new Node<double>(3.0);
    dList.InsertAt(n3, 1);

    // Get length
    std::cout << "Doubly linked list length: " << dList.GetLength() << std::endl;

    // Delete from beginning
    dList.DeleteFrom(0);

    // Get length
    std::cout << "Doubly linked list length: " << dList.GetLength() << std::endl;

    // Circular linked list
    CircularLinkedList<int> cList;

    // Insert at the beginning
    Node<int>* n4 = new Node<int>(4);
    cList.InsertAt(n4, 0);

    // Insert at the end
    Node<int>* n5 = new Node<int>(5);
    cList.InsertAt(n5, 1);

    // Insert at index 1
    Node<int>* n6 = new Node<int>(6);
    cList.InsertAt(n6, 1);

    // Get length
    std::cout << "Circular linked list length: " << cList.GetLength() << std::endl;

    // Delete from end
    cList.DeleteFrom(2);

    // Get length
    std::cout << "Circular linked list length: " << cList.GetLength() << std::endl;

    return 0;
}