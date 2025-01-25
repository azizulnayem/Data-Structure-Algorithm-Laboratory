#include "Node.h"

template <typename T>
Node<T>::Node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    next = NULL;
    prev = NULL;
}
