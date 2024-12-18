#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"
#include "libraryLib.h"

int main(){
    int opcao = -1;
    Library l1 = {.bookCount = 0};

    do{
        printf("1-  Adicionar Livro\n");
        printf("2-  Listar Livros\n");
        printf("0-  Sair\n");
        printf("Capacidade da Biblioteca: %d/%d livros", l1.bookCount, MAX_NUM_BOOKS);
        putchar('\n');
        printf("Opção: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: insertBook(&l1);
            break;
        case 2: listAllBooks(l1);
            break;
        default:
            break;
        }

    }while(opcao != 0);
    return 0;
}
