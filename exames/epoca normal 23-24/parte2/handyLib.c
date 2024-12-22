#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"

void cleanInputBuffer(){
    char ch;

    while((ch = getchar()) != '\n');
}

int getInt(int min, int max, char * msg){
    int value;

    printf(msg);

    while(scanf("%d", &value) != 1 || value < min || value > max){
        printf("Input inválido, tente novamente\n");
        cleanInputBuffer();
        puts(msg);
    }

    cleanInputBuffer();

    return value;
}

void getString(char * s, unsigned int size, char * msg){

    printf(msg);

    if(fgets(s, size, stdin) != NULL){
       unsigned int len = strlen(s) - 1;     
       if(s[len] == '\n'){
        s[len] = '\0';
       } else {
        cleanInputBuffer();
       }
    }
}