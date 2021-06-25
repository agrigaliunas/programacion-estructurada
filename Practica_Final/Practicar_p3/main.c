#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    int notas[5];
    char estado;
} t_dato;


struct s_nodo{
    t_dato dato;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

int obtenerAprobados(int notas[5], int pos){ // 8 7 7 4
    if(notas[pos] != -1){
        if(notas[pos] >=7){
            return obtenerAprobados(notas, pos+1) + 1;
        }
        else{
            return obtenerAprobados(notas, pos+1) + 0;
        }
    }
    else{
        return 0;
    }
}

void agregarAlista(t_nodo* pNodo, t_dato aux){
    if(*pNodo == NULL){
        *pNodo = malloc(sizeof(struct s_nodo));
        (*pNodo)->dato = aux;
        (*pNodo)->sig = NULL;
    }
    else{
        agregarAlista(&(*pNodo)->sig,aux);
    }
}

void cargarArchivo(t_nodo* pNodo){
    FILE* arch = fopen("promocionados.csv","r");
    int indiceNota = 0;
    int indiceLetra = 0;
    char l = 0;
    //int notas[5];
    //char estado = 0;
    l = fgetc(arch);
    t_dato aux;

    while(l != EOF){
        //char nombre[50] = {0};
        indiceLetra = 0;
        while(l != ','){
            aux.nombre[indiceLetra] = l;
            indiceLetra++;
            l = fgetc(arch);
        }
        aux.nombre[indiceLetra] = '\0';

        fscanf(arch,"%d, %d, %d, %d\n",&aux.notas[0],&aux.notas[1],&aux.notas[2],&aux.notas[3]);
        aux.notas[4] = -1;

        if(obtenerAprobados(aux.notas, 0) >= 3){
           aux.estado = 'A';
        }
        else{
           aux.estado = 'D';
        }
        
        agregarAlista(pNodo, aux);
        
        l = fgetc(arch);
    }
}

void imprimirLista(t_nodo lista){
    int i;
    if(lista != NULL){
        printf("%-10s ",lista->dato.nombre);
        printf("%d ",lista->dato.notas[0]);
        printf("%d ",lista->dato.notas[1]);
        printf("%d ",lista->dato.notas[2]);
        printf("%d ",lista->dato.notas[3]);
        printf("%-10c",lista->dato.estado);
        printf("\n");
        imprimirLista(lista->sig);
    }
}

int main(){
    t_nodo lista = NULL;

    cargarArchivo(&lista);

    imprimirLista(lista);

    return 0;
}
