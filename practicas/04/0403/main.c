#include <stdio.h>
#include <stdlib.h>

int restoEntreEnteros(int dividendo, int divisor){

    if(divisor == 0 || dividendo == 0){
        return 0;
    }

    if(dividendo>=divisor && dividendo > 0 && divisor > 0){
        return restoEntreEnteros(dividendo-divisor,divisor);
    }

    else{
        return dividendo;
    }

}

int main(){
    printf("%d",restoEntreEnteros(10,3));            // 8%3 = 2

    return 0;
}