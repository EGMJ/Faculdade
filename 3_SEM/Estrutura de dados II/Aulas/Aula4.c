#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// recursividade
// void main(void){
//     setlocale(LC_ALL,"Portuguese");
//     int num;
//     printf("Insira o valor farorial");
//     scanf("%d", &num);   
//     printf("o valor de %d, é: %d\n\n", num,fatorial(num));
//     printf("\no valor de %d, é: %d", num,fatorial(num));
// }

// int fatorial(int n){
//     if(n == 0){
//          return 1;
//     };
//     if(n > 0){
//         return n*fatorial(n-1);
//     };
// }

// int fatorialNRecursivo(int n){
//     int i, res = 1;
//     for(i = 2; i <= n; i++){
//         res = res * i;
//     }
//     return res;
// }

void main(void){
    setlocale(LC_ALL,"Portuguese");
    printf("Insira o valor de fibonnaci ");

    int num;

    scanf("%d", &num);   
    printf("\no valor de fibonnaci do %d, é: %d", num,fiboNR(num));
    printf("\no valor de fibonnaci do %d, é: %d", num,fibonacci(num));

}
// recursivo

int fibonacci(int n){

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n > 1){
         return fibonacci(n-1) + fibonacci(n-2);
    }
}

int fiboNR(int n){
    int i, f1, f2, f;
    if(n==0) return 0;
    if(n==1) return 1;
 
    f1 = 0;
    f2 = 1;
 
    for(i=2;i<=n;i++){
        f=f1+f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}