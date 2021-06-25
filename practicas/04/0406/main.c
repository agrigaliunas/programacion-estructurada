#include <stdio.h>
#include <stdlib.h>

int* dirMemoriaValorMin(int* arr){
    int* dirMemMin = NULL;
    int* dirMemActual = arr;

    if (*(arr) != 0){
        dirMemMin = dirMemoriaValorMin(arr+1);
        if(dirMemMin == NULL){
            return dirMemActual;
        }
        if( *(dirMemActual) < *(dirMemMin) ){
            return dirMemActual;
        }
        else{
            return dirMemMin;
        }
    }
    else{
        return NULL;
    }
}

int* ordenarArr(int* arr){
    int numPuntero = *(arr);            
    int* punteroNumMasChico = dirMemoriaValorMin(arr);                  // Saca el menor del arreglo y lo compara con el elemento actual
    int aux;

    if(numPuntero != 0){
        aux = *punteroNumMasChico;
        *punteroNumMasChico = numPuntero;
        *(arr) = aux;

        ordenarArr(arr+1);
    }
}

int main(){
    int arr[5] = {1,8,4,2,0};
    int i;
    printf("Arreglo: ");
    for(i=0 ; i<5 && arr[i] !=0 ; i++){
        printf("[%d] ",arr[i]);
    }
    ordenarArr(arr);
    printf("\nArreglo ordenado: ");
    for(i=0 ; i<5 && arr[i] !=0 ; i++){
        printf("[%d] ",arr[i]);
    }

    return 0;
}