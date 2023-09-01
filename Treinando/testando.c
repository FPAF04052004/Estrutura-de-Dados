#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
  
    int pivot = array[high];

    int i = (low - 1);
    for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {
        i++;
        swap(&array[i], &array[j]);
      }
    }
    swap(&array[i + 1], &array[high]);
    
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main(int argc, char **argv) {
    clock_t tempo;
    tempo = clock();
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){
        vet[i] =  i;
    }
    quickSort(vet, 0, n);
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}