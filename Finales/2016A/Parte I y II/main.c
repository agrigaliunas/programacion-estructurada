#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* 1.1 */
int* cargarArr(){
    int* arr = NULL, i = 0, n = 0;
    arr = malloc(sizeof(int));
    printf("Ingrese numeros: ");
    scanf("%d",&n);
    *(arr) = n;
    while(n != 0){
        printf("Ingrese numeros: ");
        scanf("%d",&n);
        i++;
        arr = realloc(arr,sizeof(int) * (i+1));
        *(arr+i) = n;
    }

    return arr;
}


/* 1.2 */

int sumPares(int* arr){
    if(*arr != NULL){
        if((*arr)%2 == 0){
            return sumPares(*arr+1) + (*arr);
        }
        else{
            return sumPares(*arr+1);
        }
    }
}


/* 2.1 */

int main(){
    unsigned char a=1;
    unsigned int i;
    for(i=0;i<8;i++){
        a=a&(1<<i);
    }
    printf("\n%d",a);
}

// Imprime 0

/* 2.2 */

char f(char a){
    if (a<'c')
        f(a+1);
    else{
        if (a=='b')
        f(a+1);
    }
    return a;
}

void main(){
    printf("%c",f('b'));
}

// Retorna b

/* 2.3 */

int main(){
    int* p = NULL;
    (*p) = 10;

    printf("%d",*(p)+1);

    return 0; 
}

// Error de ejecucion (p esta en NULL y no se le asigna espacio)

/* 2.4 */

void f(){
    int a = 9, b = 13;
    int *bb, **cc;

    bb = &b;
    cc = &bb;
    printf("%d", *bb+1);
}

int main(){
    f();
}

// Imprime 14

