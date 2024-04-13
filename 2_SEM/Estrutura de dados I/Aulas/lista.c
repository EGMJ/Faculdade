#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct{
	int valor;
	struct Lista *proximo;
}Lista;

void inicializar(Lista **lista);
void inserirValorNaLista(Lista **lista, int x);
int qtdElementosNaLista(Lista **lista, int cont);
void exibirLista(Lista **lista);
void apagarLista(Lista **lista);

void main(void){
	setlocale(LC_ALL, "Portuguese");
	Lista *lista;
	inicializar(&lista);
	
//	inserirValorNaLista(&lista, 10);
//	inserirValorNaLista(&lista, 5);
//	inserirValorNaLista(&lista, 7);

	inserirValorNaLista(&lista, NULL);

	exibirLista(&lista);
	
	printf("\n A quantidade de elementos na lista é: %d\n", qtdElementosNaLista(&lista,0));
	
	apagarLista(&lista);
	exibirLista(&lista);
}

void inicializar(Lista **lista){
	*lista = NULL;
	printf("\nLista inicializada\n");
}

void inserirValorNaLista(Lista **lista, int x){
	if(*lista == NULL){
		*lista = (Lista *) malloc(sizeof(Lista));
		(*lista) -> valor = x;
		(*lista) -> proximo = NULL;
	} else{
		inserirValorNaLista(&((*lista) -> proximo), x);
	}
}

int qtdElementosNaLista(Lista **lista, int cont){
	if(*lista != NULL){
		qtdElementosNaLista(&((*lista)->proximo), ++cont);
	}else return cont;
}

void exibirLista(Lista **lista){
	if(*lista != NULL){
		printf("%d, ", (*lista)->valor);
		
		if((*lista)->proximo != NULL){
			exibirLista(&((*lista)->proximo));
		}else printf("\n");
		
	}else printf("Lista vazia");
}

void apagarLista(Lista **lista){
	if((*lista) != NULL){
		apagarLista(&((*lista)->proximo));
		free(*lista);
		(*lista) = NULL;
	}
}
