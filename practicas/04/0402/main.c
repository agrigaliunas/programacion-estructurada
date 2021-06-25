#include <stdio.h>
#include <stdlib.h>

int dividirEntreEnteros(int dividendo, int divisor){   //   dividendo | divisor
                                                       //             |_______ 
    int resta = dividendo - divisor;

    if ( dividendo == 0 || divisor == 0){
        return 0;
    }

    if (dividendo > 0 && divisor > 0 && resta>=0){          // Solo si son positivos
        return 1+dividirEntreEnteros(resta, divisor);
    }


    else if(dividendo < 0 && divisor < 0 ){                 // Si son negativos los 2, los paso a positivos
        return dividirEntreEnteros(-dividendo,-divisor);
    }


    else if(dividendo < 0 && divisor > 0){                   
        return -dividirEntreEnteros(dividendo,-divisor);
    }                                                                   // Si uno de ellos es negativo, la division sera negativa.
    else if(dividendo > 0 && divisor < 0){
        return -dividirEntreEnteros(-dividendo,divisor);
    }



    else{
        return 0;
    }


}

int main(){
    printf("%d",dividirEntreEnteros(9,-3));
    return 0;
}