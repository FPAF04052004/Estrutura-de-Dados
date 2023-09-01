#include<stdio.h>

void merge(int aux[], int ini, int um_terco, int dois_tercos, int fim, int vet[]) {
	int i = ini;
    int j = um_terco;
    int k = dois_tercos;
    int l = ini;

	while ((i < um_terco) && (j < dois_tercos) && (k < fim)){
		if(aux[i] < aux[j]){
			if(aux[i] < aux[k]){
                vet[l++] = aux[i++];
            }
			else{
                vet[l++] = aux[k++];
            }
		}
		else{
			if(aux[j] < aux[k])
				vet[l++] = aux[j++];
			else
				vet[l++] = aux[k++];
		}
	}

	while ((i < um_terco) && (j < dois_tercos)) {
		if(aux[i] < aux[j]){
            vet[l++] = aux[i++];
        }
		else{
            vet[l++] = aux[j++];
        }
	}

	while ((j < dois_tercos) && (k < fim)) {
		if(aux[j] < aux[k]){
            vet[l++] = aux[j++];
        }
		else{
            vet[l++] = aux[k++];
        }
	}

	while ((i < um_terco) && (k < fim)) {
		if(aux[i] < aux[k]){
            vet[l++] = aux[i++];
        }
		else{
            vet[l++] = aux[k++];
        }
	}

	while (i < um_terco){
        vet[l++] = aux[i++];
    }

	while (j < dois_tercos){
        vet[l++] = aux[j++];
    }

	while (k < fim){
        vet[l++] = aux[k++];
    }
}

void merge_sort3_recursivo(int aux[], int ini, int fim, int vet[]) {
	if (fim - ini < 2){
        return;
    }

	int um_tercos = ini + ((fim - ini) / 3);
	int dois_tercos = ini + 2 * ((fim - ini) / 3) + 1;

	merge_sort3_recursivo(vet, ini, um_tercos, aux);
	merge_sort3_recursivo(vet, um_tercos, dois_tercos, aux);
	merge_sort3_recursivo(vet, dois_tercos, fim, aux);

	merge(vet, ini, um_tercos, dois_tercos, fim, aux);
}

void merge_sort3(int vet[], int n){
	if (n == 0){
        return;
    }

	int aux[n];
	for (int i = 0; i < n; i++){
        aux[i] = vet[i];
    }

	merge_sort3_recursivo(aux, 0, n, vet);
	for (int i = 0; i < n; i++){
        vet[i] = aux[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
	int vet[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

	merge_sort3(vet, n);
	for (int i = 0; i < n; i++){
        printf("%d ",vet[i]);
    }
	return 0;
}