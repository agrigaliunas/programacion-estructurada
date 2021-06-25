#include <stdio.h>
#include <stdlib.h>
#define MASK 32

unsigned char aMayuscula(unsigned char letra){
    return letra ^ MASK;
}

int main(){
    unsigned char letra = 'a';

    printf("%c",aMayuscula(letra));
    return 0;
}
