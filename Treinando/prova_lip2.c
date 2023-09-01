#include<stdio.h>

int x = 2;

void h(int x){
    x += 2;
    printf("%d\n", x);
}
void f(int x){
    h(x);
    printf("%d\n", x);
}
void g(int x){
    f(x);
    printf("%d\n", x);
}
int main(){
    g(x);
    printf("%d", x);
    return 0;
}