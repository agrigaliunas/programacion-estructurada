#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo; 


void insertar(p_nodo* nodo, int valor){ 
    p_nodo aux = NULL;

    if(*nodo == NULL || valor < (*nodo)->valor){
        aux = (p_nodo) malloc(sizeof(struct s_nodo)); 
        aux->valor = valor;
        aux->sigNodo = *nodo;      
        *nodo = aux;    
    }
    else{
        insertar(&(*nodo)->sigNodo, valor);
    }

}


int main(){
    p_nodo lista = NULL; // Lista es un puntero al nodo
    insertar(&lista,7);

    return 0;
}