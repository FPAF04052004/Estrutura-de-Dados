#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"

// construtor: cria uma fila vazia
template<typename T>
Queue<T>::Queue(){
    m_size = 0;
    m_first = nullptr;
    m_last = nullptr;
}
// construtor de copia. A pilha lst deve se manter com os mesmo valores.
template<typename T>
Queue<T>::Queue(Queue<T>& lst){
    Node<T>* viajante = lst.m_first;
    while (viajante != nullptr) {
        push(viajante->getValue());
        viajante = viajante->getNext();
    }
}
// destrutor: libera memoria alocada
template<typename T>
Queue<T>::~Queue(){
    clear();
}
// retorna o numero de elementos na fila
template<typename T>
int Queue<T>::size(){
    return m_size;
}
// Retorna true se e somente se a fila estiver vazia
template<typename T>
bool Queue<T>::empty(){
    return (m_size == 0);
}
// Remove todos os elementos da fila, ou seja, deixa a fila vazia
template<typename T>
void Queue<T>::clear(){
    while(!empty()){
        pop();
    }
}
//Insere no final da fila, pop_front
template<typename T>
void Queue<T>::push(T value){
    if (empty()){
        m_last = new Node<T>(value, nullptr);
        m_first = m_last;
    } else {
        Node<T>* aux = new Node<T>(value, nullptr);
        m_last->setNext(aux);
        m_last = aux;
    }
    m_size += 1;
}
// Remove e retorna o primeiro elemento da fila. push_back
// Se a fila estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
template<typename T>
T Queue<T>::pop(){
    if(empty()){
        //Novamente deu erro usar a esceção
        //throw this->runtime_error("Empty queue.")
        return -1;
    }else{
        Node<T>* aux = m_first;
        T valor = aux->getValue();
        m_first = aux->getNext();
        delete aux;
        m_size -= 1;
        return valor;
    }
}
#endif