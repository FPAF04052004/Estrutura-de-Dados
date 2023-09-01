#include <stdio.h>

void imprimeTrianguloRecursivo(int vetor[], int tamanho, int linhaAtual) {
    if (linhaAtual > tamanho) { // condição de parada da recursão
        return;
    }
    
    for (int i = 0; i < linhaAtual; i++) { // imprime os números da linha atual
        printf("%d ", vetor[i]);
    }
    printf("\n"); // pula para a próxima linha
    
    imprimeTrianguloRecursivo(vetor, tamanho, linhaAtual+1); // chama a função recursivamente para a próxima linha
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    imprimeTrianguloRecursivo(vetor, tamanho, 1); // começa a impressão do triângulo na primeira linha
    
    return 0;
}