#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nota{
    int valor;
    struct s_nota* sig;
};
typedef struct s_nota* t_nota;

struct s_alu{
    char* apellido;
    t_nota lstNota;
    struct s_alu* sig;
};
typedef struct s_alu* t_alu;

struct s_prom{
    char* apellido;
    double promedio;
    struct  s_prom* sig;
};
typedef struct s_prom* t_prom;

double obtenerPromedio(t_alu listaAlumnos){
    double promedio = 0;
    int contador = 0;
    int suma = 0;
    t_nota lstNotaAux = listaAlumnos->lstNota;
    
    while(lstNotaAux != NULL){
        suma += lstNotaAux->valor;
        contador++;
        lstNotaAux = lstNotaAux->sig;
    }

    promedio = suma/contador;
    return promedio;
}

void insertarOrdenado(t_prom* listaPromedios, char* apellido, double promedio){
    t_prom listaAux = NULL;
    if(*listaPromedios == NULL || promedio > (*listaPromedios)->promedio){
        listaAux = malloc(sizeof(struct s_prom));
        listaAux->apellido = apellido;
        listaAux->promedio = promedio;
        listaAux->sig = *listaPromedios;
        *listaPromedios = listaAux;
    }
    else{
        insertarOrdenado(&(*listaPromedios)->sig, apellido, promedio);
    }
}

void cargarPromedios(t_alu* listaAlumnos, t_prom* listaPromedios){
    double promedioCalculado = 0;
    if(*listaAlumnos != NULL){
        promedioCalculado = obtenerPromedio(*listaAlumnos);
        insertarOrdenado(listaPromedios, (*listaAlumnos)->apellido, promedioCalculado);
        cargarPromedios(&(*listaAlumnos)->sig, listaPromedios);
    }
}

void imprimirPromedios(t_prom listaPromedios){
    if(listaPromedios != NULL){
        printf("%10s %10.2lf\n",listaPromedios->apellido, listaPromedios->promedio);
        imprimirPromedios(listaPromedios->sig);
    }
}

void listado(t_alu listaAlumnos){ // Confecciona e imprime listado con el apellido y el promedio de cada alumno
    t_prom listaPromedios = NULL;
    if(listaAlumnos != NULL){
        cargarPromedios(&listaAlumnos, &listaPromedios);
        printf("%10s %10s\n", "Apellido", "Promedio");
        printf("---------------------\n");
        imprimirPromedios(listaPromedios);
    }
    
}

void agregarAlumno(t_alu* listaAlumnos, char* apellido, t_nota lstNota){
    if(*listaAlumnos == NULL){
        (*listaAlumnos) = malloc(sizeof(struct s_alu));
        (*listaAlumnos)->apellido = apellido;
        (*listaAlumnos)->lstNota = lstNota;
        (*listaAlumnos)->sig = NULL;
    }
    else{
        agregarAlumno(&(*listaAlumnos)->sig, apellido, lstNota);
    }
}

void agregarNota(t_nota* listNota, int valor){
    if(*listNota == NULL){
        *listNota = malloc(sizeof(struct s_nota));
        (*listNota)->valor = valor;
        (*listNota)->sig = NULL;
    }
    else{
        agregarNota(&(*listNota)->sig, valor);
    }
    
}

void cargarAlumnosYNotas(t_alu* listaAlumnos){
    t_nota notas1 = NULL;
    t_nota notas2 = NULL;
    t_nota notas3 = NULL;
    t_nota notas4 = NULL;
    t_nota notas5 = NULL;

    
    agregarNota(&notas1, 3);
    agregarNota(&notas1, 4);
    agregarNota(&notas1, 4);
    agregarNota(&notas1, 6);
    agregarAlumno(listaAlumnos, "Garcia", notas1);
    
    agregarNota(&notas2, 8);
    agregarNota(&notas2, 6);
    agregarNota(&notas2, 4);
    agregarNota(&notas2, 6);
    agregarAlumno(listaAlumnos, "Lopez", notas2);

    agregarNota(&notas3, 5);
    agregarNota(&notas3, 5);
    agregarNota(&notas3, 5);
    agregarNota(&notas3, 6);
    agregarAlumno(listaAlumnos, "Cardenas", notas3);

    agregarNota(&notas4, 4);
    agregarNota(&notas4, 4);
    agregarNota(&notas4, 3);
    agregarNota(&notas4, 7);
    agregarAlumno(listaAlumnos, "Molinari", notas4);

    agregarNota(&notas5, 2);
    agregarNota(&notas5, 1);
    agregarNota(&notas5, 2);
    agregarNota(&notas5, 2);
    agregarAlumno(listaAlumnos, "Estevez", notas5);
}

int main(){
    t_alu listaAlumnos = NULL;
    cargarAlumnosYNotas(&listaAlumnos);

    listado(listaAlumnos);
    free(listaAlumnos);

    return 0;

}