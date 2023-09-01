#include<iostream>

using namespace std;

class DoubleVector{
    private:
    int head;
    int m_size;
    int m_capacity;
    int tail;
    int* m_list;
    public:
    DoubleVector() {
        int metade = (m_capacity - 1) / 2;
        m_list = new int[16];
        head = metade;
        m_size = 0;
        m_capacity = 16;
        tail = metade + 1;
    }
    DoubleVector(int n) {
        int metade = (n - 1) / 2;
        m_list = new int[n];
        head = metade;
        m_size = 0;
        m_capacity = n;
        tail = metade + 1;
    }
    ~DoubleVector() {
        delete[] m_list;
    }
    int size() {
        return m_size;
    }
    bool empty() {
        return m_size == 0;
    }
    void push_back(int value) {
        if (m_size == m_capacity) {
            resize();
        }
        m_list[tail] = value;
        tail += 1;
        m_size += 1;
    }
    int pop_back() {
        if (m_size > 0) {
            tail -= 1;
            m_size -= 1;
            return m_list[tail];
        }
        return -1;
    }
    void push_front(int value) {
        if (m_size == m_capacity) {
            resize();
        }
        for (int i = m_size; i > 0; i--) {
            m_list[head + i] = m_list[head + i - 1];
        }
        m_list[head] = value;
        tail += 1;
        m_size += 1;
    }
    int pop_front() {
        if (m_size > 0) {
            int value = m_list[head];
            for (int i = 0; i < m_size - 1; i++) {
                m_list[head + i] = m_list[head + i + 1];
            }
            tail -= 1;
            m_size -= 1;
            return value;
        }
        return -1;
    }
    int at(int k) {
        if (k >= 0 && k < m_size) {
            return m_list[head + k];
        }
        return -1;
    }
    void shift() {
        int shiftCount = m_size / 2;
        int* newList = new int[m_capacity];
        for (int i = 0; i < m_size; i++) {
            newList[head + (i + shiftCount) % m_size] = m_list[head + i];
        }
        delete[] m_list;
        m_list = newList;
        head = 0;
        tail = m_size;
    }
    void resize() {
        int newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        int* newList = new int[newCapacity];
        for (int i = 0; i < m_size; i++) {
            newList[head + i] = m_list[head + i];
        }
        delete[] m_list;
        m_list = newList;
        m_capacity = newCapacity;
    }
    void remove(int k) {
        if (k >= 0 && k < m_size) {
            for (int i = k; i < m_size - 1; i++) {
                m_list[head + i] = m_list[head + i + 1];
            }
            tail -= 1;
            m_size -= 1;
        }
    }
    void removeAll(int value) {
        int dest = head;
        for (int src = head; src < tail; src++) {
            if (m_list[src] != value) {
                m_list[dest] = m_list[src];
                dest += 1;
            } else {
                m_size -= 1;
            }
        }
        tail = dest;
    }
    void print() {
        for (int i = head; i < tail; i++) {
            cout << m_list[i] << " ";
        }
        cout << endl;
    }
    void printReverse() {
        for (int i = tail - 1; i >= head; i--) {
            cout << m_list[i] << " ";
        }
        cout << endl;
    }
    void concat(DoubleVector& lst) {
        int newSize = m_size + lst.m_size;
        if (newSize > m_capacity) {
            resize();
        }
        for (int i = 0; i < lst.m_size; i++) {
            m_list[tail] = lst.m_list[lst.head + i];
            tail += 1;
        }
        m_size = newSize;
    }
    bool equals(DoubleVector& lst) {
        if (m_size != lst.m_size) {
            return false;
        }
        for (int i = 0; i < m_size; i++) {
            if (m_list[head + i] != lst.m_list[lst.head + i]) {
                return false;
            }
        }
        return true;
    }
    void replaceAt(int value, int k) {
        if (k >= 0 && k < m_size) {
            m_list[head + k] = value;
        }
    }
    void insert(int value, int k) {
        if (k >= 0 && k <= m_size) {
            if (m_size == m_capacity) {
                resize();
            }
            for (int i = m_size; i > k; i--) {
                m_list[head + i] = m_list[head + i - 1];
            }
            m_list[head + k] = value;
            tail += 1;
            m_size += 1;
        }
    }
};

void print(DoubleVector& list){
    if(!list.empty()){
        printf("%d\n", list.size());
    	for(int i = 0; i < list.size(); i++) printf("%d ", list.at(i));
    	printf("\n");
    }else printf("Lista Vazia\n");
}
void remove(DoubleVector& list) {
    if(!list.empty()){
    	while(!list.empty()){
    	    printf("%d ", list.pop_back());
    	    if(!list.empty()) printf("%d ", list.pop_front());
    	}
    	printf("\n");
    }
}
void copy(DoubleVector& origin, DoubleVector& destiny){
    for(int k = 0; k < origin.size(); k++){
        destiny.push_back(origin.at(k));
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
	//Testa o construtor default
	DoubleVector listaPares, listaImpares;

	//Testa as fun��es push_back
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

	printf("Testa o construtor com parametro n\n");
	DoubleVector listaSomentePar(listaPares.size()), listaSomenteImpar(listaImpares.size());
	copy(listaPares, listaSomentePar);
	copy(listaImpares, listaSomenteImpar);
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
	    listaSomentePar.remove(index);
	}
	if(listaSomenteImpar.size() > 10){
	    int index;
	    scanf("%d", &index);
	    listaSomenteImpar.remove(index);
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
	DoubleVector listaConcat1(listaSomenteImpar.size());
	copy(listaSomenteImpar, listaConcat1);
	listaConcat1.concat(listaSomentePar);
	DoubleVector listaConcat2(listaSomentePar.size());
	copy(listaSomentePar, listaConcat2);
	listaConcat2.concat(listaSomenteImpar);
	print(listaConcat1);
	print(listaConcat2);
	print(listaSomentePar);
	print(listaSomenteImpar);

	printf("Testa a funcao equals\n");
	printf("%d\n", listaConcat1.equals(listaConcat2));
	DoubleVector listaEqual(listaSomenteImpar.size());
	copy(listaSomenteImpar, listaEqual);
	printf("%d\n", listaEqual.equals(listaSomenteImpar));

	printf("Testa a funcao equals\n");
	printf("%d\n", listaConcat1.equals(listaConcat2));

	printf("Testa a funcao pop_back e pop_front\n");
	remove(listaSomentePar);
	remove(listaSomenteImpar);
}