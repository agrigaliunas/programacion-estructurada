#include <stdio.h>
#include <stdlib.h>



int multiplicarDosEnteros(int numero1, int numero2){

    if(numero2 == 0){
        return 0;
    }

    if(numero2 > 0 ){
        printf("%d\n",numero1 + multiplicarDosEnteros(numero1,numero2-1));
        return numero1 + multiplicarDosEnteros(numero1,numero2-1);
    }
    else if(numero2 < 0){
        return -numero1 + multiplicarDosEnteros(numero1,numero2+1);
    
    }
    else{
        return numero1;
    }
}

int main(){
    printf("%d",multiplicarDosEnteros(2,3));
    return 0;
}