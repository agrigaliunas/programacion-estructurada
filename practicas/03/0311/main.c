#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    int a,b;
}t_dosint;

void intercambiarVarPunt(int* puntero_a, int* puntero_b){
    int numero_aux;
    numero_aux = *puntero_a;
    *puntero_a = *puntero_b;
    *puntero_b = numero_aux;

}

int main(){
    t_dosint structPunteros;

    structPunteros.a = 5;
    structPunteros.b = 2;

    intercambiarVarPunt(&structPunteros.a,&structPunteros.b);
    printf("A = %d\n",structPunteros.a);
    printf("B = %d",structPunteros.b);

    return 0;
}