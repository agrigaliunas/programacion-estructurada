#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct s_texto{
    char* txt;
    unsigned int longitud;
}; typedef struct s_texto t_texto;

/* Una función que me permita ingresar una cantidad indefinida de frases diferentes,
las cuales se irán guardando en un arreglo dinámico de variables del tipo t_texto. */

t_texto cargar_texto(){
    t_texto texto;
    texto.txt = malloc(sizeof(char));

    int contador_letras = 0;
    char letra = 0;
    printf("\nIngrese texto:\n");
    letra = getche();

    while(letra != '\r'){
        texto.txt[contador_letras] = letra;
        contador_letras++;
        texto.txt = realloc(texto.txt, sizeof(char)*(contador_letras+1));
       
        letra = getche();
    }
    texto.longitud = contador_letras;
    texto.txt[contador_letras] = '\0';
    return texto;
}

void cargar_estruc_arr(t_texto** puntero_arr){
    int contador_estruc = 0;

    t_texto texto_nuevo;
    texto_nuevo = cargar_texto();

    *puntero_arr = malloc(sizeof(t_texto));

    while(texto_nuevo.longitud != 0){
        *(*puntero_arr + contador_estruc) = texto_nuevo;
        contador_estruc++;
        *puntero_arr = realloc(*puntero_arr,sizeof(t_texto)*(contador_estruc+1));
        texto_nuevo = cargar_texto();
    }

    (*(*puntero_arr + contador_estruc)).txt = NULL;
}

            /* ORDENAR CON DOBLE PUNTERO */

// void ordenar_alfabeticamente(t_texto** arreglo){ //   { { e1 , e2  , e3  },{ e1 , e2  , e3  } }
//     t_texto arr_aux;
//     int i = 0;
//     int j = 0;
    
//     for( i = 0 ; (*(*(arreglo)+i)).txt != NULL ; i++ ){      // accedo al i elemento del primer arreglo

//         for( j = i ; (*(*(arreglo)+j)).txt != NULL ; j++){

//             if(strcmp((*(*(arreglo)+i)).txt,(*(*(arreglo)+j)).txt)){

//                 arr_aux = (*(*(arreglo)+i));
//                 (*(*(arreglo)+i)) = (*(*(arreglo)+j));
//                 (*(*(arreglo)+j)) = arr_aux;
//             }
//         }
//     } 
// }


            /* ORDENAR CON UN SOLO PUNTERO */

void ordenar_alfabeticamente(t_texto* arreglo){ //   { e1 , e2  , e3  }
    t_texto arr_aux;
    int i = 0;
    int j = 0;  
    
    for( i = 0 ; (*(arreglo+i)).txt != NULL ; i++ ){

        for( j = i ; (*(arreglo + j)).txt != NULL ; j++){

            if(strcmp( (*(arreglo + i)).txt, (*(arreglo + j)).txt )){

                arr_aux = *(arreglo + i);
                *(arreglo + i) = *(arreglo + j);
                *(arreglo + j) = arr_aux;
            }
        }
    } 
}

void imprimir_arr(t_texto* arr){
    int i;
    for(i = 0 ; arr[i].txt != NULL ; i++){
        printf("\n%s, %d",arr[i].txt, arr[i].longitud);
    }
}

int main(){
    t_texto* arr_estructura = NULL; // Creo arreglo de estructuras 
    cargar_estruc_arr(&arr_estructura);

    printf("\nArreglo:\n");
    imprimir_arr(arr_estructura);

    ordenar_alfabeticamente(arr_estructura);

    printf("\nArreglo ordenado:\n");
    imprimir_arr(arr_estructura);
}