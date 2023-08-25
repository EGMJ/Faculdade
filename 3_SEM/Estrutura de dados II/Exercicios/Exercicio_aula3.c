#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Produto{
	int quantidade;
	struct Data entrega;
};

void main(void){	
	setlocale(LC_ALL,"Portuguese");
	struct Produto produto_A[5];
	
    int i;
    for(i=0;i<5;i++){
        produto_A[i].quantidade = 0;
        produto_A[i].entrega.dia = 0;
	    produto_A[i].entrega.mes = 0;
        produto_A[i].entrega.ano = 0;
    }

	produto_A[0].quantidade = 20;
    produto_A[0].entrega.dia = 01;
	produto_A[0].entrega.mes = 01;
	produto_A[0].entrega.ano = 2022;

	
	
	printf("\n--------Dados do Produto ---------\n");
    for(i=0;i<5;i++){
        
	    printf("Quantidade: %d\n", produto_A[i].quantidade);

        printf("Data de Entrega: %d",produto_A[i].entrega.dia);
	    printf("/%d/%d.\n",produto_A[i].entrega.mes,produto_A[i].entrega.ano);
    }
	
}
