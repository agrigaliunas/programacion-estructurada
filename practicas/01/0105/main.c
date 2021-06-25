#include <stdio.h>
#include <stdlib.h>
#define TERMINA 0
#define TAMANO_MAX 100

int esPos(int num){
    int esPositivo = 0; // Creo bandera esPositivo, inicializada en 0 (FALSE)

    if (num >= 0){ // Si el numero es positvo..
        esPositivo = 1; // TRUE
    }
    else{ // Si no es positivo..
        esPositivo = 0; // FALSE
    }
    return esPositivo; // Retorno la buleana.
}


int estaEnArr(int num, int arreglo[TAMANO_MAX]){  
    int esta = 0;
    int i;    

    for(i=0; arreglo[i]!=0 && i<TAMANO_MAX ; i++){ // Itero el arreglo para comprobar si el numero es igual al numero de la posicion i
        if (arreglo[i]==num){
            esta = 1;
        }
    }

    return esta; 
}


void cargarArrPNR(int arreglo[TAMANO_MAX]){
    int num = 0;
    int i = 0;
    printf("Ingrese numeros: \n");
    scanf("%d",&num); // Pido un numero


    while(num!=TERMINA && i < TAMANO_MAX-1){
        if(!esPos(num)){  // Si es positivo, re ingreso.
            printf("El numero no es positivo. Re ingrese:");   
        }

        else if(estaEnArr(num,arreglo)){  // Si esta en array, re ingreso
            printf("El numero esta en el arreglo. Re ingrese: ");
           
        }
        else{  // Si no, agrego el numero en la posicion en el array.
            arreglo[i] = num;
            i++;
        }
        scanf("%d",&num); // Vuelvo a pedir numero
    }
    arreglo[i] = TERMINA;  // Por conveniencia, indicamos el fin del array con el numero terminador [0]
}

void imprimirArr(int arreglo[TAMANO_MAX]){
    int i;
    printf("Numeros: \n");
    for(i = 0 ; i<TAMANO_MAX-1 && arreglo[i]!=TERMINA ; i++)
        printf("%d",arreglo[i]);
}

int main(){

    int arregloInt[TAMANO_MAX] = {0}; // Limpio el array
    printf("Cargar arreglo\n");
    cargarArrPNR(arregloInt);
    imprimirArr(arregloInt);
    return 0;
}
