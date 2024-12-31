#include <stdio.h>

int somaMatrizSuperior(int m[3][3]){
    int x, y, sum = 0;

    for(x = 0; x < 3; x++){
        for(y = 0 ; y <= x; y++){
            sum += m[x][y];
        }
    }

    return sum;
    
}

int somaLinhasImpares1(int m[5][5]){
    int x, y, sum = 0;

    for(x = 1; x < 5; x=x+2){
        for(y = 0; y < 5; y++){
            sum += m[x][y];
        }
    }

    return sum;
}

int somaLinhasImpares2(int m[5][5]){
    int x, y, sum= 0;

    for(x = 0; x < 5; x++){
        for(y = 0; y < 5; y++){
            if(x % 2 != 0){
                sum += m[x][y];
            }
        }
    }

    return sum;
}
int main(){
    int m[5][5] = {{1, 24, 31, 21, 43}, {12,6,74,12,54}, {41,12,54,1,12}, {41,12,54,1,12}, {41,12,54,1,12}};

    printf("%d\n", somaLinhasImpares1(m));
    printf("%d", somaLinhasImpares2(m));
    return 0;
}