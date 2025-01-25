
/*
 *  Name: Rabinul Islam
 *  ID: 011213010
 *  Course Name: Data Structure And Algorithms Lab
 *  Course Code: CSE 2216
 *  Section: B
 *  Topic: Assignment 02
 */

#ifndef DSAIASSIGNMENT02_DNODE_H
#define DSAIASSIGNMENT02_DNODE_H

#include "stdlib.h"

template <class T>
struct DNode {
    T data;
    DNode* prev;
    DNode* next;

    DNode() {
        this->prev = nullptr;
        this->next = nullptr;
    }

    DNode(T val) {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }

    DNode(DNode<T> *obj) {
        this->data = obj->data;
        this->prev = obj->prev;
        this->next = obj->next;
    }

    static DNode* create(T val) {
        DNode<T> *node = new DNode<T>(val);
        return node;
    }

    bool hasPrev() const {
        return prev != nullptr;
    }

    bool hasNext() const {
        return next != nullptr;
    }

    void inline Bind(DNode* prevNode) {
        if(prevNode == nullptr) return;
        prevNode->next = this;
        this->prev = prevNode;
    }

    void inline Bind(DNode *prevNode, DNode *nextNode) {
        if(prevNode != nullptr && nextNode != nullptr) {
            prevNode->next = this;
            this->prev = prevNode;
            nextNode->prev = this;
            this->next = nextNode;
        }
        else if(prevNode != nullptr) {
            prevNode->next = this;
            this->prev = prevNode;
        }
        else {
            nextNode->prev = this;
            this->next = nextNode;
        }
    }

    void inline disjoin() {
        if(prev != nullptr && next != nullptr) {
            prev->next = next;
            next->prev = prev;
            prev = next = nullptr;
        }
        else if(prev != nullptr) {
            prev->next = nullptr;
        }
        else {
            next->prev = nullptr;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, DNode<T>& t) {
        os << t.data;
        return os;
    }
};


#endif //DSAIASSIGNMENT02_DNODE_H
