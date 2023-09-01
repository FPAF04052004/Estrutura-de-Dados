#include<stdio.h>

int teto(int vet[], int ini, int fim, int k, int max){
    if(ini > fim){
        return max;
    }else{
        int aux = (ini + fim) / 2;
        if(k > vet[aux]){
            return teto(vet, aux - 1, fim, k, max);
        }else{
            max = vet[aux];
            return teto(vet, ini, aux - 1, k, max);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0;i < n; i++){
        scanf("%d", &vet[i]);
    }
    int k;
    scanf("%d", &k);
    printf("Teto = %d", teto(vet, 0, n, k, vet[0]));
    return 0;
}