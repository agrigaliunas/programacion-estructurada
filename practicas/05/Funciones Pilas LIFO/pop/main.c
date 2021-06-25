#include <stdio.h>
#include <stdlib.h>

/* En pilas, pop lo que permite es extraer el ultimo elemento de una pila */

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;         /* Usamos la misma estructura, pero el inicio de la lista es el tope */
};                                                                                  /* de la pila  */
typedef struct s_nodo* p_nodo;
                                

/* Funcion pop: eliminamos el nodo que guardaba dicho elemento. */
/* Tope de la pila se mueve al nodo que le sigue al primero */


int pop(p_nodo* pila){
    int valor;
    p_nodo aux = *pila;
    valor = aux->valor;
    *pila = aux->sigNodo;
    free(aux);

    return valor;
}

/* No es posible aplicar esto a una pila vacia */