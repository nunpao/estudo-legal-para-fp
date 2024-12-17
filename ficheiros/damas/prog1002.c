#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE * fp;
    char Nome[100];
    int Nota;

    if((fp = fopen("/Users/nunocosta/Desktop/Programar em C Luís Damas/exercicios/ficheiros/file.txt", "r")) == NULL){
        printf("Impossível abrir o ficheiro\n");
        exit(2);
    }

    while(fscanf(fp, "%s %d", Nome, &Nota) != EOF){
        if (Nota >= 10){
            printf("%s %d\n", Nome, Nota);
        }
    }

    fclose(fp);
}