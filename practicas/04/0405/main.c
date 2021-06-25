#include <stdio.h>
#include <stdlib.h>


int valorMaximo(int* arr){
    int valorMax = 0;
    int valorActual = *(arr);

    if( *(arr) != 0){
        valorMax = valorMaximo(arr+1);

        if(valorMax == 0){
            return valorActual;
        }
        if(valorActual > valorMax){
            return valorActual;
        }
        else{
            return valorMax;
        }
    }

    else{
        return 0;
    }

}

int* dirMemoriaValorMaximo(int* arr){
    int* dirMemMax = NULL;
    int* dirMemActual = arr;

    if (*(arr) != 0){
        dirMemMax = dirMemoriaValorMaximo(arr+1);
        if(dirMemMax == NULL){
            return dirMemActual;
        }
        if(*(dirMemActual) > *(dirMemMax)){
            return dirMemActual;
        }
        else{
            return dirMemMax;
        }
    }
    else{
        return NULL;
    }
}

int main(){
    int arreglo[] = {1,5,6,-2,11,0};
    printf("Valor maximo del arreglo es: %d\n",valorMaximo(arreglo));
    printf("Y su direccion de memoria es: %p",dirMemoriaValorMaximo(arreglo));
    return 0;
}