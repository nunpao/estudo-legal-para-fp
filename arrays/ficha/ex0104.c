#include <stdio.h>
#define DIM 3
#define MINVALUE -230231.0
#define MAXVALUE 214234235.2

void cleanInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float readFloat(int x, int y, float min, float max){
    float value;
    printf("Introduza um valor para o campo (%d, %d) [%.2f-%.2f]: \n", x, y, min, max);

    while(scanf("%f", &value) != 1 || value < min || value > max){
        printf("Erro, tente novamente\n");
        cleanInputBuffer();
        printf("Introduza um valor para o campo (%d, %d) [%.2f-%.2f]: \n", x, y, min, max);
    }
    cleanInputBuffer();

    return value;
}

void fillMatrix(float matrix[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            matrix[x][y] = readFloat(x, y, MINVALUE, MAXVALUE);
        }
    }
}

void sumElements(float matrix[DIM][DIM], float * totalValue){
    int x, y;

    for(x=0; x<DIM; x++){
        for(y=0; y<DIM; y++){
            *totalValue = *totalValue + matrix[x][y];
        }
    }
}

void printMatrix(float matrix[DIM][DIM]){
    int x, y;

    for(x=0; x<DIM; x++){
        for(y=0; y<DIM; y++){
            printf("%.1f %c", matrix[x][y], y == DIM-1 ? '\n' : ' '  );
        }
    }
}

void meanerElementMatrix(float matrix[DIM][DIM], float * min){
    int x, y;

    for(x=0; x<DIM; x++){
        for(y=0; y<DIM; y++){
            if(matrix[x][y] < *min){
                *min = matrix[x][y];
            }
        }
    }
}

void majorElementMatrix(float matrix[DIM][DIM], float * max){
    int x, y;

    for(x=0; x<DIM; x++){
        for(y=0; y<DIM; y++){
            if(matrix[x][y] > *max){
                *max = matrix[x][y];
            }
        }
    }
}



int main(){
    //Faça um programa que preencha cada posição de uma matriz (3x3 elementos inteiros) com
//um valor introduzido pelo utilizador. Deverá indicar qual o maior e qual o menor dos valores
//guardados na matriz, e deverá imprimir todo o conteúdo da matriz da forma exemplificada:

    float matrixTeste[DIM][DIM];
    float minValue = MAXVALUE, maxValue = MINVALUE, totalValue = 0;

    fillMatrix(matrixTeste);
    printMatrix(matrixTeste);
    sumElements(matrixTeste, &totalValue);
    meanerElementMatrix(matrixTeste, &minValue);
    majorElementMatrix(matrixTeste, &maxValue);
    printf("A soma dos elementos é: %.1f\n", totalValue);
    printf("o menor elemento é: %.1f\n", minValue);
    printf("o maior elemento é: %.1f\n", maxValue);


    return 0;
}