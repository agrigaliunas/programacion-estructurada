#include <stdio.h>
#include <stdlib.h>

struct s_nodo_bin{
    int valor;
    struct s_nodo_bin* izq;
    struct s_nodo_bin* der;
};
typedef struct s_nodo_bin* p_nodo_bin;

void agregarAArbolBB(p_nodo_bin* arbol, int valor){
    if(*arbol == NULL){
        *arbol = (p_nodo_bin) malloc(sizeof(struct s_nodo_bin));
        (*arbol)->valor = valor;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }
    else{
        if(valor < (*arbol)->valor){
            agregarAArbolBB(&(*arbol)->izq, valor);
        }
        else{
            agregarAArbolBB(&(*arbol)->der,valor);
        }
    }
}


int main(){
    p_nodo_bin arbol = NULL;
    agregarAArbolBB(&arbol,1);
    agregarAArbolBB(&arbol,60);
    agregarAArbolBB(&arbol,4);
    agregarAArbolBB(&arbol,32);
    agregarAArbolBB(&arbol,11);
    agregarAArbolBB(&arbol,2);
    agregarAArbolBB(&arbol,50);

    return 0;
}