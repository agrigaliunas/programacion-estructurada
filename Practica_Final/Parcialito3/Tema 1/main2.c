#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    char nombre[50];
    int notas[5]; //Finaliza en -1
    char estado;
}t_dato;

struct s_nodo{
    t_dato dato;
    struct s_nodo *sig;};
typedef struct s_nodo * t_nodo;

void agregar(t_nodo * lista, t_dato dato){
    if((*lista) == NULL){
        *lista = malloc(sizeof(struct s_nodo));
        (*lista)->dato = dato;
        (*lista)->sig = NULL;
    }
    else{
        agregar(&(*lista)->sig,dato);
    }
}

void cargarLista(t_nodo * lista){

    char letra, nombre[50], estado;
    int i=0;
    t_dato aux;
    

    FILE *archivo = fopen("promocionados.txt","r");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo...");}

    else{
        letra = fgetc(archivo);
        while(letra != EOF){
            while(letra!=','){
                nombre[i] = letra;
                i++;
                letra = fgetc(archivo);
            }
            nombre[i] = '\0';
            strcpy(aux.nombre,nombre);

            fscanf(archivo,"%d,%d,%d,%d\n",&aux.notas[0],&aux.notas[1],&aux.notas[2],&aux.notas[3]);
            aux.notas[4] = -1;  

            if ((aux.notas[1]>=7 && aux.notas[1]>=7 && aux.notas[2] >= 7) || (aux.notas[0]>=7 && aux.notas[2]>=7 && aux.notas[3] >= 7) || 
            (aux.notas[0]>=7 && aux.notas[1]>=7 && aux.notas[3] >= 7) || (aux.notas[0]>=7 && aux.notas[1]>=7 && aux.notas[2] >= 7) || 
            (aux.notas[0] >= 7 && aux.notas[1]>=7 && aux.notas[1]>=7 && aux.notas[2] >= 7)){
                aux.estado = 'A';}
            
            else{
                aux.estado = 'D';}
            
            agregar(lista,aux);
            i=0;
            letra = fgetc(archivo);

        }
    }
    fclose(archivo);
}

void imprimirLista(t_nodo lista){
    if(lista != NULL){
        printf("%-40s %d,%d,%d,%d %8c\n",lista->dato.nombre,lista->dato.notas[0],lista->dato.notas[1],lista->dato.notas[2],lista->dato.notas[3],lista->dato.estado);
        imprimirLista(lista->sig);
    }
}

int main(){
    t_nodo lista = NULL;
    cargarLista(&lista);
    printf("%-40s %-10s %-8s\n\n","Nombre","Notas","Estado");
    imprimirLista(lista);
}