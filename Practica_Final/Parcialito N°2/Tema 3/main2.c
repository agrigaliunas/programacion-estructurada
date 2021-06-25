#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 20

typedef struct{
    char *texto;
    int anio,mes;
}t_auto;

int sacarMes(int num){
    int mascara = pow(2,4)-1;
    return(num>>16 & mascara);
}

int sacarAnio(int num){
    int mascara = pow(2,12)-1;
    return(num>>20 & mascara);
}

void cargarArreglo(t_auto autos[N]){

    char *textoDinamico; 
    char letra;
    int i=0,j=0,num;

    FILE *archivo = fopen("automotores.txt","r");
    
    letra = fgetc(archivo);

    while(letra != EOF){
        textoDinamico = malloc(sizeof(char));
        while(letra != ','){
            textoDinamico[i] = letra;
            i++;
            textoDinamico = realloc(textoDinamico,(i+1)*sizeof(char));
            letra = fgetc(archivo);
        }
        textoDinamico[i] = '\0';
        
        fscanf(archivo,"%d\n",&num);

        autos[j].texto = textoDinamico;
        autos[j].mes = sacarMes(num);
        autos[j].anio = sacarAnio(num);

        i=0;
        j++;
        letra = fgetc(archivo);
    }
    autos[j].texto = NULL;
    fclose(archivo);
}

void imprimirArreglo(t_auto autos[]){
    int i;
    for(i=0;autos[i].texto != NULL;i++){
        printf("%d/%d: %s\n",autos[i].mes,autos[i].anio,autos[i].texto);
    }
}

int main(){
    t_auto autos[N];
    cargarArreglo(autos);
    imprimirArreglo(autos);
}

