#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

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
    clock_t tempo;
	tempo = clock();
    int n;
    scanf("%d", &n);
    int vet[n];   
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 100000000;
    }
    int size = sizeof(vet) / sizeof(int);
    selection_sort(vet, size);
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
    return 0;
}