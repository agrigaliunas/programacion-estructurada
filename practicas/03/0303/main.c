#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void redondeaEntero(double *punteroDelNumero){
    double numero = *punteroDelNumero;
    int numeroSinDecimales = numero;

    if(numero - numeroSinDecimales >= 0.5){
        *punteroDelNumero = numeroSinDecimales + 1;
    }
    else{
        *punteroDelNumero = numeroSinDecimales;
    }
}

int main(){
    double numero = 3.5415;
    printf("Numero: %lf\n",numero);
    printf("Direccion numero: %p\n",&numero);
    redondeaEntero(&numero);
    printf("Numero redondeado: %lf",numero);

    return 0;
}