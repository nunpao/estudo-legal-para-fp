#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 3 

int obtemValor(char * msg){
    int value = -1;

    do{
        printf("Insira a %s onde pertende jogar (0|1|2): ", msg);
        scanf("%d", &value);
    } while(value < 0 || value > 3);

    return value;
}

void imprimirMatriz(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            printf("%d %c", m[x][y], y == DIM - 1 ? '\n' : ' ');
        }
    }
}

int verificarPosicaoVazia( int m[DIM][DIM], int l, int c){
    return m[l][c] == -1;
}

int verificarVitoria(int m[DIM][DIM], int player){
    int x, y;

    for (x = 0; x < DIM; x++){
        if(m[x][0] == player && m[x][1] == player && m[x][2] == player){
            return 1;
        }
    }

    for(y = 0; y < DIM; y++){
        if(m[0][y] == player && m[1][y] == player && m[2][y] == player){
            return 1;
        }
    }

    if((m[0][0] == player && m[1][1] == player && m[2][2] == player) || (m[0][2] == player && m[1][1] == player && m[2][0] == player)){
        return 1;
    }

    return 0;
}

void inicializarMatriz(int m[DIM][DIM]){
    int x, y;

    for(x = 0; x < DIM; x++){
        for(y = 0; y < DIM; y++){
            m[x][y] = -1;
        }
    }
}

int main(){
    int galo[DIM][DIM], player = 1;

    inicializarMatriz(galo);
    imprimirMatriz(galo);
   
    while(1){
        int linha = obtemValor("linha");
        int coluna = obtemValor("coluna");
        if(verificarPosicaoVazia(galo, linha, coluna)){
            galo[linha][coluna] = player;
            imprimirMatriz(galo);

            if(verificarVitoria(galo, player) == 1){
                printf("O player %d venceu!!!", player);
                break;
            } else {
                printf("------Proxima jogada--------\n");
            }

            if(player == 1){
                player = 2;
            } else {
                player = 1;
            }
        }
    }

    return 0;
}