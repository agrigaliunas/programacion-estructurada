#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    char dni[9];
    char nombre[100], apellido[100];
    double monto_adeudado;
    unsigned int dia, mes, anio;
}t_datos;

void cargarDNI(char* dni){
    int i = 0;
    char l;

    l = getche();

    while(l != '\r' && i < 9){
        dni[i] = l;
        i++;
        l = getche();
    }

    dni[i] = '\0';
}

void cargarCadena(char* cadena){
    int i = 0;
    char l;
    
    l = getche();

    while(l != '\r' && i < 100){
        cadena[i] = l;
        i++;
        l = getche();
    }

    cadena[i] = '\0';
}


void cargarPersona(t_datos* deuda){
    printf("Ingresar DNI (0 para finalizar): ");
    cargarDNI(deuda->dni);

    if(deuda->dni[0] != '0'){
        printf("\nNombre: ");
        cargarCadena(deuda->nombre);

        printf("\nApellido: ");
        cargarCadena(deuda->apellido);

        printf("\nMonto de la deuda: ");
        scanf("%lf",&(deuda->monto_adeudado));

        printf("\nDia: ");
        scanf("%d",&(deuda->dia));

        printf("\nMes: ");
        scanf("%d",&(deuda->mes));

        printf("\nAño: ");
        scanf("%d",&(deuda->anio));
    }
}

void guardarDeuda(t_datos* deuda, char* nomArch){
    FILE* archivo = fopen(nomArch, "ab");
    
    fwrite(deuda, sizeof(t_datos), 1, archivo);

    fclose(archivo);
}

void cargarDatos(){
    t_datos deuda;
    cargarPersona(&deuda);
    
    while(deuda.dni[0] != '0'){
        guardarDeuda(&deuda,"deudores.dat");
        cargarPersona(&deuda);
    }
}

void imprimirArchivo(FILE* archivo){
    int i = 0;
    t_datos leer[50] = {0};
    fread(&leer[i], sizeof(t_datos), 1, archivo);
    for(i=0;i<160;i++){
        printf("*");
    }
    printf("\n");
    i = 0;
    while(!feof(archivo)){
        printf("%20s %20s %20s %20s %20s %20s %20s\n","DNI","NOMBRE","APELLIDO","MONTO","DIA","MES","ANIO");
        printf("%20s %20s %20s %20lf %20d %20d %20d\n",leer[i].dni,leer[i].nombre,leer[i].apellido,leer[i].monto_adeudado,leer[i].dia,leer[i].mes,leer[i].anio);
        i++;
        fread(&leer[i], sizeof(t_datos), 1, archivo);
    }
}

void abrirArchivo(){
    char* nombreArch = "deudores.dat";
    FILE* archivo = fopen(nombreArch, "rb");
    imprimirArchivo(archivo);

}


int main(){
    cargarDatos();
    abrirArchivo();
    return 0;
}