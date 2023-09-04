#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
private:
    T value;  // valor 
    Node<T>* next;  // ponteiro para o proximo no 
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e o ponteiro para o 
     * próximo nó da lista.
     * */
    Node(T val, Node<T> *nextPtr);
    
    /**
    Métodos gets e sets dos atributos
    **/
    T getValue();
    Node<T>* getNext();
    void setValue(T newValue);
    void setNext(Node<T>* newNext);
};
#include "node.cpp"
#endif