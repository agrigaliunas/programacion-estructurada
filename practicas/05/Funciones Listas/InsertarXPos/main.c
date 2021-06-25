#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

void insertarPorPosicion(p_nodo* nodo, int valor,int pos){
    int i;
    if(*nodo != NULL){
        for(i = 0 ; i != pos ; i++){
            nodo = &(*nodo)->sigNodo;
        }
        if(i == pos){
            if(*nodo == NULL){
                *nodo = (p_nodo) malloc(sizeof(struct s_nodo));
                (*nodo)->valor = valor;
                (*nodo)->sigNodo = NULL;
            }
            else{
                (*nodo)->valor = valor;
            }
        }
    }

}

void imprimirLista(p_nodo nodo){
    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sigNodo);
    }
}

void agregarALista(p_nodo* nodo, int valor){

    if(*nodo == NULL){                                      // *nodo es el nodo 
        *nodo = (p_nodo) malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sigNodo = NULL;
    }
    else{
        agregarALista(&(*nodo)->sigNodo, valor);
    }
}


int main(){
    p_nodo lista = NULL;
    agregarALista(&lista,2);
    agregarALista(&lista,5);
    agregarALista(&lista,1);
    agregarALista(&lista,7);

    printf("Lista:\n");
    imprimirLista(lista);

    insertarPorPosicion(&lista,10,1);
    insertarPorPosicion(&lista,21,4);
    printf("Lista nueva:\n");
    imprimirLista(lista);

    //Si no imprime nada, significa que la lista no tiene la longitud suficiente para insertar en esa posicion 
    return 0;
}