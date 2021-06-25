#include <stdio.h>
#include <stdlib.h>
#define FIL 10
#define COL 20
#define TERMINA_CADENA '\0'


void cargarMatTexDeArch(char matriz[FIL][COL],char nombre_archivo[]){
    FILE* archivo;
    char carac;
    int f = 0, c = 0;
    archivo = fopen(nombre_archivo, "r");

    if(archivo == NULL){
        printf("Error al cargar el archivo.");
    }
    
    carac = fgetc(archivo);

    for(f=0;f<FIL && carac!=EOF;f++){
        for(c=0;c<COL && carac!=EOF && carac!='\n' ;c++){
            matriz[f][c] = carac;
            carac = fgetc(archivo);
        }

        matriz[f][c] = TERMINA_CADENA;
        carac = fgetc(archivo);
    }

    matriz[f][c] = TERMINA_CADENA;

    fclose(archivo);
}

void imprimirMatriz(char matriz[FIL][COL]){
    int f = 0 , c = 0;

    for( f = 0 ; f < FIL && matriz[f][0]!=TERMINA_CADENA ; f++ ){
        for ( c = 0 ; c < COL && matriz[f][c]!=TERMINA_CADENA ; c++ ){
            printf("[%c]",matriz[f][c]);
        }
        printf("\n");
    }

}

int main(){
    char matriz[FIL][COL] = {0};
    char nombre_archivo[] = "equipos.txt";
    cargarMatTexDeArch(matriz,nombre_archivo);
    imprimirMatriz(matriz);
    return 0;
}