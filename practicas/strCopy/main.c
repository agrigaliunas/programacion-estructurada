/*
    Algoritmo basado en la funcion strcpy de la libreria <string.h>


   ***********
    PARAMETROS: dest -> array destino ; src = array fuente
   ***********
 
 
                                                                     */



/*  ****************FUNCION HECHA****************

#define TAMANO_MAX 100 // Este seria el tamaño del string que se quiere copiar
void stringCopy(char dest[], char src[]){
    int i,j;
    for(i=0,j=i+1;src[i]!='\0';i++,j++){
        dest[i]=src[i];
        dest[j]='\0';

    }
}

*/


// PRUEBA DE FUNCION

#include <stdio.h>
#include <stdlib.h>
#define TAMANO_MAX 100 // Este seria el tamaño del string que se quiere copiar

void stringCopy(char dest[TAMANO_MAX], char src[TAMANO_MAX]){
    int i,j;
    printf("Source: %s\n",src);
    printf("Dest: vacio\n");
    for(i=0,j=i+1;src[i]!='\0';i++,j++){
        dest[i]=src[i];
    }
    dest[i]='\0';
    printf("New dest: %s\n",dest);
}


int main() {
  char dest[TAMANO_MAX];
  char src[TAMANO_MAX] = "Hola mundo";
  stringCopy(dest,src);
  return 0;
}