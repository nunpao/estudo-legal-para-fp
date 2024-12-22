#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "handyLib.h"
#include "studentsLib.h"

void printStudent(Student s)
{
    printf("Num -> %d\n", s.num);
    printf("Name -> %s\n", s.name);
    printf("Date of Birth -> %d/%d/%d\n", s.dateBirth.day, s.dateBirth.month, s.dateBirth.year);
}

void clearStudent(Student *s)
{
    s->num = 0;
    strcpy(s->name, "");
    s->dateBirth.day = s->dateBirth.month = s->dateBirth.year = 0;
}

void updateStudent(Student * s){
    getString(s->name, MAX_STUDENT_NAME, GET_STUDENT_NAME);
    s->dateBirth.day = getInt(MIN_VAL_DAY, MAX_VAL_DAY, GET_DAY_BIRTH);
    s->dateBirth.month = getInt(MIN_VAL_MONTH, MAX_VAL_MONTH, GET_MONTH_BIRTH);
    s->dateBirth.year = getInt(MIN_VAL_YEAR, MAX_VAL_YEAR, GET_YEAR_BIRTH);
}

int searchStudentByNum(Class c, int num)
{
    int i;
    for (i = 0; i < c.studentsCounter; i++)
    {
        if (c.students[i].num == num)
        {
            return i;
        }
    }
    return -1;
}

int createStudent(Class *c)
{
        c->students[c->studentsCounter].num = c->nextStudentNum;

        cleanInputBuffer();

        getString(c->students[c->studentsCounter].name, MAX_STUDENT_NAME, GET_STUDENT_NAME);

        c->students[c->studentsCounter].dateBirth.day = getInt(MIN_VAL_DAY, MAX_VAL_DAY, GET_DAY_BIRTH);
        c->students[c->studentsCounter].dateBirth.month = getInt(MIN_VAL_MONTH, MAX_VAL_MONTH, GET_MONTH_BIRTH);
        c->students[c->studentsCounter].dateBirth.year = getInt(MIN_VAL_YEAR, MAX_VAL_YEAR, GET_YEAR_BIRTH);

        c->nextStudentNum++;
        c->studentsCounter++;
}

int allocateMem(Class *c)
{
    if (c->studentsCounter == c->classSize)
    {
        Student *temp = (Student *)realloc(c->students, sizeof(Student) * (c->classSize + 5));
        if (temp == NULL)
        {
            fprintf(stderr, "Memory allocation failed \n");
            return -1;
        }
        c->students = temp;
        c->classSize += 10;
        return 1;
    }
}

void insertStudent(Class * c){
    if(allocateMem(c) == 1){
        createStudent(c);
    }
}

void searchAndPrintStudentByNum(Class c){
    if(c.studentsCounter > 0){
        int studentIndex = searchStudentByNum(c, getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM));

        if(studentIndex != -1){
            printStudent(c.students[studentIndex]);
        }else{
            puts(ERROR_STUDENT_DOESNT_EXISTS);
        }
    }else {
        puts(ERROR_EMPTY_LIST);
    }
}

void searchAndUpdateStudent(Class * c){
    if(c->studentsCounter > 0){
        int studentIndex = searchStudentByNum(*c, getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM));

        if(studentIndex != 1){
            updateStudent(&(c->students[studentIndex]));
        } else{
            puts(ERROR_STUDENT_DOESNT_EXISTS);
        }
    } else {
        puts(ERROR_EMPTY_LIST);
    }
}

void deleteStudent(Class * c){
    if(c->studentsCounter > 0){
        int i, studentIndex = searchStudentByNum(*c, getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM));

        if(studentIndex != 1){
            for(i = studentIndex; i < c->studentsCounter; i++){
                c->students[i] = c->students[i + 1];
            }

            clearStudent(&c->students[i]);

            c->studentsCounter--;
        } else {
            puts(ERROR_STUDENT_DOESNT_EXISTS);
        }
    }else {
        puts(ERROR_EMPTY_LIST);
    }
}

void listAllStudents(Class c){
    if(c.studentsCounter > 0){
        int i;

        for(i = 0; i < c.studentsCounter; i++){
            printStudent(c.students[i]);
        }
    } else{
        puts(ERROR_EMPTY_LIST);
    }
}

int guardarAlunosFicheiro(Class c, char *fileName) {
    FILE *fp;
    int nRegs;

    if ((fp = fopen(fileName, "wb")) == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return 0;
    }

    nRegs = fwrite(&c.studentsCounter, sizeof(int), 1, fp);
    if (nRegs < 1) {
        printf("Erro ao escrever studentsCounter\n");
        fclose(fp);
        return 0;
    }

    nRegs = fwrite(&c.classSize, sizeof(int), 1, fp);
    if (nRegs < 1) {
        printf("Erro ao escrever classSize\n");
        fclose(fp);
        return 0;
    }

    nRegs = fwrite(&c.nextStudentNum, sizeof(int), 1, fp);
    if (nRegs < 1) {
        printf("Erro ao escrever nextStudentNum\n");
        fclose(fp);
        return 0;
    }

    nRegs = fwrite(c.students, sizeof(Student), c.studentsCounter, fp);
    if (nRegs < c.studentsCounter) {
        printf("Erro ao escrever students\n");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

int carregarAlunosFicheiro(Class *c, char *fileName) {
    FILE *fp;
    int nRegs;

    if ((fp = fopen(fileName, "rb")) != NULL) {
        nRegs = fread(&c->studentsCounter, sizeof(int), 1, fp);
        if (nRegs < 1) {
            printf("Erro ao ler studentsCounter\n");
            fclose(fp);
            return 0;
        }

        nRegs = fread(&c->classSize, sizeof(int), 1, fp);
        if (nRegs < 1) {
            printf("Erro ao ler classSize\n");
            fclose(fp);
            return 0;
        }

        nRegs = fread(&c->nextStudentNum, sizeof(int), 1, fp);
        if (nRegs < 1) {
            printf("Erro ao ler nextStudentNum\n");
            fclose(fp);
            return 0;
        }

        c->students = (Student *)malloc(sizeof(Student) * c->classSize);
        if (c->students == NULL) {
            printf("Erro ao alocar memória\n");
            fclose(fp);
            return 0;
        }

        nRegs = fread(c->students, sizeof(Student), c->studentsCounter, fp);
        if (nRegs < c->studentsCounter) {
            printf("Erro ao ler students\n");
            free(c->students);
            fclose(fp);
            return 0;
        }

        fclose(fp);
        return 1;
    } else {
        // Se o arquivo não existir, inicialize a estrutura
        c->studentsCounter = 0;
        c->classSize = 0; // Defina um tamanho inicial para a turma
        c->nextStudentNum = 1;
        c->students = (Student *)malloc(sizeof(Student) * c->classSize);
        
        if (c->students == NULL) {
            printf("Erro ao alocar memória\n");
            return 0;
        }

        // Crie um novo arquivo vazio
        fp = fopen(fileName, "wb");
        if (fp == NULL) {
            printf("Erro ao criar o arquivo\n");
            free(c->students);
            return 0;
        }

        fwrite(&c->studentsCounter, sizeof(int), 1, fp);
        fwrite(&c->classSize, sizeof(int), 1, fp);
        fwrite(&c->nextStudentNum, sizeof(int), 1, fp);

        fclose(fp);
        return 1;
    }
}
    