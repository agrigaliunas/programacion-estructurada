#include <stdio.h>
#include <stdlib.h>

void intercambio(int* p1, int* p2){
    int aux = 0;

    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
    
    printf("%d, %d",*p1,*p2);

}

int main(){

    int n1 = 5;
    int n2 = 3;

    

    int* p1 = &n1;
    int* p2 = &n2;

    printf("%d, %d\n",*p1,*p2);

    intercambio(p1,p2);
    return 0;
}