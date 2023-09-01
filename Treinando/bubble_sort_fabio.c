#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void bubble_sort(int vet[], int size){
    int aux;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;     
            }
        }
    }
}

int main(){
    int vet[1000];   
    for(int i = 0; i < 1000; i++){
        vet[i] = rand() % 2000;
    }
    int size = sizeof(vet) / sizeof(int);
    bubble_sort(vet, size);
    clock_t Ticks[2];
    Ticks[0] = clock();
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();
    return 0;
}