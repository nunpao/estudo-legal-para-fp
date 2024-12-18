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
    int num = getInt(MIN_STUDENT_NUM, MAX_STUDENT_NUM, GET_STUDENT_NUM);
    int indexStudent = searchStudentByNum(*c, num);

    if (indexStudent == -1)
    {
        c->students[c->studentsCounter].num = num;

        getString(c->students[c->studentsCounter].name, MAX_STUDENT_NAME, GET_STUDENT_NAME);

        c->students[c->studentsCounter].dateBirth.day = getInt(MIN_VAL_DAY, MAX_VAL_DAY, GET_DAY_BIRTH);
        c->students[c->studentsCounter].dateBirth.month = getInt(MIN_VAL_MONTH, MAX_VAL_MONTH, GET_MONTH_BIRTH);
        c->students[c->studentsCounter].dateBirth.year = getInt(MIN_VAL_YEAR, MAX_VAL_YEAR, GET_YEAR_BIRTH);

        return c->studentsCounter++;
    }

    return -1;
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
        if(createStudent(c) == -1){
            puts(ERROR_STUDENT_EXISTS);
        }
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