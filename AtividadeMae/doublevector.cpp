#include <iostream>
#include "doublevector.h"

using namespace std;
//Em ambos os construtores o metade funciona apenas como um auxiliar, m_tail e m_head nao possuem valores apenas expandem o vetor
//Construtor de capacidade padrao, 16
//Variavel metade faz com que as variaveis m_head e m_tail comecem na metade do vetor lado a lado. Nesse caso m_head sera 7 e m_tail 8
DoubleVector::DoubleVector() {
    m_capacity = 16;
    m_list = new int[m_capacity];
    m_size = 0;

    int metade = m_capacity / 2;
    m_head = metade - 1;
    m_tail = metade;
}
//Construtor de capacidade n
//Variavel metade faz com que as variaveis m_head e m_tail comecem na metade do vetor lado a lado
DoubleVector::DoubleVector(int n) {
    m_capacity = n;
    m_list = new int[m_capacity];
    m_size = 0;

    int metade = m_capacity / 2;
    m_head = metade - 1;
    m_tail = metade;
}
//Tentei fazer isso. Mas dava double free quando eu testava push front, pois o vetor ja esta sendo deletado la.
//Se o senhor ver ate a proxima aula poderia comentar em sala se tem algum problema?
DoubleVector::~DoubleVector() {
    //delete[] m_list; 
}
//Retorna o valor do size
int DoubleVector::size() {
    return m_size;
}
//Checa se o vetor esta vazio. Se estiver retorna true, ou seja, se m_size for igual a zero.
//Caso contrario retorna false
bool DoubleVector::empty() {
    return (m_size == 0);
}
//Se o vetor tiver chegado ao limite da capacidade ele entra no if e sofre um deslocamento para a esquerda usando a função leftshift
//Caso contrario a m_tail recebe o novo valor e tanto ele quanto o size sao incrementador, pois o m_tail sempre aponta para im endereco vazio e o m_size pq representa o numero de elementos presentes
void DoubleVector::push_back(int value) {
    if (m_tail == m_capacity) {
        leftshift();
    }
    m_list[m_tail++] = value;
    m_size++;
}
//Se nao tiver nada retorna -1 como esta na descricao
//Caso contrario, decrementa o tamanho e a m_tail, assim o valor na m_tail vira lixo de memoria e retorna o valor que ela esta apontando que nao faz mais parte do vetor
int DoubleVector::pop_back() {
    if (m_size > 0) {
        m_size--;
        return m_list[--m_tail];
    }else{
        return -1;
    }
}
//Se nao tiver mais espaco do lado esquerdo e o m_head passar a apontar para uma endereço negativo ocorre um descolamento total para a direita
//Caso contrario adiciona-se ao esquerda, onde estava a m_head, aumenta o tamanho do vetor e recua a m_head para um endereco vazio mais a esquerda
void DoubleVector::push_front(int value) {
    if (m_head < 0) {
        rightshift();
    }
    m_list[m_head--] = value;
    m_size++;
}
int DoubleVector::pop_front() {
    if (m_size > 0) {
        m_size--;
        return m_list[++m_head];
    }else{//Se estiver vazio retorna -1
        return -1;
    }
}
int DoubleVector::at(int k) {
    if(k >= 0 && k < m_capacity){
        return m_list[(m_head + 1) + k];
    }
    return -1;
}
void DoubleVector::leftshift(){
    if (m_head < 1){//Checa se ainda tem espaco para o lado esquerdo, lado do m_head, se tiver redimenciona
        resize();
    }else{//Caso contrario faz o deslocamento direto para a esquerda
        for (int i = m_head - 1; i < m_tail - 2; i++){
            m_list[i] = m_list[i + 2];
        }
        //Deixa o mesmo espaco sobrando de ambos os lados, -2 e e para a esquerda
        //m_head -= 2 move o inicio do vetor duas casas mais para a esquerda
        m_head -= 2;
        //m_tail -= 2 move o final do vetor duas casas mais para a esquerda
        m_tail -= 2;
    }
}
void DoubleVector::rightshift(){
    if (m_tail == m_capacity){ //Redimenciona se necessario, ou seja, se a m_tail chegou ao fim da capacidade e nao tem mais espaco
        resize();
    }else{
        for (int i = m_tail + 1; i > m_head + 2; i--){//Caso contrario desloca direto para a direit
            m_list[i] = m_list[i - 2];
        }
        //Deixa o espaco sobrando igual em ambos os lados, +2 pq e para a direita
        //m_head += 2 move o inicio do vetor duas casas mais para a direita
        m_head += 2;
        //m_tail += 2 move o final do vetor duas casas mais para a direita
        m_tail += 2;
    }
}
//Dobra a capacidade e copia a lista antiga para nova, lembrando que o vetor comeca em m_head + 1, pois o m_head e apenas um ponteiro
void DoubleVector::resize(){
    int newCapacity = m_capacity * 2;
    int* newList = new int[newCapacity];
    for (int i = 0; i < m_size; i++) {
        newList[(m_head + 1) + i] = m_list[(m_head + 1) + i];
    }
    //Era por conta desse delete abaixo que dava o problema de double free, pois quando chegava no push_front o vetor ja tava cheio e precisava redimencionar
    delete[] m_list;
    m_list = newList;
    m_capacity = newCapacity;
}
//Remove o elemento no indice indicado
void DoubleVector::remove(int k) {
    //checa se k e um valor valido
    if (k >= 0 && k < m_size) {
        for (int i = k; i < m_size - 1; i++) {
            //Percorre o vetor comecando em m_head + 1
            m_list[(m_head + 1) + i] = m_list[(m_head + 1) + i + 1];
        }
        //A cauda puxada para a esquerda por conta da remocao
        m_tail -= 1;
        //Reduz o tamanho, ja que saiu um elemento
        m_size -= 1;
    }
}
//Remove todas as ocorrencias de value tirando a primeira
void DoubleVector::removeAll(int value) { 
    for (int i = 0; i < m_size; i++) {
        if (m_list[(m_head + 1) + i] == value) {
            //Remove a ocorrencia do valor
            remove(i);
            //Volta o indice para compensar o elemento removido
            i -= 1;
        }
    }
}
//Imprime o vetor da frente para tras, ou seja, comeca no primeiro elemento ,m_head + 1 ja que o m_head esta vazio, e vai ate m_tail -1, pois a m_tail esta vazia
void DoubleVector::print() {
    for (int i = m_head + 1; i < m_tail; i++) {
        cout << m_list[i] << " ";
    }
    //Quebra de linha
    cout << endl;
}
//Imprime o vetor de tras para frente, comecando na m_tail - 1, pois a m_tail esta vazia e so serve para espandir o vetor para a direita e vai ate m_head -1, pois a m_head esta vazia e so serve para espandir para o lado esquerdo
void DoubleVector::printReverse() {     
    for (int i = m_tail - 1; i > m_head ; i--) {
        cout << m_list[i] << " ";
    }
    //Quebra de linha
    cout << endl;
}
void DoubleVector::concat(DoubleVector& lst) {
    //Soma o tamanho de ambas as listas
    int newSize = m_size + lst.m_size;
    for (int i = 0; i < lst.m_size; i++) { 
        //Usei o push_back para nao correr risco de estourar a memoria
        //Adiciona os elmentos da segunda lista ao fim da primeira conversando sua ordem. Por isso
        push_back(lst.m_list[(lst.m_head + 1) + i]);
    }
    //Atualiza o tamanho
    m_size = newSize;   
}
bool DoubleVector::equals(DoubleVector& lst) {
    //Se os tamanhos forem diferentes ja nao sao iguais
    if (m_size != lst.m_size) {
        return false;
    }else{//Caso contrario compara as duas listas elemento por elemento
        int j = m_head + 1;//Os indices de inicio de cada vetor podem ser diferented por criei essa variavel auxiliar
        for (int i = lst.m_head + 1; i < lst.m_tail; i++, j++) {      
            if (m_list[j] != lst.m_list[i]){//Se encontrar algum valor diferente volta false
                return false;
            }
        }
        //Se passar em tudo retorna verdaderio
        return true;
    }
}
void DoubleVector::replaceAt(int value, int k) {
    //Checa se o indice e valido
    if (k >= 0 && k < m_size) {
        //Busca a posicao desejada somando o inicio com o indice e substitui o valor
        m_list[(m_head + 1) + k] = value;     
    }
}
void DoubleVector::insert(int value, int k) {
    //Chega se o indice e valido
    if(k >= 0 && k <= m_size){          
        if(m_size == m_capacity){//Checa se esta cheio
            resize();
        }
        //Se nao estiver desloca todos do indice para tras com o intuito de abrir espaco para o novo valor
        for (int i = m_size; i > k; i--){
            m_list[(m_head + 1) + i] = m_list[(m_head + 1) + i - 1]; 
        }
        //Insere o novo valor
        m_list[(m_head + 1) + k] = value; 
        //Desloca a m_tail mais para a direita ja que foi inserido um novo elemento
        m_tail += 1;
        //Aumenta o tamanho
        m_size += 1;
    }
}