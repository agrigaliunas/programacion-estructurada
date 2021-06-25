#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/**

Carga un arreglo dinámico de estructura struct s_txt
dentro de la estructurase encuentra un arreglo dinámico de char

marianotrigila@gmail.com
*/

struct s_txt
{ /** Estructura */
    char *txt;
    int lon;
};
typedef struct s_txt t_txt; /** Alias */

char *cargarStrDin()
{ /** Carga un arreglo dinamico de char (string) y retorna la direccion*/
    int i = 0;
    char letra;
    char *arr = NULL; /** lo inicalizo en null*/

    letra = getche(); /** Ingresar caracter desde teclado*/
    if (letra != '\r')
    {
        arr = (char *)malloc(sizeof(char)); /** Asignar memoria Puntero a char: es un arreglo dinámico de punteros a char*/
        if (arr == NULL)
        {
            return NULL;
        } /** Sale de la funcion si no tiene memoria*/

        while (letra != '\r') /** mientras no sea un ENTER ('\r') el valor ingresado desde el teclado*/
        {
            *(arr + i) = letra;                                 /** asignar la letra (caracter) ingresada a una posicion del arreglo*/
            i++;                                                /** incrementar variable de desplazamiento de direcion */
            arr = (char *)realloc(arr, (i + 1) * sizeof(char)); /** Ampliar memoria*/
            if (arr == NULL)
            {
                return NULL;
            }
            letra = getche(); /** Ingresar caracter desde teclado*/
        }
        arr[i] = '\0'; /** Asignar '\0' determina el fin de un string */
    }
    printf("\n"); /** */
    return arr;   /** retorna la direccion de */
}

void cargarStrDin2(char **arr)
{ /** Carga un arreglo dinamico de char (string) y retorna la direccion*/
    int i = 0;
    char letra;
    *(arr) = NULL;    /** lo inicalizo en null*/
    letra = getche(); /** Ingresar caracter desde teclado*/
    if (letra != '\r')
    {
        *(arr) = (char *)malloc(sizeof(char)); /** Asignar memoria Puntero a char: es un arreglo dinámico de punteros a char*/
        if (*(arr) == NULL)
        {
            return NULL;
        } /** Sale de la funcion si no tiene memoria*/

        while (letra != '\r') /** mientras no sea un ENTER ('\r') el valor ingresado desde el teclado*/
        {
            *((*(arr)) + i) = letra; /** asignar la letra (caracter) ingresada a una posicion del arreglo*/
            //(*arr)[i]=letra;                      /**expresion equivalente a la anterior*/

            i++;                                                      /** incrementar variable de desplazamiento de direcion */
            *(arr) = (char *)realloc(*(arr), (i + 1) * sizeof(char)); /** Ampliar memoria*/
            if (*(arr) == NULL)
            {
                return NULL;
            }
            letra = getche(); /** Ingresar caracter desde teclado*/
        }
        *((*(arr)) + i) = '\0'; /** Asignar '\0' determina el fin de un string */
        //(*arr)[i]='\0';                          /** expresión equivalente a la anterior*/
    }
    printf("\n"); /** */
}

void imprimirTextDin(t_txt *text)
{ /** imprime un arreglo dinamico de text*/
    int i = 0;
    if ((text) != NULL && (text + i)->txt != NULL)
    {
        printf("text       text+i\ti\tlon\ttxt\n");
        printf("------------------------------------------------------\n");
        while ((text + i)->txt != NULL)
        { //(((text+i)->txt)[0]!='\0'){
            printf("<%d> <%d>\t%d\t%d\t%s\n", text, text + i, i, (text + i)->lon, (text + i)->txt);
            i++;
        }
    }
}

t_txt cargarUnText()
{ /** Carga una estructura del tip t_txt*/

    int pos = 0;
    t_txt text; /**  */

    /**VER las dos formas de cargar el arreglo de caracterres, retornando el puntero,
    o pasandole el doble puntero. Mantener comentada siempre una para probar.*/
    /**  - - - - - - - - - - - - - - - - - - - */
    //text.txt=cargarStrDin();                  /** Cargar un string dinámico con retorno */
    cargarStrDin2(&(text.txt)); /** Cargar un string dinámico con puntero de puntero */
    /**  - - - - - - - - - - - - - - - - - - - */

    for (pos = 0; text.txt != NULL && *((text.txt) + pos) != '\0'; pos++)
        ; /** determinar el tamaño del string cargado */
    if (text.txt != NULL)
    {
        pos++; /** incrementa para contar al '\0'*/
    }
    text.lon = pos; /** asignar el tamaño */
    return text;    /** retornar la estructura cargada */
}

t_txt *cargarTextDin()
{ /** Carga un arreglo dinamico de text y retorna la direccion*/
    int i = 0;
    int pos = 0;
    t_txt *text = NULL;
    t_txt auxText;
    auxText = cargarUnText(); /** cargar una estructura text  - */

    text = (t_txt *)malloc(sizeof(struct s_txt)); /** Asignar memoria Puntero a text: es un arreglo dinámico de punteros a text*/
    if (text == NULL)
    {
        return NULL;
    }

    while (auxText.txt != NULL)
    {                                                                  /** Mientras no sea nula txt (esto sucede cuando no se cargo dato, solo un enter)*/
        *(text + i) = auxText;                                         /** asigna el el valor de la estructura en laposicon i del arreglo*/
        i++;                                                           /** incrementar variable de desplazamiento de direcion */
        text = (t_txt *)realloc(text, sizeof(struct s_txt) * (i + 1)); /** Ampliar memoria */
        if (text == NULL)
        {
            return NULL;
        }

        auxText = cargarUnText(); /** cargar una estructura text  - */
    }
    *(text + i) = auxText; /** asigna el el valor de la estructura en laposicon i del arreglo*/
    return text;
}

void cargarTextDinPP(t_txt **text)
{ /** Carga un arreglo dinamico de text pasandole doble puntero*/

    *text = cargarTextDin();
}

int main()
{ /**VER las dos formas de cargar el arreglo, retornando el puntero,
    o pasandole el doble puntero. Mantener comentada siempre una para probar.*/
    t_txt *text = NULL;
    //text=cargarTextDin();  // retorna puntero (direccion con estructura cargada)
    cargarTextDinPP(&text); // se pasa la direccion del puntero (doble puntero)
    imprimirTextDin(text);

    return 0;
}