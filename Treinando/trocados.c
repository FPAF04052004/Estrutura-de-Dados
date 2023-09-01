#include <stdio.h>
#include <string.h>

void sort_trocados(int vet[], int n){
    int aux_1;
    int aux_2;
    int pos_1;
    int pos_2;
    for(int i = 0; i < n - 1; i++){
        if(vet[i] > vet[i + 1]){
            aux_1 = vet[i];
            pos_1 = i;
            break;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(vet[i] > vet[pos_1 - 1] && vet[i] < vet[pos_1 + 1]){
            aux_2 = vet[i];
            pos_2 = i;
            break;
        } 
    }
    vet[pos_1] = aux_2;
    vet[pos_2] = aux_1;
}

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    sort_trocados(vetor, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}