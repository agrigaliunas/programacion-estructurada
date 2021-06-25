#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};

typedef struct s_nodo* p_nodo; 

void agregarALista(p_nodo* nodo, int valor){
    if(*nodo == NULL){                                      
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
    agregarALista(&lista,3); 
    agregarALista(&lista,7);
    
    

    return 0;
}