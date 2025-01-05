#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 3

int somaDiagonal(int m[DIM][DIM]){
    int sum = 0;

    for(int i = 0; i < DIM; i++){
        sum += m[i][i];
    }

    return sum;
}

int somaOutraDiagonal(int m[DIM][DIM]){
    int sum = 0;

    for(int i = 0; i < DIM; i++){
        sum += m[i][DIM-i-1];
    }

    return sum;
}

int somaMatrizTriangularSup(int m[DIM][DIM]){
    int x, y, sum = 0;

    for(x = 0; x < DIM; x++){
        for(y = x; y < DIM; y++){
            sum += m[x][y];
        }
    }

    return sum;
}

int somaMatrizTriangularInf(int m[DIM][DIM]){
    int x, y, sum =0;

    for(x = 0; x < DIM; x++){
        for(y = 0; y <= x; y++){
            sum += m[x][y];
        }
    }

    return sum;
}

int somaSuperiorSDiagonal(int m[DIM][DIM]){
    int x, y, sum = 0;

    for(x = 0; x < DIM; x++){
        for(y = x + 1; y < DIM; y++){
            sum += m[x][y];
        }
    }

    return sum;
}

int matrizTransposta(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            m[x][y] = m[y][x];
        }
    }
}

void printMatrix(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for( y= 0; y < DIM; y++){
            printf("%d %c", m[x][y], y == DIM - 1 ? '\n' : ' ');
        }
    }
}

void rotate90Clock(int m[DIM][DIM]){
    int x, y, mTemp[DIM][DIM];

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            mTemp[y][DIM-1-x] = m[x][y];
        }
    }

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            m[x][y] = mTemp[x][y];
        }
    }
}

void rotate90Counter(int m[DIM][DIM]){
    int x, y, temp[DIM][DIM];

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            temp[DIM-y-1][x] = m[x][y];
        }
    }

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            m[x][y] = temp [x][y];
        }
    }
}

void repeatString(char * s, int maxLen){
    int i, len;

    for(len = 0; s[len] != '\0'; len++);

    for(i = 0; i < len; i++){
        s[len + i] = s[i];
    }

    s[len * 2] = '\0';
}

char toUpper(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return (ch + ('A' - 'a'));
    }

    return ch;
}

char toLower(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return (ch - ('A' - 'a'));
    }

    return ch;
}

void wordupr(char * s){
    int i;

    for(i = 1; s[i] != '\0'; i++){
        s[0] = toUpper(s[0]);
        if(s[i - 1] == ' '){
            s[i] = toUpper(s[i]);
        }
        else {
            s[i] = toLower(s[i]);
        }
    }
}

int isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }

    return 0;
}

int isLetter(char ch){
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'){
        return 1;
    }

    return 0;
}         

int isEmail(char * s){
    int len, i, hasAt, hasDomain;

    for(len = 0; s[len] != '\0'; len++) ; 

    if(len < 6) {
        return 0;
    }

    for(i = 1; s[i] != '\0'; i++){
        if(s[i] == '@' && (isDigit(s[i-1]) == 1 || isLetter(s[i-1]) == 1)){
            hasAt = 1;
            break; //evita continuar o ciclo for armazenando o indice de onde se encontra o @
        } else {
            hasAt = 0;
        }
    }

    if(!hasAt){
        return 0;
    }

    for(; s[i] != '\0'; i++){
        if(s[i] == '.' && (isDigit(s[i-1]) == 1 || isLetter(s[i-1]) == 1) && (isDigit(s[i-2]) == 1 || isLetter(s[i-2]) == 1)){
            hasDomain = 1;
            break;
        } else {
            hasDomain = 0;
        }
    }

    if(!hasDomain){
        return 0;
    }

    if(s[i +1 ] == '\0' || s[i + 2] == '\0'){
        return 0;
    }

    return 1;
}

void stringcopy(char * s1, char * s2){
    int i;

    for(i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
        s1[i] = s2[i];
    }
}

void stringcat(char*s1, char * s2){
    int i, len;
    for(i = 0, len = strlen(s1); s2[i] != '\0'; i++, len++){
        s1[len] = s2[i];
    }

    s1[len] = '\0';
}

void strpad (char * s){
    int len = strlen(s) - 1;
    s[len * 2] = '\0';
    for(; len >= 0; len--){
        s[len * 2] = s[len];
        s[len * 2 + 1] = ' ';
    }
}

void strdelc(char * s, char ch){
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++){
        if(s[i] != ch){
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}


int stricmp(char * s1, char * s2){
    int i = 0;

    while(toLower(s1[i]) == toLower(s2[i]) && s1[i] != '\0'){
        i++;
    }

    return (unsigned char) toLower(s1[i]) - (unsigned char) toLower(s2[i]);
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

void repeticoes(char * s){
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++){
        if(strcountc(s, s[i]) > 1){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void strpack(char * s){
    int i, j;
    for( i = 0; s[i] != '\0'; i++){
        if(strcountc(s, s[i]) == 1){
            for (j = i; s[j] != '\0'; j++){
                s[j] = s[j + 1];
            }
            i--;
        }
    }
}

void uma(char * s){
    int i, len = strlen(s);

    for (i = 0; i < len; i++) {
        s[len + i] = s[i];
    }

    s[len + i] = '\0';
}


int main(){
    int m[3][3] = {{12, 1, 6}, {3, 4, 5}, {6, 7, 8}};
    char boas[100] = "ALFACE";
    char boas2[100] = "oLa";

    printf("%d\n", somaDiagonal(m));
    printf("%d\n", somaOutraDiagonal(m));
    printf("%d\n", somaMatrizTriangularSup(m));
    printf("%d\n", somaMatrizTriangularInf(m));
    printf("%d\n", somaSuperiorSDiagonal(m));
    rotate90Counter(m);
    printMatrix(m);

    uma(boas);
    printf("%s", boas);
}