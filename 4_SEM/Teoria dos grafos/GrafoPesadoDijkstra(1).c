#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 7
#define qAresta 20
#define nullAresta 0

// como representar em lista de arestas?
struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta];

int mAdj[V][V];

int vertices[V];

int origem;
float custoCaminho[V];
char caminho[V][6*V];


//funções
void inicializar();
void inicializarAresta();
void imprimirListaAresta();
void imprimirMatriz();
void transformarArestaEmMatriz();
void transformarMatrizEmAresta();
void dijkstra();
void impressaoDijkstra();



void main(void){	

	inicializar();
	imprimirMatriz();
	transformarMatrizEmAresta();
	imprimirListaAresta();
	dijkstra();
	impressaoDijkstra();

}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i,j;

	for(i = 0; i < V;i++){
		custoCaminho[i] = 801505699900162050;
		vertices[i] = -1;
	}

	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
			mAdj[i][j] = nullAresta;
			
	//vertice 0
	mAdj[0][1] = 1; 
	mAdj[0][2] = 3;
	mAdj[0][3] = 6;
		
	//vertice 1
	mAdj[1][0] = 1;
	mAdj[1][3] = 4; 
	mAdj[1][5] = 9; 
		
	//vertice 2
	mAdj[2][0] = 3;
	mAdj[2][5] = 2; 
	
	//vertice 3
	mAdj[3][0] = 6;
	mAdj[3][1] = 4;
	mAdj[3][4] = 3;
	mAdj[3][5] = 2;
	
	//vertice 4
	mAdj[4][3] = 3;
	mAdj[4][5] = 4;
	
	//vertice 5
	mAdj[5][1] = 9;
	mAdj[5][2] = 2;
	mAdj[5][3] = 2; 
	mAdj[5][4] = 4; 	
	mAdj[5][6] = 11;
	
	//vertice 6
	mAdj[6][5] = 11;
	

}

void inicializarAresta(){
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	
	// vertice 0
	aresta[0].vEmergente = 0;
	aresta[0].vIncidente = 1;
	aresta[0].peso = 6;
	
	aresta[1].vEmergente = 0;
	aresta[1].vIncidente = 2;
	aresta[1].peso = 1;
	
	aresta[2].vEmergente = 0;
	aresta[2].vIncidente = 3;
	aresta[2].peso = 5;
	
	//vertice 1
	aresta[3].vEmergente = 1;
	aresta[3].vIncidente = 0;
	aresta[3].peso = 6;
	
	aresta[4].vEmergente = 1;
	aresta[4].vIncidente = 2;
	aresta[4].peso = 2;
	
	aresta[5].vEmergente = 1;
	aresta[5].vIncidente = 4;
	aresta[5].peso = 5;
	
	// vertice 2
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
	
	//vertice 3
	aresta[11].vEmergente = 3;
	aresta[11].vIncidente = 0;
	aresta[11].peso = 5;
	
	aresta[12].vEmergente = 3;
	aresta[12].vIncidente = 2;
	aresta[12].peso = 2;
	
	aresta[13].vEmergente = 3;
	aresta[13].vIncidente = 5;
	aresta[13].peso = 4;
	
	// vertice 4
	aresta[14].vEmergente = 4;
	aresta[14].vIncidente = 1;
	aresta[14].peso = 5;
	
	aresta[15].vEmergente = 4;
	aresta[15].vIncidente = 2;
	aresta[15].peso = 6;
	
	aresta[16].vEmergente = 4;
	aresta[16].vIncidente = 5;
	aresta[16].peso = 3;
	
	//vertice 5
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

void imprimirListaAresta(){
	int i;
	for(i=0;i<30;i++) printf("=");
	printf("\n     Lista de aresta          \n");
	for(i=0;i<30;i++) printf("-");
	printf("\n");
	for(i = 0; i < qAresta; i++){
		printf("\t%d  ==>  %d\t%.f\n",aresta[i].vEmergente,aresta[i].vIncidente,aresta[i].peso);
	}
	for(i=0;i<30;i++) printf("=");
	printf("\n");
}

void transformarArestaEmMatriz(){
	// a partir da lista de aresta gera-se a matriz de incidencia
	int i, j;
	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
			mAdj[i][j] = nullAresta;

	for(i = 0; i < qAresta;i++){
		mAdj[aresta[i].vEmergente][aresta[i].vIncidente] = aresta[i].peso;
	}
}

void transformarMatrizEmAresta(){
	// a partir da matriz de incidencia gera-se a lista de aresta
	int i, j, k = 0;
	for(i = 0; i < V;i++){
		for(j = 0; j < V;j++){
			if(mAdj[i][j] != nullAresta){
				aresta[k].vEmergente = i;
				aresta[k].vIncidente = j;
				aresta[k].peso = mAdj[i][j];
				k++;
			}
		}
	}
}

void dijkstra(){
	// futuramente scanf
	origem = 0;
	// futuramente scanf
	custoCaminho[origem] = 0;
	vertices[0] = origem;
	int i,j,k = 1;
//	for(i = 0;i < V;i++){
		for(j = 0;j < V;j++){
			if(mAdj[origem][j] != nullAresta){
				custoCaminho[j] = mAdj[origem][j];
				vertices[k] = j;
				//controle de quais vertices foram visitados
			}
		}
		k++;
		
//	}
	
	
		
}
void impressaoDijkstra(){
	int i;
	printf("\n-----------Custo Caminho ---------\n");
	for(i = 0; i < V;i++){
		printf("%d\t%.f\n",i,custoCaminho[i]);
	}
	printf("\n----------------------------------\n");
}





















