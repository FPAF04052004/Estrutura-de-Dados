#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void insertion_sort(int vet[], int n){
    int aux;
    int i;
    int j;
    for(i = 1; i < n; i++){
        aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]); j--){
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
    }
    //Insertion sort só deu certo até 500000. Tempos de execução em segundos: 1.876, 2.628, 2.863, 6.760, 23.469, , 50.156, 107.972, 312.825
    //Pior caso Novamento só deu certo até 500000. Tempos de execução em segundos: 3.203, 5.513, 3.788, 4.187, 3.035, 3.319, 2.920, 12.371, 
}


int main(int argc, char **argv){
	//clock_t tempo;
	//tempo = clock();
    int n;
    scanf("%d", &n);
    int vet[n];   
    for(int i = 0; i < n; i++){
        scanf("%d", & vet[i]);
    }
    int size = sizeof(vet) / sizeof(int);
    insertion_sort(vet, size);
    //printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
    for(int i =0; i < n; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}