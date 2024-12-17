#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS 49
#define MIN_APOSTA 6
#define NUM_LINHAS 7

void genRanNum(){
    long untime;
    time(&untime);
    srand((unsigned) untime);
}

void initializeArr(int * arr){
    int i;
    for(i = 0; i < NUMS; i++){
        *(arr + i) = 0;
    }
}

int getBetNum(){
    int num;
    do{
        printf("Introduza a quantidade de números que quer apostar: (0- terminar aposta)");
        scanf("%d", &num);
    } while((num < MIN_APOSTA || num > NUMS) && num != 0);
    return num;
}


void printArr(int * arr){
    int i;
    for (i = 0; i < NUMS; i++){
        if(*(arr + i) == 0){
            printf(" %2d", i + 1);
        } else{
            printf(" XX");
        }
        if ((i+1) % NUM_LINHAS == 0){
            putchar('\n');
        }
    }
    putchar('\n');
}

void readBet(int * arr, int num){
    int i, ix;

    for(i = 1; i <= num; i++){
        ix = rand()%NUMS;
        if(arr[ix] == 0){
            arr[ix] = 1;
        } else{
            i--;
        }
    }
}

int main(){
    int * nums = NULL;
    int betNums;

    nums = (int * ) malloc(NUMS * sizeof(int));

    genRanNum();

    initializeArr(nums);
    while(1){
        if((betNums = getBetNum()) == 0) break;
        readBet(nums, betNums);
        printArr(nums);
    }

    free(nums);
    nums = NULL;
    return 0;
}