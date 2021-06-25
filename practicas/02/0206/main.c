#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
#define DATOS 10
/* ------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                      FUNCION STRING COMPARE PROPIA                               */
/* ------------------------------------------------------------------------------------------------------------------------------------------------- */
int stringCompare(char str1[MAX], char str2[MAX]){
    int valor_final = 0;
    int i;
    
    for (i = 0 ; str1[i] != '\0' && str2 != '\0' && str1[i]==str2[i] ; i++){}  // Recorre hasta que encuentre letras diferentes, si no, son iguales.

    if(str1[i]!=str2[i]){

        if(str1[i] < str2[i]){  
            valor_final = -1;
        }

        else{
            valor_final = 1;
        }

    }
    return valor_final;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                      FUNCION STRING COPY PROPIA                                  */
/* ------------------------------------------------------------------------------------------------------------------------------------------------- */
void stringCopy(char dest[MAX], char src[MAX]){
    int i,j;

    for(i = 0 , j = i+1 ; src[i] != '\0' ; i++ , j++){  
        dest[i] = src[i];
        dest[j] = '\0';
    }
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------- */

struct s_persona{   // Creamos una estructura para una persona
    int dni;
    char nombre[MAX];
    char pais[MAX];
};
typedef struct s_persona Persona;   // El nombre de la estructura ahora es "Persona"


void archivoToArreglo(Persona arregloPersona[DATOS]){
    int indicePersona = 0,r;
    int indiceLetra;
    int numeroDNI;
    char c;
    FILE* archivo = fopen("personas.txt","r");
    if (archivo == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO");
    }
    else{
        r = fscanf(archivo,"%d",&numeroDNI);
        while(r!=EOF){

            arregloPersona[indicePersona].dni = numeroDNI;

            indiceLetra = 0;
            char arregloNombre[MAX] = {0};
            char arregloPais[MAX] = {0};

            c = fgetc(archivo);
            if (c == ','){
                c = fgetc(archivo);
            }

            while (c != ','){
                arregloNombre[indiceLetra]=c;
                indiceLetra++;
                c = fgetc(archivo);
            }
            stringCopy(arregloPersona[indicePersona].nombre,arregloNombre);

            c = fgetc(archivo);
            indiceLetra = 0;
            while(c!='\n'){
                arregloPais[indiceLetra] = c;
                indiceLetra++;
                c = fgetc(archivo);
            }
            stringCopy(arregloPersona[indicePersona].pais,arregloPais);

            indicePersona++;
            r = fscanf(archivo,"%d",&numeroDNI);

        }
        arregloPersona[indicePersona].dni = EOF;
    }
    fclose(archivo);
}

void ordenarPorNombre(Persona arregloPersona[DATOS]){
    int i,j;
    int auxDNI;
    char auxPersona[MAX] = {0};

    for(i = 0 ; arregloPersona[i].dni != EOF; i++){

        for(j = i ; arregloPersona[j].dni != EOF; j++){

            if (stringCompare(arregloPersona[j].nombre,arregloPersona[i].nombre) < 0){  // giovanni > agustin

                auxDNI = arregloPersona[i].dni;
                arregloPersona[i].dni = arregloPersona[j].dni;
                arregloPersona[j].dni = auxDNI;

                stringCopy(auxPersona,arregloPersona[i].nombre);
                stringCopy(arregloPersona[i].nombre,arregloPersona[j].nombre);
                stringCopy(arregloPersona[j].nombre,auxPersona);

                stringCopy(auxPersona,arregloPersona[i].pais);
                stringCopy(arregloPersona[i].pais,arregloPersona[j].pais);
                stringCopy(arregloPersona[j].pais,auxPersona);

            }
        }
    }
}

void ordenarPorPais(Persona arregloPersona[MAX]){
    int i,j;
    int auxDNI;
    char auxPersona[MAX] = {0};

    for(i = 0 ; arregloPersona[i].dni != EOF; i++){

        for(j = i ; arregloPersona[j].dni != EOF; j++){

            if (stringCompare(arregloPersona[j].pais,arregloPersona[i].pais) < 0){  // giovanni > agustin

                auxDNI = arregloPersona[i].dni;
                arregloPersona[i].dni = arregloPersona[j].dni;
                arregloPersona[j].dni = auxDNI;

                stringCopy(auxPersona,arregloPersona[i].nombre);
                stringCopy(arregloPersona[i].nombre,arregloPersona[j].nombre);
                stringCopy(arregloPersona[j].nombre,auxPersona);

                stringCopy(auxPersona,arregloPersona[i].pais);
                stringCopy(arregloPersona[i].pais,arregloPersona[j].pais);
                stringCopy(arregloPersona[j].pais,auxPersona);

            }
        }
    }
}

void ordenarPorDni(Persona arregloPersona[MAX]){
    int i,j;
    int auxDNI;
    char auxPersona[MAX] = {0};

    for(i = 0 ; arregloPersona[i].dni != EOF; i++){

        for(j = i ; arregloPersona[j].dni != EOF; j++){

            if (arregloPersona[j].dni < arregloPersona[i].dni){  // giovanni > agustin

                auxDNI = arregloPersona[i].dni;
                arregloPersona[i].dni = arregloPersona[j].dni;
                arregloPersona[j].dni = auxDNI;

                stringCopy(auxPersona,arregloPersona[i].nombre);
                stringCopy(arregloPersona[i].nombre,arregloPersona[j].nombre);
                stringCopy(arregloPersona[j].nombre,auxPersona);

                stringCopy(auxPersona,arregloPersona[i].pais);
                stringCopy(arregloPersona[i].pais,arregloPersona[j].pais);
                stringCopy(arregloPersona[j].pais,auxPersona);

            }
        }
    }

}

void imprimirTabla(Persona arregloPersona[DATOS]){
    int i;
    printf("%-20s","Documento");
    printf("%-20s","Nombre");
    printf("%-20s","Pais");
    printf("\n");
    for(i=0;i<50;i++){
        printf("=");
    }
    printf("\n");
    for(i=0 ; arregloPersona[i].dni != EOF ; i++){
        printf("%-20d",arregloPersona[i].dni);
        printf("%-20s",arregloPersona[i].nombre);
        printf("%-20s",arregloPersona[i].pais);
        printf("\n");
    }
    printf("\n");
}

int main(){
    int opcion;
    Persona arregloPersona[DATOS];
    archivoToArreglo(arregloPersona);
    printf("\n==============================================\n");
    printf("ELIJA LA OPCION");
    printf("\n");
    printf("Pulse |1| para ver listado por nombre");
    printf("\n");
    printf("Pulse |2| para ver listado por documento");
    printf("\n");
    printf("Pulse |3| para ver listado por pais");
    printf("\n");
    printf("Pulse |4| para salir");
    printf("\n");
    printf("===============================================\n");
    printf("\n");
    scanf("%d",&opcion);


    if(opcion == 1){
        ordenarPorNombre(arregloPersona);
        imprimirTabla(arregloPersona);
    }
    else if(opcion == 2){
        ordenarPorDni(arregloPersona);
        imprimirTabla(arregloPersona);
    }
    else if(opcion == 3){
        ordenarPorPais(arregloPersona);
        imprimirTabla(arregloPersona);
    }

    return 0;
}