#include <stdio.h>
#include <string.h>

#define VALOR_INVALIDO "Valor inválido, tente novamente"

void cleanInputBuffer(){
    char ch;
    while(ch = getchar() != '\n');
}

int getInt(int minValue, int maxValue, char * msg){
    int value;
    printf(msg);

    while(scanf("%d", &value) != 1 || value < minValue || value > maxValue){
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();

    return value;
}

float getFloat(float minValue, float maxValue, char * msg){
    float value;
    printf(msg);
    while(scanf("%f", &value) != 1 || value < minValue || value > maxValue){
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }

    cleanInputBuffer(); 

    return value;
}

double getDouble(double minValue, double maxValue, char * msg){
    double value;
    printf(msg);
    while(scanf("%lf", &value) != 1 || value < minValue || value > maxValue){
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }

    cleanInputBuffer();

    return value;
}

void getString(char *string, unsigned int tamanho, char *msg){
    printf(msg);

    if(fgets(string, tamanho, stdin) != NULL){
        unsigned int len = strlen(string) - 1;
        if(string[len] == '\n'){
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}