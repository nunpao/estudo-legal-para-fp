#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"
#include "libraryLib.h"

void printAuthor(Author a){
    printf("Nome -> %s\n", a.name);
    printf("Website -> %s\n", a.web);
    printf("Data Nasc -> %d/%d/%d\n", a.birthDate.day, a.birthDate.month, a.birthDate.year);
}

void printPublisher(Publisher p){
    printf("Nome ->     %s\n", p.name);
    printf("Morada ->   %s\n", p.address);
}

void printGenre(Genre g){
    switch(g){
        case 1: printf("Genre ->    FICÇAO\n");
        break;
        case 2: printf("Genre ->    TECNICO\n");
        break;
        case 3: printf("Genre ->    ROMANCE\n");
        break;
        case 4: printf("Genre ->    ESTUDO\n");
        break;
        default: break;
    }
}

void printBook(Book b){
    int i;   
    printf("----------Livro----------\n");
    printf("ISBN ->     %s\n", b.ISBN);
    printf("Título ->    %s\n", b.title);
    printGenre(b.genre);
    printf("Data Publicação ->   %d/%d/%d\n", b.publishData.day, b.publishData.month, b.publishData.year);
    printf("--Editora--\n");
    printPublisher(b.publisher);
    
    if(b.gAuthor.countAuthors > 0){
        printf("--Autores--\n");
        for(i = 0; i < b.gAuthor.countAuthors; i++){
            printAuthor(b.gAuthor.authores[i]);
            printf("----\n");
        }
    }

    printf("-------------------------\n");   
}

int searchBookISBN(Library lib, char * isbn){
    int i;

    for(i = 0; i < lib.bookCount; i++){
        if(strcmp(lib.books[i].ISBN, isbn) == 0){
            return i;
        }
    }

    return -1;
}

int createAuthor(Book * b){
    getString(b->gAuthor.authores[b->gAuthor.countAuthors].name, MAX_CH_AUT_NAME, GET_AUT_NAME);
    
    getString(b->gAuthor.authores[b->gAuthor.countAuthors].web, MAX_CH_AUT_WEB, GET_AUT_WEB);

    b->gAuthor.authores[b->gAuthor.countAuthors].birthDate.day = getInt(MIN_DAY, MAX_DAY, GET_DAY_BIRTH);
    b->gAuthor.authores[b->gAuthor.countAuthors].birthDate.month = getInt(MIN_MONTH, MAX_MONTH, GET_MONTH_BIRTH);
    b->gAuthor.authores[b->gAuthor.countAuthors].birthDate.year = getInt(MIN_YEAR, MAX_YEAR, GET_YEAR_BIRTH);

    return b->gAuthor.countAuthors++;
}

int insertAuthor(Book * b){
    int opcao = -1;
    do{
        printf("\n-----------------------Inserir Autor-----------------------");
        printf("\n1 - Adicionar Autor");
        printf("\n0 - Pular");
        printf("\n----------------------------------------------------------");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        cleanInputBuffer();

        if(opcao == 1){
            if(b->gAuthor.countAuthors < MAX_NUM_AUT){
                createAuthor(b);
            } else {
                puts(ERROR_MAX_AUT_NUM);
            }
        }
    } while(opcao != 0);
}

int createBook(Library * lib){
    char isbn[MAX_CH_BOOK_ISBN];
    cleanInputBuffer();
    getString(isbn, MAX_CH_BOOK_ISBN, GET_BOOK_ISBN);

    if(searchBookISBN(*lib, isbn) == -1){
        strcpy(lib->books[lib->bookCount].ISBN, isbn);
        getString(lib->books[lib->bookCount].title, MAX_CH_BOOK_TITLE, GET_BOOK_TITLE);

        lib->books[lib->bookCount].publishData.day = getInt(MIN_DAY, MAX_DAY, GET_DAY_PUBLISH);
        lib->books[lib->bookCount].publishData.month = getInt(MIN_MONTH, MAX_MONTH, GET_MONTH_PUBLISH);
        lib->books[lib->bookCount].publishData.year = getInt(MIN_YEAR, MAX_YEAR, GET_YEAR_PUBLISH);

        lib->books[lib->bookCount].genre = getInt(1, 4, GET_GENRE);
        
        getString(lib->books[lib->bookCount].publisher.name, MAX_CH_PUBL_NAME, GET_PUBL_NAME);
        getString(lib->books[lib->bookCount].publisher.address, MAX_CH_PUBL_ADD, GET_PUBL_ADD);

        insertAuthor(&lib->books[lib->bookCount]);

        return lib->bookCount++;
    }
    return -1;
}


void insertBook(Library * lib){
    if(lib->bookCount < MAX_NUM_BOOKS){
        if(createBook(lib) == -1){
            puts(ERROR_ISBN_EXISTS);
        }
    } else {
        puts(ERROR_LIB_FULL);
    }
}

void listAllBooks(Library lib){
    if(lib.bookCount != 0){
        int i;
        for(i = 0; i < lib.bookCount; i++){
            printBook(lib.books[i]);
        }
    } else {
        puts(ERROR_LIB_EMPTY);
    }
}