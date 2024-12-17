#include <stdio.h>
#include <stdlib.h>
#define SIZEARR 10
#define MINVALUE 0
#define MAXVALUE 12341

void clearInputBuffer(){
    char ch;
    while(ch = getchar() != '\n');
}

int getInt(int min, int max, char * msg){
    int value;
    printf(msg);

    while (scanf("%d", &value) != 1 || value < min || value > max){
        clearInputBuffer();
        
        printf("Error, try again please\n");
        printf(msg);
    }
    clearInputBuffer();
    return value;
}

void fillArray(int * a){
    int i;
    for (i = 0; i<SIZEARR; i++){
        *(a + i) = getInt(MINVALUE, MAXVALUE, "Introduza um inteiro: \n");
    }
}

void printArray(int * a){
    int i;
    for (i = 0; i<SIZEARR; i++){
        printf("%d ", *(a+i));
    }
}

void greatestEvenNumber(int * a, int * greatestEven){
    int i;
    for(i = 0; i<SIZEARR; i++){
        if(*(a + i) % 2 == 0){
            if(*(a + i) > *greatestEven){
                *greatestEven = *(a+i);
            }
        }
    }
}

int main(){
    
    int * arr = NULL, * maiorPar = MINVALUE;
    
    arr = (int *) malloc(SIZEARR * sizeof(int));

    fillArray(arr);

    printArray(arr);

    greatestEvenNumber(arr, &maiorPar);

    printf("maior número par: %d", maiorPar);

    free(arr);
    arr = NULL;
    return 0; 
}