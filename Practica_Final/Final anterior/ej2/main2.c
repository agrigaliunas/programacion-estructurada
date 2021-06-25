#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct s_indice{
    int inicial;
    int final;
};
typedef struct s_indice t_indice;

struct s_indice2{
    int linea;
    int inicial;
    int final;
};
typedef struct s_indice2 t_indice2;

struct sp_indice2{
    t_indice2 estructura;
};
typedef struct sp_indice2 tp_indice2;

struct s_data{
    tp_indice2* puntero;
};
typedef struct s_data* t_data;


int strLen(char* str){
    int i;
    for(i = 0 ; str[i] != '\0' ; i++){}
    return i;
}
t_indice buscarSub(char* str, char* sub){
    t_indice indices;
    indices.inicial = -1; indices.final = -1; // de por si, tomamos como que no se encuentra la subcadena
    int i = 0; // para str
    int j = 0; // para sub
    int lenStr = strLen(str); // longitud de str
    int lenSub = strLen(sub); // longitud de sub

    char subAux[lenSub];                  // La verdad absoluta no existe, y esto es absolutamente cierto.

    for(i = 0 ; str[i] != '\0' ; i++){ // recorro la cadena grande
        
        for(j = 0 ; j < lenSub ; j++){ 
            subAux[j] = str[i+j]; // pongo en aux el contenido del string con la longitud 
        }
        subAux[j] = '\0';

        if(strcmp(sub,subAux) == 0){
            indices.inicial = i;
            indices.final = i+j-1;
            return indices;
        }
    }
    return indices;
}

t_data indices(char* sub){
    FILE* arch = fopen("frases.dat","rb");
    char frase[512] = {0};
    int i = 0;
    // estructuras //
    t_data arrD = NULL; // arreglo de punteros a retornar
    tp_indice2* arregloPunteros = malloc(sizeof(struct sp_indice2)); // le doy espacio al arreglo dinamico para un puntero de estructura
    t_indice datosLeidos; // aca se ingresan los datos leidos del archivo pasados por buscarsub
    
    

    while(!feof(arch)){
        fread(&frase,512,1,arch);
        datosLeidos = buscarSub(frase,sub);
        if(datosLeidos.inicial != -1 && datosLeidos.final != -1){
            arregloPunteros[i].estructura.linea = i;
            arregloPunteros[i].estructura.inicial = datosLeidos.inicial;
            arregloPunteros[i].estructura.final = datosLeidos.final;
            i++;
            arregloPunteros = realloc(arregloPunteros, sizeof(struct sp_indice2)*(i+1));
        }
    }
    fclose(arch);
    arregloPunteros[i].estructura.linea = -1;
    arregloPunteros[i].estructura.inicial = -1;
    arregloPunteros[i].estructura.final = -1;
    arrD = malloc(sizeof(arregloPunteros));
    arrD->puntero = arregloPunteros;


    return arrD;
}


void imprimirArr(t_data arrD){
    int i = 0;
    if(arrD->puntero[i].estructura.inicial == -1){
        printf("\nNo se encontro la subcadena.");
        return;
    }
    else{
        for(i = 0 ; arrD->puntero[i].estructura.inicial != -1 ; i++){
            printf("\n(%d, %d, %d)",arrD->puntero[i].estructura.linea, arrD->puntero[i].estructura.inicial, arrD->puntero[i].estructura.final);
        }
    }
}

void crearArchivo(){
    FILE* archivo = fopen("frases.dat","wb");
    char frase[512] = "La verdad absoluta no existe, y esto es absolutamente cierto\n";
    fwrite(&frase, 512*sizeof(char),1,archivo);
    char frase2[512] = "Solo se que no se nada\n";
    fwrite(&frase2, 512*sizeof(char),1,archivo);
    char frase3[512] = "No llega antes el que va mas rapido sino el que sabe donde va\n";
    fwrite(&frase3, 512*sizeof(char),1,archivo);

    fclose(archivo);
}

char* cargarSub(){
    char* sub = malloc(sizeof(char));
    char c;
    printf("Ingrese sub cadena: \n");
    c = getche();
    sub = malloc(sizeof(char));
    int i;
    i = 0;
    while(c != '\r'){
        sub[i] = c;
        i++;
        c = getche();
        sub = realloc(sub,sizeof(char)*(i+1));
    }
    sub[i] = '\0';
    return sub;
}

void ordenarArr(t_data arrD, int nCam){
    int i,j;
    t_indice2 aux;
    for(i = 0 ; arrD->puntero[i].estructura.linea != -1 ; i++){
        for(j = i ; arrD->puntero[j].estructura.linea != -1 ; j++){
            if(nCam == 1){
                if(arrD->puntero[i].estructura.linea > arrD->puntero[j].estructura.linea){
                    aux = arrD->puntero[i].estructura;
                    arrD->puntero[i].estructura = arrD->puntero[j].estructura;
                    arrD->puntero[j].estructura = aux;
                }
            }

            if(nCam == 2){
                if(arrD->puntero[i].estructura.inicial > arrD->puntero[j].estructura.inicial){
                    aux = arrD->puntero[i].estructura;
                    arrD->puntero[i].estructura = arrD->puntero[j].estructura;
                    arrD->puntero[j].estructura = aux;
                }
            }
            
            if(nCam == 3){
                if(arrD->puntero[i].estructura.final > arrD->puntero[j].estructura.final){
                    aux = arrD->puntero[i].estructura;
                    arrD->puntero[i].estructura = arrD->puntero[j].estructura;
                    arrD->puntero[j].estructura = aux;
                }
            }
        }
    }
}

int main(){
    //crearArchivo();
    char* sub = NULL;
    sub = cargarSub();

    t_data arrD = NULL;
    arrD = indices(sub);
    
    printf("\nPara '%s':",sub);
    imprimirArr(arrD);
    printf("\n");
    
    int nCam;
    printf("Por cual campo desea ordenar?\n");
    scanf("%d",&nCam);
    ordenarArr(arrD,nCam);
    printf("\nArreglo ordenado:\n");
    imprimirArr(arrD);
    return 0;
}