#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int vetor[10];
int i;

void main(void){
	setlocale(LC_ALL,"Portuguese");
    int bilhete[6];
	
	int numero;
	
	srand(time(NULL));
	numero = rand()%80;

	defRandom(vetor,300,10);
	defRandom(bilhete,60,6);
	
	imprimirVetor(vetor,10);
	printf("\n\n\n");
	imprimirVetor(bilhete,6);
}

void imprimirVetor(int v[], int TAM){
	printf("\nImpressão dos numeros\n");
	
	
	for(i=0;i<TAM; i++){
		printf("%d, ", v[i]);
	}
}

void defRandom(int v[], int limite, int TAM){
	for(i=0;i<TAM;i++){
		v[i] = rand()%limite;
	}
}
