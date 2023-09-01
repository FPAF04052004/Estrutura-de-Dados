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
    if(novo.empty()){
        return -1;
    }else{
        return menor;
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
    if(novo.empty()){
        return -1;
    }else{
        return maior;
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

void to_string(vector<int> vet){
    cout << "{ ";
    for(int i{0}; i < (int)vet.size(); i++){
        cout << vet[i] << " ";
    }
    cout << "}\n";
}

pair<vector<int>, vector<int>> unicos_repetidos(vector<int> vet){
    vector<int> unicos;
    vector<int> separados;

    auto existe = [](int x, auto vet){
        return find (vet.begin(), vet.end(), x) != vet.end();
    };

    for(auto elem: vet){
        if(existe(elem, unicos)){
            repetidos.push_back(elem);
        }else{
            unicos.push_back(elem);
        }
    }
    return make_pair(unicos, separados);
}

int main(){
    string line;
    getline(cin, line);
    vector<int> vet{criar_vetor(line)};

    embaralhar(vet);
    to_string(vet);
    remove_zeros(vet);
    to_string(vet);
    aumenta_um(vet);
    to_string(vet);

    cout << "Maior = " << maior_menor(vet).first << '\n';
    cout << "Menor = " << maior_menor(vet).second << '\n';
    cout << "Menor positivo = " << menor_positivo(vet) << '\n';
    cout << "Maior negativo = " << maior_negativo(vet) << '\n'; 
    cout << "Vetor de separados = " << to_string(unicos_repetidos(vet).first);
    cout << "Vetor de  repetidos = " << to_string(unicos_repetidos(vet).second);
    cout << "Sorteio = " << sortear(vet);

    return 0;
}