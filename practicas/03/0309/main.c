#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
char* subCadena(char *p , unsigned int i, int n){      // i es de donde empieza a la subcadena // n son la cantidad de elemenos siguientes a i
    char* subP = (char*) (malloc(sizeof(char)) );
    int longitudString = 0;
    int letrasATomar = 0;
    int contadorLetras = 0;
    char caracter;

    while(*(p+longitudString) != '\0'){  // Sacamos la longitud de la cadena
        longitudString++;
    }

    if( n < 0 ){
        letrasATomar = -n;
    }
    else{
        letrasATomar = n;
    }

    if(i < longitudString){
        caracter = *(p+i);  // El primer caracter se toma donde esta i en el arreglo.

        while(caracter != '\0' && contadorLetras < letrasATomar){
            *(subP+contadorLetras) = caracter;
            contadorLetras++;
            subP = (char*) (realloc(subP, (letrasATomar*sizeof(char))) );

            if(n < 0){
                caracter = *(p+i-contadorLetras);
                printf("%c",caracter);
            }
            else{
                caracter = *(p+i+contadorLetras);
            }
        }
    }
    *(subP+contadorLetras) = '\0';

    return subP;
}

char* leerArch(char* nomArch){
    int contadorLetras = 0;
    char* arreglo = malloc(sizeof(char));
    char caracter = 0;

    FILE* archivo = fopen(nomArch, "r");

    caracter = fgetc(archivo);

    while(caracter !=EOF){
        *(arreglo+contadorLetras) = caracter;
        contadorLetras++;
        arreglo = (char*) (realloc(arreglo, (contadorLetras+1)*sizeof(char)) );
        
        caracter = fgetc(archivo);
    }
    *(arreglo+contadorLetras) = '\0';
    fclose(archivo);

    return arreglo;
}

int main(){
    char* str = NULL;
    char* subStr = NULL;
    int i = 8, n = 5;
    str = leerArch("frase.txt");
    subStr = subCadena(str,i,n); // Esto seria una direccion de memoria

    printf("Para i = %d y n = %d, se encontro el substring: ",i,n);
    printf("%s",subStr);

    return 0;
}