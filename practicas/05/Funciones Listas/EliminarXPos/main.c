#include <stdio.h>
#include <stdlib.h>

struct s_nodo{
    int valor;
    struct s_nodo* sigNodo;
};
typedef struct s_nodo* p_nodo;

void eliminarXpos(p_nodo* nodo, int pos){
    int i;
    p_nodo aux = NULL;
    if(*nodo != NULL){
        for(i = 1 ; *nodo != NULL ; i++){
            if(i == pos){
                aux = *nodo;
                *nodo = (*nodo)->sigNodo;
                free(aux);
            }
            else{
                nodo = &(*nodo)->sigNodo;
            }
        }
    }   
}



int main(){
    p_nodo lista = NULL;
    int pos = 2;
    eliminarXpos(&lista,pos);
    return 0;
}