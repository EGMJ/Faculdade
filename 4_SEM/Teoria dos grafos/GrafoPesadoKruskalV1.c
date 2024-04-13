#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 6
#define qAresta 20
#define nullAresta -99

// como representar em lista de arestas?
struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta],agm[V-1];

int mAdj[V][V];

//funções
void inicializar();
void inicializarAresta();
void imprimirListaAresta();
void imprimirMatriz();
void transformarArestaEmMatriz();
void transformarMatrizEmAresta();
void bicolor();
void coloracao();
void removeDuplicatasDeAresta();
int verificarSeEhGrafo();
void imprimirAgm();
int verificarCiclos(int vE, int vI);
void buscarMenoresPesos();

void main(void){	

/*
	inicializar();	
	imprimirMatriz();
	transformarMatrizEmAresta();
	imprimirListaAresta();
*/	
	inicializarAresta();
	imprimirListaAresta();
	transformarArestaEmMatriz();
	imprimirMatriz();
	removeDuplicatasDeAresta();	
	imprimirMatriz();
	imprimirListaAresta();
	buscarMenoresPesos();
	imprimirAgm();
	/*
	coloracao();
	imprimirMatriz();
	*/	
}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, j;
	for(i = 0; i < V-1;i++){
		agm[i].vEmergente = nullAresta;
		agm[i].vIncidente = nullAresta;
		agm[i].peso = nullAresta;
	}
	

	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
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

void inicializarAresta(){
	setlocale(LC_ALL,"Portuguese");
	
	int i;
	for(i = 0; i < V-1;i++){
		agm[i].vEmergente = nullAresta;
		agm[i].vIncidente = nullAresta;
		agm[i].peso = nullAresta;
	}
	
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
	if(k == 2) printf("O grafo não é bipartido!, Pois possui um ciclo ímpar");	
}

void coloracao(){
	int i, j, k;
	int cor[V];
	for(i = 0; i < V;i++)
		cor[i] = 100+i;	
	for(i = 0; i < V;i++){ 
		printf("%d, ",cor[i]);
	}
	printf("\n");
	for(i = 0;i < V; i++){
		k = 0;
		if(mAdj[i][i] == 0) mAdj[i][i] = cor[k];
		for(j = 0;j < V; j++){
			if((mAdj[i][j] == 1)&&(mAdj[j][j] != 0)){
				if(mAdj[j][j] == mAdj[i][i]){
					k = k + 1;
					mAdj[i][i] = cor[k];
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
		printf("É grafo");		
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
		printf("É DIgrafo");
	}
}

void buscarMenoresPesos(){
	int i,k, posicao, menorPeso;
	for(k = 0; k < V-1;k++){
		menorPeso = 99999;				
		for(i = 0; i < qAresta; i++){
			if(aresta[i].peso < menorPeso && 
					aresta[i].vEmergente != nullAresta){
				posicao = i;
				menorPeso = aresta[i].peso; 
			}	
		}
		if(verificarCiclos(aresta[posicao].vEmergente, aresta[posicao].vIncidente)){
			agm[k].vEmergente = aresta[posicao].vEmergente;
			agm[k].vIncidente = aresta[posicao].vIncidente;
			agm[k].peso = aresta[posicao].peso;
		}else{
			k--;
		}
		aresta[posicao].vEmergente = nullAresta;
		aresta[posicao].vIncidente = nullAresta;
		aresta[posicao].peso = nullAresta;
	}
}

int verificarCiclos(int vE, int vI){
	int nTemCiclos = 1, i, j;
	for(i = 0;i < V-1; i++){
		if(agm[i].vEmergente == vE){
			printf("\nEncontrou No Emergente");
			vE= agm[i].vIncidente;
			agm[i].vIncidente = nullAresta;
			agm[i].vEmergente = nullAresta;
		}else{
			if(agm[i].vIncidente == vE){
				printf("\nEncontrou No Incidente");
				vE= agm[i].vEmergente;
				agm[i].vIncidente = nullAresta;
				agm[i].vEmergente = nullAresta;				
			}
		}
		// incompleto falta demais verificações do caminho
	}	
	return nTemCiclos;
}

void imprimirAgm(){
	int i;
	printf("\n---------- AGM -----------------\n");
	for(i = 0;i < V-1; i++){
		printf("\t%d <==> %d\t%.f\n",agm[i].vEmergente,agm[i].vIncidente,
		agm[i].peso);
	}
}










