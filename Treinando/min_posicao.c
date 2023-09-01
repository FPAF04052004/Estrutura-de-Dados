#include <stdio.h>
#include <string.h>

void min_posicao(int vet[], int ini, int fim){
    int min = ini;
    for(int i = ini + 1; i <= fim; i++) if(vet[min] > vet[i]) min = i;
    
    int aux = vet[min];
    vet[min] = vet[ini];
    vet[ini] = aux;
}

void aluno_sort(int vet[], int ini, int fim){
    if(ini == fim){
        return;
    }else{
        min_posicao(vet, ini, fim);
        ini += 1;
        aluno_sort(vet, ini, fim);
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    aluno_sort(vetor, 0, n - 1);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}