#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct s_habitantes{
    int ID_habitante;
    char nombre[60];
    char sexo;
    int edad;
    int ID_localidad;
};
typedef struct s_habitantes s_habitante;

struct s_localidades{
    int ID_localidad;
    char nombre_localidad[60];
};
typedef struct s_localidades s_localidad;


struct s_csv{
    int ID_localidad;
    int ID_habitante;
};
typedef struct s_csv s_archCSV;

void cargarLocalidades(s_localidad** dirArrLocalidades){
    FILE* archivo = fopen("localidades.txt","r");
    s_localidad* arrAux = NULL;
    int indArreglo = 0, indLetra = 0;
    char caracterLeido;

    if(archivo != NULL){
        arrAux = malloc(sizeof(struct s_localidades));

        while(fscanf(archivo,"%d,",&(arrAux[indArreglo].ID_localidad)) != EOF){
            caracterLeido = fgetc(archivo);

            while(caracterLeido != '\n'){
                arrAux[indArreglo].nombre_localidad[indLetra] = caracterLeido;
                indLetra++;
                caracterLeido = fgetc(archivo);
            }
            arrAux[indArreglo].nombre_localidad[indLetra] = '\0';
            indLetra = 0;
            indArreglo++;
            arrAux = realloc(arrAux, sizeof(struct s_localidades)*(indArreglo+1));
        }

    }
    fclose(archivo);
    arrAux[indArreglo].ID_localidad = 0;
    (*dirArrLocalidades) = arrAux;
}

void cargarCsv(s_archCSV** dirArregloCsv){
    FILE* archivo = fopen("habitantesXlocalidad.txt","r");
    s_archCSV* arrAux = NULL;
    int indArr = 0;
    if(archivo != NULL){
        arrAux = malloc(sizeof(struct s_csv));
        while(fscanf(archivo,"%d,%d\n",&(arrAux[indArr].ID_localidad),&(arrAux[indArr].ID_habitante)) != EOF){
            indArr++;
            arrAux = realloc(arrAux, sizeof(struct s_csv)*(indArr+1));
        }
        arrAux[indArr].ID_localidad = 0;
    }
    (*dirArregloCsv) = arrAux;
    fclose(archivo);
    
}

int obtenerIDLocalidadPorHab(int ID_habitante){
    s_archCSV* arrCsv = NULL;
    cargarCsv(&arrCsv);
    int indCSV = 0;
    int ID_localidad = 0;
    while(arrCsv[indCSV].ID_localidad != 0){
        if(arrCsv[indCSV].ID_habitante == ID_habitante){
            ID_localidad = arrCsv[indCSV].ID_localidad;
        }
        indCSV++;
    }

    free(arrCsv);
    return ID_localidad;
}

void cargarHabitantes(s_habitante** dirArrHabitantes){
    s_habitante* arrAux = NULL;
    FILE* archivo = fopen("habitantes.dat","rb");
    int indArr = 0;

    if(archivo != NULL){

        while(fread(&(arrAux[indArr].ID_habitante), sizeof(int),1,archivo) != 0){
            fread(&(arrAux[indArr].nombre),sizeof(char)*60,1,archivo);
            fread(&(arrAux[indArr].sexo),sizeof(char),1,archivo);
            fread(&(arrAux[indArr].edad),sizeof(int),1,archivo);

            arrAux[indArr].ID_localidad = obtenerIDLocalidadPorHab(arrAux[indArr].ID_habitante);
            indArr++;
            arrAux = realloc(arrAux, sizeof(struct s_habitantes)*(indArr+1));
        }
        arrAux[indArr].ID_habitante = 0;
    
    }
    fclose(archivo);
    (*dirArrHabitantes) = arrAux;
}

int habitanEnLocalidad(char* localidad, char sexo){
    s_habitante* arregloHabitantes; // Arreglo de estructura localidad
    s_localidad* arregloLocalidades;

    cargarLocalidades(&arregloLocalidades);
    

    cargarHabitantes(&arregloHabitantes);

    /* Necesito ID localidad por char localidad */
    




}



int main(){
    char* localidad = "San Justo";
    char sexo = 'F';
    printf("En %s habitan: %d", localidad, habitanEnLocalidad(localidad,sexo));
    return 0;
}