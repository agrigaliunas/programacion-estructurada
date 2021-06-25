#include <stdio.h>
#include <stdlib.h>
#define FILAS 3
#define COLUMNAS 3

void cargarMatriz(int matriz[FILAS][COLUMNAS]){
    int f = 0, c= 0;
    for(f = 0 ; f<FILAS ; f++){
        for(c = 0 ; c<COLUMNAS ; c++){
            printf("[%d], [%d]: ",f,c);
            scanf("%d",&matriz[f][c]);
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]){
    int f=0,c=0;
    for(f = 0 ; f<FILAS ; f++){
        for(c = 0 ; c<COLUMNAS ; c++){
            printf("[%d]",matriz[f][c]);
        }
        printf("\n");
    }
}

void trasponer(int matriz[FILAS][COLUMNAS]){
    int f=0,c=0;
    for(f=0;f<FILAS;f++){
        for(c=0;c<COLUMNAS;c++){
            printf("[%d]",matriz[c][f]);
        }
        printf("\n");
    }


}

int main(){
    int matriz[FILAS][COLUMNAS] = {0};
    printf("Carga una matriz:\n");
    cargarMatriz(matriz);
    printf("Matriz cargada correctamente\n");
    imprimirMatriz(matriz);
    printf("Matriz traspuesta: \n");
    trasponer(matriz);
    return 0;
}
