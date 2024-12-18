#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"
#include "studentsLib.h"

int main(){
    int opcao = -1;
    Class cA = {.classSize = 0, .studentsCounter = 0, .students = NULL};

    do{
        printf("1-  Adicionar Aluno\n");
        printf("2-  Pesquisar Aluno\n");
        printf("3-  Atualizar Aluno\n");
        printf("4-  Apagar Aluno\n");
        printf("5-  Lista de Alunos\n");
        printf("0-  Sair\n");
        printf("%d/%d Alunos\n", cA.studentsCounter, cA.classSize);
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 0: 
                break;
            case 1: insertStudent(&cA);
                break;
            case 2: searchAndPrintStudentByNum(cA);
                break;
            case 3: searchAndUpdateStudent(&cA);
                break;
            case 4: deleteStudent(&cA);
                break;
            case 5: listAllStudents(cA);
                break;
            default: printf("Opção inválida! \n");
                break;
        }

    }while(opcao != 0);

    free(cA.students);
    cA.students = NULL;
    return 0;
}