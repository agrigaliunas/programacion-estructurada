#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_indices{
    int indiceInicial;
    int indiceFinal;
} typedef s_indices;

struct s_nodo{
    int numeroLinea;
    struct s_indices indice;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

s_indices buscarSub(char* str, char* sub){
    s_indices estructuraIndices;
    estructuraIndices.indiceInicial = -1;
    estructuraIndices.indiceFinal = -1;
    int existe = 0;
    int i = 0;    
    int j = 0;

    while(str[i] != '\0' && existe == 0){

        if(str[i] == sub[j]){   // Si encuentro por lo menos una letra, esa es la pos inicial y final
            estructuraIndices.indiceInicial = i;
            estructuraIndices.indiceFinal = i;

            while(str[i] == sub[j] && str[i] != '\0' && sub[j] != '\0'){ // Si sigo encontrando, busco hasta la posicion final
                estructuraIndices.indiceFinal = i;
                i++;
                j++;
            }           

            if(sub[j] == '\0'){ // Cuando corta el while (dejo de encontrar letras iguales), compruebo si la sub cadena termino..
                existe = 1;
            }
            
            else if(str[i] == '\0'){
                estructuraIndices.indiceInicial = -1;
                estructuraIndices.indiceFinal = -1;
                return estructuraIndices;
            }
            else if(str[i] != sub[j]){
                estructuraIndices.indiceInicial = -1;
                estructuraIndices.indiceFinal = -1;
            }

            j = 0;  // Vuelvo el indice de la sub cadena a 0 por si no termino la sub cadena..
        }
        i++; // Paso a la siguiente letra de la cadena
    }

    return estructuraIndices;
}

void leerArchivo(char*** dirArrFrases){
    FILE* archivo = fopen("frases.txt","r");
    char caracter;
    int indiceLetra = 0;
    int indiceArreglo = 0;
    char* frase = NULL;
    char** arregloFrases = NULL;

    if(archivo != NULL){
        frase = malloc(sizeof(char));
        arregloFrases = malloc(sizeof(char*));
        caracter = fgetc(archivo);

        while(caracter != EOF){

            while(caracter != '\n'){
                frase[indiceLetra] = caracter;
                indiceLetra++;
                frase = realloc(frase,sizeof(char)*(indiceLetra+1));
                caracter = fgetc(archivo);
            }
            frase[indiceLetra] = '\0';

            arregloFrases[indiceArreglo] = frase;

            indiceArreglo++;
            indiceLetra = 0;

            arregloFrases = realloc(arregloFrases,sizeof(char*)*(indiceArreglo+1));
            caracter = fgetc(archivo);

            frase = malloc(sizeof(char));
        }

        frase[0] = '\0';
        arregloFrases[indiceArreglo] = frase;  // Frase de STOP
            
    }
    fclose(archivo);

    *dirArrFrases = arregloFrases;
}

void agregarAlista(t_nodo* nodo, s_indices indices, int nroLinea){
    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->indice = indices;
        (*nodo)->numeroLinea = nroLinea;
        (*nodo)->sig = NULL;
    }
    else{
        agregarAlista(&((*nodo)->sig),indices,nroLinea);
    }
}

t_nodo indices(char* sub){
    t_nodo listaIndices = NULL;
    s_indices actualndice;
    char** arregloFrases = NULL;
    int indiceArregloFrases = 0; // Es el numero de linea

    leerArchivo(&arregloFrases); // Cargo cada linea en el arreglo

    /* Debo buscar ahora en el arreglo de frases, cuantas veces se repite la sub cadena en cada linea */
    
    //actualndice = buscarSub(arregloFrases[indiceArregloFrases],sub); // Busco el actual indice para la primera linea

    while(arregloFrases[indiceArregloFrases][0] != '\0'){ // Si hay mas lineas para leer...
        actualndice = buscarSub(arregloFrases[indiceArregloFrases],sub);
        
        if(actualndice.indiceInicial != -1 && actualndice.indiceFinal != -1){
            agregarAlista(&listaIndices,actualndice,indiceArregloFrases);
        }
        indiceArregloFrases++;
    }
    return listaIndices;
    
}
void imprimirListaIndices(t_nodo lista){
    if(lista != NULL){
        printf("(%d,",lista->numeroLinea);
        printf("%d,",lista->indice.indiceInicial);
        printf("%d)\n",lista->indice.indiceFinal);
        imprimirListaIndices(lista->sig);
    }
}

int main(){
    /*
    s_indices estructuraIndices;
    estructuraIndices = buscarSub("La verdad absoulta no existe, y esto es absolutamente cierto.", "d ab");
    printf("(%d, %d)",estructuraIndices.indiceInicial,estructuraIndices.indiceFinal);
    */
    t_nodo lista = NULL;
    lista = indices("r");
    imprimirListaIndices(lista);
    return 0;

}