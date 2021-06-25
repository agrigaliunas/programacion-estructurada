#include <stdio.h>
#include <stdlib.h>


void intABin(int numero){   // 5 = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1  (4 bytes = 32 bits)

    unsigned int mask=1<<31;        //coloca el uno en el bit más significativo (a la izquierda)

    int i;

    for (i=0;i<32;i++){
        printf("%d",(numero&(mask>>i)) != 0);
    }
}

int main(){
    int numero = 5;

    intABin(numero);

    return 0;
}