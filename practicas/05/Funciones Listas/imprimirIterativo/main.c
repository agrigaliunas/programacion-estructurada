#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};

typedef struct s_nodo* p_nodo;


void imprimirListaIterativo(p_nodo nodo){
    int i;
    for(i = 0 ; nodo != NULL ; i++){
        printf("%d\n",nodo->valor);
        nodo = nodo->sigNodo;
    }
}

int main(){

    return 0;
}