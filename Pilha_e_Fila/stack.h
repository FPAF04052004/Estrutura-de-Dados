#ifndef STACK_H
#define STACK_H
#include "node.h"

template<typename T>
class Stack{
private:
    Node<T>* m_top; // Ponteiro para o topo da pilha se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria pilha vazia
    Stack();

    // construtor de copia. A fila lst deve se manter com os mesmo valores.
    Stack(Stack<T>& lst);
    
    // destrutor: libera memoria alocada
    ~Stack();

    // retorna o numero de elementos na lista
    int size();
    
    // Retorna true se e somente se a pilha estiver vazia
    bool empty();

    // Remove todos os elementos da pilha, ou seja, deixa a pilha vazia
    void clear();

    // Insere no topo da pilha
    void push(T value); 
    
    // Remove elemento do topo da pilha
    // Se a pilha estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    T pop(); 
    
    // Consulta o elemento no topo da pilha sem remove-lo.
    T top(); 
};
#include "stack.cpp"
#endif