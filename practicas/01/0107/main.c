#include <stdio.h>
#include <stdlib.h>
#define FILAS 2
#define COLUMNAS 2

int ingresarEnMat(int f, int c){                        
    int x;
    printf("[%d],[%d]: ",f,c);
    scanf("%d",&x);
    return x;
}

void cargarMat(int matriz[FILAS][COLUMNAS]){            // Carga una matriz.
    int f = 0, c = 0;
    for(f=0;f<FILAS;f++){
        for(c=0;c<COLUMNAS;c++){                        // Por cada fila, ingresa en cada columna.
            matriz[f][c]=ingresarEnMat(f,c);            
        }
    }
}

void imprimirMat(int matriz[FILAS][COLUMNAS]){          // Imprime la matriz.
    int f=0, c=0;
    for(f=0;f<FILAS;f++){
        for(c=0;c<COLUMNAS;c++){
            printf("[%2d]",matriz[f][c]);
        }
        printf("\n");
    }
}

float promMat(int matriz[FILAS][COLUMNAS]){             // Saca promedio de la matriz. La cantidad de elementos es FILAS*COLUMNAS.
    int f=0, c=0;
    float suma = 0;
    float prom;
    for(f = 0; f<FILAS; f++){
        for(c = 0;c<COLUMNAS;c++){
            suma+=matriz[f][c];
        }
    }
    prom = suma/(FILAS*COLUMNAS);
    return prom;
} 


int main(){
    int matriz[FILAS][COLUMNAS] = {0};              // Inicializo en 0 la matriz.

    printf("Ingrese numeros a cargar: \n");
    cargarMat(matriz);

    printf("\nMatriz: \n");
    imprimirMat(matriz);

    printf("\nPromedio de matriz: %.2f",promMat(matriz));

    return 0;
}