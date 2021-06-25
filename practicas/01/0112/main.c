#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FILAS 20
#define COLUMNAS 20
#define DATOS 8

void cargarMatNumDeArch(int matriz[FILAS][COLUMNAS], char nombre_archivo[]){
    int f = 0, c = 0,n0,n1,n2,n3,n4,n5,n6,n7;
    int r;
    
    FILE* archivo;
    archivo = fopen(nombre_archivo,"r");

    if(archivo==NULL)
        printf("Error al cargar el archivo.");


    for( f=0 ; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d\n",&n0,&n1,&n2,&n3,&n4,&n5,&n6,&n7) != EOF && f < FILAS && f < DATOS; f++){
        matriz[f][0] = n0;
        matriz[f][1] = n1;
        matriz[f][2] = n2;
        matriz[f][3] = n3;
        matriz[f][4] = n4;
        matriz[f][5] = n5;
        matriz[f][6] = n6;
        matriz[f][7] = n7;
    }
    matriz[f][0]=EOF;
    fclose(archivo);

}


void imprimirMatNum(int matriz[FILAS][COLUMNAS] , int fil, int col){
    int f = 0 , c = 0;

    for(f = 0 ; f < FILAS && f < fil && matriz[f][0] != EOF ; f++){
        for(c = 0 ; c < COLUMNAS && c < col ; c++){

            if(matriz[f][c] > 0 && c == 7){
                printf("\t+%d",matriz[f][c]);
            }
            else{
                printf("\t%d",matriz[f][c]);
            }
        }
        printf("\n");
    }


}


int main(){
    int matriz[FILAS][COLUMNAS] = {0};
    char nombre_archivo[] = "puntos.txt";
    cargarMatNumDeArch(matriz,nombre_archivo);
    imprimirMatNum(matriz,5,8);                     // --> donde 5 = filas , 8 = columnas.
    return 0;
}