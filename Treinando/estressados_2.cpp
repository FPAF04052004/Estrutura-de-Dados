#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<sstream>

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

void remove_zeros(vector<int>& vet){
    vector<int> novo;
    for(auto value: vet){
        if(value != 0){
            novo.push_back(value);
        }
    }
    vet.clear();
    vet = novo;
}

void aumenta_um(vector<int>& vet){
    for(int i = 0; i < (int) vet.size(); i++){
        vet[i] += 1;
    }
}

int menor_positivo(vector<int> vet){
    vector<int> novo;
    for(auto elem: vet){
        if(elem > 0){
            novo.push_back(elem);
        }
    }
    int menor = novo[0];
    for(auto elem: novo){
        if(menor > elem){
            menor = elem;
        }
    }
    if(menor > 0){
        return menor;
    }else{
        return -1;
    }
}

int maior_negativo(vector<int> vet){
    vector<int> novo;
    for(auto elem: vet){
        if(elem < 0){
            novo.push_back(elem);
        }
    }
    int maior = novo[0];
    for(auto elem: vet){
        if(elem > maior){
            elem = maior;
        }
    }
    if(maior < 0){
        return maior;
    }else{
        return -1;
    }
}

pair<int, int> maior_menor(vector <int> vet){
    int maior = vet[0];
    int menor = vet[0];
    for(int i = 0; i < (int) vet.size(); i++){
        if(maior < vet[i]){
            maior = vet[i];
        }
        if(menor > vet[i]){
            menor = vet[i];
        }
    }
    return make_pair(maior, menor);
}

int sortear(vector<int> vet){
    int n = (rand() % vet.size());
    return vet.at(n);
}

void embaralhar(vector<int>& vet){
    int size = vet.size();
    for(int i{0}; i < size; i++){
        swap(vet.at(i), vet.at(rand() % size));
    }
}

string to_string(vector<int> vet){
    string s{"{ "};
    for(int i{0}; i < (int)vet.size(); i++){
        s += vet[i] + " ";
    }
    s += "}\n"
    return s;
}

int main(){
    string line;
    getline(cin, line);
    vector<int> vet{criar_vetor(line)};

    embaralhar(vet);
    to_string(vet);
    remove_zeros(vet);
    aumenta_um(vet);

    for(int i{0}; i < (int) vet.size(); i++){
        cout << vet.at(i) << " ";
    }
    cout << '\n';

    cout << "Maior = " << maior_menor(vet).first << '\n';
    cout << "Menor = " << maior_menor(vet).second << '\n';
    cout << "Menor positivo = " << menor_positivo(vet) << '\n';
    cout << "Maior negativo = " << maior_negativo(vet) << '\n'; 
    cout << "Sorteio = " << sortear(vet);

    return 0;
}