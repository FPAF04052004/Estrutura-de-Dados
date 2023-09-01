#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

vector<int> criar_vetor(string line){
    stringstream ss{line};
    int value{};
    vector<int> vet;
    while(ss >> value){
        vet.push_back(value);
    }
    return vet;
}

bool soma_vetor(vector<int> vet, int ini, int fim, int valor){
    if(ini == fim){
        return false;
    }else{
        if(vet.at(ini) + vet.at(fim) == valor){
            return true;
        }else{
            if(soma_vetor(vet, ini, fim - 1, valor)){
                return true;
            }else{
                return soma_vetor(vet, ini + 1, fim, valor);
            }
        }
    }
}

int main(void){
    string line;
    getline(cin, line);
    vector<int> vet{criar_vetor(line)};
    int fim = vet.size() - 1;
    int valor;
    cin >> valor;

    if(soma_vetor(vet, 0, fim, valor)){
        cout << "Sim.";
    }else{
        cout << "Nao.";
    }

    return 0;
}