/* Los encolamientos se producen al final de la lista */

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

void queue(p_cola* cola, int valor){                        
    p_nodo aux = (p_nodo) malloc(sizeof(struct s_nodo));    /* Crea un nuevo nodo en memoria */
    aux->valor = valor;                                     /* Almacena el dato */
    aux->sigNodo = NULL;                                    

    if(cola->frente == NULL && cola->final == NULL){    /* Si cola esta VACIA... */

        cola->frente = aux;   
                                /* Frente y final apuntan al nuevo nodo creado */                          
        cola->final = aux;                          
    }

    else{   /* Si cola no esta vacia... */
        cola->final->sigNodo = aux;         // El puntero siguiente del final de la cola apunta al nuevo nodo
        cola->final = aux;                  // Se mueve el final a la nueva posicion
    }
}