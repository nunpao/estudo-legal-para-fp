#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fleetManager.h"
#include "handyLib.h"

int main(){
    /*
    */
    int opcao = -1;
    Fleet f;
    loadFleet(&f, "niggerFleet");

    do{
        printf("----------Gestor de Frotas-----------\n");
        printf("1-  Inserir Camião\n");
        printf("2-  Listar Camiões\n");
        printf("3-  Atualizar Kilometragem\n");
        printf("0-  Sair\n");
        printf("Capacidade da Forta: %d/%d\n ", f.truckCount, f.fleetCapacity);
        printf("Opção Selecionada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: insertTruck(&f);
            break;
        case 2: printAllTrucks(f);
            break;
        case 3: insertKms(&f);
            break;    
        case 0: break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while(opcao != 0);

    saveFleet(f, "niggerFleet");
    free(f.trucks);
    f.trucks = NULL;
    return 0;
}