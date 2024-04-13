#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 4

int mAdj[V][V];

//funções
void inicializar();
void imprimirMatriz();
void bicolor();

void main(void){
	inicializar();	
	imprimirMatriz();
	bicolor();
	
}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	//vertice 1
	mAdj[0][0] = 0;
	mAdj[0][1] = 1; 
	mAdj[0][2] = 1; 
	mAdj[0][3] = 0; 
	
	//vertice 2
	mAdj[1][0] = 1;
	mAdj[1][1] = 0; 
	mAdj[1][2] = 0; 
	mAdj[1][3] = 1; 
	
	//vertice 3
	mAdj[2][0] = 1;
	mAdj[2][1] = 0; 
	mAdj[2][2] = 0; 
	mAdj[2][3] = 1; 
	
	//vertice 4
	mAdj[3][0] = 0;
	mAdj[3][1] = 1; 
	mAdj[3][2] = 1; 
	mAdj[3][3] = 0; 
}
// criar a função de impressão da matriz
void imprimirMatriz(){
	int i,j;
	for(i=0;i<30;i++) printf("=");
	printf("\n           Matriz          \n");
	for(i=0;i<30;i++) printf("-");
	printf("\n");
	for(i=0;i < V;i++){
		for(j=0;j< V;j++){
			printf("%d\t",mAdj[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<30;i++) printf("=");
	printf("\n");
}

void bicolor(){
	int i,j;
	int cor[2] = {98,99};
	
	for(i = 0; i < 2;i++){
		printf("%d, ",cor[i]);
	}
	printf("\n");
	
	for(i = 0; i < V; i++){
		int k = 0;
		mAdj[i][i] = cor[k];
		for(j = 0; j < V; j++){
			if(mAdj[i][j] == 1){
				if(mAdj[j][j] != 0){
					if(mAdj[j][j] == mAdj[i][i]){
						k++;
						mAdj[i][i] = cor[k];
					}					
				}
			}
		}		
	}
	imprimirMatriz();
	//criar a função para verificar se é ciclo ímpar	
}
