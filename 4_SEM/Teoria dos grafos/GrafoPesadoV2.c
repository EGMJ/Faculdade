#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 6
#define qAresta 20
#define nullAresta -99

struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta];

float mAdj[V][V];

//funções
void inicializar();
void inicializarLista();
void imprimirListaAresta();

void transformarArestaEmMatriz();
void transformarMatrizEmAresta();

void imprimirMatriz();
void bicolor();
void coloracao();

int verificarSeEhGrafo();
void removeDuplicatasDeAresta();

void main(void){

//	inicializar();	
//	imprimirMatriz();
//	transformarMatrizEmAresta();
//	imprimirListaAresta();
		
//	coloracao();
//	imprimirMatriz();



	inicializarLista();
	imprimirListaAresta();
	transformarArestaEmMatriz();
	imprimirMatriz();
	removeDuplicatasDeAresta();
	imprimirMatriz();
	imprimirListaAresta();	
		
/*	bicolor();	
	imprimirMatriz();	
	*/
}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, j;
	for(i = 0;i < V;i++)
		for(j = 0;j < V;j++)
			mAdj[i][j] = nullAresta;
			
	//vertice 0
	mAdj[0][1] = 6; 
	mAdj[0][2] = 1; 
	mAdj[0][3] = 5; 
	
	//vertice 1
	mAdj[1][0] = 6;
	mAdj[1][2] = 2; 
	mAdj[1][4] = 5; 
	
	//vertice 2
	mAdj[2][0] = 1;
	mAdj[2][1] = 2;
	mAdj[2][3] = 2; 
	mAdj[2][4] = 6; 
	mAdj[2][5] = 4; 
	
	//vertice 3
	mAdj[3][0] = 5;
	mAdj[3][2] = 2; 
	mAdj[3][5] = 4; 
	
	//vertice 4
	mAdj[4][1] = 5;
	mAdj[4][2] = 6; 
	mAdj[4][5] = 3; 
	
	//vertice 5
	mAdj[5][2] = 4;
	mAdj[5][3] = 4; 
	mAdj[5][4] = 3;  
}

void inicializarLista(){
	setlocale(LC_ALL,"Portuguese");
//------- vertice 0 --------------
	aresta[0].vEmergente = 0;
	aresta[0].vIncidente = 1;
	aresta[0].peso = 6;
	
	aresta[1].vEmergente = 0;
	aresta[1].vIncidente = 2;
	aresta[1].peso = 1;
		
	aresta[2].vEmergente = 0;
	aresta[2].vIncidente = 3;
	aresta[2].peso = 5;
//---------- vertice 1 --------------
	aresta[3].vEmergente = 1;
	aresta[3].vIncidente = 0;
	aresta[3].peso = 6;
	
	aresta[4].vEmergente = 1;
	aresta[4].vIncidente = 2;
	aresta[4].peso = 2;
		
	aresta[5].vEmergente = 1;
	aresta[5].vIncidente = 4;
	aresta[5].peso = 5;
	
//---------- vertice 2 -------------
	aresta[6].vEmergente = 2;
	aresta[6].vIncidente = 0;
	aresta[6].peso = 1;
	
	aresta[7].vEmergente = 2;
	aresta[7].vIncidente = 1;
	aresta[7].peso = 2;
	
	aresta[8].vEmergente = 2;
	aresta[8].vIncidente = 3;
	aresta[8].peso = 2;
	
	aresta[9].vEmergente = 2;
	aresta[9].vIncidente = 4;
	aresta[9].peso = 6;
	
	aresta[10].vEmergente = 2;
	aresta[10].vIncidente = 5;
	aresta[10].peso = 4;
	
//----------- vertice 3 ------------
	aresta[11].vEmergente = 3;
	aresta[11].vIncidente = 0;
	aresta[11].peso = 5;
	
	aresta[12].vEmergente = 3;
	aresta[12].vIncidente = 2;
	aresta[12].peso = 2;
	
	aresta[13].vEmergente = 3;
	aresta[13].vIncidente = 5;
	aresta[13].peso = 4;
	
	//----------- vertice 4 ------------
	aresta[14].vEmergente = 4;
	aresta[14].vIncidente = 1;
	aresta[14].peso = 5;
	
	aresta[15].vEmergente = 4;
	aresta[15].vIncidente = 2;
	aresta[15].peso = 6;
	
	aresta[16].vEmergente = 4;
	aresta[16].vIncidente = 5;
	aresta[16].peso = 3;
	
	//----------- vertice 5 ------------
	aresta[17].vEmergente = 5;
	aresta[17].vIncidente = 2;
	aresta[17].peso = 4;
	
	aresta[18].vEmergente = 5;
	aresta[18].vIncidente = 3;
	aresta[18].peso = 4;
	
	aresta[19].vEmergente = 5;
	aresta[19].vIncidente = 4;
	aresta[19].peso = 3;

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
			printf("%.f\t",mAdj[i][j]);
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
		printf("%d  ==>  %d\t%.f\n" ,
		aresta[i].vEmergente,aresta[i].vIncidente,aresta[i].peso);
	}
	for(i=0;i<tam;i++) printf("=");
	printf("\n");
}

