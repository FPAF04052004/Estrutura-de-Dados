#ifndef NODE_CPP
#define NODE_CPP
#include "node.h"

template<typename T>
Node<T>::Node(T val, Node<T> *nextPtr){
    value = val;
    next = nextPtr;
}
template<typename T>
T Node<T>::getValue(){
    return this->value;
}
template<typename T>
void Node<T>::setValue(T newValue){
    this->value = newValue;
}
template<typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}
template<typename T>
void Node<T>::setNext(Node<T>* newNext){
    this->next = newNext;
}

#endif