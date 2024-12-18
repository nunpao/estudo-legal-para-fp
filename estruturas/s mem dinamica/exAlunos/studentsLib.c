#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "handyLib.h"
#include "studentsLib.h"

//recebe um aluno e imprime os seus dados 
void printStudent(Student s){
    printf("Num -> %d\n", s.num);
    printf("Name -> %s\n", s.name);
    printf("Date Birth -> %d/%d/%d\n", s.dateBirth.day, s.dateBirth.month, s.dateBirth.year);
}

//recebe um aluno e elimina todos os seus dados, será utilizada para apagar um aluno
void cleanStudent(Student * s){
    s->num = 0;
    strcpy(s->name, " ");
    s->dateBirth.day = s->dateBirth.month = s->dateBirth.year == 0;
}

//recebe um aluno e atualiza os seus parametros
void updateStudent(Student * s){
    getString(s->name, MAX_STUDENT_NAME, GET_STUDENT_NAME);
    s->dateBirth.day = getInt(MIN_VAL_DAY, MAX_VAL_DAY, GET_DAY_BIRTH);
    s->dateBirth.month = getInt(MIN_VAL_MONTH, MAX_VAL_MONTH, GET_MONTH_BIRTH);
    s->dateBirth.year = getInt(MIN_VAL_YEAR, MAX_VAL_YEAR, GET_YEAR_BIRTH);
}

//recebe uma turma (conjunto de alunos), juntamente com um numero do aluno que se pretende encontrar.
//precorre a lista de alunos, se encontrar o aluno devolve o indice, caso contrario devolve -1

int searchStudent(Class c, int num){
    int i;

    for(i = 0; i < c.studentCounter; i++){
        if(c.students[i].num == num){
            return i;
        }
    }

    return -1;
}

//recebe uma turma, ira efetuar a criação de um novo aluno

int createStudent(Class * c){
    int num = getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM);

    //verifica se já existe um aluno com esse numero
    if(searchStudent(*c, num) == -1){

        //caso não exista efetua a criação de um novo aluno

        c->students[c->studentCounter].num = num;
        
        getString(c->students[c->studentCounter].name, MAX_STUDENT_NAME, GET_STUDENT_NAME);

        c->students[c->studentCounter].dateBirth.day = getInt(MIN_VAL_DAY, MAX_VAL_DAY, GET_DAY_BIRTH);
        c->students[c->studentCounter].dateBirth.month = getInt(MIN_VAL_MONTH, MAX_VAL_MONTH, GET_MONTH_BIRTH);
        c->students[c->studentCounter].dateBirth.year = getInt(MIN_VAL_YEAR, MAX_VAL_YEAR, GET_YEAR_BIRTH);

        return c->studentCounter++;
    }

    //caso ja exista, devolve -1
    return -1;
}

// efetua uma serie de verificações e utiliza a função anteriror para adicionar
void insertStudent(Class * c){
    if(c->studentCounter < MAX_NUM_STUDENTS){
        if(createStudent(c) == -1){
            puts(ERROR_STUDENT_EXISTS);
        }
    }else {
        puts(ERROR_FULL_LIST);
    }
}

//verifica se o aluno de que se está à procura existe e, caso exista, imprime os seus atributos
void searchStudentByNum(Class c){
    if(c.studentCounter > 0){
        int studentIndex = searchStudent(c, getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM));

        if(studentIndex != -1){
            printStudent(c.students[studentIndex]);
        } else {
            puts(ERROR_STUDENT_DOESNT_EXISTS);
        }
    }else{
        puts(ERROR_EMPTY_LIST);
    }
}

void searchAndUpdateStudent(Class * c){
    if(c->studentCounter > 0){
        int studentIndex = searchStudent(*c, getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM));

        if(studentIndex != -1){
            updateStudent(&(c->students[studentIndex]));
        } else {
            puts(ERROR_STUDENT_DOESNT_EXISTS);
        }
    }else {
        puts(ERROR_EMPTY_LIST);
    }
}

// esta é tricky de entender, nem vou dar ao trabalho de escrever 
void deleteStudent(Class * c){
     if(c->studentCounter > 0){
        int i, studentIndex = searchStudent(*c, getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM));

        if(studentIndex != 1){
            for(i = studentIndex; i < c->studentCounter - 1; i++){
                c->students[i] = c->students[i+1];
            }

            cleanStudent(&c->students[i]);

            c->studentCounter--;
        } else {
            puts(ERROR_STUDENT_DOESNT_EXISTS);
        }
    } else {
        puts(ERROR_EMPTY_LIST);
    }
}

void listAllStudents(Class c){
    if(c.studentCounter > 0){
        int i; 

        for(i = 0; i < c.studentCounter; i++){
            printStudent(c.students[i]);
        }
    } else {
        puts(ERROR_EMPTY_LIST);
    }
}


