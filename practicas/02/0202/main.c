#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAMANO_ARREGLO 10


struct s_punto{
    double x;
    double y;
};

typedef struct s_punto Punto;                       // ---> s_punto tiene como alias a Punto

void cargarEnStructArch(Punto arregloDePuntos[TAMANO_ARREGLO]){
    int i = 0;
    FILE* archivo;
    archivo = fopen("puntos.txt","r");
    if (archivo == NULL){
        printf("No se pudo abrir el archivo...");
    }
    else{
        for( i = 0 ; fscanf(archivo,"%lf, %lf,",&arregloDePuntos[i].x,&arregloDePuntos[i].y) != EOF && i < TAMANO_ARREGLO; i++){
            printf("%.2lf, %.2lf\n",arregloDePuntos[i].x,arregloDePuntos[i].y);
        }

    }

    fclose(archivo);
}

int main(){
    Punto p1, p2;
    Punto arreglo_puntos[TAMANO_ARREGLO];  // --> creo un arreglo de puntos para la strcuct s_punto (alias: Punto)
    cargarEnStructArch(arreglo_puntos);

    return 0;
}