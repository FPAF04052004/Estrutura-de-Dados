#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void merge_3(int vet[], int ini, int meio,int fim){
    int aux[fim];
    int i = ini;
    int j = meio + 1;
    int l = 0;
    while(i <= meio && j <= fim){
        if(vet[i] <= vet[j]){
            aux[l++] = vet[i++];
        }else{
            aux[l++] = vet[j++];
        }
    }
    while(i <= meio){
        aux[l++] = vet[i++];
    }
    while(j <= fim){
        aux[l++] = vet[j++];
    }
    for(int k = 0; k <= fim; k++){
        vet[k] = aux[k];
    }
}

void merge_sort_3(int vet[], int ini, int fim){
    if(ini < fim){
        int um_terco = (ini + fim) / 3;
        int dois_tercos =  2 * ((ini + fim) / 3);
        merge_sort_3(vet, ini, um_terco);
        merge_sort_3(vet, um_terco + 1, dois_tercos);
        merge_sort_3(vet, dois_tercos + 1, fim);
        merge_3(vet, ini, um_terco, dois_tercos);
        merge_3(vet, ini, dois_tercos, fim);
    }
}

int main(){
    clock_t tempo;
    tempo = clock();
    int n;
    scanf("%d", &n);
    int *vet = (int *)(malloc(n * sizeof(int)));   
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 100000000;
    }
    int size = sizeof(vet) / sizeof(int);
    merge_sort_3(vet, 0, size)
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}