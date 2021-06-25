#include <stdio.h>
#include <stdlib.h>


struct s_nodo_bin{
    int valor;
    struct s_nobo_bin* izq;
    struct s_nodo_bin* der;
};
typedef struct s_nodo_bin* t_nodo_bin;

void agregar(t_nodo_bin* pArbol, int valor){
    if(*pArbol == NULL){
        *pArbol = malloc(sizeof(struct s_nodo_bin));
        (*pArbol)->valor = valor;
        (*pArbol)->izq = NULL;
        (*pArbol)->der = NULL;
    }

    else{
        if(valor < (*pArbol)->valor){
            agregar(&(*pArbol)->izq,valor);
        }
        else{
            agregar(&(*pArbol)->der,valor);
        }
        
    }
}

void eliminarNodo(t_nodo_bin* pArbol){
    if(*pArbol != NULL){
        eliminarNodo(&(*pArbol)->izq);
        eliminarNodo(&(*pArbol)->der);

        free(*pArbol);
        *pArbol = NULL;
    }
}

void eliminarValor(t_nodo_bin* pArbol, int valor){
    if(*pArbol == NULL){
        return;
    }
    else{
        if( (*pArbol)->valor == valor){
            eliminarNodo(pArbol);
        }
        else{
            if(valor < (*pArbol)->valor){
                eliminarNodo(&(*pArbol)->izq);
            }
            else{
                eliminarNodo(&(*pArbol)->der);
            }
        }
    }
}


void postorder(t_nodo_bin arbol){
    if(arbol != NULL){
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("(%d) ",arbol->valor);
    }
}

int main(){
    // agregamos contenido al ABB
    t_nodo_bin arbol = NULL;
    agregar(&arbol,15);
    agregar(&arbol,9);
    agregar(&arbol,6);
    agregar(&arbol,14);
    agregar(&arbol,13);
    agregar(&arbol,20);
    agregar(&arbol,17);
    agregar(&arbol,63);
    agregar(&arbol,26);
    agregar(&arbol,72);


    printf("\nPostorder\n");
    postorder(arbol);
   
    printf("\nEliminado el 9 y sus descendientes: \n");
    eliminarValor(&arbol,9);

    postorder(arbol);
    return 0;
}