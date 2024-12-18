#define MIN_VAL_DAY 1
#define MAX_VAL_DAY 31
#define GET_DAY_BIRTH "Introduza o dia de nascimento: "

#define MIN_VAL_MONTH 1
#define MAX_VAL_MONTH 12
#define GET_MONTH_BIRTH "Introduza o mês de nascimento: "

#define MIN_VAL_YEAR 1900
#define MAX_VAL_YEAR 2024
#define GET_YEAR_BIRTH "Introduza o ano de nascimento: "

#define MIN_STUDENT_NUM 0
#define MAX_STUDENT_NUM 1000
#define GET_STUDENT_NUM "Introduza um número de aluno: "

#define MAX_STUDENT_NAME 50
#define GET_STUDENT_NAME "Introduza o nome do aluno: "

#define ERROR_STUDENT_EXISTS "O número de aluno já está atribuido"
#define ERROR_STUDENT_DOESNT_EXISTS "O número de aluno já está atribuido"
#define ERROR_FULL_LIST "A lista de alunos está cheia"
#define ERROR_EMPTY_LIST "A lista de alunos está vazia"


typedef struct{
    int day, month, year;
}Date;

typedef struct{
    int num;
    char name[MAX_STUDENT_NAME];
    Date dateBirth;
}Student;

typedef struct{
    int studentsCounter;
    int classSize;
    Student * students;
}Class;

void insertStudent(Class * c);
void searchAndPrintStudentByNum(Class c);
void searchAndUpdateStudent(Class * c);
void deleteStudent(Class * c);
void listAllStudents(Class c);