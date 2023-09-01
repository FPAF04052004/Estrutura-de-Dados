#include <stdio.h>
#include <string.h>

int soma_digito(int numero, int soma){
    if(numero < 10){
        soma += numero;
        return soma;
    }else{
        int rest = numero % 10;
        return soma_digito(numero / 10, soma + rest);
    }
}

int main(){
    int numero;
    int soma = 0;
    scanf("%d", &numero);

    printf("%d", soma_digito(numero, soma));

    return 0;
}