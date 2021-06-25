#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
#define DATOS 10

struct s_persona{
    int dni;
    char nombre[MAX];
    char pais[MAX];
};
typedef struct s_persona Persona;

void importarAEstructura(Persona arregloPersonas[DATOS]){
    FILE* archivo = fopen("personas.txt","r");
    int i = 0,r,letra;
    int n_dni;
    char c;
    if (archivo == NULL){
        printf("Error al abrir el archivo");
    }
    else{
        r = fscanf(archivo,"%d",&n_dni);
        while(r != EOF){
            arregloPersonas[i].dni = n_dni;
            int letra = 0;
            char arrNombre[MAX] = {0};
            char arrPais[MAX] = {0};
            c = fgetc(archivo);

            if(c == ','){
                c = fgetc(archivo);
            }

            while(c!=','){
                arrNombre[letra] = c;
                letra++;
                c = fgetc(archivo);
            }
            strcpy(arregloPersonas[i].nombre,arrNombre);
            c = fgetc(archivo);
            letra = 0;
            while(c != '\n'){
                arrPais[letra] = c;
                letra++;
                c = fgetc(archivo);
            }
            strcpy(arregloPersonas[i].pais,arrPais);
            i++;
            r = fscanf(archivo,"%d",&n_dni);

        }
        arregloPersonas[i].dni = EOF;
    }
    fclose(archivo);
}

void imprimirTabla(){
    Persona arregloPersonas[DATOS];
    int i;
    importarAEstructura(arregloPersonas);

    // CABECERAS
    printf("%-20s","Documento");
    printf("%-20s","Nombre");
    printf("%-20s","Pais");
    printf("\n");
    for(i=0;i<60;i++){
        printf("=");
    }
    printf("\n");
    for(i = 0 ; arregloPersonas[i].dni != EOF ; i++){
        printf("%-20d",arregloPersonas[i].dni);
        printf("%-20s",arregloPersonas[i].nombre);
        printf("%-20s",arregloPersonas[i].pais);
        printf("\n");
    }
}




int main(){
    imprimirTabla();
    return 0;
}