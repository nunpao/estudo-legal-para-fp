#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frotaLib.h"
#include "handyLib.h"

void inicializarFrota(Frota * f){
    f->contadorCamioes = 0;
    Camiao * temp = (Camiao * ) malloc(sizeof(Camiao) * FROTA_CAPACIDADE_INICIAL);

    if(temp != NULL){
        f->camioes = temp;
        f->tamanhoFrota = FROTA_CAPACIDADE_INICIAL;
    }
}


int existe(Frota f, char * matricula){
    int i;

    for(i = 0; i < f.contadorCamioes; i++){
        if(strcmp(f.camioes[i].matricula, matricula) == 0){
            return i;
        }
    }

    return -1;
}

void realocarMemoriaFrota(Frota * f){
    Camiao * temp = (Camiao * ) realloc(f->camioes, (f->tamanhoFrota * 2) * sizeof(Camiao));

    if(temp == NULL){
        printf("Memory allocation error!\n");
        return 0;
        exit(EXIT_FAILURE);
    }

    f->camioes = temp;
    f->tamanhoFrota *= 2;
}

int insereCamiao(Frota * f){
    char matricula[MATRICULA_TAMANHO];

    getString(matricula, MATRICULA_TAMANHO, "Introduza a matricula a adicionar");

    if(existe(*f, matricula) == -1){
        if(f->contadorCamioes == f->tamanhoFrota){
            realocarMemoriaFrota(f);
        }

        strcpy(f->camioes[f->contadorCamioes].matricula, matricula);

        f->camioes[f->contadorCamioes].contador = 0;

        f->contadorCamioes++;

        return 1;
    } else {
        printf("Matricula já faz parte da frota\n");
        return 0;
    }
}

int insereKms(Frota * f, char * matricula, int km){
    int indexCamiao = existe(*f, matricula);

    if(indexCamiao != -1){
        if(f->camioes[indexCamiao].contador < KMS_CAPACIDADE){
            f->camioes[indexCamiao].kms[f->camioes[indexCamiao].contador] = km;
            f->camioes[indexCamiao].contador++;
            return 1;
        } else {
            printf("Valor máximo de entradas de km atingido");
            return -2;
        }
    }else{
        printf("Não existe nenhum camiao com essa matricula na frota!");
        return -1;
    }
}

void guardaFrota(Frota f, char * file){
    FILE * fp;
    int n_regs;

    if((fp = fopen(file, "wb")) == NULL){
        printf("Erro a abrir o ficheiro!");
        exit(EXIT_FAILURE);
    }

    n_regs = fwrite(&f.contadorCamioes, sizeof(int), 1, fp);

    if(n_regs != 1){
        printf("Erro a guardar a variavel contadorCamioes");
    }

    n_regs = fwrite(&f.tamanhoFrota, sizeof(int), 1, fp);

    if(n_regs != 1){
        printf("Erro a guardar a variavel tamanhoFrota");
    }

    n_regs = fwrite(f.camioes, sizeof(Camiao), f.contadorCamioes, fp);

    if(n_regs != f.contadorCamioes){
        printf("Erro a guardar informação de camioes");
    } 

    fclose(fp);
}