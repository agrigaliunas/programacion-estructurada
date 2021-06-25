#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> // PARA USAR strcmp() strcpy()
#define FIL 5
#define COL 10
#define TERMINA_CADENA '\0'
#define ENTER '\r'

void cargarMatText(char matriz[FIL][COL]){
    int f = 0;
    int c = 0;
    char letra;
    letra = getche();
    for(f=0 ; letra!=ENTER && f<FIL; f++){      
        for(c=0 ; letra!=ENTER && c<COL; c++){
            matriz[f][c]=letra;
            letra = getche();
        }
        matriz[f][c] = TERMINA_CADENA;
        printf("\n");
        letra = getche();
        
    }
    matriz[f][c]=TERMINA_CADENA;
}

void ordenarMatText(char matriz[FIL][COL]){
    int f = 0, c = 0;
    char aux[COL];
    for(f=0;matriz[f][0]!=TERMINA_CADENA;f++){
        for(c=f+1;matriz[c][0]!=TERMINA_CADENA;c++){
           if(strcmp(matriz[f],matriz[c]) > 0){
                strcpy(aux,matriz[f]);
                strcpy(matriz[f],matriz[c]);                // Faltaria pasar a minuscula la primera letra para asi comparar mejor
                strcpy(matriz[c],aux);
            }

        }
    }
    


}


void imprimirMatText(char matriz[FIL][COL]){
    int c = 0 , f = 0;
    printf("\n");
    for(f=0;f<FIL && matriz[f][0] != TERMINA_CADENA ;f++){
        for(c=0;c<COL && matriz[f][c] != TERMINA_CADENA;c++){
            printf("\t[%c]",matriz[f][c]);
        }
        printf("\n");
    }
}

int main(){
    char matriz[FIL][COL] = {0};
    printf("Cargar matriz:\n ");
    cargarMatText(matriz);
    imprimirMatText(matriz);
    ordenarMatText(matriz);
    imprimirMatText(matriz);
    return 0;
}