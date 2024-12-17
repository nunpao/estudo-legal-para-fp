#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cleanInputBuffer(){
    char ch;
    while(ch = getchar() != '\n');
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

int compareStrings(char * s1, char * s2 ){
    int i;
    for (i = 0; *(s1 + i) != '\0' || *(s1 + i) == *(s2+i); i++) ; 
    if( *(s1 + i) == '\0' && *(s2 + i) == '\0'){
        return 1;
    }
    return 0;
}
int main(){
    char s1[50], s2[50];

    getString(s1, 50, "Introduza a string 1: ");
    getString(s2, 50, "Introduza a string 2: ");

    if(compareStrings == 1){
        printf("As strings são iguais");
    } else {
        printf("As strings são diferentes");
    }
    return 0;
}