#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define aleatorio 1000
#define TAM 1000

int vetor [TAM];

void criarVetor(){
	int i;
	for(i=0;i< TAM; i++){
		vetor[i] = (rand() % aleatorio)+1;
	}
}

void imprimirVetor(){
	int i;
	printf("\n\n---------------vetor----------------\n\n");
	for(i=0;i<TAM;i++){
		printf("%d, ",vetor[i]);
	}
	printf("\n\n");
}



void ordenacaoVetor(int *v, int n){
	int j;
	for (j = 1; j < n; ++j) {
	int x = vetor[j];
	int i;
	for (i = j-1; i >= 0 && vetor[i] > x; --i)
		vetor[i+1] = vetor[i];
	vetor[i+1] = x;
	}
}

void main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));

	criarVetor();
	imprimirVetor();
	ordenacaoVetor(&vetor, TAM);
	imprimirVetor();
}

