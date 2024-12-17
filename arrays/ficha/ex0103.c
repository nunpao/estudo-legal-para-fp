#include <stdio.h>
#define DIMX 3
#define DIMY 3

void cleanInputBuffer(){
    char ch;

    while(ch = getchar() != '\n');
}

int readInt(int min, int max, char* msg){
    int value;

    printf(msg);

    while(scanf("%d", &value) != 1 || value < min || value > max){
        cleanInputBuffer();

        printf("\nErro, por favor tente novamente!");
        printf(msg);
    }
    cleanInputBuffer();

    return value;
}

void fillMatriz(int matrix[DIMX][DIMY]){
    int x, y;
    for (x = 0; x < DIMX; x++){
        for(y = 0; y<DIMY; y++){
            printf("Preencha a posição (%d,%d)\n", x, y);
            matrix[x][y] = readInt(-200, 200, "Introduza um inteiro [-200 : 200]\n");
        }
    }
}

void printMatrix(int matrix[DIMX][DIMY]){
    int x, y;
    for (x = 0; x < DIMX; x++){
        for(y = 0; y<DIMY; y++){
            printf("%d %c", matrix[x][y], y == DIMY -1 ? '\n' :  ' ');
        }
    }
}

void countOcurrences(int matrix[DIMX][DIMY], int num, int * count){
    int x, y;

    for(x = 0; x < DIMX; x++){
        for(y = 0; y < DIMY; y++){
            if (matrix[x][y] == num){
                *count = *count + 1; 
            }
        }
    }
}

int main(){
    //faça um programa que prencha cada posição de uma matriz 4x5 com valores inteiros introduzidos pelo uitlizador.
    // deverá depois ler um outro valor do utilizador e indicar quantas vezes existe na matriz

    int matrix[DIMX][DIMY];
    int count = 0;
    
    printf("Número de ocorrencias: %d", count);

    fillMatriz(matrix);
    
    printMatrix(matrix);

    countOcurrences(matrix, 12, &count);

    printf("Número de ocorrencias: %d", count);

    return 0;
}