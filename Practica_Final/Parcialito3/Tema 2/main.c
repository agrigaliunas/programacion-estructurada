#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char txt[100];
    char car;
    int cantidad_caracter;}t_refran;

struct s_nodo{
    t_refran ref;
    struct s_nodo *sig;};
typedef struct s_nodo * t_nodo;

void agregar(t_nodo * lista, t_refran refran){
    if((*lista) == NULL){
        *lista = malloc(sizeof(struct s_nodo));
        (*lista)->ref = refran;
        (*lista)->sig = NULL;
    }
    else{
        agregar(&(*lista)->sig,refran);
    }
}



int cantidad(char* texto,char caracter){
    if(*texto != '\0'){
        if(*texto == caracter){
            return 1 + cantidad((texto+1),caracter);
        }
        else{
            return 0 + cantidad((texto+1),caracter);
        }
    }
}

void cargarLista(t_nodo * lista){

    char caracter;
    char texto[100];

    int i=0;

    t_refran auxiliar;

    FILE* archivo = fopen("refranes.txt","r");
    caracter = fgetc(archivo);

    if(archivo == NULL){
        printf("No se pudo abrir el archivo...");}
    
    
    else{
        while(caracter != EOF){
            
            if(caracter!='\n'){
                
                while(caracter != ','){
                    texto[i] = caracter;
                    i++;
                    caracter = fgetc(archivo);
                }

                texto[i] = '\0';
                strcpy(auxiliar.txt,texto);

                caracter = fgetc(archivo);
                auxiliar.car = caracter;

                auxiliar.cantidad_caracter = cantidad(texto,caracter);
                
                caracter = fgetc(archivo);
                i=0;
                agregar(lista,auxiliar);
            }
            else{
                caracter = fgetc(archivo);
            }
        }
    }
    fclose(archivo);
}

int main(){
    t_nodo lista = NULL;
    cargarLista(&lista);
    printf("%-50s %12s %10s\n\n","Refran","Caracter","Cantidad");
    imprimirLista(lista);

}
