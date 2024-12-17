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

void transposeMatrix(int m[DIM][DIM], int mT[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            mT[x][y] = m[y][x];
        }
    }
}



int main(){

    int matrix[DIM][DIM], tMatrix[DIM][DIM];

    initializeMatrix(matrix); 
    initializeMatrix(tMatrix);

    fillMatrix(matrix);
    transposeMatrix(matrix, tMatrix);

    printf("A matriz transposta da matriz: \n");
    printMatrix(matrix);
    printf("A matriz transposta da matriz é: \n");
    printMatrix(tMatrix);

    return 0;
}