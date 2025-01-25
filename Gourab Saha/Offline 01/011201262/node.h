#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node() : data(T()), next(nullptr), prev(nullptr) {}
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

#endif // NODE_H