#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ENTER '\r'

// Carga por teclado string en un arreglo dinamico, usando malloc y realloc

char *cargarStdDin(){
    char *arregloCadDin = (char *) (malloc(sizeof(char)));
    char caracter = 0;
    int contadorLetras = 0;
    printf("Ingrese por teclado: ");
    caracter = getche();

    while (caracter != ENTER){
        
        *(arregloCadDin + contadorLetras) = caracter;
        
        contadorLetras++;
       
        
        
        arregloCadDin = realloc(arregloCadDin, (contadorLetras+1)*sizeof(char)); // contLetras+1 = espacios que quiero ; lo multiplico por el tamaño en bytes de entero
        if(arregloCadDin == NULL){
            return NULL;                // Compruebo que no hubo error al hacer realloc
        }

        caracter = getche();
    }

    *(arregloCadDin+contadorLetras) = '\0';

    return arregloCadDin;
}


int main(){

    printf("\n\n%s", cargarStdDin());
    return 0;
}