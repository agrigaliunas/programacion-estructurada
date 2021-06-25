#include <stdio.h>
#include <stdlib.h>

struct s_nodo_bin{
    int valor;
    struct s_nodo_bin* izq;
    struct s_nodo_bin* der;
};
typedef struct s_nodo_bin* p_nodo_bin;

void eliminarNodoArbol(p_nodo_bin* arbol){
    if((*arbol) != NULL ){
        eliminarNodoArbol(&((*arbol)->izq));
        eliminarNodoArbol(&((*arbol)->der));
        free(*arbol);
        *arbol = NULL;
    }
}

int main(){

    return 0;
}