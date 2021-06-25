#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct s_punto{
    float x;
    float y;

};

int compararDistancia(struct s_punto punto1, struct s_punto punto2){
    float norma_punto1 = sqrt( pow(punto1.x,2) + pow(punto1.y,2) );    //--> La norma es la distancia entre el origen 0,0 y el punto.
    float norma_punto2 = sqrt( pow(punto2.x,2) + pow(punto2.y,2) );
    int punto_mas_lejano;

    if (norma_punto1 > norma_punto2){
        punto_mas_lejano = 1;
    }

    else if (norma_punto2 > norma_punto1){
        punto_mas_lejano = 2;
    }

    return punto_mas_lejano;
}

int main(){
    struct s_punto punto1,punto2;

    printf("El origen es : (0,0)\n");

    printf("Ingrese la informacion x del punto 1: ");
    scanf("%f",&punto1.x);
    printf("Ingrese la informacion y del punto 1: ");
    scanf("%f",&punto1.y);

    printf("Ingrese la informacion x del punto 2: ");
    scanf("%f",&punto2.x);
    printf("Ingrese la informacion y del punto 2: ");
    scanf("%f",&punto2.y);

    printf("Punto 1: (x=%.2f , y=%.2f)\n",punto1.x,punto1.y);

    printf("Punto 2: (x=%.2f , y=%.2f)\n",punto2.x,punto2.y);

    if (punto1.x == punto2.x && punto1.y == punto2.y){
        printf("Ambos puntos son iguales");
    }
    else{
        printf("El punto mas lejano es el punto %d ",compararDistancia(punto1,punto2));
    }

    return 0;
}