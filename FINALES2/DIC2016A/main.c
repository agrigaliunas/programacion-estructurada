#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_vendedores{
    int codigoVendedor;
    char nombreVendedor[30];
    int objetivoTarjetasAnual;
    double sueldoAnual;
}
typedef estructuraVendedores;

struct sNodoBin{
    estructuraVendedores vendedor;
    struct sNodoBin* izq;
    struct sNodoBin* der;
};
typedef struct sNodoBin* tNodoBin;

struct s_ventas{
    int codigoVendedor;
    char mesVenta[15];
    int cantidadTarjetas;
}
typedef estructuraVentas;

void cargarVendedorArbol(tNodoBin* dirArbol, estructuraVendedores vendedor){
    if(*dirArbol == NULL){
        (*dirArbol) = malloc(sizeof(struct sNodoBin));
        (*dirArbol)->vendedor = vendedor;
        (*dirArbol)->izq = NULL;
        (*dirArbol)->der = NULL;
    }
    else{
        if(((*dirArbol)->vendedor).codigoVendedor < vendedor.codigoVendedor){
            cargarVendedorArbol(&((*dirArbol)->izq),vendedor);
        }
        else{
            cargarVendedorArbol(&((*dirArbol)->der),vendedor);
        }
    } 
}

void cargarArbolVendedores(tNodoBin* dirArbol, FILE* fVende){
    estructuraVendedores vendedorNuevo;
    char caracterLeido;
    int indiceLetra = 0;

    if(fVende != NULL){

        while(fscanf(fVende,"%d,",&vendedorNuevo.codigoVendedor) != EOF){

            caracterLeido = fgetc(fVende);

            while(caracterLeido != ','){
                vendedorNuevo.nombreVendedor[indiceLetra] = caracterLeido;
                indiceLetra++;
                caracterLeido = fgetc(fVende);
            }
            vendedorNuevo.nombreVendedor[indiceLetra] = '\0';
            indiceLetra = 0;
            fscanf(fVende,"%d,%lf\n",&vendedorNuevo.objetivoTarjetasAnual,&vendedorNuevo.sueldoAnual);
            cargarVendedorArbol(dirArbol, vendedorNuevo);
        }
    }
    fclose(fVende);

}

void obtenerVentas(estructuraVentas** dirArrVentas){
    estructuraVentas* arrAux = NULL;
    FILE* archivo = fopen("ventasTarjetas.dat","rb");
    int indiceVenta = 0;

    if(archivo != NULL){

        arrAux = malloc(sizeof(struct s_ventas));

        while(fread(&arrAux[indiceVenta].codigoVendedor,sizeof(int),1,archivo) != 0){

            fread(&arrAux[indiceVenta].mesVenta,sizeof(char),15,archivo);
            fread(&arrAux[indiceVenta].cantidadTarjetas,sizeof(int),1,archivo);

            indiceVenta++;
            arrAux = realloc(arrAux,sizeof(struct s_ventas)*(indiceVenta+1));
        }
        arrAux[indiceVenta].codigoVendedor = 0;        
    
    }   
    fclose(archivo);

    (*dirArrVentas) = arrAux;
    free(arrAux);
}

estructuraVendedores obtenerVendedorPorID(tNodoBin arbol, int idVen){
    estructuraVendedores vendedorEncontrado;

    if(arbol == NULL){
        vendedorEncontrado.codigoVendedor = 0;
        return vendedorEncontrado;
    }

    else{

        if( (arbol->vendedor).codigoVendedor == idVen){
            vendedorEncontrado = arbol->vendedor;
            return vendedorEncontrado;
        }

        else{

            if( (arbol->vendedor).codigoVendedor < idVen)
                return obtenerVendedorPorID(arbol->izq,idVen);
            

            else if( (arbol->vendedor).codigoVendedor > idVen)
                return obtenerVendedorPorID(arbol->der,idVen);
            
        }
    }

}

int obtenerTarjetasVendidas(estructuraVentas* arrVentas, int idVen){
    int indiceVenta = 0;
    int cantidadTarjetas = 0;

    while(arrVentas[indiceVenta].codigoVendedor != 0){
        if(idVen == arrVentas[indiceVenta].codigoVendedor){
            cantidadTarjetas += arrVentas[indiceVenta].cantidadTarjetas;
        }
        indiceVenta++;
    }
    free(arrVentas);
    return cantidadTarjetas;
}


void liquidar(tNodoBin arbol, int idVen){
    estructuraVentas* arrVentas = NULL;

    obtenerVentas(&arrVentas);  

    int totalTarjetasVendidas = obtenerTarjetasVendidas(arrVentas, idVen);
    estructuraVendedores vendedorFinal = obtenerVendedorPorID(arbol, idVen);
    /* Nombre, ID, total tarjetas, objetivo anual */

    printf("Vendedor: %s\n",vendedorFinal.nombreVendedor);
    printf("ID: %d\n",vendedorFinal.codigoVendedor);
    printf("Total tarjetas vendidas: %d\n",totalTarjetasVendidas);
    printf("Objetivo anual: %d",vendedorFinal.objetivoTarjetasAnual);
}

int main(){
    tNodoBin arbol = NULL;
    FILE* fVende = fopen("vendedores.txt","r");

    cargarArbolVendedores(&arbol, fVende);

    liquidar(arbol,3);

    fclose(fVende);

    free(arbol);
    return 0;
}