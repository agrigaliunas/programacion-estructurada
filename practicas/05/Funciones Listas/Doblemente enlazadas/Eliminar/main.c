#include <stdio.h>
#include <stdlib.h>


typedef struct s_nodo{
    int valor;
    struct s_nodo* sig;
    struct s_nodo* ant;
} * t_nodo;


void eliminar(t_nodo*lista, int valor){
    t_nodo aux;
    
    for(aux = *lista; aux->valor != valor && aux->sig != NULL; aux = aux->sig);

    if (aux == *lista){
        *lista = (*lista)->sig;
        (*lista)->ant = NULL;
        free(aux);
    }
    
    else if (aux->valor == valor){

        if(aux->sig != NULL){
            aux->sig->ant = aux->ant;
        }
        
        aux->ant->sig = aux->sig;
        free(aux);

    }
}