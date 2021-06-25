#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TERMINA_CADENA '\0'
#define FILAS 20
#define COLUMNAS 20

void intercambiarArreglosInt(int arreglo1[COLUMNAS], int arreglo2[COLUMNAS]){
    int i;
    int aux;

    for(i=0; i<COLUMNAS ; i++){
            aux = arreglo1[i];
            arreglo1[i] = arreglo2[i];
            arreglo2[i] = aux;
    }
}

void cargarMatTextArch(char matriz[FILAS][COLUMNAS],char nombre_archivo[]){

    int f, c;
    char carac;
    FILE* archivo = fopen(nombre_archivo,"r");
    
    if (archivo == NULL){
        printf("Error al abrir el achivo");
    }
    else{

        carac = fgetc(archivo);
        for (f = 0 ; f < FILAS && carac != EOF ; f++ ){
            for ( c = 0  ; c< COLUMNAS && carac != EOF && carac != '\n' ; c++){
                matriz[f][c] = carac;
                carac = fgetc(archivo);
            }

            matriz[f][c] = TERMINA_CADENA;
            carac = fgetc(archivo);
        }

        matriz[f][0] = TERMINA_CADENA;
    }
    fclose(archivo);
}

void cargarMatNumArch(int matriz[FILAS][COLUMNAS], char nombre_archivo[]){
    int f,c;
    FILE* archivo = fopen(nombre_archivo,"r");
    if (archivo == NULL){
        printf("Error al abrir el archivo.");
    }
    else{
        for(f = 0 ; fscanf(archivo,"%d,%d,%d,%d,%d,%d,%d,%d\n",&matriz[f][0],&matriz[f][1],&matriz[f][2],&matriz[f][3],&matriz[f][4],&matriz[f][5],&matriz[f][6],&matriz[f][7]) != EOF && f < FILAS ; f++){    
        }
        matriz[f][0] = EOF;
    }
    fclose(archivo);
}

void imprimirTabla(int datos[FILAS][COLUMNAS], char cabecera[FILAS][COLUMNAS], char items[FILAS][COLUMNAS], int fil, int col){
    int x;
    int y;

    printf("\n");

    //Imprimimos las cabeceras
    for(y=0; y<col+1; y++){                     // Por cada fila de la matriz, es una columna de la tabla
            printf("%-8s",cabecera[y]);
    }

    printf("\n");

    for(y=0; y<col+1; y++){
        if(y==0){
            printf("----------");
        }
        else{
            printf("--------");
        }

    }

    printf("\n");

    //Imprimimos los items a medida que pasan los datos
    for(y=0; y<fil; y++){
        printf("%-8s",items[y]);
        for(x=0; x<col; x++){
            if( datos[y][x] > 0 && x == 7 ){
                    printf("+%-7d",datos[y][x]);
            }
            else{
                printf("%-8d",datos[y][x]);
            }
        }
        printf("\n");

    }
}

void ordenarTabla(char items[FILAS][COLUMNAS], int datos[FILAS][COLUMNAS],int criterio){
    int i,j;
    char aux[COLUMNAS] = {0};
    if (criterio == 1){
        for ( i = 0 ; items[i][0] != TERMINA_CADENA ; i++){
            for ( j = 0 ; items[j][0] != TERMINA_CADENA ; j++){
                if (strcmp(items[j],items[i]) < 0){
                    strcpy(aux,items[i]);
                    strcpy(items[i],items[j]);
                    strcpy(items[j],aux);
                    intercambiarArreglosInt(datos[j],datos[i]);
                }
            }
        }

    }
    else{
        for ( i = 0 ; items[i][0] != TERMINA_CADENA ; i++){
            for ( j = 0 ; items[j][0] != TERMINA_CADENA ; j++){
                if (strcmp(items[j],items[i]) > 0){
                    strcpy(aux,items[i]);
                    strcpy(items[i],items[j]);
                    strcpy(items[j],aux);
                    intercambiarArreglosInt(datos[j],datos[i]);
                }
            }
        }
    }
}

int main(){
                                                                            // formato --->> [FILAS] [COLUMNAS]
    char items[FILAS][COLUMNAS] = {0};     // ----> items.txt
    char cabecera[FILAS][COLUMNAS] = {0};    // ----> cabeceras.txt
    int datos[FILAS][COLUMNAS] = {0};        // ----> datos.txt (los puntajes)
    int criterio;

    cargarMatTextArch(cabecera,"cabeceras.txt");
    cargarMatTextArch(items,"items.txt");
    cargarMatNumArch(datos,"datos.txt");

    printf("Ordenar ascendente (0) o descendente (1): ");
    scanf("%d",&criterio);

    ordenarTabla(items,datos,criterio);
    imprimirTabla(datos,cabecera,items,5,8);

    return 0;
}