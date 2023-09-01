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

int main(int argc, char **argv){
	clock_t tempo;
	tempo = clock();
    int n;
    scanf("%d", &n);
    int vet[n];   
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 100000000;
    }
    int size = sizeof(vet) / sizeof(int);
    bubble_sort(vet, size);
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
    return 0;
}