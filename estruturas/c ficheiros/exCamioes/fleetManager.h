#define FLEET_INICIAL_CAP 2 //capacidade inicial da frota
#define KMS_CAP 6 //quantidade de registos de KMS a alocar por camiao

#define LICENCE_PLATE_SIZE 10 // limite de caracteres para matricula
#define LICENCE_PLATE_INS_MSG "Introduza a matricula do camião a adicionar: "

typedef struct {
    int countKms;
    int kms[KMS_CAP];
    char licencePlate[LICENCE_PLATE_SIZE];
}Truck;

typedef struct {
    int truckCount;
    int fleetCapacity;
    Truck * trucks;
}Fleet;

void inicializeFleet(Fleet * f);
void insertTruck(Fleet * f);
void printAllTrucks(Fleet f);
void insertKms(Fleet * f);
void saveFleet(Fleet f, char * filename);
void loadFleet(Fleet * f, char * filename);