#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha{
    int anio;
    int mes;
    int dia;
};
typedef struct s_fecha t_fecha;

struct s_localidades{
    int ID_localidad,
    char nombre[200];
    double promAltura;
    int alturaMin;
    int alturaMax;
    struct s_localidades* sig;
};
typedef struct s_localidades* t_localidades;

t_localidades maxCinco(int n, int anio){    // Retorna cantidad "n" de localidades cuyos promAltura sean los MAYORES para "anio"
    t_localidades localidad = NULL;

    return localidad;
}

int main(){



    
    return 0;
}
