#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

int longitudLista(p_nodo nodo){        // Contaria la cantidad de nodos
    int cantNodos = 0;
    if(nodo == NULL){
        cantNodos = 0;
    }
    if(nodo != NULL){
        for(cantNodos = 0 ; nodo != NULL ; cantNodos++){
            nodo = nodo->sigNodo;
        }
    }
    return cantNodos;
}


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


void imprimirLista(p_nodo nodo){
    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sigNodo);
    }
}

int main(){
    p_nodo lista = NULL;
    agregarALista(&lista,1);
    agregarALista(&lista,1);
    agregarALista(&lista,1);
    agregarALista(&lista,1);
    agregarALista(&lista,1);
    agregarALista(&lista,1);
    printf("Lista:\n");
    imprimirLista(lista);
    printf("Longitud: %d",longitudLista(lista));
    return 0;
}