#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

class DoubleVector {
private:
    int m_head;
    int m_size;
    int m_capacity;
    int m_tail;
    int* m_list;
public:
    // construtor: cria lista vazia
    DoubleVector();
    // construtor de copia
    DoubleVector(int n);
    // destrutor: libera memoria alocada
    ~DoubleVector();
    //Retorna o numero de elementos na lista.
    int size();
    //Retorna true se a lista estiver vazia e false caso contrário.
    bool empty();
    //Insere o inteiro value ao final da lista.
    void push_back(int value);
    //Remove elemento do final da lista e retorna seu valor.
    int pop_back();
    //Insere o inteiro value no inicio da lista.
    void push_front(int value); 
    //Remove elemento do inicio da lista e retorna seu valor.
    int pop_front(); 
    //Retorna o elemento da lista de índice k (Cuidado, é o índice dalista e não do vetor). A funcão verifica se k esta dentro dos limites de elementos validos. Caso contr´ario, retorna -1. Obrigatoriamente deve ser O(1).
    int at(int k);
    //Separei por uma questao de organizacao
    //Realiza o deslocamento completo, seja para a esquerda, de acordo a descrição na Seção 1.1.1. Caso desejem, podem dividir em duas funções
    void leftshift();
    //Realiza o deslocamento completo, seja para a direita, de acordo a descrição na Seção 1.1.1. Caso desejem, podem dividir em duas funções
    void rightshift();
    //Realiza o redimensionamento, de acordo a descrição na Secão 1.2.
    void resize();
    //Remove o elemento de índice k da lista (Cuidado, é o índice da lista e n˜ao do vetor) de acordo a descrição na Seção 1.1.2. A ordem dos demais elementos da lista devem se manter.
    void remove(int k); 
    //Remove da lista todas as ocorrências de value. A ordem dos demais elementos da lista entre se devem se manter.
    void removeAll(int value);
    //Imprime os elementos da lista.
    void print();
    //Imprime os elementos da lista em ordem reversa.
    void printReverse();
    //Concatena a lista atual com a lista lst passada por parâmetro. A lista lst não é modificada nessa operação. Os elementos de lst serão adicionados na ordem no final da lista do objeto da fun¸c˜ao.
    void concat(DoubleVector& lst);
     // Determina se a lista passada por parâmetro é igual à lista em questão. Duas listas são iguais se elas possuem o mesmo tamanho
    //e o valor do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista 
    bool equals(DoubleVector& lst);
    //Substitui o valor no índice k pelo elemento value (somente se 0 <= k <= m_size -1).
    void replaceAt(int value, int k);
   // Insere um elemento no indice k da lista. Nesse caso, um deslocamento parcial deve ser feito no sentido onde tem menos espaços disponíveis, semelhante a descrito na seção 1.1.2 da atividade mãe..
    void insert(int value, int k);
};

#endif