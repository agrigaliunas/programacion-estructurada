#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sig;
};

typedef struct s_nodo* t_nodo; // Puntero a s_nodo (s_nodo es el nodo con los datos)

void agregarALista(t_nodo* nodo, int valor){

    if(*nodo == NULL){                                      // *nodo es el nodo 
        *nodo = (t_nodo) malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }
    else{
        agregarALista(&(*nodo)->sig, valor);
    }
}

void imprimirLista(t_nodo nodo){

    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sig);
    }
}

void imprimirListaIterativo(t_nodo nodo){
    int i;
    for(i = 0 ; nodo != NULL ; i++){
        printf("%d\n",nodo->valor);
        nodo = nodo->sig;
    }
}

void imprimirListaInversa(t_nodo nodo){
    if(nodo != NULL){
        imprimirListaInversa(nodo->sig);
        printf("%d\n",nodo->valor);
    }
}


int main(){
    t_nodo lista = NULL;
    agregarALista(&lista,14);
    agregarALista(&lista,17);
    agregarALista(&lista,20);
    agregarALista(&lista,23);
    printf("Lista normal:\n");
    imprimirLista(lista);
    // imprimirListaIterativo(lista);
    printf("Lista al reves:\n");
    imprimirListaInversa(lista);
    return 0;
}