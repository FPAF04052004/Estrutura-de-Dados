#include <iostream>
#include<vector>
#include<sstream>
#include<string>

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

int max_elem(vector<int> vet, int size){
    if(size == 1){
        return vet[0];
    }else{
        //return max(max_elem(vet, size - 1), vet[size - 1]);
        if(vet[size - 1] > max_elem(vet, size)){
            return vet[size - 1];
        }else{
            return max_elem(vet, size);
        }
    }
}

int min_elem(vector<int> vet, int size){
    if(size == 1){
        return vet[0];
    }else{
        //return min(min_elem(vet, size - 1), vet[size - 1]);
        if(vet[size - 1] < min_elem(vet, size)){
            return vet[size - 1];
        }else{
            return min_elem(vet, size);
        }
    }
}

int soma(vector<int> vet, int ini, int fim){
    int acc = 0;
    if(ini == fim){
        return vet[0];
    }else{
        acc += vet[ini];
        return soma(vet, ini + 1, fim);
    }
}

int main(){
    string line;
    getline(cin, line);
    vector<int> vet{criar_vetor(line)};
    int size = vet.size();

    cout << "Soma = " << soma(vet, 0, size0) << '\n';
    cout << "Maior elemento = " << max_elem(vet, size) << '\n';
    cout << "Menor elemento =  "<< min_elem(vet, size) << '\n';
    return 0;
}