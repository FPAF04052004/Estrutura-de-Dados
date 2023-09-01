#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

vector<string> criar_vetor(string line){
    stringstream ss{line};
    string s;
    vector<string> vet;
    while(ss >> s){
        vet.push_back(s);
    }
    return vet;
}

bool find(vector<string> vet, string procurada, int ini){
    if(vet.size() == ini){
        return false;
    }else if(vet.at(ini).compare(procurada)){
        return true;
    }else{
        return find(vet, procurada, ini + 1);
    }
}

int main(){
    string line;
    getline(cin, line);
    vector<string> vet{criar_vetor(line)};
    string procurada;
    getline(cin, procurada);
    cout << find(vet, procurada, 0);
}