#include <stdio.h>
#include <stdlib.h>

void intercambiarVarPunt(int* puntero_a, int* puntero_b){
 int numero_aux;
 numero_aux = *puntero_a;
 *puntero_a = *puntero_b;
 *puntero_b = numero_aux;

}

int main(){
    int a = 2;
    int b = 4;
    printf("Numero A: %d\n",a);
    printf("Numero b: %d\n",b);
    printf("Se intercambiambian las variables...\n");
    intercambiarVarPunt(&a,&b);
    printf("Numero A: %d\n",a);
    printf("Numero b: %d\n",b);
    return 0;
}

