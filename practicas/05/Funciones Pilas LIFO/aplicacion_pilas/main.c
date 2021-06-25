#include <stdio.h>
#include <stdlib.h>

/* RECORDAR QUE PILAS SON DE TIPO       L.I.F.O (last in, fisrt out) */

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

int pop(p_nodo* pila){
    int valor;
    if(*pila != NULL){
        p_nodo aux = *pila;
        valor = aux->valor;
        *pila = aux->sigNodo;
        free(aux);
        return valor;
    }
    else{
        printf("Error. La pila esta vacia.");
    }
    
}

void push(p_nodo* pila, int valor){
    p_nodo aux = (p_nodo) malloc(sizeof(struct s_nodo));   // Se crea nodo auxiliar
    aux->valor = valor;                                    // Se le da el valor al nodo auxiliar
    aux->sigNodo = NULL;                                   // Si no hay otro nodo aparte, este apunta a NULL
    aux->sigNodo = *pila;                                  // El nodo auxiliar, apunta al nodo que ya existia
    *pila = aux;                                           // El nodo auxiliar, pasa a ser el ultimo elemento
}

            /* Es como si los nodos apuntan desde el ultimo (aux), hasta el primero */

int main(){
    int valor;
    p_nodo pila = NULL;

    while(valor != 0){    
        printf("Ingrese valor, terminar con 0: ");
        scanf("%d",&valor);
        if(valor != 0){
            push(&pila,valor);
        }
    }

    printf("\nElementos de la pila, desapilados:\n");

    while(pila != NULL){
        valor = pop(&pila);
        printf("%d - ",valor);
    }

    printf("\n");


    return 0;
}