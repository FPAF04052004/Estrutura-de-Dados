#include<stdio.h>

int contem_soma(int vet[], int ini, int fim, int valor){
    if(ini == fim){
        return 0;
    }else if(vet[ini] + vet[fim] > valor){
        return contem_soma(vet, ini, fim - 1, valor);
    }else if(vet[ini] + vet[fim] < valor){
        return contem_soma(vet, ini + 1, fim, valor);
    }else{
        return 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    int valor;
    scanf("%d", &valor);
    if(contem_soma(vet, 0, n - 1, valor)){
        printf("Sim\n");
    }else{
        printf("Nao");
    }
    return 0;
}