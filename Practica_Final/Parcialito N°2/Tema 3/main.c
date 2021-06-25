#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20

typedef struct {
    char *texto;
    int anio,mes;}t_auto;

int sacarMes(unsigned int numero){
    int mascara = pow(2,4)-1;
    return((numero>>16)&mascara);
}

int sacarAnio(unsigned int numero){
    int mascara = pow(2,12)-1;
    return((numero>>20)&mascara);
}

void cargarArreglo(t_auto autos[N]){

    char caracter;
    char *arregloDinamico = NULL;
    int i=0, j=0, num=0;

    FILE*archivo = fopen("automotores.txt","r");

    caracter = fgetc(archivo);

    while(caracter != EOF){
        arregloDinamico = malloc(sizeof(char));
        while(caracter != ','){
            arregloDinamico[i] = caracter;
            i++;
            caracter = fgetc(archivo);
            arregloDinamico = realloc(arregloDinamico,(i+1)*sizeof(char));
        }
        arregloDinamico[i] = '\0';
        
        autos[j].texto = arregloDinamico;
        
        fscanf(archivo,"%d\n",&num);
        autos[j].mes = sacarMes(num);
        autos[j].anio = sacarAnio(num);
        j++;
        caracter = getc(archivo);
        i=0;
        
    }
    autos[j].texto = NULL;
    fclose(archivo);
}

void imprimirArreglo(t_auto autos[]){
    int i;
    for(i=0;autos[i].texto != NULL; i++){
        printf("%d/%d: %s\n",autos[i].mes,autos[i].anio,autos[i].texto);
    }
}

int main(){
    t_auto autos[N];
    cargarArreglo(autos);
    imprimirArreglo(autos);
}
