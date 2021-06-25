#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ENTER '\r'


struct s_texto{
    char* txt;
    unsigned int longitud;
};

typedef struct s_texto t_texto;


t_texto cargarTexto(){
    t_texto texto;
    int contadorLetras = 0;
    char caracter = 0;

    texto.txt = malloc(sizeof(char));

    caracter = getche();

    while(caracter != ENTER){
        *( (texto.txt) + contadorLetras) = caracter;
        contadorLetras++;

        
        texto.txt = realloc(texto.txt,(contadorLetras+1)*sizeof(char));
        caracter = getche();
    }

    *((texto.txt) + contadorLetras) = '\0';
    texto.longitud = contadorLetras;

    return texto;
}

void escribirArchText(char* nombre_archivo, t_texto texto){

    FILE* archivo = fopen(nombre_archivo, "w");
    char caracter = 0;
    int i = 0;

    fprintf(archivo,"%d,",texto.longitud);

    caracter = *(texto.txt+i);

    while(i < texto.longitud && caracter !='\0'){
        fputc(caracter,archivo);
        i++;
        caracter = *(texto.txt+i);
    }
    fputc('\n',archivo);

    fclose(archivo);
}

int main(){
    escribirArchText("frases_con_longitud.csv",cargarTexto());

    return 0;
}