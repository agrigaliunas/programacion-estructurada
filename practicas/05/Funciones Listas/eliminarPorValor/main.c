#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

void eliminarValor(p_nodo* nodo, int valor){
    p_nodo aux = NULL;
    if(*nodo == NULL){
        printf("Error al borrar valor de una lista vacia");
    }
    else if((*nodo)->valor == valor){
        aux = (*nodo);
        (*nodo) = (*nodo)->sigNodo;
        free(aux);
    }
    else{
        eliminarValor(&(*nodo)->sigNodo, valor);
    }
}

int main(){
    p_nodo lista = NULL;

}


