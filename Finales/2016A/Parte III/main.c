#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// #define MAX 15

struct s_empleado{
    int codigoVendedor;
    char* nomVendedor;
    int objetivoTarjAnual;
    double sueldoAnual;
}
typedef s_empleado;

struct sNodoBin{
    s_empleado empleado;
    struct sNodoBin* izq;
    struct sNodoBin* der; 
};
typedef struct sNodoBin* tNodoBin;

struct s_ventas{
    int codigoVendedor;
    char mes[15];
    int cantidadDeTarjetas;
};
typedef struct s_ventas s_venta;

void cargarVendedorEnArbol(tNodoBin* arbol, s_empleado empleadoNuevo){
    if(*arbol == NULL){
        *arbol = malloc(sizeof(struct sNodoBin));
        (*arbol)->empleado = empleadoNuevo;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }
    else{
        if(empleadoNuevo.codigoVendedor < ((*arbol)->empleado).codigoVendedor){
            cargarVendedorEnArbol(&((*arbol)->izq),empleadoNuevo);
        }
        else{
            cargarVendedorEnArbol(&((*arbol)->der),empleadoNuevo);
        }
    }
}


int cargarArbolVendedores(tNodoBin* arbol, FILE* fVende){
    s_empleado empleadoNuevo;
    int i = 0;
    char letra;
    char* string = NULL;

    if(fVende != NULL){

        while(fscanf(fVende,"%d,",&empleadoNuevo.codigoVendedor) != EOF){
            i = 0;
            string = malloc(sizeof(char));
            letra = fgetc(fVende);

            while(letra != ','){
                string[i] = letra;
                i++;
                string = realloc(string,sizeof(char) * (i+1));
                letra = fgetc(fVende);
            }

            string[i] = '\0';
            empleadoNuevo.nomVendedor = string;

            fscanf(fVende,"%d,",&empleadoNuevo.objetivoTarjAnual);
            fscanf(fVende,"%lf\n",&empleadoNuevo.sueldoAnual);

            cargarVendedorEnArbol(arbol, empleadoNuevo);
        }

    }
}


int obtenerTarjetasXID(int idVen){
    int totalTarjetas = 0;

    s_venta* arrVentas = NULL;
    int indVenta = 0;

    FILE* archivoVentas = fopen("ventasTarjetas.dat", "rb");

    if(archivoVentas != NULL){
        arrVentas = malloc(sizeof(struct s_ventas));

        while(fread(&arrVentas[indVenta].codigoVendedor, sizeof(int), 1, archivoVentas) != 0){
            fread(arrVentas[indVenta].mes, sizeof(char), 15, archivoVentas);
            fread(&arrVentas[indVenta].cantidadDeTarjetas, sizeof(int), 1, archivoVentas);

            indVenta++;
            arrVentas = realloc(arrVentas, sizeof(struct s_ventas) * (indVenta+1));
        }

        arrVentas[indVenta].codigoVendedor = 0;
    }

    fclose(archivoVentas);

    indVenta = 0;
    
    while(arrVentas[indVenta].codigoVendedor != 0){
        if(arrVentas[indVenta].codigoVendedor == idVen){
            totalTarjetas += arrVentas[indVenta].cantidadDeTarjetas;
        }
        indVenta++;
    }
    free(arrVentas);

    return totalTarjetas;
    
}




s_empleado obtenerInfo(tNodoBin arbol, int idVen){
    s_empleado empleadoEncontrado;

    if(arbol->empleado.codigoVendedor == idVen){
        empleadoEncontrado = arbol->empleado;
    }

    else{
        if(idVen < (arbol->empleado).codigoVendedor){
            return obtenerInfo(arbol->izq, idVen);
        }
        else{
            return obtenerInfo(arbol->der, idVen);
        }
    }
}


int liquidar(tNodoBin arbol, int idVen){
    s_empleado empleado = obtenerInfo(arbol, idVen);
    int cantTarjetas = obtenerTarjetasXID(idVen);

    printf("Vendedor: %s\n",empleado.nomVendedor);
    printf("ID: %d\n",empleado.codigoVendedor);
    printf("Total tarjetas vendidas anual: %d\n",cantTarjetas);
    printf("Objetivo anual: ",empleado.objetivoTarjAnual);

}

int main(){
    tNodoBin arbol = NULL;
    FILE* fVende = fopen("vendedores.txt","r");
    cargarArbolVendedores(&arbol, fVende);

    fclose(fVende);
    return 0;
}