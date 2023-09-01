#include<stdio.h>
int teto(int vet[], int ini, int fim, int k, int max){
    if(k <= max) return max;
    int aux;
    if(fim % 2 == 0) aux = (ini + fim) / 2;
    else aux = (ini + fim) / 2 + 1;
    if(k > vet[aux]) return teto(vet, aux - 1, fim, k, vet[aux]);
    else if(k == vet[aux]) return vet[aux];
    else return teto(vet, ini, aux - 1, k, vet[aux]);
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