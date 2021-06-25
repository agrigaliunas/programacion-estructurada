#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// PILAS Para un entero
/*
struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void push(t_nodo* pNpila, int valor){  // Apilar
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = NULL;
    aux->sig = *pNpila; // El primer nodo pasa a ser el ultimo
    *pNpila = aux; // El nodo actual pasa a ser el primero
}

// Recordar que en las pilas, el ultimo nodo es lo primero que se agrego.

int pop(t_nodo* pNpila){ // Desapilar y devolver el valor de lo desapilado
    int valorDesapilado;
    t_nodo aux = *pNpila; // aux es el primer nodo de la pila (la cima)
    valorDesapilado = aux->valor; 
    *pNpila = aux->sig;
    free(aux);

    return valorDesapilado;
} 


int main(){
    t_nodo pila = NULL;
    push(&pila,4);
    push(&pila,2);
    push(&pila,7);

    printf("%d",pop(&pila));

    return 0;
}
*/

// PILAS Para una estructura

/*
struct s_datos{
    char* nombre;
    int dni;
};
typedef struct s_datos s_datos;

struct s_nodo{
    s_datos persona;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void push(t_nodo* pNpila, char* nombre, int dni){
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->persona.nombre = nombre;
    aux->persona.dni = dni;
    aux->sig = NULL;

    aux->sig = *pNpila;
    *pNpila = aux;
    
}

s_datos pop(t_nodo* pNpila){
    s_datos datosRetornados;
    t_nodo aux = *pNpila;

    datosRetornados.nombre = aux->persona.nombre;
    datosRetornados.dni = aux->persona.dni;

    *pNpila = aux->sig;
    free(aux);
    
    return datosRetornados; 
}

void imprimirPila(t_nodo pila){
    if(pila != NULL){
        printf("%s, %d\n",pila->persona.nombre,pila->persona.dni);
        imprimirPila(pila->sig);
    }
}

int main(){ 
    t_nodo pila = NULL;
    push(&pila,"Agustin",42996646);
    push(&pila,"Carlos",37998121);
    push(&pila,"Marta",17599021);
    imprimirPila(pila);

    s_datos datosPop = pop(&pila);
    printf("\nDatos del pop: \n");
    printf("%s, %d\n",datosPop.nombre,datosPop.dni);
    return 0;
}
*/


// COLAS Para un entero

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

struct s_cola{
    t_nodo frente;
    t_nodo final;
};
typedef struct s_cola t_cola;

void queue(t_cola* cola, int valor){
    t_nodo aux = malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = NULL;

    if(cola->frente == NULL && cola->final == NULL){ // Si no hay nadie en la cola (frente = final),
        cola->frente = aux;                             // la persona se une a la cola y pasa a ser
        cola->final = aux;                              // la unica
    }
    else{                        // Si ya hay alguien en la cola, paso a ser el siguiente del ultimo, por ende,
        cola->final->sig = aux;  // el ultimo.
        cola->final = aux;
    }
}

int dequeue(t_cola* cola){
    int valor;
    t_nodo aux = cola->frente;
    cola->frente = cola->frente->sig;
    valor = aux->valor;
    free(aux);

    if(cola->frente == NULL){
        cola->final = NULL;
    }

    return valor;
}

int main(){
    t_cola cola = {NULL, NULL};

    queue(&cola, 4); // Frente
    queue(&cola, 3);
    queue(&cola, 10);
    queue(&cola, 14);
    queue(&cola, 2); // Final

    printf("%d",dequeue(&cola));
}