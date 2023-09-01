#include<stdio.h>

int ordenar(int vet[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; i < n - 1; i++){
            if(vet[i] > vet[j]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0;i < n; i++){
        scanf("%d", &vet[i]);
    }
    if(ordenar(vet, n)){
        printf("Esta ordenado");
    }else{
        printf("Nao esta ordenado");
    }
}