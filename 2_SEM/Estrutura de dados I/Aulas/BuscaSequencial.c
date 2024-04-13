#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 1000
#define value 43
#define aleatorio 1000

int vetor [TAM];

void main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	int i;
	for(i=0;i< TAM;i++){
		vetor[i] = (rand() % aleatorio)+1;
	}
	printf("\n\n---------------vetor----------------\n\n");

	for(i=0;i<TAM;i++){
		printf("%d, ",vetor[i]);
	}
	printf("\n\n");
	
	i = 0;
	int valor = value;
	bool encontrado = 0;
	
	while(i<TAM && !encontrado){
		if(vetor[i] == valor){
			encontrado = 1;
		}else{
			i++;
		}
	}
	if(encontrado){
		printf("o valor %d encontrado na posição %d",vetor[i],i);
	}else{
		printf("o valor %d não encontrado", valor);
	}
}
