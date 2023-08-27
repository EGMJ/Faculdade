#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 4

int passou;
int opcao;

typedef struct{
    int item[MAX];
    int primeiro;
    int ultimo;
}Fila;

// iniciando uma fila
void inicializarFila(Fila *f){
    f->primeiro = 0;
    f->ultimo = -1;
}

int vaziaFila(Fila *f){
    if((f->primeiro > f->ultimo) && (!passou)){
        return 1;
    }else{
        if(passou) return 1;
        return 0;
    }
}

int cheiaFila(Fila *f){
    if(!vaziaFila(f) && (f->ultimo == (f->primeiro -1))){
        return 1;
    }else{
        return 0;
    }
}

int remover(Fila *f){
	int temp = f->item[f->primeiro];
    f->primeiro++;
    if(f->primeiro == MAX){
        f->primeiro == 0;
        passou = 0;
    }
    return(temp);
}

void inserir(Fila *f, int v){
	f->ultimo++;
    if(f->ultimo == MAX){
        f->ultimo = 0;
        passou = 1;
    }
    f->item[f->ultimo] = v;
}

void mostrarFila(Fila *f){
    int i;
    for(i = f->primeiro; i != f->ultimo; i++){
        if(i == MAX) i = 0;
        printf("%d \t", f->item[i]);
    }
        printf("%d \t", f->item[i]);
}



void main(void){
    setlocale(LC_ALL, "Portuguese");
    
    Fila umaFila;

    inicializarFila(&umaFila);

    while (1){
        printf("_____________ SELECIONE UMA OP��O ____________\n\n");
        printf("1. Inserir na fila\n");
        printf("2. Remover da fila\n");
        printf("3. Mostrar a fila\n");
        printf("0. Sair\n Opção? ");

        scanf("%d", &opcao);

        switch(opcao){

        case 0:
            exit(0);

        case 1:
            if(cheiaFila(&umaFila)) printf("Fila cheia\n\n");
            else{
                int valor;
                printf("Insira o valor: ");
                scanf("%d ", &valor);
                inserir(&umaFila, valor);
            }
            break;

        case 2:
            if(vaziaFila(&umaFila)) printf("Fila vazia\n\n");
            else{
                int valor;
                valor = remover(&umaFila);
                printf("O valor removido foi %d", valor);
            }
            break;

        case 3:
            if(vaziaFila(&umaFila)) printf("Fila vazia\n\n");
            else{
                printf("Elementos na Fila: ");
                mostrarFila(&umaFila);
            }
            break;

        default:
            printf("Opção invalida");
        }
    }
    


    
}

 
