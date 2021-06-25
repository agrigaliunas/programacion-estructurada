#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int n, o , p;
    char p1[26], p2[50];
    double a, b, c;
}t_varios;

void intercambiarStruct(t_varios *struct1, t_varios *struct2){
    t_varios structAux;

    structAux = *struct1;
    *struct1 = *struct2;
    *struct2 = structAux;

}


int main(){
    t_varios struct1, struct2;
    double tamanoByteStruct = sizeof(t_varios);
    intercambiarStruct(&struct1,&struct2);

    printf("Tamano en byte de struct: %lf",tamanoByteStruct);

    return 0;
}