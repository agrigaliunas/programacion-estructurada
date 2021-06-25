#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_comisiones{
    int nro_registro;
    char* nombre;
    char* apellido;
} typedef comision;

comision crearAlumnoParada(){
    comision alumnoParada;
    alumnoParada.nro_registro = -1;
    alumnoParada.nombre = "";
    alumnoParada.apellido = "";
    return alumnoParada;
}

void leerArchivo(comision** dirArrComision, char* nomArchivo){
    FILE* archivo = fopen(nomArchivo,"r");

    comision alumnoNuevo;
    comision alumnoParada = crearAlumnoParada();
    comision* arrAux = NULL;
    char caracter = 0;
    int indArreglo = 0; 
    int indLetra = 0;

    if(archivo != NULL){
        arrAux = malloc(sizeof(comision));

        while(fscanf(archivo,"%d,",&(alumnoNuevo.nro_registro)) != EOF){

            indLetra = 0;
            alumnoNuevo.nombre = malloc(sizeof(char));
            caracter = fgetc(archivo);

            while(caracter != ','){
                *(alumnoNuevo.nombre + indLetra) = caracter;
                indLetra++;
                alumnoNuevo.nombre = realloc(alumnoNuevo.nombre, sizeof(char)*(indLetra+1));
                caracter = fgetc(archivo);
            }
            *(alumnoNuevo.nombre + indLetra) = '\0';

            indLetra = 0;

            alumnoNuevo.apellido = malloc(sizeof(char));
            caracter = fgetc(archivo);
            
            while(caracter != '\n'){
                *(alumnoNuevo.apellido+indLetra) = caracter;
                indLetra++;
                alumnoNuevo.apellido = realloc(alumnoNuevo.apellido, sizeof(char)*(indLetra+1));
                caracter = fgetc(archivo);
            }
            *(alumnoNuevo.apellido+indLetra) = '\0';

            *(arrAux + indArreglo) = alumnoNuevo;
            indArreglo++;

            arrAux = realloc(arrAux, sizeof(comision)*(indArreglo+1));
            
        }

        *(arrAux+indArreglo) = alumnoParada;
    }

    fclose(archivo);

    *dirArrComision = arrAux;    
}

int estaEnArreglo(comision alumno, comision* arregloAlumnos){
    int esta = 0;
    int i = 0;
    while(arregloAlumnos[i].nro_registro != -1){
        if(alumno.nro_registro == arregloAlumnos[i].nro_registro){
            esta = 1;
        }
        i++;
    }
    return esta;
}

void unirArreglos(comision** dirArrComisiones, comision* arrComisionAM, comision* arrComisionBM){
    comision* arrAux = malloc(sizeof(comision));
    comision alumnoParada = crearAlumnoParada();
    int indiceArr = 0;
    int indiceUnion = 0;

    arrAux[0] = alumnoParada;

    while(arrComisionAM[indiceArr].nro_registro != alumnoParada.nro_registro){
        if(estaEnArreglo(arrComisionAM[indiceArr],arrAux) == 0){
            arrAux[indiceUnion] = arrComisionAM[indiceArr];
            indiceUnion++;
            arrAux = realloc(arrAux,sizeof(comision)*(indiceUnion+1));
            arrAux[indiceUnion] = alumnoParada;
        }
        indiceArr++;
    }

    indiceArr = 0;

    while(arrComisionBM[indiceArr].nro_registro != alumnoParada.nro_registro){
        if(estaEnArreglo(arrComisionBM[indiceArr],arrAux) == 0){
            arrAux[indiceUnion] = arrComisionBM[indiceArr];
            indiceUnion++;
            arrAux = realloc(arrAux,sizeof(comision)*(indiceUnion+1));
            arrAux[indiceUnion] = alumnoParada;
        }
        indiceArr++;
    }

    *dirArrComisiones = arrAux;

}

void crearArchivo(comision* arrAlumnos){
    FILE* archivo = fopen("comisiones.csv","w");
    int i = 0;

    while(arrAlumnos[i].nro_registro != -1){
        fprintf(archivo,"%d,%s,%s\n",arrAlumnos[i].nro_registro,arrAlumnos[i].nombre,arrAlumnos[i].apellido);
        i++;
    }
    fclose(archivo);

}

/*
void ordenarArrRegistro(comision** arrAlumnos){  
    comision aux;
    int i = 0;
    int j = 0;

    for(i = 0 ; (*arrAlumnos+i)->nro_registro != -1 ; i++){

        for(j = i ; (*arrAlumnos+j)->nro_registro != -1 ; j++){

            if( (*arrAlumnos+i)->nro_registro < (*arrAlumnos+j)->nro_registro ){

                aux = *(*arrAlumnos+i);
                *(*arrAlumnos+i) = *(*arrAlumnos+j);
                *(*arrAlumnos+j) = aux;

            }
        }
    }

}

/* 

void ordenar(t_per** per){
    int i=0,j=0;
    t_per aux;
    for(i=0;(*per+i)!=NULL;i++){
        for(j=i+1;(*per+j)!=NULL;j++){
            if((*per+i)->dni<(*per+j)->dni){
                aux=*(*per+i);
                *(*per+i)=*(*per+j);
                *(*per+j)=aux;
            }
        }
    }
}


/*

void unificar(char* nomArchivoAM, char* nomArchivoBM){
    comision* arrComisionAM = NULL;
    comision* arrComisionBM = NULL;
    comision* arrComisiones = NULL;

    leerArchivo(&arrComisionAM, nomArchivoAM);
    leerArchivo(&arrComisionBM, nomArchivoBM);

    unirArreglos(&arrComisiones, arrComisionAM, arrComisionBM);

    int i = 0;

    for(i = 0 ; arrComisiones[i].nro_registro != -1 ; i++){
        printf("%d\n",arrComisiones[i].nro_registro);
    }


    ordenarArrRegistro(&arrComisiones);
    //crearArchivo(arrComisiones);

    printf("\n\n");
    for(i = 0 ; arrComisiones[i].nro_registro != -1 ; i++){
        printf("%d\n",arrComisiones[i].nro_registro);
    }
  
}

*/


void ordenarArrRegistro(comision* arrAlumnos){
    comision alumnoAux;
    int i = 0;
    int j = 0;

    for(i = 0 ; arrAlumnos[i].nro_registro != -1 ; i++){
        for(j = i ; arrAlumnos[j].nro_registro != -1 ; j++){
            if(arrAlumnos[j].nro_registro < arrAlumnos[i].nro_registro){
                alumnoAux = arrAlumnos[i];
                arrAlumnos[i] = arrAlumnos[j];
                arrAlumnos[j] = alumnoAux;
            }
        }
    }
}

void unificar(char* nomArchivoAM, char* nomArchivoBM){
    comision* arrComisionAM = NULL;
    comision* arrComisionBM = NULL;
    comision* arrComisiones = NULL;

    leerArchivo(&arrComisionAM, nomArchivoAM);
    leerArchivo(&arrComisionBM, nomArchivoBM);

    unirArreglos(&arrComisiones, arrComisionAM, arrComisionBM);


    ordenarArrRegistro(arrComisiones);
    crearArchivo(arrComisiones);
    
}


int main(){
    unificar("comisionAM.csv","comisionBM.csv");

    return 0;
}