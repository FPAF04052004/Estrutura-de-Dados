#include<stdio.h>

void merge(int vet[], int ini, int um_terco, int dois_terco, int fim){
    int i = ini;
    int j = um_terco + 1;
    int l = dois_terco + 1;
    int index = ini;
    int temp[fim];
    while((i <= um_terco) && (j <= dois_terco) && (l <= fim) && (index <= fim)){
        if (vet[i] < vet[j]) {
            if(vet[i] < vet[l]){
                temp[index] = vet[i];
                i++;
            }else{
                temp[index] = vet[l];
                l++;
            }
        }else {
            if(vet[j] < vet[l]){
                temp[index] = vet[j];
                j++;
            }else{
                temp[index] = vet[l];
                l++;
            }
        }
        index ++;
    }
    for(int k = 0; k < index; k++){
        printf("%d ", temp[k]);
    }
    return;
    for(int k = 0; k < index; k++){
        vet[k] = temp[k];
    }
}

void merge_sort3(int vet[], int ini, int fim){
    if(ini < fim){
        int um_terco = (ini + fim) / 3;
        int dois_tercos = 2 * ((ini + fim) / 3);
        merge_sort3(vet, 0, um_terco);
        merge_sort3(vet, um_terco + 1, dois_tercos);
        merge_sort3(vet, dois_tercos + 1, fim);
        merge(vet, ini, um_terco, dois_tercos, fim);
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    merge_sort3(vetor, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}