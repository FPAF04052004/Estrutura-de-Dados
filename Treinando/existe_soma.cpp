#include<iostream>

using namespace std;

int existe_soma(int vet[], int ini, int fim, int chave){
    if(ini > fim){
        return 0;
    }else if(vet[ini] + vet[fim] == chave){
        return 1;
    }else if(vet[ini] + vet[fim] < chave){
        return existe_soma(vet, ini + 1, fim, chave);
    }else{
        return existe_soma(vet, ini, fim - 1, chave);
    }
}
int main(){
    int n;
    cin >> n;
    int vet[n];
    for(int i{0}; i < n; i++){
        cin >> vet[i];
    }
    int chave;
    cin >> chave;
    if(existe_soma(vet, 0, n - 1, chave)){
        printf("Sim");
    }else{
        printf("Nao");
    }
}