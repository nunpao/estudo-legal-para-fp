#define SALAS_TAM_INICIAL 5
#define SALA_NOME_MAX 51

typedef struct{
    int capacidade; //capacidade máxima de alunos na sala
    int ocupacao; //numero de alunos com presenca marcada na sala
    char nome[SALA_NOME_MAX]; //nome da sala (deve ser unico)
    int * presencas; //Armazena os numeros dos alunos presentes na sala. Apontador para as presenças
} Sala;

typedef struct {
    int contador; //quantidade de salas existentes(inicializado com 0)
    int tamanho; //quantidade de salas alocadas(inicializado com SALAS_TAM_INICIAL)
    Sala * salas;
}Salas;

