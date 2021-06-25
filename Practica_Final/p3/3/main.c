#include <stdio.h>
#include <stdlib.h> 

void redondeo(double* p_num){
    double numero = *p_num;
    int numero_sin_decimales = numero;
    double resta = numero - numero_sin_decimales;

    if(resta >= 0.50){
        *p_num = numero_sin_decimales + 1;
    } else{
        *p_num = numero_sin_decimales;
    }
}

int main(){
    double num = 2.3;

    redondeo(&num); // Le paso su puntero para poder modificar la variable
    printf("%.2lf\n",num);

    return 0;
}