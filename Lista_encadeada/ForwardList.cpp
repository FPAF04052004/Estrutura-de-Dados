#include "ForwardList.h"
#include "Node.h"

ForwardList::ForwardList(){
    this->m_size = 0;
    this->m_head = new Node(0, nullptr);
}
ForwardList::ForwardList(ForwardList& lst){
    m_head = new Node(0, nullptr);
    m_size = 0;
    while(lst.m_head->getNext() != nullptr){
        push_back(lst.m_head->getNext()->getValue());
    }
}
ForwardList::~ForwardList(){
    clear();
    delete m_head;
}
int ForwardList::size() const{
    return m_size;
}
bool ForwardList::empty() const{
    if(m_size == 0){
        return true;
    }else{
        return false;
    }
}
void ForwardList::clear(){
    while(m_head->getNext() != nullptr){
        Node* aux = m_head->getNext();
        m_head->setNext(aux->getNext());
        delete aux;
    }
    m_size = 0;
}
int ForwardList::at(int k){
    if(k < 0 || k > m_size - 1){
        return -1;
    }else{
        int cont = 0;
        Node* aux = m_head;
        while(cont <= k){
            aux->setNext(aux->getNext());
            cont += 1;
        }
        return aux->getValue();
    }
}
void ForwardList::push_back(int value){
    Node* viajante = m_head;
    while(viajante->getNext() != nullptr){
        viajante = viajante->getNext();
    }
    Node* aux = new Node(value, nullptr);
    viajante->setNext(aux);
    m_size += 1;
}
int ForwardList::pop_back(){
    if(m_size == 0){
        return -1;
    }else{
        Node* aux = m_head;
        while(aux->getNext()->getNext() != nullptr){
            aux->setNext(aux->getNext());
        }
        int valor = aux->getNext()->getValue();
        delete aux->getNext();
        aux->setNext(nullptr);
        m_size -= 1;
        return valor;
    }
}
void ForwardList::insert(int value, int k){
    if(k >= 0 && k <= m_size){
        int cont = 0;
        Node* viajante = m_head;
        while(cont < k){
            viajante = viajante->getNext();
            cont += 1;
        }
        Node *aux = new Node(value, nullptr);
        aux->setNext(viajante->getNext());
        viajante->setNext(aux);
        m_size += 1;
    }
}
void ForwardList::removeAt(int k){
    if(k <= 0; k < m_size){
        Node *aux = m_head;
        int cont = 0;
        while(cont < k - 1){
            aux = aux->getNext();
            cont++;
        }
        Node *remover = aux->getNext();
        aux->setNext(aux->getNext()->getNext());
        delete remover;
        m_size -= 1;
    }
}
Node* ForwardList::getNode(int k){
    if(m_head == nullptr || k < 0|| k >= m_size){
        return nullptr;
    }else{
        Node* atual = m_head;
        for(int i{0}; i < k; i++){
            atual = atual->getNext();
        }
        return atual;
    }
}
void ForwardList::replaceAt(int value, int k){
    Node* aux = m_head;
    int cont = 0;
    while(cont < k){
        aux = aux->getNext();
        cont += 1;
    }
    aux->setvalue(value);
}
void ForwardList::removeAll(int value){
    Node* aux = m_head;
    Node* morto;
    while(aux->getNext()->getNext() != nullptr){
        if(aux->getNext()->getValue() == value){
            morto = (aux->getNext());
            aux->setNext(aux->getNext()->getNext());
            delete morto;
            m_size -= 1;
        }
    }
}
void ForwardList::push_front(int value){
    Node* aux = new Node(value, nullptr);
    aux->setNext(m_head->getNext());
    m_head->setNext(aux);
    m_size += 1;
}
int ForwardList::pop_front(){
    Node *aux = m_head->getNext();
    int value = aux->getValue();
    m_head->setNext(aux->getNext());
    delete aux;
    m_size -= 1;
    return value; 
}  
bool ForwardList::equals(ForwardList& lst){
    if(m_size == lst.m_size){
        for(int i{0}; i < m_size; i++){
            if(at(i) != lst.at(i)){
                return false;
            }
        }
    }else{
        return false;
    }
    return true;
}
void ForwardList::concat(ForwardList& lst){
    Node *aux = lst.m_head->getNext();
    while(aux != nullptr){
        push_back(aux->getValue());
        aux = aux->getNext(); 
    }
} 
void ForwardList::remove_duplicates(){
    Node *viajante = m_head->getNext();
    for(int i{0}; viajante->getNext() != nullptr; i++){
        for(int j{i + 1}; viajante->getNext() != nullptr; j++){
            if(at(i) == at(j)){
                removeAt(j);
                j -= 1;
            }
        }
    }
}