#include <stdio.h>

int main(){
    FILE * fp;
    char ch;

    fp = fopen("/Users/nunocosta/Desktop/Programar em C Luís Damas/exercicios/ficheiros/file.txt", "r");

    if(fp == NULL){
        printf("Impossível abrir o ficheiro\n");
    } else {
        printf("FIcheiro aberto com sucesso!!!\n");
    }

    while((ch=fgetc(fp)) != EOF){
        putchar(ch);
    }
        fclose(fp);
    return 0;
}