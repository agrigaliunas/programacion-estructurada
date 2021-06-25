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


p_nodo_bin* darDirNodo(p_nodo_bin* arbol, int numeroBuscado){
    if(*arbol == NULL){
        return NULL;
    }
    
    else if(*arbol != NULL){
        if((*arbol)->valor == numeroBuscado){
            return arbol;
        }
        else{
            if(numeroBuscado < (*arbol)->valor){
                return darDirNodo(&((*arbol)->izq), numeroBuscado);
            }
            else{
                return darDirNodo(&((*arbol)->der), numeroBuscado);
            }
        }
    }
}

void eliminarNodo(p_nodo_bin* arbol){
    if(*arbol != NULL){
        eliminarNodo(&((*arbol)->izq));
        eliminarNodo(&((*arbol)->der));

        free(*arbol);
        *arbol = NULL;
    }
}

void eliminarSub(p_nodo_bin* arbol, int valor){
    if(*arbol == NULL){
        return;
    }
    else{
        if(valor == (*arbol)->valor){
            eliminarNodo(arbol);
        }
        else{
            if(valor < (*arbol)->valor){
                eliminarNodo(&((*arbol)->izq));
            }
            else{
                eliminarNodo(&((*arbol)->der));
            }
        }
    }
    return;
}


void inorder(p_nodo_bin arbol){
    if(arbol != NULL){
        inorder(arbol->izq);
        printf("%d - ", arbol->valor);
        inorder(arbol->der);
    }
}

void eliminarValorArbol(p_nodo_bin* arbol, int valor){
    p_nodo_bin* dirNodo = darDirNodo(arbol, valor);
    eliminarNodo(dirNodo);
}


int main(){
    p_nodo_bin arbol = NULL;
    agregarAArbolBB(&arbol, 1);
    agregarAArbolBB(&arbol, 54);
    agregarAArbolBB(&arbol, 22);
    agregarAArbolBB(&arbol, 4);
    agregarAArbolBB(&arbol, 8);
    agregarAArbolBB(&arbol, -6);

    printf("In order: \n");
    inorder(arbol);
    printf("\n");

    eliminarValorArbol(&arbol, 22);

    printf("In order: \n");
    inorder(arbol);
    printf("\n");


    return 0;
}