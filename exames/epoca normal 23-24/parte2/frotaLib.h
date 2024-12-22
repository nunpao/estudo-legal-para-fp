#define FROTA_CAPACIDADE_INICIAL 2 // quantidade incial de camiões na frota

#define KMS_CAPACIDADE 6 //quantidade de registo de km a alocar por camiao

#define MATRICULA_TAMANHO 10 

typedef struct{
    int contador;
    char matricula[MATRICULA_TAMANHO];
    int kms[KMS_CAPACIDADE]; 
} Camiao;

typedef struct {
    int contadorCamioes;
    int tamanhoFrota;
    Camiao * camioes;
} Frota;

void inicializarFrota(Frota * f);
int insereCamiao(Frota * f);
int existe(Frota f, char * matricula);
int inserekms(Frota * f, char * matricula, int kms);
