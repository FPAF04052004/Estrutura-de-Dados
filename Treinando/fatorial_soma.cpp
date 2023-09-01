#include<iostream>

using namespace std;

int fatorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * fatorial(n - 1);
    }
}

int soma(int n){
    if(n == 0){
        return 0;
    }else{
        return n + soma(n - 1);
    }
}

int main(){
    int n;
    cin >> n;

    cout << "Fatorial = " << fatorial(n) << '\n';
    cout << "Soma dos N primeiros inteiros = " << soma(n);
}