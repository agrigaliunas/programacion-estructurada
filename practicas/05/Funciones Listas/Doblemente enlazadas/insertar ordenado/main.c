#include <stdio.h>
#include <stdlib.h>

void insertar(t_nodo* lista, int valor){
    t_nodo aux;
    t_nodo nuevo = nuevo_nodo(valor);

    if (*lista == NULL || valor < (*lista)->valor){
        nuevo->sig = *lista;
        if(*lista != NULL)
        (*lista)->ant = nuevo;
        *lista = nuevo;
    }
    else{
        for (aux = *lista; valor > aux->valor && aux->sig != NULL; aux = aux->sig);
        if (valor < aux->valor){
            nuevo->sig = aux;
            nuevo->ant = aux->ant;
            aux->ant->sig = nuevo;
            aux->ant = nuevo;
        }
        else{
            nuevo->ant = aux;
            aux->sig = nuevo;
        }
    }
}