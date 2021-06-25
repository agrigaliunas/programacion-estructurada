#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a,b,c;
}t_tres;


void ordenarEstructura(t_tres *estructuraTresNumeros){
    int numeroMemoria;
    if ((*estructuraTresNumeros).a > (*estructuraTresNumeros).b){
        numeroMemoria = (*estructuraTresNumeros).a;
        (*estructuraTresNumeros).a = (*estructuraTresNumeros).b;
        (*estructuraTresNumeros).b = numeroMemoria;
    }
    if ((*estructuraTresNumeros).a > (*estructuraTresNumeros).c){
        numeroMemoria = (*estructuraTresNumeros).a;
        (*estructuraTresNumeros).a = (*estructuraTresNumeros).c;
        (*estructuraTresNumeros).c = numeroMemoria;
    }
    if ((*estructuraTresNumeros).b > (*estructuraTresNumeros).c){
        numeroMemoria = (*estructuraTresNumeros).b;
        (*estructuraTresNumeros).b = (*estructuraTresNumeros).c;
        (*estructuraTresNumeros).c = numeroMemoria;
    }

}

int main(){
    t_tres estructuraTresNumeros;
    estructuraTresNumeros.a = 456456;
    estructuraTresNumeros.b = 323215;
    estructuraTresNumeros.c = 878545;

    printf("Sin orden: \n");
    printf("%d\n",estructuraTresNumeros.a);
    printf("%d\n",estructuraTresNumeros.b);
    printf("%d\n",estructuraTresNumeros.c);

    ordenarEstructura(&estructuraTresNumeros);
    printf("\n");

    printf("Ordenados: \n");
    printf("%d\n",estructuraTresNumeros.a);
    printf("%d\n",estructuraTresNumeros.b);
    printf("%d\n",estructuraTresNumeros.c);
    return 0;
}