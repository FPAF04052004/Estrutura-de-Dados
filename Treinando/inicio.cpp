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
    for(int i{0}; i < (int)vet.size(); i++){
        vet[i] += 1;
    }
    vet.clear();
}

int main(){
    string line;
    getline(cin, line);
    vector<int> vet{criar_vetor(line)};
    remove_zeros(vet);
    aumenta_um(vet);
    for(int i{0}; i < (int) vet.size(); i++){
        cout << vet.at(i) << " ";
    }
}