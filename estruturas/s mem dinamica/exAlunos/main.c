#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"
#include "studentsLib.h"


int main(){
    int opcao = -1;
    Class cA = {.studentCounter = 0};

    do{
        printf("1-  Criar Novo Aluno\n");
        printf("2-  Procurar Aluno\n");
        printf("3-  Atualizar Dados de Aluno\n");
        printf("4-  Apagar Aluno\n");
        printf("5-  Listar Todos Alunos\n");
        printf("0-  Sair\n");
        printf("%d/%d alunos\n", cA.studentCounter, MAX_NUM_STUDENTS);
        scanf("%d", &opcao);

        switch(opcao){
            case 0: 
                break;
            case 1: insertStudent(&cA);
                break;
            case 2: searchStudentByNum(cA);
                break;
            case 3: searchAndUpdateStudent(&cA);
                break;
            case 4: deleteStudent(&cA);
                break;
            case 5: listAllStudents(cA);
                break;
            default:
                printf("Opção Inválida\n");
                break;
        }
    }while(opcao != 0);
    return 0;
}