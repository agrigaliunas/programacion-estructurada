#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

/* Armamos una estructura auxiliar, para poder manipular los extremos de la cola */
struct s_cola{
    p_nodo frente;  // Puntero al frente de la cola
    p_nodo final;   // Puntero al final de la cola
};
typedef struct s_cola p_cola;


int dequeue(p_cola* cola){
    int valor;

    p_nodo aux = cola->frente;      
    cola->frente = cola->frente->sigNodo;       // Mover el puntero del frente de la cola al siguiente elemento
    valor = aux->valor;                         // Almacenamos el valor del nodo que esta al frente de la cola

    free(aux);                                  // Eliminamos nodo que esta al frente de la cola

    if(cola->frente == NULL){                   // Si la cola esta vacia
        cola->final = NULL;                     // El final de la cola tambien apunta a NULL
    }


    return valor;
}



void queue(p_cola* cola, int valor){                        
    p_nodo aux = (p_nodo) malloc(sizeof(struct s_nodo));    /* Crea un nuevo nodo en memoria */
    aux->valor = valor;                                     /* Almacena el dato */
    aux->sigNodo = NULL;                                    

    if(cola->frente == NULL && cola->final == NULL){    /* Si cola esta VACIA... */

        cola->frente = aux;   
                                /* Frente y final apuntan al nuevo nodo creado */                          
        cola->final = aux;                          
    }

    else{   /* Si cola no esta vacia... */
        cola->final->sigNodo = aux;         // El puntero siguiente del final de la cola apunta al nuevo nodo
        cola->final = aux;                  // Se mueve el final a la nueva posicion
    }
}


int main(){
    int val;
    p_cola cola = { NULL, NULL };

    while (val != 0){
        printf("Ingrese valores, con 0 finaliza: ");
        scanf("%d", &val);
        if (val != 0)
            queue(&cola, val);
    } 

    printf("\nDatos ingresados: ");

    while (cola.frente != NULL){
        val = dequeue(&cola);
        printf("%d -", val);
    }

    printf("\n");


    return 0;
}