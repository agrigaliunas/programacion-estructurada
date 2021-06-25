#include <stdio.h>
#include <stdlib.h>

int* dirMemVar(int arr[6]){
    return &(arr[2]);
}

int* dirMemVar2(int arr[6]){
    return arr+2;
}

// En este caso es lo mismo hacer arr+2 que &(arr[2])

int main(){

    int arr[6] = {1,2,4,6,5,8};

    printf("%p",dirMemVar(arr)); // Retorna accediendo a la posicion y luego su puntero
    printf("\n");
    printf("%p",dirMemVar2(arr));
    return 0;
}