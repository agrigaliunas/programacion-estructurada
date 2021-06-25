/*
    Algoritmo basado en la funcion strcmp de la libreria <string.h>



  ATENCION:
        ESTA FUNCION ESTA OPTIMIZADA, YA QUE CONVIERTE CADA CARACTER A MINUSCULA ANTES DE COMPARAR ****--



   ***********
    PARAMETROS: str1 --> primer string a comparar ; str2 --> segundo string a comparar


    si valor de retorno < 0 , indica que str1 es menor que str2.

    si valor de retorno > 0 , indica que str2 es menor que str1.

    si valor de retorno = 0 indica que str1 es igual a str2.
   ***********
 
 
                                                                     */

// ****************FUNCION HECHA****************   
#include <stdio.h>
#include <stdlib.h>

int stringCompare(char arreglo1[], char arreglo2[]){  // Acordarse que esto compara letra por letra
    int i;
    int valor = 0;

    for(i=0; arreglo1[i] != '\0' && arreglo2[i] != '\0' && arreglo1[i] == arreglo2[i]; i++){}  // DEVUELVE EL VALOR DONDE LA LETRA EMPIEZA A SERDIFERENTE

    if(arreglo1[i]!=arreglo2[i]){

        if(arreglo1[i] < arreglo2[i]){
            valor = -1;
        }

        else{
            valor = 1;
        }

    
    }

    return valor;
}


int main(){
    char arreglo1[] = "ahustin";
    char arreglo2[] = "agustyn";
    printf("%d",stringCompare(arreglo1,arreglo2));
    return 0; 
}