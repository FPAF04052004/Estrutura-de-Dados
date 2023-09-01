#include <stdio.h>

int maior(int vet[], int n){
    if(n == 0){
        return vet[0];
    }else{
        int max_elem = maior(vet, n-1);
        if(max_elem > vet[n -1]){
            return max_elem;
        }else{
            return vet[n - 1];
        }
    } 
}

int menor(int vet[], int n){
    if(n == 0){
        return vet[0];
    }else{
        if(menor(vet, n - 1) < vet[size - 1]){
            return menor(vet, n - 1);
        }else{
            return vet[size - 1];
        }
    }
}

int soma(int vet[], int ini, int fim){
    int acc = 0;
    if(ini == fim){
        return vet[ini];
    }else{
        acc = vet[ini] + acc;
        return soma(vet, ini + 1, fim);
    }
}

int mult(int vet[], int ini, int fim){
    int acc = 1;
    if(ini == fim){
        return vet[ini];
    }else{
        acc = vet[ini] * acc;
        return soma(vet, ini + 1, fim);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Soma = d", soma(vetor, 0, n - 1));
    printf("Mult = d", mult(vetor, 0, n - 1));
    printf("Maior elemento = %d\n", maior(vetor, n));
    printf("Menor elemento = %d\n", menor(vetor, n));

    return 0;
}