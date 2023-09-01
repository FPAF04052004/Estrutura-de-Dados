#include<stdio.h>

void selection_sort(int vet[], int n){
    int menor; 
    int aux;
    for(int i = 0; i < n - 1; i++){
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }if(i != menor){
                aux = vet[i];
                vet[i] = vet[menor];
                vet[menor] = aux;
            }
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
    selection_sort(vet, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}