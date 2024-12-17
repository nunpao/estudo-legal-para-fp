#include <stdio.h>

//Devolve o número de caracteres existentes na string s (sem contar o '\0').
int strlen(char *c){
    int i;
    for(i = 0; c[i] != '\0'; i++) ; 
    return i++;
}

//Verifica se uma string contém ou não algum caractere, devolvendo o valor lógico correspondente.
int isNull(char *s){
    return s[0] == '\0';
}

// Essa função copia a string orig para a string dest.

void strcpy(char * sI, char * sO){
    int i;

    for (i = 0; sI[i] != '\0'; i++){
        *(sO + i) = *(sI + i); 
    }
    sO[i] = '\0';
}

//Coloca a string orig imediatamente após o final da string dest.
void strcat(char * sin, char * sout){
    int i, len;

    for(i = 0, len = strlen(sout); *(sin + i) != '\0'; i++, len++){
        *(sout + len) = *(sin + i);
    }
    *(sout + len) = '\0';
}

//devolve o numero de ocorrencias do caracter ch na string s

int strcountc(char * s, char ch){
    int i, count;

    for(i = 0, count = 0; *(s+i) != '\0'; i++){
        if(*(s+i) == ch){
            count++;
        }
    }
    return count;
}

// determina se um caracter é ou não um digito
int isDigit(char c){
    if(c >= (int) '0' && c <= (int) '9'){
        return 1;
    }
    return 0;
}

//devolve o numero de digitos numa string
int strcountd(char *s){
    int i, count;
    for (i= count = 0 ; *(s + i) != '\0'; i++){
        if(isDigit(*(s+i))){
            count++;
        }
    }
    return count;
}

//Devolve o índice da primeira ocorrência do caractere ch na string s.
//Se o caractere não existir devolve - 1, pois zero é um indice possível (primeiro elemento da string).

int indchr(char *s, char ch){
    int i;
    for(i = 0; *(s + i) != '\n'; i++){
        if(*(s + i) == ch){
            return i;
        }
    }

    return -1;
}

//verifica se a string é um palindromo, isto é, se é lida da mesma forma da esquerda para a direita e da direita para a esquerda.

int strpal(char *s){
    int i, j;

    for(i = 0, j = strlen(s) -1; i<j; i++, j--){
        if(s[i] != s[j]){
            return 0;
        }
    }

    return 1;
}

//inverte uma string e devolve-a invertida;
char *strrev(char *s){
    int i, len;
    len = strlen(s) - 1;
    char aux;

    for(i = 0; i < len; i++, len--){
        aux = *(s+i);
        *(s+i) = *(s+len);
        *(s+len) = aux;
    }
    return s;
}

//compara as strings

int strcmp(char *s1, char *s2){
    int i;

    for(i = 0; *(s1+i) != '\0' && *(s1 + i) == *(s2 + i); i++) ;

    if(*(s1+i) == '\0' && *(s2+i) == '\0'){
        return 1;
    }

    return 0;
}

//colocar um traço apos cada um dos caracteres da string s 

char * strpad(char *s){
    int len = strlen(s);
    s[len * 2] = s[len];
    
    int i = len -1; //remove o terminador

    for(; i >= 0; i--){
        printf("posicao: %d\n caracter: %c\n", i, s[i]);
        s[i*2] = s[i];
        s[i*2+1] = '-';
    }

    return s;
}

int main(){
    char s1[30] = "B04s Man0s";
    char s2[30] = "oi oi";
    char s3[10] = "ola";
    char c = 'o';
    printf("%d\n", strlen(s1));
    printf("%d\n", isNull(s1));

    printf("antes da copia:\n s1 = %s\n s2 = %s\n", s1, s2);
    strcpy(s1, s2);
    printf("depois da copia:\n s1 = %s\n s2 = %s\n", s1, s2);

    printf("antes da copia:\n s1 = %s\n s2 = %s\n", s1, s2);
    strcat(s1, s2);
    printf("depois da copia:\n s1 = %s\n s2 = %s\n", s1, s2);

    printf("numero de ocorrencias de '%c' em '%s': %d \n", c, s1, strcountc(s1, c));
    
    printf("numero de digitos na string: \"%s\": %d\n",s1, strcountd(s1));

    printf("\'%c\' aparece pela primeira vez na string \"%s\" na posição %d\n", 'a', s1, indchr(s1, 'a'));

    printf("%s", strpad(s3));

    return 0;
}

