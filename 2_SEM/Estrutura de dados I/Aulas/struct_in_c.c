#include <stdio.h>
#include <locale.h>

#define QTD 2

struct Data{
	int dia, mes, ano; //estrutura homogenea, secomporta como se fosse vetor
};

struct Aluno{ //estrutura heterogenea
    char nome[20],endereco[80];
    struct Data nascimento;
    struct Data matricula;
    struct Data conclusaoCurso;
} lista[QTD];

typedef struct Aluno2{
	char nome[20],endereco[80];
}aluno;


int main(){
    setlocale(LC_ALL, "Portuguese");
    int i;
    
    struct Aluno a1;
	printf("Tamanho da estrutura de dados aluno %d bytes\n", sizeof(a1));

    for(i=0; i<QTD; i++){
        printf("Insira o nome do Aluno: ");
        scanf("%s", lista[i].nome);
        
        printf("\nInsira o endereço do Aluno: ");
        scanf("%s", lista[i].endereco);
        
        printf("\nInsira o ano do nascimento: ");
        scanf("%d", &lista[i].nascimento.ano);
        
        printf("\nInsira o mes de nascimento: ");
        scanf("%d", &lista[i].nascimento.mes);
        
        printf("\nInsira o dia de nascimento: ");
        scanf("%d", &lista[i].nascimento.dia);
    }
    
    for (i=0; i<QTD; i++){
        printf("\n\n-------------------Aluno---------------------");
        printf("\nNome: %s", lista[i].nome);
        printf("\nEndereco: %s", lista[i].endereco);
        printf("\nData de Nascimento: %d/%d/%d", lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano);
    }
}


