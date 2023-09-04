#ifndef STACK_CPP
#define STACK_CPP
#include "stack.h"

using namespace std;

// construtor: cria pilha vazia
template<typename T>
Stack<T>::Stack(){
    m_top = nullptr;
    m_size = 0;
}
// construtor de copia. A fila lst deve se manter com os mesmo valores.
template<typename T>
Stack<T>::Stack(Stack<T>& lst){
    m_size = 0;
    for(int i{0}; i < lst.size(); i++){
        push(lst.pop());
    }
}
// destrutor: libera memoria alocada
template<typename T>
Stack<T>::~Stack(){
    clear();
}
// retorna o numero de elementos na lista
template<typename T>
int Stack<T>::size(){
    return m_size;
}
// Retorna true se e somente se a pilha estiver vazia
template<typename T>
bool Stack<T>::empty(){
    return (m_size == 0);
}
// Remove todos os elementos da pilha, ou seja, deixa a pilha vazia
template<typename T>
void Stack<T>::clear(){
    while(!empty()){
        pop();
    }
    m_size = 0;
}
// Insere no topo da pilha, push_back
template<typename T>
void Stack<T>::push(T value){
    if(empty()){
        m_top = new Node<T>(value, nullptr);
    }else{
        Node<T>* aux = new Node<T>(value, nullptr);
        aux->setNext(m_top);
        m_top = aux;
    }
    m_size += 1;
}
// Remove elemento do topo da pilha pop_back
// Se a pilha estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
template<typename T>
T Stack<T>::pop(){
    //O throw tava dando erro, por isso nao botei
    Node<T>* viajante = m_top;
    T valor = viajante->getValue();
    m_top = m_top->getNext();
    delete viajante;
    m_size -= 1;
    return valor;
    
}
// Consulta o elemento no topo da pilha sem remove-lo.
template<typename T>
T Stack<T>::top(){
    if (empty()) {
        throw this->runtime_error("Empty stack.");
    }else{
        return m_top->getValue();
    }
}
#endif