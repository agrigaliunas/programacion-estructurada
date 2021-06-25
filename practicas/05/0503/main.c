#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};

typedef struct s_nodo* p_nodo;


void agregarALista(p_nodo* nodo, int valor){
    if(*nodo == NULL){                                      
        *nodo = (p_nodo) malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sigNodo = NULL;
    }
    else{
        agregarALista(&(*nodo)->sigNodo, valor);
    }
}


void eliminarValor(p_nodo* nodo, int valor){
    p_nodo aux = NULL;
    int primero = 0;
    if(*nodo == NULL){
        printf("Error al borrar valor de una lista vacia");
    }
    else if((*nodo)->valor == valor && primero == 0){
        primero = 1;
        aux = (*nodo);
        (*nodo) = (*nodo)->sigNodo;
        free(aux);
    }
    else{
        eliminarValor(&(*nodo)->sigNodo, valor);
    }
}

void imprimirLista(p_nodo nodo){

    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sigNodo);
    }
}


int main(){
    p_nodo lista = NULL;
    agregarALista(&lista,7);
    agregarALista(&lista,5);
    agregarALista(&lista,2);
    agregarALista(&lista,5);
    agregarALista(&lista,10);
    printf("Lista normal:\n");
    imprimirLista(lista);
    
    eliminarValor(&lista,5);
    printf("Lista alterada:\n");
    imprimirLista(lista);

    return 0;
}