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

void ordenacaoVetor(int v[TAM], int n){
	int i, j, aux, posicaoMenor;
    for(i=0;i < n-1; i++){
        posicaoMenor = i;
        for(j= i+1; j < n; j++){
            if(v[j] < v[posicaoMenor]) {
                posicaoMenor = j;
            }
            aux = v[i];
            v[i] = v[posicaoMenor];
            v[posicaoMenor] = aux;
        }
    }
}

void main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));

	criarVetor();
	imprimirVetor();
	ordenacaoVetor(vetor, TAM);
	imprimirVetor();
}

