#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Estrutura de dados homogenea
int valor[10];
int bilhete[6];
int i,j,k;

int cidade[4][4];


// Estrutura de dados heterogenea
struct pessoa{
	char nome[20]; // se o nome for definido como int é homogenia
	int idade;
}p[10];

void main(void){
    setlocale(LC_ALL, "Portuguese");
	// CONTEM 6 numeros de 1 - 60
	// nao repete os numeros
	// sorteiro aleatorio
	
	srand(time(NULL));
	
/*
	for(k = 0; k<30;k++){
		printf("\n");
		
		bilhete[0] = rand()%60 + 1;
		
		for (i = 0; i< 6; i++){
			int aux = rand()%60 + 1;
			
			int achou = 0;
						for(j = i-1; j >= 0; j--){
				if(bilhete[j] == aux){
					achou = 1;
					i--;
					break;
				}
			}
			if(achou == 0) bilhete[i] = aux;
		}
		for (i = 0; i< 6; i++){
			printf("%d ", bilhete[i]);
		}
	}
	
	
	
	strcpy(p[0].nome, "Edson");
	p[0].idade = 41;
	
	strcpy(p[1].nome, "Carlos");
	p[1].idade = 1;
	
	strcpy(p[2].nome, "Julia");
	p[2].idade = 19;
	
	
	
	printf("\n\n Pessoas: \n");
	for(i=0;i<10;i++){
		printf("\nNome: %s, Idade = %d.", p[i].nome, p[i].idade);
	}
	*/
	// cidade um:
	cidade[0][0] = 0;
	cidade[0][1] = 1;
	cidade[0][2] = 1;
	cidade[0][3] = 0;
	
	// cidade dois:
	cidade[1][0] = 1;
	cidade[1][1] = 0;
	cidade[1][2] = 1;
	cidade[1][3] = 1;
	
	// cidade tres:
	cidade[2][0] = 1;
	cidade[2][1] = 1;
	cidade[2][2] = 0;
	cidade[2][3] = 0;
	
	// cidade quatro:
	cidade[3][0] = 0;
	cidade[3][1] = 1;
	cidade[3][2] = 0;
	cidade[3][3] = 0;
	
	printf("\n Matrizes das cidades\n\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%d\t", cidade[i][j]);
		}
		printf("\n");
	}
	
	
	
}
