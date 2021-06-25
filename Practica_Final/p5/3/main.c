#include <stdio.h>
#include <stdlib.h>

// Eliminar un nodo de una lista de enteros

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void insertarFinal(t_nodo* pNodo, int valor){
    if(*pNodo == NULL){
        *pNodo = malloc(sizeof(struct s_nodo));
        (*pNodo)->valor = valor;
        (*pNodo)->sig = NULL;
    }
    else{
        insertarFinal(&(*pNodo)->sig,valor);
    }
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("{%d} ",lista->valor);
        imprimirLista(lista->sig);
    }
}

void eliminarNodo(t_nodo* pNodo, int valor){
    t_nodo aux = NULL;
    if(*pNodo == NULL){
        printf("\nLa lista esta vacia!\n");
    }
    else if(valor == (*pNodo)->valor){ // Con este else if evitamos que siga recorriendo una vez que encuentra al nodo
        aux = *pNodo;
        *pNodo = (*pNodo)->sig;
        free(aux);
    }
    else{
        eliminarNodo(&(*pNodo)->sig,valor);
    }
    
}

int main(){
    t_nodo lista = NULL;
    insertarFinal(&lista,1);
    insertarFinal(&lista,3);
    insertarFinal(&lista,2);
    insertarFinal(&lista,8);
    insertarFinal(&lista,7);
    insertarFinal(&lista,88);

    imprimirLista(lista);
    printf("\n");
    
    eliminarNodo(&lista,8);
    imprimirLista(lista);


    return 0;
}