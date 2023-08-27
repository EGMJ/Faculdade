#include <stdio.h>
#include <malloc.h>
#include <locale.h>

struct Fila{
    int capacidade;
    float *dados;
    int primeiro;
    int ultimo;
    int nItens;
};

void criarFila(struct  Fila *f, int c){
    f->capacidade = c;
    f->dados = (float *) malloc(f->capacidade * sizeof(float));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;
}

void inserir( struct Fila *f, int v ){
    if(f->ultimo == f->capacidade - 1){
        f->ultimo = -1;
    }
    f->ultimo++;
    f->dados[f->ultimo] = v;
    f->nItens++; 
}

int remover(struct Fila *f){
    int temp = f->dados[f->primeiro++];
    if(f->primeiro == f->capacidade){
        f->primeiro = 0;
    }
    f->nItens--;
    return temp;
}

int estaVazia( struct Fila *f ){
    return (f->nItens==0);
}

int estaCheia( struct Fila *f ){
    return (f->nItens == f->capacidade);
}

void mostrarFila( struct Fila *f ){
    int cont, i;
    for (cont = 0, i=f->primeiro; cont < f->nItens; cont++){
        printf("%.2f\t", f->dados[i++]);
        if(i== f->capacidade){
            i=0;
        }
    }
    printf("\n\n");
}

void main(void){
    setlocale(LC_ALL,"Portuguese");

    int opcao, capacidade;
    float valor;
    struct Fila umaFila;

    printf("Insira a capacidade da fila:");
    scanf("%d", &capacidade);
    criarFila(&umaFila, capacidade);

    while (1){
        printf("1 - Para inserir elemento\n");
        printf("2 - Para remover elemento\n");
        printf("3 - Para mostrar a fila\n");
        printf("0 - Para sair\n");
        
        scanf("%d", &opcao);

        switch(opcao){
        case 0: 
			exit(0);
        
        case 1:
            if(estaCheia(&umaFila)){
                printf("Fila cheia\n\n");
            }else{
                printf("Insira um valor: ");
                scanf("%.2f", valor);
                inserir(&umaFila, valor);
                printf("%.2f inserido com sucesso\n\n",valor);
            }
            break;      
            
        case 2:
            if(estaVazia(&umaFila)){
                printf("Fila vazia\n\n");
            }else{
                valor = remover(&umaFila);
                printf("%.2f removido com sucesso\n\n",valor);
            }
            break;
            
        case 3:
            if(estaVazia(&umaFila)){
            printf("Fila vazia\n\n");
            }else{
                printf("Conteudo da fila: ");
                mostrarFila(&umaFila);
            }
            break;
        default:
            printf("opção invalida!\n");
            
        }

    }
    
  
    
}
