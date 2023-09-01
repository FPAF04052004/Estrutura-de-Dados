#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;
    
    int L[n1], M[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    
    
    int i = 0;
    int j = 0;
    int k = p;
    
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
          arr[k] = L[i];
          i++;
        } else {
          arr[k] = M[j];
          j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    //Merge sort só deu certo até 1000000. Tempos de execução em segundos: 7.572, 1.117, 9.796, 17.904, 4.592, 3.753,8.184, 2.672,  2.075, 5.723
    // Pior caso novamente só deu certo até 1000000. Tempos de execução em segundos: 1.6170, 1.686, 1.870, 1.701, 1.870, 2.208, 3.608, 2.971, 4.253, 30.122.
} 
int main(int argc, char **argv){
	clock_t tempo;
	tempo = clock();
    int n;
    scanf("%d", &n);
    int *vet = (int *)(n * sizeof(int)); 
    for(int i = 0; i < n; i++){
        vet[i] = i;
    }
    int size = sizeof(vet) / sizeof(int);
    mergeSort(vet, 0, size);
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
    return 0;
}