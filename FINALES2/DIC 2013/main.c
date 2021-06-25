#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_habitantes{
    int ID_habitante;
    char nombre[60];
    char sexo;
    int edad;
};
typedef struct s_habitantes s_habitante;

struct s_localidades{
    int ID_localidad;
    char nombreLocalidad[60];
};
typedef struct s_localidades s_localidad;

struct s_habXloc{
    int ID_localidad;
    int ID_habitante;
};
typedef struct s_habXloc s_habXloc;

void cargarLocalidades(s_localidad** dirArrLocalidades){
    s_localidad* arrAux = NULL;
    FILE* archivo = fopen("localidades.txt","r");
    int indiceArr = 0;
    int indiceLetra = 0;
    char caracterLeido;

    if(archivo != NULL){
        arrAux = malloc(sizeof(struct s_localidades));

        while(fscanf(archivo,"%d,",&(arrAux[indiceArr].ID_localidad)) != EOF){
            caracterLeido = fgetc(archivo);

            while(caracterLeido != '\n'){
                arrAux[indiceArr].nombreLocalidad[indiceLetra] = caracterLeido;
                indiceLetra++;
                caracterLeido = fgetc(archivo);
            }
            arrAux[indiceArr].nombreLocalidad[indiceLetra] = '\0';
            indiceLetra = 0;
            indiceArr++;
            arrAux = realloc(arrAux, sizeof(struct s_localidades)*(indiceArr+1));
        }
        
    }

    fclose(archivo);

    arrAux[indiceArr].ID_localidad = 0;

    (*dirArrLocalidades) = arrAux;
}

void cargarHabitantes(s_habitante** dirArrHabitantes){
    FILE* archivo = fopen("habitantes.dat","rb");
    s_habitante* arrAux = NULL;
    int indicieArr = 0;

    if(archivo != NULL){
        arrAux = malloc(sizeof(struct s_habitantes));

        while(fread(&(arrAux[indicieArr].ID_habitante) ,sizeof(int),1,archivo) != 0){
            fread(&(arrAux[indicieArr].nombre) ,sizeof(char)*60,1,archivo);
            fread(&(arrAux[indicieArr].sexo) ,sizeof(char),1,archivo);
            fread(&(arrAux[indicieArr].edad) ,sizeof(int),1,archivo);
            indicieArr++;
            arrAux = realloc(arrAux, sizeof(struct s_habitantes)*(indicieArr+1));
        }
        arrAux[indicieArr].ID_habitante = 0;
    }
    fclose(archivo);

    *dirArrHabitantes = arrAux;
}

void cargarHabitantesXlocalidad(s_habXloc** dirArrHabXloc){
    s_habXloc* arrAux = NULL;
    FILE* archivo = fopen("habitantesXlocalidad.txt","r");
    int indiceArr = 0;

    if(archivo != NULL){
        arrAux = malloc(sizeof(struct s_habXloc));

        while(fscanf(archivo,"%d,%d\n",&(arrAux[indiceArr].ID_localidad),&(arrAux[indiceArr].ID_habitante)) != EOF){
            indiceArr++;
            arrAux = realloc(arrAux, sizeof(struct s_habXloc)*(indiceArr+1));
        }
        arrAux[indiceArr].ID_habitante = 0;
    }
    fclose(archivo);
    *dirArrHabXloc = arrAux;
}

int obtenerIDlocalidad(char* localidad, s_localidad* localidades){
    int indiceLocalidad = 0;
    int ID_localidad = 0;
    while(localidades[indiceLocalidad].ID_localidad != 0){
        if(strcmp(localidad,localidades[indiceLocalidad].nombreLocalidad) == 0){
            ID_localidad = localidades[indiceLocalidad].ID_localidad;
        }
        indiceLocalidad++;
    }
    return ID_localidad;
}

