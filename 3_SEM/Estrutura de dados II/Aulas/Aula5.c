#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int multi(int x){
    if(x <= 500){
        printf("%d, ",x);
        x = x + 5;
        multi(x);
    }
}

int soma100(int x, int soma){
    if(x<= 100){
        soma = soma + x;
        x = x + 1;
        soma = soma100(x, soma);
    }
    return soma;
}

void main(void){
    // int x = 5;
    // multi(x);
    printf("%d, ", soma100(1,0));

}