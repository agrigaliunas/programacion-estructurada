#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};

typedef struct s_nodo* p_nodo;

void imprimirLista(p_nodo nodo){

    if(nodo != NULL){
        printf("%d\n",nodo->valor);
        imprimirLista(nodo->sigNodo);
    }
}

int main(){

    return 0;
}