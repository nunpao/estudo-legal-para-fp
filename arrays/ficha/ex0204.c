#include <stdio.h>
#include <stdlib.h>
#define DIM 3

void cleanInputBuffer(){
    char ch;

    while (ch = getchar() != '\n');
}

int getInt(int posX, int posY){
    int value;
    printf("Introduza um valor inteiro, posição -> (%d, %d)", posX, posY);

    while (scanf("%d", &value) != 1){
        cleanInputBuffer();
        printf("Erro, tente novamente!");
        printf("Introduza um valor inteiro, posição -> (%d, %d)", posX, posY);
    }
    cleanInputBuffer();
    return value;
}

void initializeMatrix(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            m[x][y] = 0;
        }
    }
}

void fillMatrix(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            m[x][y] = getInt(x, y);
        }
    }
}

void printMatrix(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            printf("%d %c", m[x][y], y == DIM - 1 ? '\n' : ' ');
        }
    }
}

void rotateMatrix90(int m[DIM][DIM], int mR[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            mR[x][y] = m[DIM-y-1][x];
        }
    }
}



int main(){

    int matrix[DIM][DIM], rMatrix[DIM][DIM];

    initializeMatrix(matrix); 
    initializeMatrix(rMatrix);

    fillMatrix(matrix);
    rotateMatrix90(matrix, rMatrix);

    printf("A matriz transposta da matriz: \n");
    printMatrix(matrix);
    printf("A matriz transposta da matriz é: \n");
    printMatrix(rMatrix);

    return 0;
}