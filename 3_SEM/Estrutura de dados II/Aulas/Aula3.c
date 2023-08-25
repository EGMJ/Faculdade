#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Conta{
	int numero;
	char nome[20];
	struct Data abertura;
	struct Data ultimoPag;
};

void main(void){	
	setlocale(LC_ALL,"Portuguese");
	struct Conta pessoa1;
	
	pessoa1.numero = 1234;
	strcpy(pessoa1.nome,"Juliano Silva");

	pessoa1.abertura.dia = 11;
	pessoa1.abertura.mes = 02;
	pessoa1.abertura.ano = 1997;

	pessoa1.ultimoPag.dia = 05;
	pessoa1.ultimoPag.mes = 8;
	pessoa1.ultimoPag.ano = 2023;
	
	printf("\n--------Dados da Pessoa 1 ---------\n");
	printf("Número da conta: %d\n",pessoa1.numero);
	printf("Nome: %s\n",pessoa1.nome);
	printf("Data de Abertura: %d",pessoa1.abertura.dia);
	printf("/%d/%d.\n",pessoa1.abertura.mes,pessoa1.abertura.ano);
	printf("Data do ultimo pagamento: %d",pessoa1.ultimoPag.dia);
	printf("/%d/%d\n",pessoa1.ultimoPag.mes,pessoa1.ultimoPag.ano);

    struct Conta pessoa[100];

    printf("\n\n O tamanho da estrutura de dados conta é: %d de bytes", sizeof(struct Conta));
    printf("\n\n O tamanho da estrutura de dados conta é: %d de bytes", sizeof( pessoa));
}
