#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void printArr(int * arr){
    int i;
    for (i = 0; i< DIM; i++){
        printf("%d ", *(arr + i));
    }
}


int isPrime(int num){
    int i = 2;
    for (; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

void fillArr(int *arr){
    int i = 0, num = 2;

    while (i < DIM){
        if(isPrime(num)){
            *(arr + i) = num;
            i++;
        }
        num++;
    } 
}

int main(){
    int * arr = NULL;

    arr = (int * ) malloc (DIM * sizeof(int));

    fillArr(arr);

    printArr(arr);

    free(arr);
    arr = NULL;
    return 0;
}