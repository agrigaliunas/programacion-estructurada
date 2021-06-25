/* Ejercicio 6 de la Practica 1 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ENTER '\r'              
#define TERMINA_CADENA '\0'    
#define TAMANO_MAX 100          

int lenTexto(char arreglo[]){                                               // Retorna la longitud del cuerpo.
    int i;
    for(i=0; i<TAMANO_MAX-1 && arreglo[i]!=TERMINA_CADENA;i++){}            //For si cuerpo, devuelve la ultima posicion util sin el \0.
    return i;
}

int esLetra(char c){                                                        // Retorna 1 (true) si el caracter pasado por parametro es letra, caso contrario 0 (false).
    int esL = 0;
    if (c>='A' && c<='Z' || c>='a' && c<='z'){
        esL = 1;
    }
    return esL;
}

char aMayuscula(char c){                                                    //Convierte el caracter en mayuscula.
    c = c-32;
    return c;
}

void capitalizarLetra(char arreglo[TAMANO_MAX]){                            //Capitaliza la primer letra del arreglo, aun que este empiece con caracter diferente a letra.
    int i=0;
    int bandera = 1;
    while(esLetra(arreglo[i]) && bandera == 1){   
        if (arreglo[i]>'a' && arreglo[i]<'z'){
            arreglo[i] = aMayuscula(arreglo[i]);
            bandera = 0;
        }
        else{
            i++;
        }
    }
}

void agregarPunto(char arreglo[TAMANO_MAX]){                                //Agrego un punto en la ultima posicion.
    int ultimaPos = lenTexto(arreglo);
    if(arreglo[ultimaPos-1] == '.'){
        arreglo[ultimaPos] == TERMINA_CADENA;
    }
    else if(arreglo[ultimaPos] != '.'){
        arreglo[ultimaPos] = '.';
        arreglo[ultimaPos+1] = TERMINA_CADENA;
    }
}

void espacios(char arreglo[TAMANO_MAX]){                                    //Quita espacios de mas en el arreglo. Falta solo comprobar si en el inicio tambien hay espacios.
    int len = lenTexto(arreglo);          
    int i = 0;
    int contEsp = 0;
    int aCorrer;
    while(arreglo[i]!=TERMINA_CADENA){
        i++;
        contEsp = 0;
        while(arreglo[i] == ' '){
            contEsp++;
            i++;
            
        }
        if(contEsp > 1){
            aCorrer = contEsp-1;
            for(i;i<len ; i++){
                arreglo[i-aCorrer]=arreglo[i];
                arreglo[i] = TERMINA_CADENA;
            }
            i=0;
        }      
    }
}
        


void normalizar(char arreglo[TAMANO_MAX]){                                  //Normaliza el arreglo (capitaliza, verifica punto y espacios).
    espacios(arreglo); 
    agregarPunto(arreglo);   
    capitalizarLetra(arreglo);   
                                             
}


void cargarText(char arreglo[TAMANO_MAX]){                                  //Carga un texto string en un arreglo de constante TAMAÑO MAXIMO
    char c = 0; 
    int i = 0;
    printf("Ingrese texto: ");

    c = getche();
    while(c != ENTER && i<TAMANO_MAX-2){                                    //Bucle que ingresa caracter a caracter a traves de un getche().
        arreglo[i] = c;
        i++;
        c = getche();
    }
    arreglo[i] = TERMINA_CADENA;
}
void imprimirText(char arreglo[TAMANO_MAX]){                                //Imprime el arreglo como texto.
    int i;
    for(i=0;arreglo[i]!=TERMINA_CADENA;i++){ 
        printf("%c",arreglo[i]);
    }
}

int main(){
    char arregloTexto[TAMANO_MAX] = {0};                                    //Inicializa el arreglo en 0.
    cargarText(arregloTexto);                                               //Carga el texto por entrada estandar.
    printf("\nArreglo sin normalizar: \n"); 
    imprimirText(arregloTexto);                                             //Imprime el arreglo cargado sin normalizar.
    normalizar(arregloTexto);                                               //Normaliza el arreglo cargado.
    printf("\nArreglo normalizado: \n");
    imprimirText(arregloTexto);                                             //Imprime el arreglo normalizado.
    return 0;
}


