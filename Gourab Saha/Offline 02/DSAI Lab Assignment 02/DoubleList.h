
/*
 *  Name: Rabinul Islam
 *  ID: 011213010
 *  Course Name: Data Structure And Algorithms Lab
 *  Course Code: CSE 2216
 *  Section: B
 *  Topic: Assignment 02
 */

#ifndef DSAIASSIGNMENT02_DOUBLELIST_H
#define DSAIASSIGNMENT02_DOUBLELIST_H
#include "stdlibs.h"
#include "DNode.h"

template <class T>
class DoubleList {
private:
    DNode<T> *head;
    DNode<T> *tail;
    std::size_t length;

    bool inline isEmpty() const;
    bool inline isIndexValid(int) const;

public:
    DoubleList();
    DoubleList(T);
    void pushFront(T);
    void pushBack(T);
    void pushAt(T, int);
    void remove(T);
    void removeFront();
    void removeBack();
    void removeAt(int);
    void reverse();

    T& at(int);
    T& operator[](int);
    void swap(int, int);
    std::size_t getLength() const;
    std::size_t getLength();
    void clear();
    void printList();
};


#endif //DSAIASSIGNMENT02_DOUBLELIST_H
