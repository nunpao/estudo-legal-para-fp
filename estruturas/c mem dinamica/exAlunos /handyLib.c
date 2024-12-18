#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"

#define INVALID_INPUT "Valor inválido, tente novamente \n"


void cleanInputBuffer(){
    char ch;

    while(ch = getchar() != '\n');
}

int getInt(int min, int max, char * msg){
    int value;

    printf(msg);

    while(scanf("%d", &value) != 1 || value < min || value > max){
        puts(INVALID_INPUT);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();

    return value;
}

float getFloat(float min, float max, char * msg){
    float value;

    printf(msg);

    while(scanf("%f", &value) != 1 || value < min || value > max){
        puts(INVALID_INPUT);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;
}

double getDouble(double min, double max, char * msg){
    double value;

    printf(msg);

    while(scanf("%lg", &value) != 1 || value < min || value > max){
        puts(INVALID_INPUT);
        cleanInputBuffer();
        printf(msg);
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
        }else{
            cleanInputBuffer();
        }
    }
}