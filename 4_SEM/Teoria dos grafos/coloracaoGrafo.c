#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 6
#define qAresta 20

struct Aresta{
	int vEmergente;
	int vIncidente;
	//float peso;
}aresta[qAresta];

int mAdj[V][V];

//funções
void inicializar();
void inicializarLista();
void imprimirListaAresta();

void transformarArestaEmMatriz();
void transformarMatrizEmAresta();

void imprimirMatriz();
void bicolor();
void coloracao();

void main(void){

	inicializar();	
	imprimirMatriz();
	transformarMatrizEmAresta();
	imprimirListaAresta();
		
	coloracao();
	imprimirMatriz();
/*
	inicializarLista();
	imprimirListaAresta();
	transformarArestaEmMatriz();
	imprimirMatriz();
	bicolor();	
	imprimirMatriz();	
	*/
}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, j;
	for(i = 0;i < V;i++)
		for(j = 0;j < V;j++)
			mAdj[i][j] = 0;
			
	//vertice 1
	mAdj[0][1] = 1; 
	mAdj[0][2] = 1; 
	mAdj[0][3] = 1; 
	
	//vertice 2
	mAdj[1][0] = 1;
	mAdj[1][2] = 1; 
	mAdj[1][5] = 1; 
	
	//vertice 3
	mAdj[2][0] = 1;
	mAdj[2][1] = 1;
	mAdj[2][3] = 1; 
	mAdj[2][4] = 1; 
	mAdj[2][5] = 1; 
	
	//vertice 4
	mAdj[3][0] = 1;
	mAdj[3][2] = 1; 
	mAdj[3][4] = 1; 
	
	//vertice 5
	mAdj[4][2] = 1;
	mAdj[4][3] = 1; 
	mAdj[4][5] = 1; 
	
	//vertice 6
	mAdj[5][1] = 1;
	mAdj[5][2] = 1; 
	mAdj[5][4] = 1;  
}

void inicializarLista(){
	setlocale(LC_ALL,"Portuguese");
//------- vertice 1 --------------
	aresta[0].vEmergente = 1;
	aresta[0].vIncidente = 2;
	
	aresta[1].vEmergente = 1;
	aresta[1].vIncidente = 3;
	
	aresta[2].vEmergente = 1;
	aresta[2].vIncidente = 4;
//---------- vertice 2 --------------
	aresta[9].vEmergente = 2;
	aresta[9].vIncidente = 1;
	
	aresta[3].vEmergente = 2;
	aresta[3].vIncidente = 4;
//---------- vertice 3 -------------
	aresta[4].vEmergente = 3;
	aresta[4].vIncidente = 1;
	
	aresta[5].vEmergente = 3;
	aresta[5].vIncidente = 4;
//----------- vertice 4 ------------
	aresta[8].vEmergente = 4;
	aresta[8].vIncidente = 1;
	
	aresta[6].vEmergente = 4;
	aresta[6].vIncidente = 2;
	
	aresta[7].vEmergente = 4;
	aresta[7].vIncidente = 3;

}
// criar a função de impressão da matriz
void imprimirMatriz(){
	int i,j, tam = V*7;
	for(i=0;i<tam;i++) printf("=");
	printf("\n");
	for(i=0;i < ((tam-6)/2);i++)printf(" "); 
	printf("Matriz\n");
	for(i=0;i<tam;i++) printf("-");
	printf("\n");
	for(i=0;i < V;i++){
		for(j=0;j< V;j++){
			printf("%d\t",mAdj[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<tam;i++) printf("=");
	printf("\n");
}

void imprimirListaAresta(){
	int i,j, tam = V*7;
	for(i=0;i<tam;i++) printf("=");
	printf("\n");
	for(i=0;i < ((tam-15)/2);i++)printf(" ");   
	printf("Lista de aresta\n");
	for(i=0;i<tam;i++) printf("-");
	printf("\n");
	for(i = 0; i < qAresta; i++){
		for(j=0;j < ((tam-11)/2);j++)printf(" ");
		printf("%d  ==>  %d\n",aresta[i].vEmergente,aresta[i].vIncidente);
	}
	for(i=0;i<tam;i++) printf("=");
	printf("\n");
}

void transformarArestaEmMatriz(){
	int i;
	for(i = 0; i < qAresta;i++){
		mAdj[aresta[i].vEmergente - 1][aresta[i].vIncidente - 1] =  1;
	}
}

void transformarMatrizEmAresta(){
	int i, j, k = 0;
	for(i =0 ; i < V;i++){
		for(j =0; j < V;j++){
			if(mAdj[i][j] == 1){
				aresta[k].vEmergente = i+1;
				aresta[k].vIncidente = j+1;
				k++;
			}
		}
	}	
}

void bicolor(){
	int i,j;
	int cor[2] = {98,99};
	
	for(i = 0; i < 2;i++){
		printf("%d, ",cor[i]);
	}
	printf("\n");
	int k;
	for(i = 0; i < V; i++){
		k = 0;
		mAdj[i][i] = cor[k];
		for(j = 0; j < V; j++){
			if(mAdj[i][j] == 1){
				if(mAdj[j][j] != 0){
					if(mAdj[j][j] == mAdj[i][i]){
						k++;
						if(k == 2){
							i = V;
							j = V;
							break;
						}
						mAdj[i][i] = cor[k];
					}					
				}
			}
		}		
	}
	imprimirMatriz();
	if(k == 2) printf("\nO grafo não é bipartido!, Pois possui um ciclo ímpar");
	else printf("\nO grafo é bipartido!");	
}

void coloracao(){
	int i,j,k;
	int cor[V];
	
	for(i = 0; i < V;i++)
		cor[i] = 100 + i;
	
	for(i = 0; i < V;i++){
		printf("%d, ",cor[i]);
	}
	printf("\n");
	for(i = 0; i < V; i++){
		k = 0; 
		if(mAdj[i][i] == 0) mAdj[i][i] = cor[k];
		for(j = 0; j < V;j++){
			if((mAdj[i][j] == 1)&&(mAdj[j][j] != 0)){
				if(mAdj[j][j] == mAdj[i][i]){
					k++;
					mAdj[i][i]=cor[k];
					j = 0;
				}
			}
		}
	}	
}









