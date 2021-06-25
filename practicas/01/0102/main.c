#include <stdio.h>
#include <stdlib.h>
int suma(int n1,int n2){
    return n1+n2;
}
int resta(int n1,int n2){
    return n1-n2;
}
int producto(int n1,int n2){
    return n1*n2;
}
int division(int n1, int n2){
    if(n2 == 0){
        printf("Error, division por 0.");
        return 0;
    }
    else{
        return n1/n2;
    }
}
int main(){

    int numero1,numero2;
    char operacion;

    printf("Ingrese numero 1: ");
    scanf("%i",&numero1);

    printf("Ingrese numero 2: ");
    scanf("%i",&numero2);

    getchar();
    printf("Ingrese operacion [+ - / *]: ");
    operacion = getchar();

    if (operacion == '+'){  // LOS CARACTERES (NO STRINGS) SE ESCRIBEN ENTRE '' .
        printf("Resultado: %i",suma(numero1,numero2));
    }
    else if(operacion == '-'){
        printf("Resultado: %i",resta(numero1,numero2));
    }
    else if(operacion == '/'){
        printf("Resultado: %i",division(numero1,numero2));
    }
    else if(operacion == '*'){
        printf("Resultado: %i",producto(numero1,numero2));
    }
    return 0;
}
