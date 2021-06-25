/* Realizar una función que cuente la cantidad de bits que están en 1 en una variable de
                tipo unsigned int. */

#include <stdio.h>
#include <stdlib.h>
#define MASK 1

int cuentaBits(unsigned int numero){    
    int cont = 0;
    int i;
    for (i = 0 ; i<32 ; i++){
        if ((numero & MASK) == 1){
            cont++;
        }
        numero = numero >> 1;
    }
    return cont;
}

int main(){
    unsigned int numero = 127;
    printf("%d",cuentaBits(numero));
    return 0;
}