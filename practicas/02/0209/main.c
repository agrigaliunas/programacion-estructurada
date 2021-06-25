#include <stdio.h>
#include <stdlib.h>
#define MASK 127

char shiftearAlaIzq(char c){           // char c = 'd' = 100 
    int resultado = (c >> 1) & MASK;                         
    return resultado;                                     
}  

int main(){
    printf("%d", shiftearAlaIzq(127));
    return 0;
}