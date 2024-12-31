#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handyLib.h"
#include "salasManager.h"

#include <stdio.h>
#include <stdlib.h>
#include "salasManager.h"

void guardarSalas(Salas salas, char *filename)
{
    FILE *fp;
    int nregs;

    if ((fp = fopen(filename, "wb")) == NULL)
    {
        printf("ERRO ao abrir ficheiro para escrita \n");
        return;
    }

    nregs = fwrite(&salas.contador, sizeof(int), 1, fp);
    if (nregs != 1)
    {
        printf("Erro a guardar salas.contador\n");
        fclose(fp);
        return;
    }

    nregs = fwrite(&salas.tamanho, sizeof(int), 1, fp);
    if (nregs != 1)
    {
        printf("Erro a guardar salas.tamanho\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < salas.contador; i++)
    {
        nregs = fwrite(&salas.salas[i].capacidade, sizeof(int), 1, fp);
        if (nregs != 1)
        {
            printf("Erro a guardar capacidade da sala\n");
            fclose(fp);
            return;
        }

        nregs = fwrite(&salas.salas[i].ocupacao, sizeof(int), 1, fp);
        if (nregs != 1)
        {
            printf("Erro a guardar ocupacao da sala\n");
            fclose(fp);
            return;
        }

        nregs = fwrite(salas.salas[i].nome, sizeof(char), SALA_NOME_MAX, fp);
        if (nregs != SALA_NOME_MAX)
        {
            printf("Erro a guardar nome da sala\n");
            fclose(fp);
            return;
        }

        nregs = fwrite(salas.salas[i].presencas, sizeof(int), salas.salas[i].ocupacao, fp);
        if (nregs != salas.salas[i].ocupacao)
        {
            printf("Erro a guardar presencas da sala\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

int carregarSalas(Salas *salas, char *filename)
{
    FILE *fp;
    int nregs;

    if ((fp = fopen(filename, "rb") != NULL))
    {
        nregs = fread(&salas->contador, sizeof(int), 1, fp);

        if (nregs != 1)
        {
            printf("Erro a ler contador de salas\n");
            fclose(fp);
            return 0;
        }

        nregs = fread(&salas->tamanho, sizeof(int), 1, fp);

        if (nregs != 1)
        {
            printf("Erro a ler tamanho de salas\n");
            fclose(fp);
            return 0;
        }

        Sala *temp = (Sala *)malloc(sizeof(Sala) * salas->tamanho);

        if (temp == NULL)
        {
            printf("Erro ao alocar memória");
            return 0;
        }

        salas->salas = temp;

        for (int i = 0; i < salas->contador; i++)
        {
            nregs = fread(&salas->salas[i].capacidade, sizeof(int), 1, fp);
            if (nregs != 1)
            {
                printf("Erro a ler capacidade da sala\n");
                fclose(fp);
                return 0;

                nregs = fread(&salas->salas[i].ocupacao, sizeof(int), 1, fp);
                if (nregs != 1)
                {
                    printf("Erro a ler ocupacao da sala\n");
                    fclose(fp);
                    return 0;
                }

                nregs = fread(salas->salas[i].nome, sizeof(char), 1, fp);
                if (nregs != SALA_NOME_MAX)
                {
                    printf("Erro a ler nome da sala\n");
                    fclose(fp);
                    return 0;
                }

                int *temp = (int *)malloc(sizeof(int) * salas->salas[i].capacidade);

                if (temp == NULL)
                {
                    printf("Erro a alocar memória");
                    fclose(fp);
                    return 0;
                }

                salas->salas[i].presencas = temp;

                nregs = fread(salas->salas[i].presencas, sizeof(int), salas->salas[i].ocupacao, fp);

                if (nregs != salas->salas[i].ocupacao)
                {
                    printf("Erro a ler presencas");
                    fclose(fp);
                    return 0;
                }
            }

            fclose(fp);
            return 1;
        }
    } else {
        fclose(fp);

        //inicializa salas
        salas->contador = 0;
        
        Sala * temp = (Sala * ) malloc(sizeof(Sala) * SALAS_TAM_INICIAL);

        if(temp == NULL){
            printf("erro a alocar mem");
            fclose(fp);
            return 0;
        }

        salas->salas = temp;
        salas->tamanho = SALAS_TAM_INICIAL;

        if((fp = fopen(filename, "wb")) != NULL){
            //guarda os valores iniciais
            fwrite(&salas->contador, sizeof(int), 1, fp);
            fwrite(&salas->tamanho, sizeof(int), 1, fp);
            fwrite(&salas->salas, sizeof(Sala), salas->contador, fp);

            return 1;
        }
    }
       
}


int procurarSala(Salas s, char * nome){
    int i;

    for(i = 0; i < s.contador; i++){
        if(strcmp(s.salas[i].nome, nome) == 0){
            return i;
        }
    }

    return 0;
}

int expandirMemSala(Salas * s){
    if(s->contador == s->tamanho){
        Sala * temp = realloc (s->salas, sizeof(Sala) * (2 * s->tamanho));

        if(temp == NULL){
            return -1; //indicando que não houve sucesso na realocacao
        }

        s->salas = temp;

        s->tamanho *= 2;

        return 1; //indicando que houve sucesso na realocação
    } else {
        return 0; //indicando que nao foi feita nenhuma realocação
    }
}

int inserirSala(Salas * s, char * nome, int capacidade){
    int indexSala = procurarSala(*s, nome);

    if(indexSala == -1){ //indicando que nao existe nenhuma sala com o nome dado
        if(expandirMemSala(s) == -1){ //caso exista um problema na realocao de memoria(return -1) devolve 0 na fncao de criação
            return 0;
        }

        strcpy(s->salas[s->contador].nome, nome);

        s->salas[s->contador].ocupacao = 0;

        int * temp = (int *) malloc(sizeof(int) * capacidade);

        if(temp == NULL){
            printf("errro na alocacao de mem");
            return 0;
        }

        s->salas[s->contador].presencas = temp;
        s->salas[s->contador].capacidade = capacidade;

        s->contador++;

        return 1;
    } else {
        return 0;
    }
}

void apagarDadosSala(Sala * s){
    s->capacidade = 0;
    strcpy(s->nome, "");
    s->ocupacao = 0;
    s->presencas = NULL;
}

int removerSala(Salas * s, char * nome){
    int i, indexSala = procurarSala(*s, nome);

    if(indexSala != -1){
        free(s->salas[indexSala].presencas);
        
        for(i = indexSala; i < s->contador - 1; i++){
            s->salas[i] = s->salas[i + 1];
        }   

        apagarDadosSala(&s->salas[i]);   
        s->contador--;

        return 1;
    }else {
        return 0;
    }
}