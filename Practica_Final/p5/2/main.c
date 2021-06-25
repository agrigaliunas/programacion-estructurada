#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Agregar ordeando una lista de enteros

/*

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;


void insertarOrdenado(t_nodo* pLista, int valor){
    t_nodo aux = NULL;
    if(*pLista == NULL || valor < (*pLista)->valor){
        aux = malloc(sizeof(struct s_nodo));
        aux->valor = valor;
        aux->sig = *pLista;
        *pLista = aux; // El nodo en el que me encuentro pasa a ser el nodo auxiliar (intercambio nodos)
    }
    else{
        insertarOrdenado(&(*pLista)->sig, valor);
    }
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%d",lista->valor);
        imprimirLista(lista->sig);
    } 
}

int main(){
    t_nodo lista = NULL;
    insertarOrdenado(&lista, 4);
    insertarOrdenado(&lista, 1);
    insertarOrdenado(&lista, 7);
    imprimirLista(lista);
    return 0;
}

*/


// Agregar ordenado lista con campos

struct s_nodo{
    char* nombre;
    char* apellido;
    int dni;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo; // t_nodo apunta al primer nodo de la lista

void insertarOrdenadoApe(t_nodo* pNodo, char* nombre, char* apellido, int dni){
    t_nodo aux = NULL;
    if(*pNodo == NULL || strcmp(apellido, (*pNodo)->apellido) < 0){
        aux = malloc(sizeof(struct s_nodo));

        aux->apellido = apellido;
        aux->nombre = nombre;
        aux->dni = dni;

        aux->sig = *pNodo;
        *pNodo = aux;
    }
    else{
        insertarOrdenadoApe(&(*pNodo)->sig, nombre, apellido, dni);
    }
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%s, %s, %d\n",lista->nombre,lista->apellido,lista->dni);
        imprimirLista(lista->sig);
    }
}

int main(){
    t_nodo lista = NULL;

    insertarOrdenadoApe(&lista,"Agustin","Grigaliunas",42996646);
    insertarOrdenadoApe(&lista,"Gabriela","Zaurichs",38768483);
    insertarOrdenadoApe(&lista,"Eduardo","Ribera",14935922);
    insertarOrdenadoApe(&lista,"Rosana","Krivohlavy",16962059);

    imprimirLista(lista);
    return 0;
}