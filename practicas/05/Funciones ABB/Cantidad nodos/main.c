#include <stdio.h>
#include <stdlib.h>

struct s_nodo_bin{
    int dato;
    struct s_nodo_bin* pIzq;
    struct s_nodo_bin* pDer;
};
typedef struct s_nodo_bin* t_nodo_bin;

int descendientes(t_nodo_bin_ptr arb){
    if(arb != NULL){
        return descendientes(arb->pIzq) + descendientes(arb->pDer) + 1;
    } 
    else{
        return 0;
    }
}