#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};

typedef struct s_nodo* nodo;

void agregarNumOrdenado(nodo* dirNodoLista, int valor){
    nodo nodoAux = NULL;
    
    if(*dirNodoLista == NULL || valor < (*dirNodoLista)->valor){
        nodoAux = malloc(sizeof(struct s_nodo));
        nodoAux->valor = valor;
        nodoAux->sigNodo = *dirNodoLista;
        *dirNodoLista = nodoAux;
    }

    else{
        agregarNumOrdenado(&(*dirNodoLista)->sigNodo, valor);
    }
}

void imprimirLista(nodo lista){
    if(lista != NULL){
        printf("%d\n",lista->valor);
        imprimirLista(lista->sigNodo);
    }
}

int main(){
    nodo lista = NULL;  //Direccion de memoria de la estructura s_nodo
    
    agregarNumOrdenado(&lista,7);
    agregarNumOrdenado(&lista,3);
    agregarNumOrdenado(&lista,10);
    agregarNumOrdenado(&lista,5);
    printf("Lista ordenada: \n");
    imprimirLista(lista);
    return 0;
}