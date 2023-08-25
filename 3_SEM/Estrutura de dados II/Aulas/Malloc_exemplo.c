#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

const int TAMANHO = 7;

// Alocação de memoria dinamica

void main(void){	
	setlocale(LC_ALL,"Portuguese");
    int *x;

    x = (int *) malloc(TAMANHO*sizeof(int));
    
    // populando o vetor
    x[0] = 11;    x[1] = 8;    x[2] = -7;    x[3] = 1;
    x[4] = 25;    x[5] = 32;    x[6] = 51;

    int i;
    for(i=0;i<TAMANHO;i++){
        printf("%d\t", x[i]);
    }
    free(x);

    char *nome;

    lendoNome(&nome);
    printf("\n\n O seu nome é: %s ", nome);
    free(nome);
}

void lendoNome(int **n){
    char auxNome[200];

    printf("\n\n Insira seu nome: ");
    gets(auxNome);
    *n = (char *) malloc(strlen(auxNome)*sizeof(char));
    strcpy(*n,auxNome);
}
