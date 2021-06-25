#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20

typedef struct{
    char *texto;
    int anio,mes;}t_peli;

int sacarAnio(unsigned int num){
    int mascara = pow(2,12)-1;
    return(num>>2 & mascara);
}

int sacarMes(unsigned int num){
    int mascara = pow(2,4)-1;
    return(num>>14 & mascara);
}

void cargarArreglo(t_peli pelicula[N]){
    char *textoDinamico;
    char letra;
    int i=0,j=0,num;

    FILE *archivo = fopen("peliculas.txt","r");
    
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
        pelicula[j].texto = textoDinamico;

        fscanf(archivo,"%d\n",&num);
        pelicula[j].anio = sacarAnio(num);
        pelicula[j].mes = sacarMes(num);

        j++;
        letra = fgetc(archivo);
        i=0;
    }
    pelicula[j].texto = NULL;
    fclose(archivo);
}

void imprimirArreglo(t_peli pelicula[N]){
    int i;
    for(i=0;pelicula[i].texto != NULL; i++){
        printf("%d/%d: %s\n",pelicula[i].mes,pelicula[i].anio,pelicula[i].texto);
    }
}

int main(){
    t_peli pelicula[N];
    cargarArreglo(pelicula);
    imprimirArreglo(pelicula);
}