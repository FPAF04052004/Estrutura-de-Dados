#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> vet[n];
    int value;
    for(int i{0}; i < n; i++){
        cin >> value;
        vet->push_back(value);
    }
    for(int i{0}; i < n; i++){
        cout << vet[i] << " ";
    }
}