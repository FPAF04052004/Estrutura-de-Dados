#include<stdio.h>

int insertion_sort_recursivo(int vet[], int pos, int n){
    int aux = vet[pos];
    if(n == pos){
        return vet[0];
    }else{
        if(aux < vet[pos - 1]){
            vet[pos] = vet[pos - 1];
            return insertion_sort_recursivo(vet, ini + 1, fim + 1, n);
        }else{
            return insertion_sort_recursivo(vet, ini + 1, fim + 1, n);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];   
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    insertion_sort_recursivo(vet, 1, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}