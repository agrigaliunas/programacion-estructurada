#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int n,o,p;
    char p1[26], p2[50];
    double a,b,c;
} t_varios;

void intercambio(t_varios* s1, t_varios* s2){
    t_varios saux;
    saux = *s1;
    *s1 = *s2;
    *s2 = saux;

}


int main(){
    t_varios s1;
    t_varios s2;

    intercambio(&s1,&s2);


    return 0;
}