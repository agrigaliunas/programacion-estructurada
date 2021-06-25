#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20

typedef struct{
char* texto;
int anio, mes;}t_emp;

int sacarMes(unsigned int numero){
    int mascara = pow(2,4)-1;
    return(numero & mascara);
}

int sacarAnio(unsigned int numero){
    int mascara = pow(2,12)-1;
    return((numero>>4) & mascara);
}

void cargarArreglo(t_emp empleado[]){

    char *arregloDinamico = NULL;
    char caracter;
    int i = 0, j = 0, num = 0;

    FILE* archivo = fopen("empleados.txt","r");

    caracter = fgetc(archivo);

    while(caracter != EOF){
        arregloDinamico = malloc(sizeof(char));
        while(caracter != ','){ 
            arregloDinamico[i] = caracter;
            i++;
            caracter = fgetc(archivo);
            arregloDinamico = realloc(arregloDinamico,sizeof(char)*(i+1));
        }

        arregloDinamico[i] = '\0';
        
        empleado[j].texto = arregloDinamico;
        
        fscanf(archivo,"%d\n",&num);
        empleado[j].anio = sacarAnio(num);
        empleado[j].mes = sacarMes(num);
        j++;
        
        caracter = fgetc(archivo);
        i = 0;
    }
    empleado[j].texto = NULL;
    fclose(archivo);
}

void imprimirArreglo(t_emp empleado[]){
    int i = 0;
    for(i=0;empleado[i].texto != NULL;i++){
        printf("%d/%d: %s\n",empleado[i].mes,empleado[i].anio,empleado[i].texto);
    }
}

int main(){
    
    t_emp empleado[N];
    cargarArreglo(empleado);
    imprimirArreglo(empleado);

}