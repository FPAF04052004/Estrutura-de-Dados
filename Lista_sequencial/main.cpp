#include<iostream>
#include "Vector.h"

using namespace std;

void print(Vector& list) {
    if(!list.empty()){
        printf("%d\n", list.size());
    	for(int i = 0; i < list.size(); i++) printf("%d ", list.at(i));
    	printf("\n");        
    }else printf("Lista Vazia\n"); 
}


int main() {
    int n, k;
    scanf("%d", &n);
	Vector lista;
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    lista.push_back(k);
	}
	print(lista);
	lista.remove_duplicates();
	print(lista);
	auto print = [&lista](){
		for(int i{0}; i < lista.size(); i++){
			cout << lista[i] << ' ';
		}
		cout << '\n';
	};
}