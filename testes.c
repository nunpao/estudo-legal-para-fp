#include <stdio.h>
#include <string.h>

int strcounta(char * s){
    int i, count = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] < '0' || s[i] > '9'){
            count++;
        }
    }

    return count;
}

int strcountc(char * s, char ch){
    int i, count = 0;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == ch){
            count++;
        }
    }

    return count;
}

void strlwr(char * s){
    int i;

    for(i = 0; s[i] != '\0'; i++){
       if(s[i] >= 'A' && s[i] <= 'Z'){
        s[i] = s[i] + 32;
       }
    }
}

void strnset(char * s, char ch, int n){
    int i;

    for(i=0; s[i] != '\0' && i < n; i++){
        s[i] = ch;
    }
}

void repeticoes(char *s) {
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        if (strcountc(s, s[i]) == 1) {
            for (j = i; s[j] != '\0'; j++){
                s[j] = s[j + 1];
            }
            i--;
        }
    }
}

void strpack(char * s){
    int i, j;
    for( i = 0; s[i] != '\0'; i++){
        if(s[i] == s[i + 1]){
            for (j = i; s[j] != '\0'; j++){
                s[j] = s[j + 1];
            }
            i--;
        }
    }
}

void entremeado(char *s, int num) {
    int i, j, len = strlen(s);

    if(num != 0){
        for (i = 0, j = 0; i < len; i += num + 1) {
            s[j++] = s[i];
        }
        s[j] = '\0'; 
    }
}

int main(){
    char oi[100] = "Era uma vez";

    xspace(oi);

    printf("%s", oi);
}