void transformarArestaEmMatriz(){
	int i, j;
	for(i = 0;i < V;i++)
		for(j = 0;j < V;j++)
			mAdj[i][j] = nullAresta;
	
	for(i = 0; i < qAresta;i++){
		mAdj[aresta[i].vEmergente][aresta[i].vIncidente] =  
		aresta[i].peso;
	}
}

void transformarMatrizEmAresta(){
	int i, j, k = 0;
	for(i =0 ; i < V;i++){
		for(j =0; j < V;j++){
			if(mAdj[i][j] != nullAresta){
				aresta[k].vEmergente = i;
				aresta[k].vIncidente = j;
				aresta[k].peso = mAdj[i][j]; 
				k++;
			}
		}
	}	
}

void bicolor(){
	int i,j;
	float cor[2] = {98,99};
	
	for(i = 0; i < 2;i++){
		printf("%f, ",cor[i]);
	}
	printf("\n");
	int k;
	for(i = 0; i < V; i++){
		k = 0;
		mAdj[i][i] = cor[k];
		for(j = 0; j < V; j++){
			if(mAdj[i][j] == 1){
				if(mAdj[j][j] != nullAresta){
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
	float cor[V];
	
	for(i = 0; i < V;i++)
		cor[i] = 100 + i;
	
	for(i = 0; i < V;i++){
		printf("%f, ",cor[i]);
	}
	printf("\n");
	for(i = 0; i < V; i++){
		k = 0; 
		if(mAdj[i][i] == nullAresta) mAdj[i][i] = cor[k];
		for(j = 0; j < V;j++){
			if((mAdj[i][j] == 1)&&(mAdj[j][j] != nullAresta)){
				if(mAdj[j][j] == mAdj[i][i]){
					k++;
					mAdj[i][i]=cor[k];
					j = 0;
				}
			}
		}
	}	
}

int verificarSeEhGrafo(){
	int ehGrafo = 0;
	int i, j;
	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			if(mAdj[i][j] == mAdj[j][i]) ehGrafo = 1;
			else{
				ehGrafo = 0;
				i = V;
				break;
			}
		}
	}
	return ehGrafo;
}

void removeDuplicatasDeAresta(){
	if(verificarSeEhGrafo()){
		printf("É grafo.");
		
		int i, j;
		for(i = 0;i < V;i++){
			for(j = 0; j < V;j++){
				if(j < i) mAdj[i][j] = nullAresta;
			}
		}
		
		for(i = 0;i < qAresta; i++){
			aresta[i].vEmergente = nullAresta;
			aresta[i].vIncidente = nullAresta;
			aresta[i].peso = nullAresta;
		} 
		
		transformarMatrizEmAresta();
				
		
	}else{
		printf("É DÍgrafo.");
	}
}




