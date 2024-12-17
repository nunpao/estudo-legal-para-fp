#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5


// ex1: implementa uma função que recebe duas strings e devolve o numero total de caracteres iguais presentes nas duas strings

int contaCaracteresIguais(char * s1, char * s2){ 
    int i, count = 0;

    for (i = 0; *(s1 + i) != '\0' || *(s2 + i) != '\0'; i++){
        if(*(s1+i) == *(s2 + i)){
            count++;
        }
    }

    return count;
}

// implementa uma função que recebe um array de inteiros e o respetivo tamanho, e devolve a media aritmetica dos valores positivos existentes no array

float mediaPositivos(int * a, int tam){
    int i, count = 0, sum = 0;

    for (i = 0; i < tam; i++){
        if(a[i] > 0){
            count++;
            sum+=a[i];
        }
    }

    return (float)sum/count;
}

//implemente uma função que recebe uma matriz de inteiros e devolve a soma de todos os elementos nas linhas com indice impar da matriz

int somaLinhasImpares(int m[DIM][DIM]){
    int x, y, sum;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            if(x % 2 != 0){
                sum += m[x][y];
            }
        }
    }

    return sum;
}

//implemente um procedimento que recebe uma matriz de numeros inteiros e um numero inteiro num, e imprime o número total de elementos da matriz que são maiores que num e menores que num;

void totalMaioresMenores(int m[DIM][DIM], int num){
    int cMaior = 0, cMenor = 0, x, y;

    for (x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            printf("%d %c", m[x][y], y == DIM-1? '\n' : ' ');

            if(m[x][y] > num ){
                cMaior++;
            }else{
                cMenor++;
            }
        }
    }

    printf("%d elementos da matriz são maiores que %d\n", cMaior, num);
    printf("%d elementos da matriz são menores que %d\n", cMenor, num);

}

//implemente uma função que recebe uma string e verifica se a mesma é um palindromo;

int palidromo(char * s){
    int i, len;
    len = strlen(s) - 1;

    for(i = 0; i < len; i++, len--){
        if(s[i] != s[len]){
            return 0;
        }
    }

    return 1;
}

int main(){
    /*
    //ex1
    char s1[] = "boas manos";
    char s2[] = "soeduhgfhsjdhfs";
    printf("%d", contaCaracteresIguais(s1, s2));
    */

   /*   
   //ex2
    int a[20] = {-1, 2, -2, 4, 2};

    printf("%f", mediaPositivos(a, 20));
   */

    /*
    //ex3
    int matriz[DIM][DIM] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("%d", somaLinhasImpares(matriz));
    */
    
    
    //ex4
    /*
    int matriz[DIM][DIM] = {
        {5, 5, 5, 5, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    totalMaioresMenores(matriz, 6);    
    */

    char * s1 = "ama";

    palidromo(s1) == 1 ? printf("é") : printf("não é");
    
    return 0;
}