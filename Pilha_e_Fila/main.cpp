#include <stdio.h>
#include "queue.cpp"
#include "stack.cpp"

void printQueue(Queue<int>& fila) {
    printf("%d\n", fila.size());
    while(!fila.empty()){
        printf("%d ", fila.pop());
    }
}
void printStack(Stack<int>& pilha) {
    printf("%d\n", pilha.size());
    while(!pilha.empty()){
        printf("%d ", pilha.pop());
    }
}
int main() {
    int n, k;
	Queue<int> fila;
	Stack<int> pilha;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    if(i % 2 == 0) fila.push(k);
		else pilha.push(k);
	}
	printQueue(fila);
	printStack(pilha);
}