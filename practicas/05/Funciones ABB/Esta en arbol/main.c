#include <stdlib.h>
#include <stdio.h>

struct s_nodo_bin{
    int valor;
    struct s_nodo_bin* izq;
    struct s_nodo_bin* der;
};
typedef struct s_nodo_bin* p_nodo_bin;

int estaEnABB(p_nodo_bin arbol, int valor){
    if(arbol == NULL){
        return 0;
    }
    else{
        if(valor == arbol->valor){
            return 1;
        }
        else{
            if(valor < arbol->valor){
                return estaEnABB(arbol->izq, valor);
            }
            else{
                return estaEnABB(arbol->der, valor);
            }
        }
    }
}

int main(){
    return 0;
}