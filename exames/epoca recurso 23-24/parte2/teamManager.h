#define JOGADORES_QTD_INICIAL 10
#define JOGADORES_CAPACIDADE 35
#define JOGADORES_NOME_TAM 10

typedef struct {
    int contador;
    char nome[JOGADORES_NOME_TAM];
    int jogos[JOGADORES_CAPACIDADE];
} Jogador;

typedef struct{
    int contador;
    int capacidade;
    Jogador * jogadores;
} Equipa;