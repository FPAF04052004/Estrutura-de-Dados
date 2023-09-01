#include<iostream>

using namespace std;

int main(){
    int capacidade{0};
    int entrada_saida{0};
    int num_de_pessoas{0};
    cin >> capacidade;
    while(num_de_pessoas < 2 * capacidade){
        cin >> entrada_saida;
        num_de_pessoas += entrada_saida;
        if(num_de_pessoas == 0 ){
            cout << "Vazio\n";
        }else if(num_de_pessoas >= capacidade){
            cout << "Lotado\n";
        }else{
            cout << "Ainda cabe\n";
        }
    }
    cout << "Hora de partir\n";
    return 0;
}