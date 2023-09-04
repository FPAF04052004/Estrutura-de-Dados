#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

template<typename T>
class Queue{
private:
    Node<T>* m_first; // Aponta para o inicio da fila se houver, caso contrário será null
    Node<T>* m_last; // Aponta para o final da fila se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria uma fila vazia
    Queue();

    // construtor de copia. A pilha lst deve se manter com os mesmo valores.
    Queue(Queue<T>& lst);
    
    // destrutor: libera memoria alocada
    ~Queue();

    // retorna o numero de elementos na fila
    int size();
    
    // Retorna true se e somente se a fila estiver vazia
    bool empty();

    // Remove todos os elementos da fila, ou seja, deixa a fila vazia
    void clear();

    //Insere no final da fila
    void push(T value); 

    // Remove e retorna o primeiro elemento da fila.
    // Se a fila estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    T pop(); 

};
#include "queue.cpp"
#endif