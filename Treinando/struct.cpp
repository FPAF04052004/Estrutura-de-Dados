#include<iostream>

using namespace std;

struct Car{
    int pass;
    string cor;
    double km;
};

void dirigir(Car &car){
    int dirigidos;
    cin >> dirigidos;
    car.km += dirigidos;
}

void show(Car &car){
    cout << "Passageiros = " << car.pass;
    cout << "Cor = " << car.cor;
    cout << "Kilometragem = " << car.pass;
}

void entrar_passageiros(Car &car){
    int entrada;
    cin >> entrada;
    car.pass += entrada;
}

void sair_passageiros(Car &car){
    int saida;
    cin >> saida;
    car.pass -= saida;
}

void mudar_cor(Car &car){
    string nova_cor;
    cin >> nova_cor;
    car.cor = nova_cor;
}

int main(){
    int pass;
    string cor;
    double km;
    cin >> pass >> cor >> km;
    Car car{pass, cor, km};

    char c;
    cin >> c;

    cout << "Deseja mexer no carro\n";
    while(c == 'y'){
        char h;
        cin >> h;
        cout << "Deseja dirigir o carro?\n";
        if(h == 'y' &&  car.pass > 0){
            dirigir(car);
        }else if(car.pass == 0){
            cout << "Carro vazio\n";
        }
        cout << "Entraram passageiros?";
        cin >> h;
        if(h == 'y'){
            entrar_passageiros(car);
        }
        cout << "Saíram passageiros?";
        cin >> h;
        if(h == 'y'){
            sair_passageiros(car);
        }
        cout << "Deseja mudar a cor?";
        cin >> h;
        if(h == 'y'){
            mudar_cor(car);
        }
        show(car);
        cout << "Ainda deseja mexer no carro?";
        cin >> c;
    }
    show(car);
    return 0;
}