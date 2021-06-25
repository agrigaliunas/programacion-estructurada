#include <stdio.h>
#include <stdlib.h>

// Eliminar por posicion un nodo

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

void eliminarXpos(t_nodo* pNodo, int posicion){
    int posActual = 0;
    t_nodo aux = NULL;
    if(*pNodo == NULL){
        printf("La lista esta vacia!");
    }
    else{
        for(posActual = 0 ; *pNodo != NULL ; posActual++){
            if(posActual == posicion){
                aux = *pNodo;
                *pNodo = (*pNodo)->sig;
                free(aux);
            }   
            else{
                pNodo = &(*pNodo)->sig; // Paso de nodo
            }
        }
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
    
    eliminarXpos(&lista,4); // Posicion 4 es el numero 7
    imprimirLista(lista);
}