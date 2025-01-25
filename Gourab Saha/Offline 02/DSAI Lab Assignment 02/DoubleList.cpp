
/*
 *  Name: Rabinul Islam
 *  ID: 011213010
 *  Course Name: Data Structure And Algorithms Lab
 *  Course Code: CSE 2216
 *  Section: B
 *  Topic: Assignment 02
 */

#include "DoubleList.h"

template<class T>
DoubleList<T>::DoubleList() {
    length = 0;
}

template<class T>
DoubleList<T>::DoubleList(T val) {
    DNode<T> *node = new DNode<T>(val);
    head = tail = node;
    length = 1;
}

template<class T>
bool inline DoubleList<T>::isEmpty() const {
    return (head == nullptr);
}

template<class T>
bool inline DoubleList<T>::isIndexValid(int index) const {
    return (index >= 0 && index < length);
}

template<class T>
void DoubleList<T>::pushFront(T val) {
    DNode<T> *node = new DNode<T>(val);
    if(isEmpty()) {
        head = tail = node;
    }
    else {
        head->Bind(node);
        head = node;
    }
    length++;
}

template<class T>
void DoubleList<T>::pushBack(T val) {
    DNode<T> *node = new DNode<T>(val);
    if(isEmpty()) {
        tail = head = node;
    }
    else {
        node->Bind(tail);
        tail = node;
    }
    length++;
}

template<class T>
void DoubleList<T>::pushAt(T val, int index) {
    if(!isIndexValid(index) && index != length) {
        std::cerr << "Invalid Index." << std::endl;
        return;
    }

    DNode<T> *node = new DNode<T>(val);
    if(isEmpty()) {
        head = tail = node;
        length++;
    }
    else if(index == 0) pushFront(val);
    else if(index == length) pushBack(val);
    else {
        DNode<T> *it = head;
        size_t count = 0;

        while(it != nullptr && count < index) {
            it = it->next;
            count++;
        }
        node->Bind(it->prev, it);
        length++;
    }
}

template<class T>
void DoubleList<T>::remove(T val) {
    if(head->data == val) {
        DNode<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    else if(tail->data == val) {
        DNode<T> *temp = tail;
        tail = tail->prev;
        delete temp;
        length--;
    }
    else {
        DNode<T> *it = head;
        while(it != nullptr && it->data != val) {
            it = it->next;
        }
        if(it != nullptr) {
            it->disjoin();
            delete it;
            length--;
        }
    }
}

template<class T>
void DoubleList<T>::removeFront() {
    if(!isEmpty()) {
        DNode<T> *temp = head;
        head = head->next;
        temp->disjoin();
        delete temp;
        length--;
    }
    else {
        std::cerr << "List empty!\n";
    }
}

template<class T>
void DoubleList<T>::removeBack() {
    if(!isEmpty()) {
        DNode<T> *temp = tail;
        tail = tail->prev;
        temp->disjoin();
        delete temp;
        length--;
    }
    else {
        std::cerr << "List empty!\n";
    }
}

template<class T>
void DoubleList<T>::removeAt(int index) {
    if(!isIndexValid(index) || isEmpty()) {
        std::cerr << "List empty or invalid index.\n";
        return;
    }
    else if(index == 0) removeFront();
    else if(index == length - 1) removeBack();
    else {
        DNode<T> *it = head;
        size_t count = 0;

        while(it != nullptr && count < index) {
            it = it->next;
            count++;
        }
        if(it != nullptr) {
            it->disjoin();
            delete it;
            length--;
        }
    }
}

template<class T>
T& DoubleList<T>::at(int index) {
    if(!isIndexValid(index)) {
        throw new std::out_of_range("invalid index");
    }
    else {
        DNode<T> *it = head;
        std::size_t count = 0;
        while(it != nullptr && count < index) {
            it = it->next;
            count++;
        }
        if(it == nullptr) {
            throw new std::invalid_argument("stack is null");
        }
        return it->data;
        //return it != nullptr ? &(it->data) : nullptr;
    }
}

template<class T>
T& DoubleList<T>::operator[](int index) {
    return at(index);
}

template<class T>
void DoubleList<T>::swap(int a, int b) {
    if(!isIndexValid(a) || !isIndexValid(b)) {
        std::cerr << "Invalid index." << std::endl;
    }
    T temp = at(a);
    at(a) = at(b);
    at(b) = temp;
}

template<class T>
void DoubleList<T>::reverse() {
    if(!isEmpty()) {
        DNode<T> *it = head;
        DNode<T> *temp;
        while(it != nullptr) {
            temp = it->next;
            it->next = it->prev;
            it->prev = temp;
            it = temp;
        }

        temp = head;
        head = tail;
        tail = temp;
    }
}

template<class T>
std::size_t DoubleList<T>::getLength() const {
    return length;
}

template<class T>
std::size_t DoubleList<T>::getLength() {
    DNode<T> *it = head;
    std::size_t count = 0;
    while(it != nullptr) {
        it = it->next;
        count++;
    }
    return count;
}

template<class T>
void DoubleList<T>::clear() {
    if(!isEmpty()) {
        while(head != nullptr) {
            DNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        length = 0;
    }
}

template<class T>
void DoubleList<T>::printList() {
    if(isEmpty()) {
        std::cerr << "List empty!\n";
        return;
    }
    DNode<T> *it = head;
    while(it != nullptr) {
        std::cout << *it << " ";
        it = it->next;
    }
    std::cout << "\nSize: " << length << std::endl;
}
