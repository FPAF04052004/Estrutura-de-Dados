#include<stdio.h>

int x = 2;

void h(){
    x += 2;
    printf("%d\n", x);
}
void f(){
    int x = 0;
    h();
    printf("%d\n", x);
}
void g(){
    int x = 1;
    f();
    printf("%d\n", x);
}
int main(){
    g();
    printf("%d", x);
    return 0;
}