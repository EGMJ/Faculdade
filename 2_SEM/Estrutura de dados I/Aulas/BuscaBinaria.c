#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define aleatorio 100
#define valor 43
#define TAM 100

int vetor [TAM];

void main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	int i;
	for(i=0;i< TAM; i++){
		vetor[i] = (rand() % aleatorio)+1;
	}

	// ordenação acéfala
	int j, aux;
	for(j=0;j< TAM; j++){
		for(i=0;i< TAM; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}

	// fim da ordenação acéfala
	printf("\n\n---------------vetor----------------\n\n");
	for(i=0;i<TAM;i++){
		printf("%d, ",vetor[i]);
	}

	printf("\n\n");

	int direita,esquerda,meio;
	bool encontrado = 0;
	esquerda = 0;
	direita = TAM - 1;

	while (esquerda<=direita && !encontrado){
		meio = (direita+esquerda)/2;
		if(vetor[meio] == valor){
			encontrado = 1;
		}else if(valor<vetor[meio]){
			direita = meio - 1;
		}else{
			esquerda = meio + 1;
		}		
	}
	if(encontrado){
		printf("\n\n Valor %d encontrado na posição %d", vetor[meio],meio);
	}else{
		printf("\n\n Valor %d não encontrado", valor);
	}
	


}
