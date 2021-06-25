#include <stdio.h>
#include <stdlib.h>
#define N 25
#define CANTIDAD 100

struct s_equipo{
    char nombre[N];
    int partidosGanados;
    int partidosPerdidos;
    int partidosEmpatados;
    int golesFavor;
    int golesContra;
};

typedef struct s_equipo Equipo;

void cargarDatos(Equipo arregloEquipos[CANTIDAD], char nombreItems[], char nombreDatos[]){
    FILE* archivoItems;
    FILE* archivoDatos;
    int indice;
    archivoItems = fopen(nombreItems,"r");
    if (archivoItems == NULL){
        printf("Error al abrir archivo items...");
    }

    archivoDatos = fopen(nombreDatos,"r");
    if (archivoDatos == NULL){
        printf("Error al abrir archivo datos...");
    }
    
    for (indice = 0 ; indice < CANTIDAD && fscanf(archivoItems,"%s\n",arregloEquipos[indice].nombre) != EOF ; indice++){
        fscanf(archivoDatos,"%d,%d,%d,%d,%d\n",&arregloEquipos[indice].partidosGanados,
                                               &arregloEquipos[indice].partidosPerdidos,
                                               &arregloEquipos[indice].partidosEmpatados,
                                               &arregloEquipos[indice].golesFavor,
                                               &arregloEquipos[indice].golesContra          );          // Termina fscanf
    }
    arregloEquipos[indice].nombre[0] = '\0';

    fclose(archivoItems);
    fclose(archivoDatos);
}

void imprimirTabla(Equipo arregloEquipos[CANTIDAD],char nombreCabeceras[]){
    FILE* archivoCabeceras;
    archivoCabeceras = fopen(nombreCabeceras,"r");
    int i, j;
    char cabecera[N];
    int puntos, difGoles, partidosJugados;

    if (archivoCabeceras == NULL){
        printf("Error al abrir archivo cabeceras...");
    }

    else{

        printf("\n");
        for ( i = 0 ; fscanf(archivoCabeceras,"%s",cabecera)!=EOF ; i++ ){
            printf("%-8s",cabecera);
        }
        
        fclose(archivoCabeceras);
        printf("\n");
        printf("--------------------------------------------------------------------");
        printf("\n");
        for (j = 0 ; arregloEquipos[j].nombre[0] != '\0'; j++){

            printf("%-8s",arregloEquipos[j].nombre);

            puntos = (arregloEquipos[j].partidosGanados*3) + arregloEquipos[j].partidosEmpatados;
            printf("%-8d",puntos);

            partidosJugados = arregloEquipos[j].partidosGanados+arregloEquipos[j].partidosEmpatados+arregloEquipos[j].partidosPerdidos;
            printf("%-8d",partidosJugados);

            printf("%-8d",arregloEquipos[j].partidosGanados);
            printf("%-8d",arregloEquipos[j].partidosEmpatados);
            printf("%-8d",arregloEquipos[j].partidosPerdidos);
            printf("%-8d",arregloEquipos[j].golesFavor);
            printf("%-8d",arregloEquipos[j].golesContra);

            difGoles = arregloEquipos[j].golesFavor - arregloEquipos[j].golesContra;
            printf("%-8d",difGoles);

            printf("\n");
        }

    }
}


int main(){
    Equipo arregloEquipos[CANTIDAD];
    cargarDatos(arregloEquipos,"items.txt","datos.txt");
    imprimirTabla(arregloEquipos,"cabeceras.txt");


    return 0;
}