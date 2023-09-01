#include <string.h>
#include<stdio.h>

void merge(int vet[], int ini, int um_terco, int dois_terco, int fim, int aux[]){
    int i = ini;
    int j = um_terco;
    int k = dois_terco;
    int l = fim;
 
    while ((i < um_terco) && (j < dois_terco) && (k < fim)){
        if(gArray[i] < gArray[j]){
            if(gArray[i] < gArray[k]){
                destArray[l++] = gArray[i++];
            }else{
                destArray[l++] = gArray[k++];
            }
        }
        else{
            if(gArray[j] < gArray[k]){
                destArray[l++] = gArray[j++];
            }else{
                destArray[l++] = gArray[k++];
            }
        }
    }
 
    while ((i < mid1) && (j < mid2)){
        if(gArray[i] < gArray[j]){
            destArray[l++] = gArray[i++];
        }else{
            destArray[l++] = gArray[j++];
        }
    }
 
    while ((j < mid2) && (k < high)){
        if(gArray[j] < gArray[k]){
            destArray[l++] = gArray[j++];
        }else{
            destArray[l++] = gArray[k++];
        }
    }
 
    while ((i < mid1) && (k < high)){
        if(gArray[i] < gArray[k]){
            destArray[l++] = gArray[i++];
        }else{
            destArray[l++] = gArray[k++];
        }
    }
 

    while (i < mid1)
        destArray[l++] = gArray[i++];
 
    while (j < mid2)
        destArray[l++] = gArray[j++];
 
    while (k < high)
        destArray[l++] = gArray[k++];
}
 
void merge_sort3_recursivo(int vet[], int ini, int fim, int aux[]){
    if (ini - fim < 2){
        return;
    }
 
    int um_terco = ini + ((fim - ini) / 3);
    int dois_terco = ini + 2 * ((fim - ini) / 3) + 1;
 
    // Sorting 3 arrays recursively
    merge_sort3_recursivo(vet, ini, um_terco, aux);
    merge_sort3_recursivo(vet, um_terco, dois_terco, aux);
    merge_sort3_recursivo(vet, dois_terco, fim, aux);
 
    // Merging the sorted arrays
    merge(vet, ini, um_terco, dois_terco, fim, aux);
}
 
void merge_sort3(int vet[], int n){
    if (n == 0){
        return;
    }
 
    int aux[n];
    for (int i = 0; i < n; i++){
        aux[i] = vet[i];
    }
 
    merge_sort3_recursivo(vet, 0, n, aux);
 
    for (int i = 0; i < n; i++){
        vet[i] = aux[i];
    }
}
 
int main(){
    int n;
    scanf("%d", &n);
    int vet[n];

    merges_sort3(vet, n);
    for (int i = 0; i < n; i++){
        prinf("%d", vet[i]);
    }
    return 0;
}