#include <stdio.h>
#include <locale.h>

#define MAX 4

int passou;

typedef struct{
	int item[MAX];
	int primeiro;
	int ultimo;
}Fila;

void inicializarFila(Fila *f){
	f->primeiro = 0;
	f->ultimo = -1;
	passou = 0;	
}

int vaziaFila(Fila *f){
	if((f->primeiro > f->ultimo)&&(!passou)){
		return 1;
	}else{
		if(passou) return 1;
		return 0;
	}
}

int cheiaFila(Fila *f){
	if(f->ultimo == (f->primeiro -1)){
		return 1;
	}else{
		return 0;
	}
}

int remover(Fila *f){
	int temp = f->item[f->primeiro];
	f->primeiro++;
	if(f->primeiro == MAX){
		f->primeiro = 0;
		passou = 0;
	} 
	return(temp);
}

void inserir(Fila *f,int v){
	f->ultimo++;
	if(f->ultimo == MAX){
		f->ultimo = 0;
		passou = 1;
	} 
	f->item[f->ultimo] = v;
}

void mostrarFila(Fila *f){
	int i;
	for(i = f->primeiro; i != f->ultimo;i++){
		if(i == MAX) i = 0;
		printf("%d\t",f->item[i]);
	}
	printf("%d\n",f->item[i]);	
}


void main(void){
	//https://codeshare.io/QnD0gJ
	setlocale(LC_ALL,"Portuguese");
	
	Fila umaFila;
	inicializarFila(&umaFila);
	int opcao;
	while(1){
		printf("\n---- SELECIONE UMA OPÇÃO ----\n");
		printf("1. Inserir na fila\n");
		printf("2. Remover da fila\n");
		printf("3. Mostrar a fila\n");
		printf("0. Sair\nOpção? ");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 0: exit(0);
			case 1: 
				if(cheiaFila(&umaFila)) printf("\nFila Cheia!!!\n\n");
				else{
					int valor;
					printf("\nInsira o valor ");
					scanf("%d",&valor);
					inserir(&umaFila,valor);
				}
				break;
			case 2:
				if(vaziaFila(&umaFila)) printf("\nFila Vazia!!!\n\n");
				else{
					int valor;
					valor = remover(&umaFila);
					printf("\nO valor removido foi %d\n",valor);
				}
				break;
			case 3:
				if(vaziaFila(&umaFila)) printf("\nFila Vazia!!!\n\n");
				else{
					printf("Elementos na Fila: ");
					mostrarFila(&umaFila);
				} 
				break;
			default:
				printf("\nOpção invalida!!!");	
		}	
	}	
}






