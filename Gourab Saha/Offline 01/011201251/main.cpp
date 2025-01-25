#include <iostream>
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"

int main()
{
    // Testing Doubly Linked List with integers
    std::cout << "Testing Doubly Linked List with integers:" << std::endl;
    DoublyLinkedList<int> intList;
    intList.insertAt(new Node<int>(1), 0);
    intList.insertAt(new Node<int>(2), 1);
    intList.insertAt(new Node<int>(3), 2);
    intList.insertAt(new Node<int>(4), 0);
    intList.insertAt(new Node<int>(5), 2);
    std::cout << "Length: " << intList.getLength() << std::endl;
    intList.deleteFrom(2);
    std::cout << "Length: " << intList.getLength() << std::endl;

    // Testing Circular Linked List with strings
    std::cout << "Testing Circular Linked List with strings:" << std::endl;
    CircularLinkedList<std::string> strList;
    strList.insertAt(new Node<std::string>("hello"), 0);
    strList.insertAt(new Node<std::string>("world"), 1);
    strList.insertAt(new Node<std::string>("this"), 2);
    strList.insertAt(new Node<std::string>("is"), 3);
    strList.insertAt(new Node<std::string>("a"), 4);
    strList.insertAt(new Node<std::string>("test"), 5);
    std::cout << "Length: " << strList.getLength() << std::endl;
    strList.deleteFrom(2);
    std::cout << "Length: " << strList.getLength() << std::endl;

    return 0;
}