void obtenerHabitantesDeLocalidad(int** dirArrHabitanLocalidad, s_habXloc* arrHabXLoc, int ID_localidad){
    int* arrAux = NULL;
    int indiceArr = 0;
    int indiceArrAux = 0;

    arrAux = malloc(sizeof(int));

    while(arrHabXLoc[indiceArr].ID_habitante != 0){
        if(ID_localidad == arrHabXLoc[indiceArr].ID_localidad){
            arrAux[indiceArrAux] = arrHabXLoc[indiceArr].ID_habitante;
            indiceArrAux++;
            arrAux = realloc(arrAux, sizeof(int)*(indiceArrAux+1));
            arrAux[indiceArrAux] = 0;
           
        }
        indiceArr++;
    }
    *dirArrHabitanLocalidad = arrAux;
}

int obtenerCantidadSexo(int* arregloIDEnLocalidad, s_habitante* arregloHabitantes, char sexo){
    int cantidad = 0;
    int i = 0; // Para arreglo habitantes
    int j = 0; // Para arreglo con ID de habitantes

    /* puede haber habitantes que tengan habiten pero no sean de SEXO, entonces omito.. */
    
    while(arregloHabitantes[i].ID_habitante != 0 && arregloIDEnLocalidad[j] != 0){

        while(arregloHabitantes[i].ID_habitante != arregloIDEnLocalidad[j]){
            i++;
        }
        if(sexo == arregloHabitantes[i].sexo){
            cantidad++;
            i++;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    
    return cantidad;
}

void ordenarPorID(int* arr){
    int aux;
    for(int i = 0 ; arr[i] != 0 ; i++){
        for(int j = i ; arr[j] != 0 ; j++){
            if(arr[i] > arr[j]){
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

int cantidadPersonas(char* localidad, char sexo){
    int cant = 0;
    int i = 0;
    s_localidad* arrLocalidades = NULL;
    s_habitante* arrHabitantes = NULL;
    s_habXloc* arrHabXloc = NULL;
    
    cargarLocalidades(&arrLocalidades);
    cargarHabitantes(&arrHabitantes);
    cargarHabitantesXlocalidad(&arrHabXloc);
    int ID_localidad = obtenerIDlocalidad(localidad, arrLocalidades);
    
    int* arrIDEnLocalidad = NULL;  // Aca estaran los habitantes (ID_habitante) para X ID_localidad

    obtenerHabitantesDeLocalidad(&arrIDEnLocalidad, arrHabXloc, ID_localidad);

    ordenarPorID(arrIDEnLocalidad);

    cant = obtenerCantidadSexo(arrIDEnLocalidad, arrHabitantes, sexo);
    free(arrHabitantes); free(arrHabXloc); free(arrLocalidades); free(arrIDEnLocalidad);
    return cant;
}

void obtenerLocalidadLongeva(char localidadMasLongeva[60]){
    s_localidad* arrLocalidades = NULL;
    s_habitante* arrHabitantes = NULL;
    s_habXloc* arrHabXloc = NULL;
    cargarLocalidades(&arrLocalidades);
    cargarHabitantes(&arrHabitantes);
    cargarHabitantesXlocalidad(&arrHabXloc);

    int indiceArr = 0; 
    int suma = 0, prom = 0;

    /* deberia tomar el id de habitante, de la localidad con mayor promedio de edad */
    
    while(arrHabitantes[indiceArr].ID_habitante != 0){
        suma+= arrHabitantes[indiceArr].edad;
        indiceArr++;
    }


    /* No esta termianda, ya que en la s_habitantes deberia estar el ID localidad, pero no lo puse */

}

int main(){
    char* localidad = "San Justo";
    char sexo = 'F';
    int cantidadQueHabitan = cantidadPersonas(localidad,sexo);
    printf("Para %s, siendo %c, habitan: %d personas",localidad,sexo,cantidadQueHabitan);
    char localidadMasLongeva[60] = {0};
    obtenerLocalidadLongeva(localidadMasLongeva);

    return 0;
}