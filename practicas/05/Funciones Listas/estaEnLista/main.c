#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

int estaEnLista(p_nodo nodo, int valor){
    int i;
    int esta = 0;
    if(nodo != NULL){
        for(i = 0 ; esta == 0 && nodo != NULL ; i++){
            if(valor == nodo->valor){
                esta = 1;
            }
            else{
                nodo = nodo->sigNodo;
            }
        }
    }
    return esta;

} 

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


void imprimirLista(p_nodo nodo){
    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sigNodo);
    }
}

int main(){
    p_nodo lista = NULL;
    int valor = 44;
    agregarALista(&lista,1);
    agregarALista(&lista,2);
    agregarALista(&lista,44);
    agregarALista(&lista,7);
    imprimirLista(lista);
    printf("%d",estaEnLista(lista,valor));
    return 0;
}