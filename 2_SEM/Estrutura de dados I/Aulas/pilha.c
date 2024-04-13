#include <stdio.h>
#include <locale.h>

#define MAX 10

// Estrutura de dados Pilha
typedef struct {
    int item[MAX];
    int topo;
}Pilha;

void iniPilha(Pilha *p){
    p->topo = -1; // Indica que não há nenhum item na pilha.
}

int pilhaVazia(Pilha *p){ 
    if(p->topo == -1){ // Verifica se está vazia, se estiver retorna verdadeiro se não falso
        return(1); 
    }else{
        return 0;
    }
}

int pilhaCheia(Pilha *p){
    if(p->topo == MAX - 1){ // Verifica se está cheia, se estiver retorna verdadeiro se não falso
        return 1;
    }else return 0;
}

int empilhar(Pilha *p, int x){
    if(pilhaCheia(p)){
        printf("Pilha cheia, vc não pode add novos itens"); 
        return (-1);
    }else{
        p->topo++; // soma um ao topo, depois atribui o valor de x para o item e depois retorna o topo
        p->item[p->topo] = x;
        return (p->topo);
    }
}

int desempilhar(Pilha *p){
    if(pilhaVazia(p)){
        printf("Pilha vazia, vc não pode remover itens.");
        return -1;
    }else{
        int aux = p->item[p->topo]; // vc cria uma variavel auxiliar e atribui o valor do item no topo e depois subtrai o valor do topo informando que o novo topo é o seu valor anterior e depois mostra o valor que vc retirou do topo e que pode ser substituido por outro quando vc adicionar outro valor.
        p->topo--;
        return aux;
    }
}

int retornaTopo(Pilha *p){
    return p->item[p->topo];
}

void imprimirPilhaVetor(Pilha *p){
    printf("--------- Imprimir como Vetor --------------\n");
    int i;
    for(i=0;i <= p->topo;i++){
        printf("%d ,", p->item[i]);
    }
}

void imprimirPilha(Pilha *p){
    printf("--------- Imprimir Pilha --------------\n");
    int i;
    for(i = p->topo; i >= 0; i--){
        printf("%d, ", p->item[i]);
    }
}

void main(void){ // Ficara por ultimo pois não é necessario passar todas funções no main
    Pilha p;
    iniPilha(&p);

    empilhar(&p, 5);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 13);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 45);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 77);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 98);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 8978);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 8955);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 85);
    printf("%d, ", retornaTopo(&p));
    empilhar(&p, 845);
    printf("%d, ", retornaTopo(&p));
    
    printf("\n\n\n\n");

    imprimirPilhaVetor(&p);
    printf("\n\n\n\n");
    imprimirPilha(&p);

    // desempilhar(&p);
    // printf("%d, ", retornaTopo(&p));

}
