#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ENTER '\r'

char* cargarStrDin1(){
    char *arregloStrDin = (char*) (malloc(sizeof(char)));
    char caracter = 0;
    int contadorLetras = 0;
    printf("Escriba string: ");
    caracter = getche();

    while(caracter !=ENTER){
        *(arregloStrDin+contadorLetras) = caracter;
        contadorLetras++;

        arregloStrDin = (char*) (realloc(arregloStrDin, (contadorLetras+1)*sizeof(char)) );
        if(arregloStrDin == NULL){
            return NULL;
        }

        caracter = getche();
    }
        *(arregloStrDin+contadorLetras) = '\0';
    return arregloStrDin;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


void cargarStrDin2(char** punteroStr){   // Es la direccion de memoria del puntero
    *punteroStr = (char*) (malloc(sizeof(char)));
    int contadorLetras = 0;
    char caracter = 0;

    caracter = getche();
    while (caracter != ENTER){
        *(*punteroStr + contadorLetras) = caracter;
        contadorLetras++;

        *punteroStr = (char*) (realloc(*punteroStr, (contadorLetras+1)*sizeof(char)) );
        
        caracter = getche();
    }
    *(*punteroStr + contadorLetras) = '\0'; 
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////


void escribirArch(char *nombre_archivo, char *string){  // Escribe en el archivo el contenido del string cargado con memoria dinamica.
    
    FILE* archivo = fopen(nombre_archivo,"w");
    int indice = 0;
    char caracter;
    
    caracter = *string;

    while(caracter != '\0'){
        fputc(caracter,archivo);
        indice++;
        caracter = *(string+indice);
    }

    fclose(archivo);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimirArch(char *nombre_archivo){
    FILE* archivo = fopen(nombre_archivo, "r");
    int i;
    char caracter;
    caracter = fgetc(archivo);
    if(archivo == NULL){
        printf("Error al abrir el archivo");
    }

    else{
        for (i = 0 ; caracter != EOF ; i++){
            printf("%c",caracter);
            caracter = fgetc(archivo);
        }
    }

    fclose(archivo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    char *string = NULL; // Recordamos que strings (arreglos) son punteros... Lo inicializamos en NULL
   
    string = cargarStrDin1();  // String es una direcicon de memoria, como asi un puntero
    
    //cargarStrDin2(&string);

    escribirArch("frase.txt",string);

    printf("\n\n");

    imprimirArch("frase.txt");


    return 0;
}