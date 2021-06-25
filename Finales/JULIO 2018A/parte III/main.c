#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_indice{
    int indice_inicial;
    int indice_final;
};
typedef struct s_indice t_indice;

struct s_nodo{
    int numero_linea;
    struct s_indice indice;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;


t_indice buscarSub(char* str, char* sub){
    t_indice indices;

    indices.indice_inicial = -1;
    indices.indice_final = -1;

    int existeSub = 0;
    int indStr = 0;
    int indSub = 0;

    while(str[indStr] != '\0' && !existeSub){

        if(str[indStr] == sub[indSub]){
            indices.indice_inicial = indStr;
            indices.indice_final = indStr;
        
            while(str[indStr] == sub[indSub] && str[indStr] != '\0' && sub[indSub] != '\0'){
                indices.indice_final = indStr;
                indStr++;
                indSub++;
            }

            if(sub[indSub] == '\0'){
                existeSub = 1;
            }
            
            indSub = 0;
        }

        indStr++;

    }

    return indices;

}

void leerArchivo(char* nombre_archivo, char*** dirArregloFrases){
    FILE* archivo = fopen(nombre_archivo, "r");
    char caracterLeido;
    int indiceLetra = 0;
    int indiceFrase = 0;
    char* frase = NULL;
    char** arregloFrases = NULL; // Ponemos todo en un arreglo de frases, ya que cada INDEX representa una LINEA

    if(archivo != NULL){

        arregloFrases = malloc(sizeof(char *));  // Le doy lugar de UNA FRASE al arreglo de frases
        frase = malloc(sizeof(char)); // Le doy lugar de UN CARACTER a la frase
        
        caracterLeido = fgetc(archivo);

        while(caracterLeido != EOF){
            
            while(caracterLeido != '\n'){
                frase[indiceLetra] = caracterLeido;
                indiceLetra++;
                frase = realloc(frase, sizeof(char) * (indiceLetra+1)); 
                caracterLeido = fgetc(archivo);
            }

            frase[indiceLetra] = '\0';

            arregloFrases[indiceFrase] = frase;  // Pongo la frase en el arreglo de frases

            indiceFrase++; // Paso al siguiente elemento el arreglo de frases

            arregloFrases = realloc(arregloFrases, sizeof(char*) * (indiceFrase+1)); // Le doy un espacio mas al arreglo de frases
            
            caracterLeido = fgetc(archivo); // Leo de nuevo el caracter.. hasta que sea EOF (todavia no se si termino el archivo)
            indiceLetra = 0;

            frase = malloc(sizeof(char));
             // La frase ahora empieza desde 0
        }

        frase[0] = '\0'; 
        arregloFrases[indiceFrase] = frase;

        fclose(archivo);
    }

    (*dirArregloFrases) = arregloFrases;

}

void agregarALista(t_indice indices, int numeroLinea, t_nodo* nodo){
    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->numero_linea = numeroLinea;
        (*nodo)->indice = indices;
        (*nodo)->sig = NULL;
    }
    else{
        agregarALista(indices, numeroLinea, &((*nodo)->sig));
    }
}

t_nodo indices(char* sub){
    t_nodo listaDeIndices = NULL;
    t_indice actualIndice;
    int nroLinea = 0;
    char** arregloFrases = NULL;
    

    leerArchivo("frases.txt", &arregloFrases);  
    /* Contendra la ubicacion actual de sub en arreglo */
    actualIndice = buscarSub(arregloFrases[nroLinea], sub);

    // Cada indice del arreglo de frases es una linea del archivo...
    while(arregloFrases[nroLinea][0] != '\0'){

        /* ..... */
        actualIndice = buscarSub(arregloFrases[nroLinea], sub);

        if(actualIndice.indice_inicial != -1 && actualIndice.indice_final != -1){
            agregarALista(actualIndice, nroLinea , &listaDeIndices); // 0 6 7 // 6
        }

        nroLinea++;
    }
    
    return listaDeIndices;
}

void imprimirListaIndices(t_nodo lista){
    if(lista != NULL){
        printf("(%d,",lista->numero_linea);
        printf("%d,",lista->indice.indice_inicial);
        printf("%d)\n",lista->indice.indice_final);
        imprimirListaIndices(lista->sig);
    }
}

int main(){
    t_nodo lista = NULL;
    lista = indices("da");
    imprimirListaIndices(lista);

    return 0;
}