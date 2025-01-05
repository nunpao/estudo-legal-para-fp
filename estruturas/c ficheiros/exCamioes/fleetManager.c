#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handyLib.h"
#include "fleetManager.h"

void inicializeFleet(Fleet * f){
    f->truckCount = 0;

    Truck * temp = (Truck *) malloc(sizeof(Truck) * 2);

    if(temp == NULL){
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    f->trucks = temp;

    f->fleetCapacity = 2;
}

int searchTruck(Fleet f, char * licencePlate){
    int i;

    for(i = 0; i < f.truckCount; i++){
        if(strcmp(f.trucks[i].licencePlate, licencePlate) == 0){
            return i;
        }
    }

    return -1;
}

int allocMemTrucks(Fleet * f){
    if(f->fleetCapacity == f->truckCount){
        Truck * temp = (Truck *) realloc(f->trucks, (sizeof(Truck) * (f->fleetCapacity * 2)));

        if(temp == NULL){
            printf("Memory allocation error!\n");
            return -1; //erro na alocacao
        }

        f->trucks = temp;

        f->fleetCapacity *= 2;

        return 1; //realocacao feita corretamente
    }else {
        return 0; //nao é necessario efetuar alocacao
    }
}


int createTruck(Fleet * f){
    char licence[LICENCE_PLATE_SIZE];
    getString(licence, LICENCE_PLATE_SIZE, LICENCE_PLATE_INS_MSG);
    if(searchTruck(*f, licence) == -1){
        if(allocMemTrucks(f) != -1){
            strcpy(f->trucks[f->truckCount].licencePlate, licence);
            f->trucks[f->truckCount].countKms = 0;
            
            return f->truckCount++;
        }else{
            return -2; //problema de alocacao de memoria
        }
    }else{
        return -1; //ja existe um camiao com essa matricula
    }
}

void insertTruck(Fleet * f){
    int result = createTruck(f); 

    if (result == -1) {
        printf("Um camião com essa matricula já faz parte da frota!\n");
    } else if (result == -2) {
        printf("Erro de alocação de memória, tente novamente! \n");
    } else {
        printf("Camião Criado!\n");
    }
}

int totalKms(Truck t){
    int i, totalKms = 0;

    for(i = 0; i < t.countKms; i++){
        totalKms += t.kms[i];
    }

    return totalKms;
}

void printTruck(Truck t){
    printf("Matricula:      %s\n", t.licencePlate);
    printf("Kilometragem:   %d\n", totalKms(t));
}

void printAllTrucks(Fleet f){
    int i;

    for(i = 0; i < f.truckCount; i++){
        printTruck(f.trucks[i]);
    }
}

int inputKms(Fleet * f, char * licencePlate, int kms){
    int indexCamiao = searchTruck(*f, licencePlate);
    if(indexCamiao != -1){
        if(f->trucks[indexCamiao].countKms < KMS_CAP){
            f->trucks[indexCamiao].kms[f->trucks[indexCamiao].countKms] = kms;
            f->trucks[indexCamiao].countKms++;
            return 1;
        }else {
            return -2;
        }
    }else {
        return -1;
    }
}

void insertKms(Fleet * f){
    char licencePlate[LICENCE_PLATE_SIZE];
    int kms, res;

    getString(licencePlate, LICENCE_PLATE_SIZE, "Introduza a matricula do camião a que pretende adicionar a kilometragem: ");
    kms = getInt(0, 10000, "Introduza a kilometragem que pretende adicionar ao veiculo [0-10000]: ");

    res = inputKms(f, licencePlate, kms);

    if(res == -1){
        printf("A matricula que inseriu não pertence a nenhum veículo da frota\n");
    } else if(res == -2){
        printf("O limite de kilometragem foi atingido\n");
    } else {
        printf("A kilometragem do camião ""%s"" foi atualizada com sucesso!\n", licencePlate);
    }
}

void saveFleet(Fleet f, char * filename){
    FILE * fp;
    int nregs;

    if((fp = fopen(filename, "wb")) == NULL){
        printf("Ficheiro não encontrado");
    }

    nregs = fwrite(&f.truckCount, sizeof(int), 1, fp);

    if(nregs != 1){
        printf("ERRO na gravação de f.truckCount");
    }

    nregs = fwrite(&f.fleetCapacity, sizeof(int), 1, fp);

    if(nregs != 1){
        printf("ERRO na gravação de f.fleetCapacity");
    }

    nregs = fwrite(f.trucks, sizeof(Truck), f.truckCount, fp);

    if(nregs != f.truckCount){
        printf("ERRO na gravação de f.trucks");
    }

    fclose(fp);                                                                                                         
}

void loadFleet(Fleet * f, char * filename){
    FILE * fp;
    int nregs;

    if((fp = fopen(filename, "rb")) != NULL){
        printf("Ficheiro Aberto");

        nregs = fread(&f->truckCount, sizeof(int), 1, fp);

        if(nregs != 1){
            printf("ERRO a ler f.truckCount");
        }

        nregs = fread(&f->fleetCapacity, sizeof(int), 1, fp);

        if(nregs != 1){
            printf("ERRO a ler f.fleetCapacity");
        }

        Truck * temp = (Truck * ) malloc (sizeof(Truck) * f->fleetCapacity);
        
        if(temp == NULL){
            printf("ERRO alocação memoria inicial");
        }

        f->trucks = temp;

        nregs = fread(f->trucks, sizeof(Truck), f->truckCount, fp);

        if(nregs != f->truckCount){
            printf("ERRO a ler trucks");
        }

        fclose(fp);
    } else {
        inicializeFleet(f);

        if((fp = fopen(filename, "wb")) == NULL){
        printf("Ficheiro não encontrado");
        }

    nregs = fwrite(&f->truckCount, sizeof(int), 1, fp);

    if(nregs != 1){
        printf("ERRO na gravação de f.truckCount");
    }

    nregs = fwrite(&f->fleetCapacity, sizeof(int), 1, fp);

    if(nregs != 1){
        printf("ERRO na gravação de f.fleetCapacity");
    }

    nregs = fwrite(f->trucks, sizeof(Truck), f->truckCount, fp);

    if(nregs != f->truckCount){
        printf("ERRO na gravação de f.trucks");
    }

    fclose(fp);

    }
}