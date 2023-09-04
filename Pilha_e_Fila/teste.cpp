#include<stdio.h>

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
    Node(T val, Node<T> *nextPtr){
        value = val;
        next = nextPtr;
    }
    /**
    Métodos gets e sets dos atributos
    **/
    T getValue(){
        return value;
    }
    Node<T>* getNext(){
        return next;
    }
    void setValue(T newValue){
        value = newValue;
    }
    void setNext(Node<T>* newNext){
        next = newNext;
    }
};

template<typename T>
class Queue {
private:
    Node<T>* m_first; // Aponta para o inicio da fila se houver, caso contrário será null
    Node<T>* m_last; // Aponta para o final da fila se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria uma fila vazia
    Queue(){
        m_size = 0;
        m_first = nullptr;
        m_last = nullptr;
    }

    // construtor de copia. A pilha lst deve se manter com os mesmo valores.
    Queue(Queue<T>& lst){
         Node<T>* viajante = lst.m_first;
        while (viajante != nullptr) {
            push(viajante->getValue());
            viajante = viajante->getNext();
        }
    }
    
    // destrutor: libera memoria alocada
    ~Queue(){
        clear();
        delete m_first;
    }

    // retorna o numero de elementos na fila
    int size(){
        return m_size;
    }
    
    // Retorna true se e somente se a fila estiver vazia
    bool empty(){
        return (m_size == 0);
    }

    // Remove todos os elementos da fila, ou seja, deixa a fila vazia
    void clear(){
        while(!empty()){
            pop();
        }
    }

    //Insere no final da fila
    void push(T value){
        Node<T>* aux = new Node<T>(value, nullptr);
        if (empty()){
            m_first = m_last = aux;
        }else{
            m_last->setNext(aux);
            m_last = aux;
        }
            m_size += 1;
    }

    // Remove e retorna o primeiro elemento da fila.
    // Se a fila estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    T pop(){
        if (empty()) {
            throw this->runtime_error("Empty queue.");
        }else{
            Node<T>* viajante = m_first;
            T value = viajante->getValue;
            m_first = m_first->getNext();
            delete viajante;
            m_size -= 1;
            if (empty()) {
                m_last = nullptr;
            }
            return value;
        }
    }

};

template<typename T>
class Stack {
private:
    Node<T>* m_top; // Ponteiro para o topo da pilha se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria pilha vazia
    Stack(){
        m_top = nullptr;
        m_size = 0;
    }

    // construtor de copia. A fila lst deve se manter com os mesmo valores.
    Stack(Stack<T>& lst);
    
    // destrutor: libera memoria alocada
    ~Stack(){
        clear();
        delete m_top;
    }

    // retorna o numero de elementos na lista
    int size(){
        return m_size;
    }
    
    // Retorna true se e somente se a pilha estiver vazia
    bool empty(){
        return (m_size == 0);
    }

    // Remove todos os elementos da pilha, ou seja, deixa a pilha vazia
    void clear(){
        while ((!empty())){
            pop();
        }
    }

    // Insere no topo da pilha
    void push(T value){
        Node<T>* newNode = new Node(value, nullptr);
        newNode->setNext(m_top);
        m_top = newNode;
        m_size += 1;
    }
    
    // Remove elemento do topo da pilha
    // Se a pilha estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    T pop(){
        if (empty()){
            throw this->runtime_error("Empty stack.");
        }else{
            Node<T>* temp = m_top;
            T value = temp->getValue();
            m_top = m_top->getNext();
            delete temp;
            m_size -= 1;
            return value;
        }
    }
    
    // Consulta o elemento no topo da pilha sem remove-lo.
    T top(){
        if(empty()){
        throw this->runtime_error("Empty stack.");
        }else{
            return m_top->getValue();
        }
    }
};


void printQueue(Queue<int>& fila) {
    printf("%d\n", fila.size());
    while(!fila.empty()){
        printf("%d ", fila.pop());
    }
}
void printStack(Stack<int>& pilha) {
    printf("%d\n", pilha.size());
    while(!pilha.empty()){
        printf("%d ", pilha.pop());
    }
}
int main() {
    int n, k;
	Queue<int> fila;
	Stack<int> pilha;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    if(i % 2 == 0) fila.push(k);
		else pilha.push(k);
	}
	printQueue(fila);
	printStack(pilha);
}