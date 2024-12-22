#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia, mes, ano;
} Data;

typedef struct {
    int num;
    char nome[40];
    Data dataNascimento;
} Aluno;

typedef struct{
    int contador;
    int alocados;
    Aluno * alunos;
} GAlunos;

//retorna 1 se sucesso, 0 c.c

int guardarAlunosFicheiro(GAlunos gA, char * fileName){
    FILE * fp; 
    int nRegs; //numero de registos que sao escritos no ficheiro

    if((fp = fopen(fileName, "wb")) == NULL){
        printf("Erro"); return 0;
    }

    nRegs = fwrite(&gA.contador, sizeof(int), 1, fp);

    if(nRegs < 1){
        printf("Erro");
        return 0;
    }

    nRegs = fwrite(&gA.alocados, sizeof(int), 1, fp);

    if(nRegs < 1){
        printf("Erro");
        return 0;
    }

    nRegs = fwrite(gA.alunos, sizeof(Aluno), gA.contador, fp);

     if(nRegs < gA.contador){
        printf("Erro");
        return 0;
    }

    fclose(fp);
    return 1;
}

int carregarAlunosFicheiro(GAlunos * gA, char * fileName){
    FILE * fp;
    int nRegs;

    if((fp = fopen(fileName, "rb")) != NULL){
        nRegs = fread(&gA->contador, sizeof(int), 1, fp);

        if(nRegs < 1){
            printf("Erro");
            return 0;
        }

        nRegs = fread(&gA->alocados, sizeof(int), 1, fp);

        if(nRegs < 1){
            printf("Erro");
            return 0;
        }

        gA->alunos = malloc(sizeof(Aluno) * gA->alocados);

        nRegs = fread(gA->alunos, sizeof(Aluno), gA->contador, fp);

        if(nRegs < gA->contador){
            printf("Erro");
            return 0;
        }

        fclose(fp);

        return 1;
    } else {
        fclose(fp);

        fp = fopen(fileName, "wb");

        gA->contador = 0;

        nRegs = fwrite(&gA->contador, sizeof(int), 1, fp);

        gA->alocados = 0;

        nRegs = fwrite(&gA->alocados, sizeof(int), 1, fp);

        gA->alunos = (Aluno *) malloc (sizeof(Aluno) * gA->alocados);

        gA->alunos = NULL;
        
        fclose(fp);
    }
}
int main(){
    GAlunos gA;
}