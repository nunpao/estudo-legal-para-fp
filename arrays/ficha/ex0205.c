#include <stdio.h>
#define LEN 20

void cleanInputBuffer(){
    char ch;
    while(ch = getchar() != '\n');
}

int strlen(char * s){
    int count = 0, i;

    for(i = 0; *(s + i) != '\0'; i++){
        count++;
    }

    return count;
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

void invertString(char * s){
    int i = 0; 
    int count = strlen(s) - 1;
    char ch;

    for (; i < count; i++ , count--){
        ch = s[count];
        s[count] = s[i];
        s[i] = ch;
    }
}

int main(){
    char s1[LEN];

    getString(s1, LEN, "Mete uma string: ");
    printf("%d", strlen(s1));
    printf("\nString inserida: %s", s1);
    invertString(s1);
    printf("\nString invertida: %s", s1);
}