#include <stdio.h>
#include <stdlib.h>

/* Con estructura de numeros */

/*
struct s_nodo{
    int valor;                    
    struct s_nodo* siguiente;   // &lista --> ( t_nodo ) --> ( []--[]--[]--[] ) 
};
typedef struct s_nodo* t_nodo; // t_nodo es un puntero a s_nodo


void agregarALista(t_nodo* pLista, int valor){
    if(*pLista == NULL){
        *pLista = malloc(sizeof(struct s_nodo));
        (*pLista)->valor = valor;
        (*pLista)->siguiente = NULL;
    }
    else{
        agregarALista(&(*pLista)->siguiente,valor);
    }
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%d, ",(*lista).valor);
        imprimirLista((*lista).siguiente);
    }
}

void imprimirInversa(t_nodo lista){
    // Voy hasta el final de la lista. Imprimo desde ahi.
    if(lista != NULL){
        imprimirInversa((*lista).siguiente);
        printf("%d, ",(*lista).valor);
    }   
}

int main(){
    t_nodo lista = NULL;
    agregarALista(&lista,14);
    agregarALista(&lista,17);
    agregarALista(&lista,20);
    agregarALista(&lista,23);
    printf("\n");
    imprimirLista(lista);
    printf("\n");
    imprimirInversa(lista);

    return 0;
}
*/


/* Con estructura de nombre, apellido y dni */

struct s_nodo{
    char* nombre;
    char* apellido;
    int dni;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void cargarLista(t_nodo* pLista, char* nombre, char* ape, int dni){
    if(*pLista == NULL){
        *pLista = malloc(sizeof(struct s_nodo));
        (*pLista)->nombre = nombre;
        (*pLista)->apellido = ape;
        (*pLista)->dni = dni;
        (*pLista)->sig = NULL;
    }
    else{
        cargarLista(&(*pLista)->sig, nombre, ape, dni);
    }
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%s, %s, %d\n",lista->nombre,lista->apellido,lista->dni);
        imprimirLista(lista->sig);
    }
}

void imprimirInversa(t_nodo lista){
    if(lista != NULL){
        imprimirInversa(lista->sig);
        printf("%s, %s, %d\n",lista->nombre,lista->apellido,lista->dni);
    }
}

int main(){
    t_nodo lista = NULL;
    cargarLista(&lista,"Agustin","Grigaliunas",42996646);
    cargarLista(&lista,"Gabriela","Grigaliunas",38768483);
    cargarLista(&lista,"Eduardo","Grigaliunas",14935922);
    cargarLista(&lista,"Rosana","Krivohlavy",16962059);
    imprimirLista(lista);
    printf("\n");
    imprimirInversa(lista);

    return 0;
}