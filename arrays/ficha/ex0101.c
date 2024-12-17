#include <stdio.h>

#define MSG "insira o valor do produto: "
#define DIM 10

void cleanInputBuffer(){
    char ch;
    while((ch = getchar()) != '\n');
}

float getFloat(float minValue, float maxValue, char * msg){
    float value;
    char ch;
    printf(msg);

    while(scanf("%f", &value) != 1 || value < minValue || value > maxValue){
        printf("Error try again\n");
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return value;
}

void fillProductsArray(float a[], int dim){
    int i;
    for(i = 0; i < dim; i++){
        a[i] = getFloat(0, 100000.0, MSG);
    }
}

int sumArrayMembers(float a[], int dim){
    int i;
    int total;
    for(i = 0; i < dim; i++){
       total += a[i];
    }

    return total;
}

void showArray(float a[], int dim){
    int i;
    for(i = 0; i < dim; i++){
       printf("%.2f ", a[i]);
    }

    printf("\nA soma dos valores dos produtos é de: %d", sumArrayMembers(a, dim));
}



int main(){
    float products[DIM];
    
    fillProductsArray(products, DIM);

    showArray(products, DIM);


    return 0;
}