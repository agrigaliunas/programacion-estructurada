#include <stdio.h>
#include <stdlib.h>

void invertir(int* arreglo,unsigned int longitud){
    int aux = 0;

    if(longitud > 1){
        aux = *(arreglo);
        *(arreglo) = *(arreglo+longitud-1);
        *(arreglo+longitud-1) = aux;
        invertir(arreglo+1,longitud-2);
    }
}

int main(){
    int arreglo[5] = {6,2,7,1,8};
    printf("Arreglo normal: \n");
    printf("%d\n",arreglo[0]);
    printf("%d\n",arreglo[1]);
    printf("%d\n",arreglo[2]);
    printf("%d\n",arreglo[3]);
    printf("%d\n",arreglo[4]);

    invertir(arreglo,5);
    printf("Arreglo invertido: \n");
    printf("%d\n",arreglo[0]);
    printf("%d\n",arreglo[1]);
    printf("%d\n",arreglo[2]);
    printf("%d\n",arreglo[3]);
    printf("%d\n",arreglo[4]);
    return 0;
}