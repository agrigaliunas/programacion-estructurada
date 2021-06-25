#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
            - Visitar el nodo padre
PRE ORDER:  - Recorrer el subárbol izquierdo
            - Recorrer el subárbol derecho

********************************************

IN ORDER:   - Recorrer el subárbol izquierdo
            - Visitar el nodo padre
            - Recorrer el subárbol derecho

********************************************

POST ORDER: - Recorrer el subárbol izquierdo
            - Recorrer el subárbol derecho
            - Visitar el nodo padre

********************************************
*/

struct s_nodo_bin{
    int valor;
    struct s_nodo_bin* izq;
    struct s_nodo_bin* der;
};
typedef struct s_nodo_bin* p_nodo_bin;

/***************************************************************************************************************/

                                                    /***********/
                                                    /* ARBOLES */
                                                    /***********/



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


void preorder(p_nodo_bin arbol){
    if(arbol != NULL){
        printf("%d - ", arbol->valor);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
} 

void inorder(p_nodo_bin arbol){
    if(arbol != NULL){
        inorder(arbol->izq);
        printf("%d - ", arbol->valor);
        inorder(arbol->der);
    }
}

void postorder(p_nodo_bin arbol){
    if(arbol != NULL){
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("%d - ", arbol->valor);
        
    }
}

void por_niveles(p_nodo_bin arbol, int nivel){
    if(arbol != NULL){
        if( nivel > 0 ){//Si estamos en el nivel 0, estamos en el nivel que queremos imprimir
            por_niveles(arbol->izq, nivel - 1 );
            por_niveles(arbol->der, nivel - 1 );
        }
        else if(nivel == 0){
            printf("%d\n", arbol->valor);
        }
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

    printf("\n******************\n");
    printf("\nPre-order:\n");
    preorder(arbol);

    printf("\n******************\n");
    printf("\nIn-order:\n");
    inorder(arbol);

    printf("\n******************\n");
    printf("\nPost-order:\n");
    postorder(arbol);

    printf("\n******************\n");
    printf("\nPor niveles:\n");
    por_niveles(arbol, 2);
    return 0;

}