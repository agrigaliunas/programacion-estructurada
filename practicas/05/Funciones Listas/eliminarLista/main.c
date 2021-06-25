#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;      

void eliminarLista(p_nodo* nodo){
    p_nodo aux = NULL;
    if(*nodo != NULL){
        aux = (*nodo);
        (*nodo) = (*nodo)->sigNodo;
        free(aux);
        eliminarLista(&(*nodo));
    }
}

int main(){
    p_nodo lista = NULL;
    eliminarLista(&lista);

    return 0;
}