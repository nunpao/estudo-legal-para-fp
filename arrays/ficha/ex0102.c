#include <stdio.h>
#include <string.h>

#define DIM 50

void cleanInputBuffer(){
    char ch;
    while(ch = getchar() != '\n');
}

void getString(char * s, int size, char * msg){
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

void ceaserCypherCoder(char * s, int pos){
    int i;

    for(i = 0; s[i] != '\0'; i++){
        s[i] = ((int) s[i]) + pos;
    }
}
int main(){
    char s[DIM];
    int pos;

    getString(s, DIM, "Introduza a string que pretende codificar");

    printf("Introduza o numero de posições que pretende avançar/recuar: "); scanf("%d", &pos);

    ceaserCypherCoder(s, pos);

    printf("%s", s);

    return 0;
}
