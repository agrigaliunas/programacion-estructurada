#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// 1.1

void cargarString(char** str){
    int i = 0;
    char aux;
    *str = malloc(sizeof(char));

    printf("Ingrese caracter:\n ");
    aux = getche();

    while(aux != '\r'){
        *(*str + i) = aux;
        i++;
        *str = realloc(*str, sizeof(char)*(i+1));
        aux = getche();
    }

    *(*str + i) = '\0';
}

int main(){

    char* str = NULL;
    cargarString(&str);

    for(int i = 0 ; str[i] != '\0' ; i++){
        printf("%c",str[i]);
    } 
    
    return 0;
}





// 1.2
/*
struct s_per{
    int dni;
};
typedef struct s_per t_per;

void ordenar(t_per** per){
    int i=0, j=0;
    t_per aux;
    for(i = 0 ; (*per+i) != NULL ; i++){
        for(j = i+1 ; (*per+j) != NULL ; j++){
            if( (*per+i)->dni < (*per+j)->dni ){
                aux = *(*per+i);
                *(*per+i) = *(*per+j);
                *(*per+j) = aux;
            }
        }
    }
}
*/
