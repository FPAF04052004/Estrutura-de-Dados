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
    //Bubble sort so deu certo até 200000. Tempos de execução em segundos: 0.007, 0.099, 0.529, 13.373 , 46.728 e 165.089 tudo em segundos.
    //Pior caso: Novamento só deu certo até 200000. Tempos de execução em segundos: 2.470, 10.149, 34.753, 31.113 , 406.438 e 120.973
}

int main(int argc, char **argv){
	clock_t tempo;
	tempo = clock();
    int n;
    scanf("%d", &n);
    int vet[n];   
    for(int i = 0; i < n; i++){
        vet[i] = i;
    }
    int size = sizeof(vet) / sizeof(int);
    bubble_sort(vet, size);
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
    return 0;