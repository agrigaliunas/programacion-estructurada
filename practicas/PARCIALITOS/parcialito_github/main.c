  
#include <stdio.h>
#include <stdlib.h>

//http://bitwisecmd.com/

//Mascara dia:0b11111000000000000000 5 bits
//Mascara mes:0b00000111100000000000 4 bits
//Mascara ano:0b00000000011111111111 11 bits

typedef struct s_fecha{
    int dia;
    int mes;
    int ano;
} t_fecha;

//Funciones prototipo

int entregarDiaDeLaFecha(int fechaEncriptada);
int entregarMesDeLaFecha(int fechaEncriptada);
int entregarAnoDeLaFecha(int fechaEncriptada);
void extraerFechasDelArchivo(t_fecha** arregloDeFechas,char * nombreDelArchivo);
t_fecha desencriptarFecha(int fechaEncriptada);

/////////////////////////////////////////////////////

int main(){

    t_fecha* arregloDeFechas = NULL; // Creo puntero a estructura que es un arreglo.
    int i = 0;

    extraerFechasDelArchivo(&arregloDeFechas, "fechas.txt");  // Extraigo las fechas del archivo. Paso la dir. memoria ya que recibe doble puntero.
    return 0;
}

int entregarDiaDeLaFecha(int fechaEncriptada){
     int diaDeLaFecha = 0;
     int mascaraDia = 0b11111000000000000000;

     diaDeLaFecha = (mascaraDia & fechaEncriptada) >> 15;
     return diaDeLaFecha;
}

int entregarMesDeLaFecha(int fechaEncriptada){
     int mesDeLaFecha = 0;
     int mascaraMes = 0b00000111100000000000;

     mesDeLaFecha = (mascaraMes & fechaEncriptada) >> 11;
     return mesDeLaFecha;
}

int entregarAnoDeLaFecha(int fechaEncriptada){
     int anoDeLaFecha = 0;
     int mascaraAno = 0b00000000011111111111;

     anoDeLaFecha = (mascaraAno & fechaEncriptada);
     return anoDeLaFecha;
}

void extraerFechasDelArchivo(t_fecha** arregloDeFechas, char* nombreDelArchivo){ //Recibe direccion memoria del puntero de la estructura.
    FILE * archivoDeFechas = fopen(nombreDelArchivo, "r");
    int contadorDeFechas = 0;
    int fechaEncriptada;

    t_fecha nuevaFecha; //Creo nueva fecha

    t_fecha fechaDeParo;
    fechaDeParo.dia = 0;
    fechaDeParo.mes = 0;
    fechaDeParo.ano = 0;

    *arregloDeFechas = malloc(sizeof(t_fecha)); // le asigno la cantidad de memoria necesaria al contenido de la direccion de memoria del puntero

    while( fscanf(archivoDeFechas, "%d\n", &fechaEncriptada) != EOF ){  // leo numeros en el archivo

        nuevaFecha = desencriptarFecha(fechaEncriptada);   // Desencripto la fecha

        *(*(arregloDeFechas)+contadorDeFechas) = nuevaFecha; // Le asigno la nueva fecha al contenido de la direccion de memoria del puntero

        contadorDeFechas++;
        *arregloDeFechas = realloc(*arregloDeFechas, sizeof(t_fecha) * (contadorDeFechas+1) );

    }

    //La ultima fecha tendra todo 0

    *(*(arregloDeFechas)+contadorDeFechas) = fechaDeParo;

    fclose(archivoDeFechas);
}

t_fecha desencriptarFecha(int fechaEncriptada){
    t_fecha fecha;

    fecha.dia = entregarDiaDeLaFecha(fechaEncriptada);
    fecha.mes = entregarMesDeLaFecha(fechaEncriptada);
    fecha.ano = entregarAnoDeLaFecha(fechaEncriptada);
    printf("%d,%d,%d\n",fecha.dia,fecha.mes,fecha.ano);
    return fecha;
}