#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vetor[10];
int aux;

void main(void){
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    int i;
    for(i=0;i<10;i++){
        vetor[i] = rand()%1000;
    }

    for(i=0;i<10;i++){
        printf("%d, ", vetor[i]);
    }

    printf("O maior valor do vetor é: %d", max(-999, 0));

}

// implemente recursividade uma funcao max que retorne o maior valor armazenado em um vetor v contendo n numeros inteiro

int max(int maior, int i){
    if(i == 10) return maior;
    if(maior < vetor[i]){
        max(vetor[i], i+1);
    }else{
        max(maior, i+1);
    }
    
}