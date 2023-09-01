#include<iostream>
#include<vector>
#include<string>
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

int max_elem(vector<int> vet, int size){
    if(size == 0){
        return vet[0];
    }else{
        int maior = max_elem(vet, size - 1);
        return max(maior, vet[size - 1]);
    }
}

int min_elem(vector<int> vet, int size){
    if(size == 0){
        return vet[0];
    }else{
        int menor = min_elem(vet, size - 1);
        return min(menor, vet[size - 1]);
    }
}

int main(){
    string line;
    getline(cin, line);
    vector<int> vet{criar_vetor(line)};
    int size = vet.size();

    cout << "Maior elemento = " << max_elem(vet, size) << '\n';
    cout << "Menor elemento = " << min_elem(vet, size) << '\n';
    
    return 0;
}