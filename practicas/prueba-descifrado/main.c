#include <stdio.h>
#include <stdlib.h>

// Esto dice "hola" 1752132705 --> int 4 bytes (32 bits)

void descifrarEntero(unsigned int mask, unsigned int numero){
    int i;
    
    int num = 0;

    num = (numero&(mask<<24))>>24;
    printf("%c",num);       // Aca esta la H del hola

    num = (numero&(mask<<16))>>16;  // Aca esta la O
    printf("%c",num);

    num = (numero&(mask<<8))>>8;  // Aca esta la L
    printf("%c",num);

    num = (numero&(mask));   // Aca esta la A
    printf("%c",num);
}




int main(){
    unsigned int mask = 255;
    unsigned int numero = 1752132705;
    descifrarEntero(mask,numero);
    return 0;
}