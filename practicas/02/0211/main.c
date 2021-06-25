/* Realizar una función que reciba como parámetros 4 unsigned char y que coloque cada
uno de ellos en una variable de tipo unsigned int, que devolverá en su valor de retorno. */

#include <stdio.h>
#include <stdlib.h>

unsigned int shiftearIzq8Bits(unsigned int valor_retorno){
    return valor_retorno << 8;
}

unsigned int colocarCharEnInt(unsigned char a,unsigned char b, unsigned char c, unsigned char d){ 
    unsigned int valor_retorno = 0;


    valor_retorno = a | valor_retorno;
    shiftearIzq8Bits(valor_retorno);

    valor_retorno = b | valor_retorno;
    shiftearIzq8Bits(valor_retorno);

    valor_retorno = c | valor_retorno;
    shiftearIzq8Bits(valor_retorno);

    valor_retorno = d | valor_retorno;
    shiftearIzq8Bits(valor_retorno);

    return valor_retorno;
}


int main(){
    unsigned char a = 'a'; // '97'  0 1 1 0 0 0 0 1
    // --- //
    unsigned char b = 'b'; // '98'  0 1 1 0 0 0 1 0
    // --- //
    unsigned char c = 'c'; // '99'  0 1 1 0 0 0 1 1
    // --- //
    unsigned char d = 'd'; // '100' 0 1 1 0 0 1 0 0

    printf("%u",colocarCharEnInt(a,b,c,d));

    return 0;
}