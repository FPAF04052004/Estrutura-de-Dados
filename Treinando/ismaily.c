#include<stdio.h>

int x = 0;

void foo(){
    x++;
}

void bar(){
    int x = 0;
    foo();
}
//  Se fosse dinamico, seria 0. Pois o valor de x mais próximo é 0, a variável global.
int main(){
    bar();
    printf("%d", x);
    return 0;
}