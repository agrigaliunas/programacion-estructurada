#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 20

typedef struct{
    char *texto;
    int anio,mes;}t_emp;

int sacarAnio(unsigned int num){
    int mascara = pow(2,12)-1;
    return(num>>4 & mascara);
}

int sacarMes(unsigned int num){
    int mascara = pow(2,4)-1;
    return (num & mascara);
}

void cargarArreglo(t_emp empleado[N]){

    char *textoDinamico;
    char letra;
    int i=0, j=0, num;

    FILE *archivo = fopen("empleados.txt","r");

    letra = fgetc(archivo);

    while(letra != EOF){
        textoDinamico = malloc(sizeof(char));
        while(letra != ','){
            textoDinamico[i] = letra;
            i++;
            textoDinamico = realloc(textoDinamico,(i+1)*(sizeof(char)));
            letra = fgetc(archivo);
        }
        textoDinamico[i] = '\0';
        empleado[j].texto = textoDinamico;

        fscanf(archivo,"%d\n",&num);

        empleado[j].mes = sacarMes(num);
        empleado[j].anio = sacarAnio(num);

        letra = fgetc(archivo);
        i=0;
        j++;
    }
    empleado[j].texto = NULL;
    fclose(archivo);
}

void imprimirArreglo(t_emp empleado[N]){
    int i;
    for(i=0; empleado[i].texto != NULL; i++){
        printf("%d/%d: %s\n",empleado[i].mes,empleado[i].anio,empleado[i].texto);
    }
}

int main(){
    t_emp empleado[N];
    cargarArreglo(empleado);
    imprimirArreglo(empleado);
}