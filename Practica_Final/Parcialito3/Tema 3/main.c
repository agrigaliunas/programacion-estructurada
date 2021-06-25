#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char fr[100];
    int limite;
    int valido;}t_frase;

struct s_nodo{
    t_frase frase;
    struct s_nodo *sig;};
typedef struct s_nodo * t_nodo;

int validar(char * frase){
    if(*frase != '\0'){
        return 1 + validar(frase+1);
    }
    return 0;
}

void agregar(t_nodo*lista, t_frase contenido){

        if((*lista)==NULL){
            *lista = malloc(sizeof(struct s_nodo));
            (*lista)->frase = contenido;
            (*lista)->sig = NULL;
        }else{
            agregar(&(*lista)->sig,contenido);
        }
}

void imprimir(t_nodo lista){
    if(lista != NULL){
        printf("%-80s %10d %10d\n",lista->frase.fr,lista->frase.limite,lista->frase.valido);
        imprimir(lista->sig);
    }
}


void cargarLista(t_nodo * lista){

    int i=0,largo;
    char frase[100];
    char caracter;
    t_frase aux;
    
    FILE* archivo = fopen("frases.txt","r");
    caracter = fgetc(archivo);

    
    if(archivo == NULL){
        printf("Error al abrir el archivo");
    }

    else{
        while(caracter != EOF){
            
            while(caracter != ';'){
            frase[i] = caracter;
            i++;
            caracter = fgetc(archivo);
            }
        
        frase[i] = '\0';
        strcpy(aux.fr,frase);

        largo = validar(frase);
            

        fscanf(archivo,"%d\n",&aux.limite);


        if(largo<=aux.limite){
            aux.valido = 1;
        }else{
            aux.valido = 0;
        }

        
        agregar(lista,aux);
        i=0;
        caracter = fgetc(archivo);
        }
    }
    fclose(archivo);
}

int main(){
    t_nodo lista = NULL;
    cargarLista(&lista);
    printf("%-80s %10s %10s\n","Frase","Limite","Validez");
    imprimir(lista);
}
