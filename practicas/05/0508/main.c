#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
IN ORDER:   - Recorrer el subárbol izquierdo
            - Visitar el nodo padre
            - Recorrer el subárbol derecho
********************************************

*/

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

void inorder(p_nodo_bin arbol){
    if(arbol != NULL){
        inorder(arbol->izq);
        printf("%d - ", arbol->valor);
        inorder(arbol->der);
    }
    if(arbol == NULL){
        printf("El arbol esta vacio!");
    }
}


int main(){
    p_nodo_bin arbol = NULL;
    int n;
    printf("Ingrese numero: ");
    scanf("%d",&n);
    agregarAArbolBB(&arbol, n);
    while(n != 0){
        printf("Ingrese numero: ");
        scanf("%d",&n);
        agregarAArbolBB(&arbol, n);
    }

    printf("\nIn-order:\n");
    inorder(arbol);

    return 0;
}