#include<stdio.h>

int fib(int n1, int n2, int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 1;
    }else{
        int acc = n1 + n2;
        n1 = n2;
        n2 = acc;
        return fib(n1, n2, n - 1) + fib(n1, n2, n - 2);
    }
}

int main(void){
    int n = 0;
    int n1 = 1;
    int n2 = 1;
    printf("Determine o termo da sequencia que voce quer saber\n");
    scanf("%d", &n);

    printf("O termo %d de fib e = %d", n, fib(n1, n2, n));
    return 0;
}