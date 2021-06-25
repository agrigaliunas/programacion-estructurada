#include <stdio.h>
#include <stdlib.h>


struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

void eliminarXpos(p_nodo* nodo, int pos){
    int i;
    p_nodo aux = NULL;
    if(*nodo != NULL){
        for(i = 1 ; *nodo != NULL ; i++){
            if(i == pos){
                aux = *nodo;
                *nodo = (*nodo)->sigNodo;
                free(aux);
            }
            else{
                nodo = &(*nodo)->sigNodo;
            }
        }
    }
    else{
        printf("La lista esta vacia");
    }
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


int main(){
    p_nodo lista = NULL;
    agregarALista(&lista,1);   
    agregarALista(&lista,2); 
    agregarALista(&lista,3);
    agregarALista(&lista,4);
    
    eliminarXpos(&lista,2);
    return 0;

}