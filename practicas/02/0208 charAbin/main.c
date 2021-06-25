#include <stdio.h>
#include <stdlib.h>
#define MASK 128

void deCharABin(char carac){
    int i;
    for (i = 0 ; i<8 ; i++){            // Es i < 8 ya que estamos hablando de CHARS (8 bits)
        printf("%d", (carac&(MASK>>i)) != 0);  // Si es diferente de 0, imprimo True o False (False = 0, True = 1)
    }
}


int main(){
    char caracter = 'c';
    deCharABin(caracter);

    return 0;
}
