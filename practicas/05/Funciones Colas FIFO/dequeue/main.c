/* Las eliminaciones se producen al principio */

#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

/* Armamos una estructura auxiliar, para poder manipular los extremos de la cola */
struct s_cola{
    p_nodo frente;  // Puntero al frente de la cola
    p_nodo final;   // Puntero al final de la cola
};
typedef struct s_cola p_cola;




int dequeue(p_cola* cola){
    int valor;

    p_nodo aux = cola->frente;      
    cola->frente = cola->frente->sigNodo;       // Mover el puntero del frente de la cola al siguiente elemento
    valor = aux->valor;                         // Almacenamos el valor del nodo que esta al frente de la cola

    free(aux);                                  // Eliminamos nodo que esta al frente de la cola

    if(cola->frente == NULL){                   // Si la cola esta vacia
        cola->final = NULL;                     // El final de la cola tambien apunta a NULL
    }


    return valor;
}