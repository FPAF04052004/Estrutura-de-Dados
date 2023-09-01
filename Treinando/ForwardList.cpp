#include <stdio.h>

class Node {
private:
    int value;  // valor 
    Node* next;  // ponteiro para o proximo no 
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e o ponteiro para o 
     * próximo nó da lista.
     * */
    Node(int val, Node *nextPtr){
        value = val;
        next = nextPtr;
    }
    
    /**
    Métodos gets e sets dos atributos
    **/
    int getValue(){
        return value;
    }
    Node* getNext(){
        return next;
    }
    void setvalue(int newValue){
        value = newValue;
    }
    void setNext(Node* newNext){
        next = newNext;
    }
};

class ForwardList {
private:
    Node* m_head; // aponta para o inicio da lista se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
 
    ForwardList(){
        this->m_size = 0;
        this->m_head = new Node(0, nullptr);
    }
    ForwardList(ForwardList& lst){
        this->m_head = new Node(0, nullptr);
        this->m_size = lst.m_size;
        Node* aux = lst.m_head->getNext();
        while(aux != nullptr){
            push_back(aux->getValue());
            aux = aux->getNext();
        }
    }
    ~ForwardList(){
        clear();
        delete m_head;
        m_size = 0;
    }
    int size() const{
        return m_size;
    }
    bool empty() const{
        if(m_size == 0){
            return true;
        }else{
            return false;
        }
    }
    void clear(){
        while(m_head->getNext() != nullptr){
            Node* viajante = m_head->getNext();
            m_head->setNext(viajante->getNext());
            delete viajante;
            m_size -= 1;
        }
    }
    int at(int k){
        if(k < 0 || k > m_size - 1){
            return -1;
        }else{
            int cont = 0;
            Node* aux = m_head;
            while(cont <= k){
                aux = aux->getNext();
                cont += 1;
            }
            return aux->getValue();
        }
    }
    void push_back(int value){
        Node* viajante = m_head;
        while(viajante->getNext() != nullptr){
            viajante = viajante->getNext();
        }
        Node* aux = new Node(value, nullptr);
        viajante->setNext(aux);
        m_size += 1;
    }
    int pop_back(){
        if(m_size == 0){
            return -1;
        }else{
            Node* aux = m_head;
            while(aux->getNext()->getNext() != nullptr){
                aux = aux->getNext();
            }
            int valor = aux->getNext()->getValue();
            delete aux->getNext();
            aux->setNext(nullptr);
            m_size -= 1;
            return valor;
        }
    }
    void insert(int value, int k){
        if(k >= 0 && k < m_size){
            Node* viajante = m_head;
            int cont = 0;
            while(cont <= k){
                viajante = viajante->getNext();
            }
        }
    }
    Node* getNode(int k){
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
    void replaceAt(int value, int k) {
        if (k >= 0 && k < size()) {
            Node* aux = m_head->getNext();
            int cont = 0;
            while (cont < k) {
                aux = aux->getNext();
                cont += 1;
            }
            aux->setvalue(value);
        }
    }
    void removeAll(int value) {
        Node* aux = m_head;
        while (aux->getNext() != nullptr) {
            if (aux->getNext()->getValue() == value) {
                Node* morto = aux->getNext();
                aux->setNext(aux->getNext()->getNext());
                delete morto;
                m_size -= 1;
            }else{
                aux = aux->getNext();
            }
        }
    }
    void push_front(int value) {
        Node* aux = new Node(value, m_head->getNext());
        m_head->setNext(aux);
        m_size += 1;
    }
    int pop_front(){
        Node* aux = m_head->getNext();
        int value = aux->getValue();
        m_head->setNext(aux->getNext());
        delete aux;
        m_size -= 1;
        return value;
    }
    bool equals(ForwardList& lst) {
        if (m_size != lst.m_size) {
            return false;
        }else{
            Node* aux1 = m_head->getNext();
            Node* aux2 = lst.m_head->getNext();
            while (aux1 != nullptr) {
                if (aux1->getValue() != aux2->getValue()) {
                    return false;
                }
                aux1 = aux1->getNext();
                aux2 = aux2->getNext();
            }
            return true;
        }
    }
    void concat(ForwardList& lst) {
        Node* aux = m_head;
        while (aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        Node* lstNode = lst.m_head->getNext();
        while (lstNode != nullptr) {
            aux->setNext(new Node(lstNode->getValue(), nullptr));
            aux = aux->getNext();
            lstNode = lstNode->getNext();
            m_size += 1;
        }
    }
    void removeAt(int k){
        if (k >= 0 && k < m_size) {
            Node* aux = m_head;
            int cont = 0;
            while (cont < k) {
                aux = aux->getNext();
                cont++;
            }
            Node* morto = aux->getNext();
            aux->setNext(aux->getNext()->getNext());
            delete morto;
            m_size -= 1;
        }
    }
    void remove_duplicates() {
        Node* viajante = m_head->getNext();
        while (viajante != nullptr){
            Node* comparador = viajante;
            while(comparador->getNext() != nullptr){
                if(viajante->getValue() == comparador->getNext()->getValue()){
                    Node* remover = comparador->getNext();
                    comparador->setNext(remover->getNext());
                    delete remover;
                    m_size -= 1;
                }else{
                    comparador = comparador->getNext();
                }
            }
            viajante = viajante->getNext();
        }
  }

};     
void print(ForwardList& list){
    if(!list.empty()){
        printf("%d\n", list.size());
        for(int i = 0; i < list.size(); i++) printf("%d ", list.at(i));
        printf("\n");        
    }else printf("Lista Vazia\n");
}
void remove(ForwardList& list){
    if(!list.empty()){
        while(!list.empty()){
            printf("%d ", list.pop_back());
            if(!list.empty()) printf("%d ", list.pop_front());
        }
        printf("\n"); 
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
	//Testa o construtor default
	ForwardList listaPares, listaImpares;
	
	//Testa as funções push_back e resize
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    if(k % 2 == 0) listaPares.push_back(k);
		else listaImpares.push_back(k);
	}
	printf("Testa o construtor default, funcoes push_back e at\n");
	print(listaPares);
	print(listaImpares);
	
	printf("Testa a funcao pop_back\n");
	if(listaPares.size() > 10){
	    for(int i = 0; i < 5; i++) listaPares.pop_back();  
	} 
	if(listaImpares.size() > 10){
	    printf("%d %d\n", listaImpares.pop_back(), listaImpares.pop_back());
	}
	print(listaPares);
	print(listaImpares);
	
	printf("Testa o construtor que faz copia\n");
	ForwardList listaSomentePar(listaPares), listaSomenteImpar(listaImpares);
	print(listaSomentePar);
	print(listaSomenteImpar);	
	
	printf("Testa a funcao replaceAt\n");
	if(listaSomentePar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomentePar.replaceAt(value, index);
	}
	if(listaSomenteImpar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomenteImpar.replaceAt(value, index);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao removeAt\n");
	if(listaSomentePar.size() > 10){
	    int index; 
	    scanf("%d", &index);
	    listaSomentePar.removeAt(index);
	}
	if(listaSomenteImpar.size() > 10){
	    int index; 
	    scanf("%d", &index);
	    listaSomenteImpar.removeAt(index);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao insert\n");
	if(listaSomentePar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomentePar.insert(value, index);
	}
	if(listaSomenteImpar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomenteImpar.insert(value, index);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao removeAll\n");
	if(listaSomentePar.size() > 10){
	    int value; 
	    scanf("%d", &value);
	    listaSomentePar.removeAll(value);
	}
	if(listaSomenteImpar.size() > 10){
	    int value; 
	    scanf("%d", &value);
	    listaSomenteImpar.removeAll(value);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);	
	
	printf("Testa a funcao push_front\n");
	if(listaSomentePar.size() >= 2){
	    int value; 
	    scanf("%d", &value);
	    listaSomentePar.push_front(value);
	    scanf("%d", &value);
	    listaSomentePar.push_front(value);	    
	}
	if(listaSomenteImpar.size() >= 2){
	    int value; 
	    scanf("%d", &value);
	    listaSomenteImpar.push_front(value);
	    scanf("%d", &value);
	    listaSomenteImpar.push_front(value);	    
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao concat\n");
	ForwardList listaConcat1(listaSomenteImpar);
	listaConcat1.concat(listaSomentePar);
	ForwardList listaConcat2(listaSomentePar);
	listaConcat2.concat(listaSomenteImpar);
	print(listaConcat1);	
	print(listaConcat2);
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao equals\n");
	printf("%d\n", listaConcat1.equals(listaConcat2));
	ForwardList listaEqual(listaSomenteImpar);
	printf("%d\n", listaEqual.equals(listaSomenteImpar));
	
	printf("Testa a funcao equals\n");
	printf("%d\n", listaConcat1.equals(listaConcat2));
	
	printf("Testa a funcao pop_back e pop_front\n");
	remove(listaSomentePar);
	remove(listaSomenteImpar);
}