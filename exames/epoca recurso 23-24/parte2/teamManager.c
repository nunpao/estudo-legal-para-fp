#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"
#include "teamManager.h"

void criarEquipa(Equipa * e){
    e->contador = 0;

    Jogador * temp = (Jogador *) malloc(sizeof(Jogador) * JOGADORES_QTD_INICIAL);

    if(temp == NULL){
        printf("Erro na alocação de memória");
        return;
    }

    e->jogadores = temp;

    e->capacidade = JOGADORES_QTD_INICIAL;
}

int existe(Equipa e, char * nome){
    int i;

    for (i = 0; i < e.contador; i++){
        if(strcmp(e.jogadores[i].nome, nome) == 0){
            return i;
        }
    }

    return -1;
}


int alocarMemEquipa(Equipa * e){
    if(e->contador == e->capacidade){
        
        Jogador * temp = (Jogador * ) realloc(e->jogadores, sizeof(Jogador) * (e->capacidade * 2));

        if(temp == NULL){
            printf("Erro na realocação de memória!");
            return -1; //erro na alocação
        }

        e->jogadores = temp;

        e->capacidade *= 2;

        return 1; //realocacao feita com sucesso 

    } else {
        return 0; //nenhuma alocação foi feita
    }
}

int insereJogador(Equipa * e, char * nome){
    int indexJogador = existe(*e, nome);

    if(indexJogador == -1){ //indicando que nao existe nenhum jogador com esse nome, cria
        alocarMemEquipa(e); //realoca memoria caso necessário

        strcpy(e->jogadores[e->contador].nome, nome); //efetua a criação de um novo jogador
        e->jogadores[e->contador].contador = 0;
        e->contador++;

        return 1; //retorna um afirmando que a criação foi bem sucedida
    }else {
        return 0; //ja existe um jogador com esse nome
    }
}

int registaGolosJogador(Equipa * e, char * nome, int golos){
    int indexJogador = existe(*e, nome);

    if(indexJogador != -1){ //caso o jogador exista...
        if(e->jogadores[indexJogador].contador < JOGADORES_CAPACIDADE){ 
            e->jogadores[indexJogador].jogos[e->jogadores[indexJogador].contador] = golos;
            e->jogadores[indexJogador].contador++;

            return 1; //registo guardado corretamente
        }else {
            return -2; //o tamanho limite estabelecido por (JOGADORES_CAPACIDADE) foi atingido
        }
    }else {
        return -1; //o nome indicado nao corresponde a nenhum jogador
    }
}

void carregaEquipa(Equipa * e, char * ficheiro){
    FILE * fp;
    int nregs;

    if((fp = fopen(ficheiro, "rb")) == NULL){
        printf("Erro: Não foi possível abrir o ficheiro para leitura.\n");
        return;
    }

    nregs = fread(&e->contador, sizeof(int), 1, fp);

        if(nregs != 1){
            printf("ocorreu um problema a ler e.contador");
            return;
        }

        nregs = fread(&e->capacidade, sizeof(int), 1, fp);

        if(nregs != 1){
            printf("ocorreu um problema a ler e.capacidade");
            return;
        }

        Jogador * temp = (Jogador *) malloc(sizeof(Jogador) * e->capacidade);

        if(temp == NULL){
            printf("ocorreu um problema na realocação de memoria");
            exit(EXIT_FAILURE);
        }

        e->jogadores = temp;

        nregs = fread(e->jogadores, sizeof(Jogador), e->contador, fp);

        if(nregs != e->contador){
            printf("ocorreu um problema na realocação de memoria");
            return;
        }

        fclose(fp);
}