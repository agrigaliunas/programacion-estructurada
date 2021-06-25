#include <stdio.h>
#include <stdlib.h>

struct s_alumnos{
    int nro_registro;
    char* nombre;  // Tener en cuenta que son DINAMICOS
    char* apellido; // IDEM
};
typedef struct s_alumnos s_alumno;

s_alumno crearAlumnoStop(){
    s_alumno alumnoStop;
    alumnoStop.nro_registro = 0;
    alumnoStop.nombre = NULL;
    alumnoStop.apellido = NULL;
    return alumnoStop;
}

void leerArchivo(char* nomArchivo, s_alumno** dirArrAlumnos){
    FILE* archivo = fopen(nomArchivo, "r");
    // Puedo poner todos los alumnos en un array, e ir fijandome si ese alumno ya esta en ese arreglo.
    s_alumno alumnoStop = crearAlumnoStop(); // Creamos el alumno que determina el fin del arreglo de alumnos
    s_alumno* arregloAlumnos = NULL; // Creamos el arreglo de alumnos
    s_alumno nuevoAlumno; // Un alumno nuevo
    int indiceAlumno = 0; // Determina el indice de cada alumno en el array
    int indiceLetra = 0; // Determina el indice de cada letra 
    char caracter = 0; // Letras que son tomadas del archivo

    if(archivo != NULL){ // Compruebo que el archivo no este vacio
        arregloAlumnos = malloc(sizeof(s_alumno)); // Asigno el espacio para un alumno en el array
        
        while(fscanf(archivo,"%d,",&(nuevoAlumno.nro_registro)) != EOF){    // Tomo el valor de nro_registro y tambien compruebo que no sea EOF
            indiceLetra = 0;
            nuevoAlumno.nombre = malloc(sizeof(char)); // Le doy espacio de UN CHAR al nombre (es dinamico el array de char)
            caracter = fgetc(archivo);

            while(caracter != ','){
                *(nuevoAlumno.nombre + indiceLetra) = caracter; // Le sumo al nombre el caracter leido del archivo
                indiceLetra++;
                nuevoAlumno.nombre = realloc(nuevoAlumno.nombre, sizeof(char) * (indiceLetra+1)); // Le sumo otro byte de char para tener espacio
                caracter = fgetc(archivo);
            }
            *(nuevoAlumno.nombre + indiceLetra) = '\0';


            indiceLetra = 0;  // Se restaura el indice de letras

            /* Se repite estructura anterior, pero para apellido */
            nuevoAlumno.apellido = malloc(sizeof(char)); // Asigno espacio de un CHAR al apellido
            caracter = fgetc(archivo);

            while(caracter != '\n'){
                *(nuevoAlumno.apellido + indiceLetra) = caracter;
                indiceLetra++;
                nuevoAlumno.apellido = realloc(nuevoAlumno.apellido, sizeof(char) * (indiceLetra+1));
                caracter = fgetc(archivo);
            }
            *(nuevoAlumno.apellido + indiceLetra) = '\0';


            *(arregloAlumnos + indiceAlumno) = nuevoAlumno; // Agrego el alumno al array
            indiceAlumno++; // Paso al siguiente espacio en el array (NULL)
            arregloAlumnos = realloc(arregloAlumnos, sizeof(s_alumno) * (indiceAlumno+1)); // Le doy espacio al arreglo para añadir otro alumno
        }

        *(arregloAlumnos + indiceAlumno) = alumnoStop; // Termino el array con el alumno NULL     
        fclose(archivo);
    }

    
    (*dirArrAlumnos) = arregloAlumnos; // Paso los datos del arreglo creado al pasado por parametro
    
}

int estaEnArreglo(s_alumno* arregloUnion, s_alumno alumno){
    int i = 0;
    int esta = 0;
    s_alumno alumnoStop = crearAlumnoStop();
    while(arregloUnion[i].nro_registro != alumnoStop.nro_registro){
        if(alumno.nro_registro == arregloUnion[i].nro_registro){
            esta = 1;  
        }
        i++;
    }
    return esta;
}

