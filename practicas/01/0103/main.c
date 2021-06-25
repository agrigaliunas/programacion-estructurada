  
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_CHARACTERS 100
#define ENTER '\r'
#define FIN_CADENA '\0'

void intercambiarCaracteres(char oldChar , char newChar, char string[MAX_CHARACTERS]){

    int i;

    for(i=0 ; string[i]!=FIN_CADENA ; i++){
            if(string[i] == oldChar){
                string[i] = newChar;
            }
    }

}

void cargarArreglo(char arreglo[MAX_CHARACTERS]){
    int i = 0;
    char c;
    c = getche();

    
    while( c!= ENTER && i < MAX_CHARACTERS-1 ){ // \r es retorno de carro (enter)
        arreglo[i] = c;
        i++;
        c = getche();
    }

    arreglo[i] = FIN_CADENA;  // \0 es el terminador de cadena

}

int main(){

    char stringText[MAX_CHARACTERS];
    char oldChar;
    char newChar;

    printf("Ingrese texto: ");
    cargarArreglo(stringText);

    printf("\n");

    printf("Ingrese caracter a reemplazar: ");
    oldChar=getche();

    printf("\n");

    printf("Ingrese caracter de reemplazo: ");
    newChar=getche();

    printf("\n");

    intercambiarCaracteres(oldChar,newChar,stringText);

    printf("%s",stringText);

    return 0;
}
