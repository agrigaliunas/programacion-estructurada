#include <stdio.h>
#include <stdlib.h>

/* En pilas, push lo que permite es agregar un elemento */

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;         /* Usamos la misma estructura, pero el inicio de la lista es el tope */
};                                                                                  /* de la pila  */
typedef struct s_nodo* p_nodo;
                                

/* Funcion push: elemento que se agrega se convierte en el nuevo tope. */

void push(p_nodo* pila, int valor){
    p_nodo aux = (p_nodo) malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sigNodo = NULL;
    aux->sigNodo = *pila;
    *pila = aux;
}