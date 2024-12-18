#define MAX_NUM_BOOKS 50

#define MIN_DAY 1
#define MAX_DAY 31
#define GET_DAY_PUBLISH "Introduza o dia de publicação: "
#define GET_DAY_BIRTH "Introduza o dia de nascimento: "

#define MIN_MONTH 1
#define MAX_MONTH 12
#define GET_MONTH_PUBLISH "Introduza o mês de publicação: "
#define GET_MONTH_BIRTH "Introduza o mês de nascimento: "

#define MIN_YEAR 1900
#define MAX_YEAR 2024
#define GET_YEAR_PUBLISH "Introduza o ano de publicação: "
#define GET_YEAR_BIRTH "Introduza o ano de nascimento: "

#define MAX_CH_PUBL_NAME 50
#define GET_PUBL_NAME "Introduza o nome da editora: "

#define MAX_CH_PUBL_ADD 80
#define GET_PUBL_ADD "Introduza a morada da editora: "

#define GET_GENRE "Defina o género do livro (FICCAO = 1 || TÉCNICO = 2 || ROMANCE = 3 || ESTUDO = 4)"

#define MAX_CH_AUT_NAME 50
#define GET_AUT_NAME "Introduza o nome do autor: "

#define MAX_CH_AUT_WEB 100
#define GET_AUT_WEB "Introduza o website do autor: "

#define MAX_NUM_AUT 5

#define MAX_CH_BOOK_ISBN 13
#define GET_BOOK_ISBN "Introduza o ISBN do livro: "

#define MAX_CH_BOOK_TITLE 100
#define GET_BOOK_TITLE "Introduza o título do livro: "

#define ERROR_MAX_AUT_NUM "Atingiu o número máximo de autores!"
#define ERROR_ISBN_EXISTS "O ISBN inserido já pertence a outro livro"
#define ERROR_LIB_FULL "A biblioteca está cheia"
#define ERROR_LIB_EMPTY "A bibilioteca está vazia"

typedef struct{
    int day, month, year;
}Date;

typedef struct{
    char name[MAX_CH_PUBL_NAME];
    char address[MAX_CH_PUBL_ADD];
}Publisher;

typedef enum{
     FICÇAO = 1, TÉCNICO, ROMANCE, ESTUDO
}Genre;

typedef struct{
    char name[MAX_CH_AUT_NAME];
    char web[MAX_CH_AUT_WEB];
    Date birthDate;
}Author;

typedef struct{
    int countAuthors;
    Author authores[MAX_NUM_AUT];
}GAuthor;

typedef struct{
    char ISBN[13];
    char title[MAX_CH_BOOK_TITLE];
    Date publishData;
    Publisher publisher;
    Genre genre; 
    GAuthor gAuthor;
}Book;

typedef struct{
    int bookCount;
    Book books[MAX_NUM_BOOKS];
}Library;


void insertBook(Library * lib);
void listAllBooks(Library lib);
void listAllAuthors(Library lib);
void listAllPublishers(Library lib);