#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
    char* texto;
    int anio, mes;
} t_auto;

int decodeMes(unsigned int codificado){
    int mask_mes = pow(2,4) - 1;
    return ((codificado>>16) & mask_mes);
}

int decodeAnio(unsigned int codificado){
    int mask_anio = pow(2,12) - 1;
    return ((codificado>>20) & mask_anio);
}

void cargarArchivo(t_auto** pArreglo){
    FILE* archivo = fopen("automotores.txt","r");
    *pArreglo = malloc(sizeof(t_auto));
    int indiceLetra = 0; int indiceArr = 0;
    char letra = 0;
    char* textoDin = NULL;
    int encriptado;
    letra = fgetc(archivo);

    while(letra != EOF){
        textoDin = malloc(sizeof(char));
        while(letra != ','){
            textoDin[indiceLetra] = letra;
            indiceLetra++;
            textoDin = realloc(textoDin,sizeof(char)*(indiceLetra+1));
            letra = fgetc(archivo);
        }
        textoDin[indiceLetra] = '\0';
        indiceLetra = 0;
        (*(*pArreglo + indiceArr)).texto = textoDin;

        fscanf(archivo,"%d\n",&encriptado);
        (*(*pArreglo + indiceArr)).mes = decodeMes(encriptado);
        (*(*pArreglo + indiceArr)).anio = decodeAnio(encriptado);

        indiceArr++;
        *pArreglo = realloc(*pArreglo,sizeof(t_auto)*(indiceArr+1));
        letra = fgetc(archivo);
    }

    fclose(archivo);
}


void imprimirArreglo(t_auto* arreglo){
    int i = 0;
    for(i = 0 ; arreglo[i].texto != NULL ; i++){
        printf("%d/%d: %s\n",arreglo[i].mes,arreglo[i].anio,arreglo[i].texto);
    }
}

int main(){
    t_auto* arreglo = NULL;
    cargarArchivo(&arreglo);

    imprimirArreglo(arreglo);

    return 0;
}