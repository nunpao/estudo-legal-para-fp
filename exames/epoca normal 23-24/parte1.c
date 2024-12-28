#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5

//ex 1 - implemente uma função que receba uma string e devolva a soma de espaços em branco 
int contaEspaçosEmBranco(char * s){
    int count = 0, i;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
            count++;
        }
    }

    return count;
}

//ex2 - implementa uma função que recebe uma string e um char c, e que devolva a ultima posicao no array em que c ocorre na string.
int devolveUltimaPosicao(char * s, char c){
    int i, len = strlen(s) - 1;

    for(i = len; i >= 0; i--){
        if(s[i] == c){
            return i;
        }
    }

    return -1;
}

//ex3 - implemente uma função que receba um array de inteiros e o seu tamanho e devolva 0 se o array estiver ordenado de forma crescente e 1 caso contrario 
int ordenado( int * a, int size){
    int i;

    for(i = 0; i < size - 1; i++){
        if(a[i] > a[i + 1]){
            return 0;
        }   
    }
    return 1;
}

//ex4 - implemente uma função que receba uma matriz de inteiros e devolvea a soma de tofos os elementos localizados acima e na diagonal
int somaMatrizSuperior(int m[DIM][DIM]){
    int x, y, sum = 0;
    for(x = 0; x < DIM; x++){
        for(y = x; y < DIM; y++){
            sum += m[x][y];
        }
    }
    return sum;
}

//ex5 - implemente uma matriz que recebe uma matriz de numeros inteiros e devolve o total de numeros inteiros pares
int totalParesMatriz(int m[DIM][DIM]){
    int x, y, count = 0; 

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            if(m[x][y] % 2 == 0){
                count ++;
            }
        }
    }

    return count;
}

//ex6 - implemente um procedimento que recebe uma string s e recebe a mesma string invertida
void invertePalavra(char *s){
    char chTemp, i, len = strlen(s) - 1;

    for(i = 0; i < len; i++, len--){
        chTemp = s[i];
        s[i] = s[len]; 
        s[len] = chTemp;
    } 
}

int main(){
    /*
    //EX1
    char * s = "teste    t s te";
    printf("%d", contaEspaçosEmBranco(s));
    */

    /*
        //EX2
        char * s = "um texte extremamente insignificante";
        printf("%d", devolveUltimaPosicao(s, 'e'));
    */

    /*
        //EX3
        int a[5] = {24, 26, 30, 35, 40};

        printf("%d", ordenado(a, 5));

    */

   
   //EX4
    int matriz[DIM][DIM] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    printf("%d", somaMatrizSuperior(matriz));
    


    /*
    //EX5
    int matriz[DIM][DIM] = {
        {1, 1, 1, 1, 1},
        {1, 2, 1, 1, 1},
        {1, 1, 5, 4, 1},
        {1, 1, 6, 1, 1},
        {1, 1, 1, 1, 1}
    };

    printf("%d", totalParesMatriz(matriz));
    */

   char msg[15] = "fundamentos  ";

   invertePalavra(msg);

   printf("%s", msg);
    

  return 0; 
}