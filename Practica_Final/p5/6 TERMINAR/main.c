#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct s_datos{
    int dni;
    char* nombre;
    char* apellido;
    int registro;
};
typedef struct s_datos s_datos;

struct s_nodo{
    s_datos persona;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;




void cargarLista(t_nodo* pNodo, int dni, char* nombre, char* apellido, int registro){

    if(*pNodo == NULL){
        *pNodo = malloc(sizeof(struct s_nodo));
        
        (*pNodo)->persona.dni = dni;
        (*pNodo)->persona.nombre = nombre;
        (*pNodo)->persona.apellido = apellido;
        (*pNodo)->persona.registro = registro;

        (*pNodo)->sig = NULL;
    }

    else{
        cargarLista(&(*pNodo)->sig, dni, nombre, apellido, registro);
    }
}

void cargarArchivo(t_nodo* pNodo){
    FILE* archivo = fopen("personas.txt", "r");   

    int dni;
    int registro; 
    int i = 0;
    char letra = 0;
    char* nombre = NULL;
    char* apellido = NULL;
    
    if(archivo == NULL){
        printf("Error al leer archivo");
    }

    else{
        

        while(fscanf(archivo,"%d,",&dni) != EOF){
            nombre = malloc(sizeof(char));
            apellido = malloc(sizeof(char));
            i = 0;
            letra = fgetc(archivo);

            while(letra != ',' && letra != EOF){
                nombre[i] = letra;
                i++;
                letra = fgetc(archivo);
                nombre = realloc(nombre,sizeof(char)*(i+1));
            }
            nombre[i] = '\0';

            i = 0;
            letra = fgetc(archivo);

            while(letra != ',' && letra != EOF){
                apellido[i] = letra;
                i++;
                letra = fgetc(archivo);
                apellido = realloc(apellido,sizeof(char)*(i+1));
            }
            apellido[i] = '\0';

            fscanf(archivo,"%d,",&registro);
            
            cargarLista(pNodo,dni,nombre,apellido,registro);
        }
    }

}

void imprimirLista(t_nodo lista){
    
    if(lista != NULL){
        printf("%d %s %s %d\n",lista->persona.dni,lista->persona.nombre,lista->persona.apellido,lista->persona.registro);
        imprimirLista(lista->sig);
    }
}

void ordenarAux(t_nodo* pLista_aux, int dni, char* nombre, char* apellido, int registro){
    t_nodo lista_aux2 = NULL;

    if(*pLista_aux == NULL || registro < (*pLista_aux)->persona.registro){
        lista_aux2 = malloc(sizeof(struct s_nodo));
        lista_aux2->persona.dni = dni;
        lista_aux2->persona.nombre = nombre;
        lista_aux2->persona.apellido = apellido;
        lista_aux2->persona.registro = registro;

        lista_aux2->sig = *pLista_aux;
        *pLista_aux = lista_aux2;
    }
    else{
        ordenarAux(&(*pLista_aux)->sig,dni,nombre,apellido,registro);
    }
}

void ordenarConAuxiliar(t_nodo* pNodo){

    t_nodo listaAux = NULL;
    while(*pNodo != NULL){ // A ordenarAux le paso los datos de cada nodo de la lista y los pongo en una nueva lista, ordenada
        ordenarAux(&listaAux,(*pNodo)->persona.dni,(*pNodo)->persona.nombre,(*pNodo)->persona.apellido,(*pNodo)->persona.registro);
        *pNodo = (*pNodo)->sig;
    }
    *pNodo = listaAux;  // La lista desordenada pasa a ser la ordenada

}

// void ordenarSAux(t_nodo* pNodo){
//     s_datos structAux;
//     if((*pNodo)->persona.registro > (*pNodo)->sig->persona.registro){
//         structAux = (*pNodo)->persona;
//         (*pNodo)->persona = (*pNodo)->sig->persona;
//         (*pNodo)->sig->persona = structAux;

//     }
//     else{
//         ordenarSAux(&(*pNodo)->sig);
//     }
// }

// void ordenarSinAuxiliar(t_nodo* pNodo){
//     while(*pNodo != NULL){
//         ordenarSAux(pNodo);
//         *pNodo = (*pNodo)->sig;
//     }
// }



int main(){
    t_nodo lista = NULL;

    cargarArchivo(&lista);
    imprimirLista(lista);

    // ordenarConAuxiliar(&lista);
    // printf("\nOrdenada con aux: \n");
    // imprimirLista(lista);

    ordenarSinAuxiliar(&lista);
    printf("\nOrdenada sin aux: \n");
    imprimirLista(lista);


    return 0;
}