#include <stdio.h>
#include <stdlib.h>

int *entregarDirMemArr(int arregloInt[5],int posicion){ // Recordar que los arreglos son punteros de por si.
    return arregloInt + posicion;
}

int main(){
    int arregloInt[5];    
    int *direccionMemoriaPos = entregarDirMemArr(arregloInt,2);

    printf("Direccion del arreglo: %p\n",&arregloInt);
    printf("Direccion de la posicion buscada: %p",direccionMemoriaPos);
    
    return 0;
}