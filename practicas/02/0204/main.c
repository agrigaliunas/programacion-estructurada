#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 15
#define DATOS 3
#define MAX_PERSONAS 4
#define ENTER '\r'

struct s_persona{
    int dni;
    char nombre[MAX];
    char pais[MAX];
};
typedef struct s_persona Persona;

void cargarDatosEnArchivo(Persona personaNueva, char nombre_archivo[]){
    FILE* archivo = fopen(nombre_archivo,"a");
    fprintf(archivo,"%d,",personaNueva.dni);
    fprintf(archivo,"%s,",personaNueva.nombre);
    fprintf(archivo,"%s\n",personaNueva.pais);
    fclose(archivo);
}

void cargarString(char string[MAX]){
    char c;
    int i;
    c = getche();
    for (i = 0 ; c != ENTER && i<MAX-1; i++){
        string[i] = c;
        c = getche();
    }
    string[i] = '\0';
 }

void cargarDatos(){
    Persona personaNueva;
    FILE* archivo;
    int i = 0, contadorPersonas = 0;

    printf("Ingrese DNI: (0 para finalizar):\n");
    scanf("%d",&personaNueva.dni);

    while(personaNueva.dni != 0 && contadorPersonas < MAX_PERSONAS){
        printf("Ingrese nombre: ");
        cargarString(personaNueva.nombre);
        printf("Ingrese pais: ");
        cargarString(personaNueva.pais);
    // ------------------------------ //
        printf("%d, ",personaNueva.dni);
        printf("%s, ",personaNueva.nombre);
        printf("%s\n",personaNueva.pais);
        
        cargarDatosEnArchivo(personaNueva,"personas.txt");
        contadorPersonas++;

        if (contadorPersonas < MAX_PERSONAS){
            printf("Ingrese DNI: (0 para finalizar):\n");
            scanf("%d",&personaNueva.dni);
        }
    }
}

int main(){
    char nombre_archivo[]="personas.txt";
    cargarDatos();

    return 0;
}