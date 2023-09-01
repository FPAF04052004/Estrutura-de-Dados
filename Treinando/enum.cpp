#include<iostream>

using namespace std;

enum Opcao{
    PEDRA, 
    PAPEL,
    TESOURA
};

enum Result{
    EMPATE,
    JOG1,
    JOG2
};

Result jokenpo(Opcao jog1, Opcao jog2){
    if(jog1 == jog2){
        return EMPATE;
    }else if(jog1 == PEDRA && jog2 == TESOURA){
        return JOG1;
    }else if(jog1 == TESOURA && jog2 == PAPEL){
        return JOG1;
    }else if(jog1 == PAPEL && jog2 == PEDRA){
        return JOG1;
    }else{
        return JOG2;
    }
}

string to_string(Result res){
    if(res == EMPATE){
        return "Empate";
    }else if(res == JOG1){
        return "Jogador 1 venceu";
    }else{
        return "Jogador 2 venceu";
    }
}

int main(){
    Opcao jog1;
    Opcao jog2;

    while(true){
        istream >> jog1;
        cout << to_string(jokenpo(jog1, jog2));
    }

    return 0;
}