void unirArreglos(s_alumno** unificados, s_alumno* comision_AM, s_alumno* comision_BM){
    s_alumno* arregloUnion = malloc(sizeof(s_alumno));
    s_alumno alumnoStop = crearAlumnoStop();
    int indAlumno = 0;
    int indArregloUnion = 0;

    arregloUnion[0] = alumnoStop;

    while(comision_AM[indAlumno].nro_registro != alumnoStop.nro_registro){  // Mientras que el alumno de AM no sea stop
        if(estaEnArreglo(arregloUnion, comision_AM[indAlumno]) == 0){ // Si alumno no esta en el arreglo de union, lo agrego
            arregloUnion[indArregloUnion] = comision_AM[indAlumno]; // Agrego al alumno al arreglo final
            indArregloUnion++;
            arregloUnion = realloc(arregloUnion, sizeof(s_alumno) * (indArregloUnion+1));
            arregloUnion[indArregloUnion] = alumnoStop;
        }
        indAlumno++;
    }

    indAlumno = 0;

    while(comision_BM[indAlumno].nro_registro != alumnoStop.nro_registro){  // Mientras que el alumno de BM no sea stop
        if(estaEnArreglo(arregloUnion, comision_BM[indAlumno]) == 0){ // Si alumno no esta en el arreglo de union, lo agrego
            arregloUnion[indArregloUnion] = comision_BM[indAlumno]; // Agrego al alumno al arreglo final
            indArregloUnion++;
            arregloUnion = realloc(arregloUnion, sizeof(s_alumno) * (indArregloUnion+1));
            arregloUnion[indArregloUnion] = alumnoStop;
        }
        indAlumno++;
    }
    (*unificados) = arregloUnion;

}

void ordenarArreglo(s_alumno* arregloAlumnos){
    int i = 0, j = 0;
    s_alumno alumnoAux;
    s_alumno alumnoStop = crearAlumnoStop();

    for(i = 0 ; arregloAlumnos[i].nro_registro != alumnoStop.nro_registro ; i++){

        for(j = i ; arregloAlumnos[j].nro_registro != alumnoStop.nro_registro ; j++){

            if(arregloAlumnos[j].nro_registro < arregloAlumnos[i].nro_registro){

                alumnoAux = arregloAlumnos[i];                           
                arregloAlumnos[i] = arregloAlumnos[j];
                arregloAlumnos[j] = alumnoAux;

            }
        }
    }
}

void grabarEnArchivo(s_alumno* arregloAlumnos){
    FILE* archivo = fopen("comisionABM.csv", "w");
    int i = 0;

    while(arregloAlumnos[i].nro_registro != 0){
        fprintf(archivo,"%d,%s,%s\n",arregloAlumnos[i].nro_registro,arregloAlumnos[i].nombre,arregloAlumnos[i].apellido);
        i++;
    }
    fclose(archivo);
}

void unificar(char* n_archComAM, char* n_archComBM){
    s_alumno* alumnosAM = NULL;
    s_alumno* alumnosBM = NULL;
    // FILE* archBM = fopen(n_archComBM,"r");

    /* Leemos el primer archivo */
    leerArchivo(n_archComAM, &alumnosAM); 
    leerArchivo(n_archComBM, &alumnosBM);
    /* Ahora, en alumnosAM es un arreglo con los alumnos AM, lo mismo con alumnosBM */

    /* Tenemos que unificar los dos arreglos */
    s_alumno* alumnosUnificados = NULL; // En este arreglo estaran todos los alumnos, sin repeticiones

    if(alumnosAM != NULL && alumnosBM != NULL){
        unirArreglos(&alumnosUnificados, alumnosAM, alumnosBM);
    }

    ordenarArreglo(alumnosUnificados);

    // for(int i = 0 ; alumnosUnificados[i].nro_registro != 0 ; i++){
    //     printf("%d, %s, %s\n",alumnosUnificados[i].nro_registro, alumnosUnificados[i].nombre, alumnosUnificados[i].apellido);
    // }
    grabarEnArchivo(alumnosUnificados);
}

int main(){
    unificar("comisionAM.csv","comisionBM.csv");
    return 0;
}