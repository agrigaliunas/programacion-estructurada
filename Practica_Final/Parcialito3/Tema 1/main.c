#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    int notas[5]; //finaliza en -1
    char estado;}t_dato;

struct s_nodo{
    t_dato dato;
    struct s_nodo *sig;};
typedef struct s_nodo * t_nodo;

void agregar(t_nodo * nodo, t_dato val)
{
	if ((*nodo)==NULL)
	{
		*nodo=malloc(sizeof(struct s_nodo));
		(*nodo)->dato=val;
		(*nodo)->sig=NULL;
	}
	else
	{
		agregar(&(*nodo)->sig, val);
	}
}

void cargarLista(t_nodo * lista){
    
    int i = 0;
    char *nombreDinamico;
    char caracter;
    t_dato aux;

    FILE* archivo = fopen("promocionados.txt","r");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo...");
    }
    else{
        
        while(caracter != EOF){
            nombreDinamico = malloc(sizeof(char));
            while(caracter != ','){
                nombreDinamico[i] = caracter;
                i++;
                caracter = fgetc(archivo);
                nombreDinamico = realloc(nombreDinamico,(i+1)*sizeof(char));
            }

            nombreDinamico[i] = '\0';
            strcpy(aux.nombre,nombreDinamico);

            fscanf(archivo,"%d,%d,%d,%d\n",&aux.notas[0],&aux.notas[1],&aux.notas[2],&aux.notas[3]);
            aux.notas[4] = -1; 

            if ((aux.notas[1]>=7 && aux.notas[1]>=7 && aux.notas[2] >= 7) || (aux.notas[0]>=7 && aux.notas[2]>=7 && aux.notas[3] >= 7) || 
            (aux.notas[0]>=7 && aux.notas[1]>=7 && aux.notas[3] >= 7) || (aux.notas[0]>=7 && aux.notas[1]>=7 && aux.notas[2] >= 7) || 
            (aux.notas[0] >= 7 && aux.notas[1]>=7 && aux.notas[1]>=7 && aux.notas[2] >= 7)){
                aux.estado = 'A';
            }else
            {
                aux.estado = 'D';
            }
            
            agregar(lista,aux);
            i=0;
            caracter = fgetc(archivo);
        }      
    }   
}

void imprimir(t_nodo lista)
{
	if (lista!=NULL)
	{
		printf("%-50s %d,%d,%d,%d %10c\n",  lista->dato.nombre, lista->dato.notas[0],lista->dato.notas[1],lista->dato.notas[2],lista->dato.notas[3],lista->dato.estado);
		imprimir(lista->sig);
	}
}

int main(){
    t_nodo lista = NULL;
    cargarLista(&lista);
    printf("%s %50s %15s\n\n","Nombre","Notas","Estado");
    imprimir(lista);
}