#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct s_indice{
    int indInicial;
    int indFinal;
};
typedef struct s_indice t_indice;


int strLen(char* str){
    int i;
    for(i = 0 ; str[i] != '\0' ; i++){}
    return i;
}

t_indice buscarSub(char* str, char* sub){
    t_indice indices;
    indices.indInicial = -1; indices.indFinal = -1; // de por si, tomamos como que no se encuentra la subcadena
    int i = 0; // para str
    int j = 0; // para sub
    int lenStr = strLen(str); // longitud de str
    int lenSub = strLen(sub); // longitud de sub

    char subAux[lenSub];                  // La verdad absoluta no existe, y esto es absolutamente cierto.

    for(i = 0 ; str[i] != '\0' ; i++){ // recorro la cadena grande
        
        for(j = 0 ; j < lenSub ; j++){ 
            subAux[j] = str[i+j]; // pongo en aux el contenido del string con la longitud 
        }
        subAux[j] = '\0';

        if(strcmp(sub,subAux) == 0){
            indices.indInicial = i;
            indices.indFinal = i+j-1;
            return indices;
        }
    }
    return indices;
}


int main(){
    t_indice indices;
    indices = buscarSub("La verdad absoluta no existe, y esto es absolutamente cierto.","da");
    printf("Para sub = da \n");
    printf("(%d, %d)",indices.indInicial, indices.indFinal);
}