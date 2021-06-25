#include <stdio.h>
#include <stdlib.h>

struct s_carta{
    int numero, valor;
    char palo;
};
typedef struct s_carta t_carta;

void ordenarCartas(t_carta *carta1, t_carta *carta2, t_carta *carta3){
    t_carta cartaAux;

    if ((*carta1).valor > (*carta2).valor){
        cartaAux = (*carta1);
        *carta1 = *carta2;
        *carta2 = cartaAux;
    }

    if ((*carta1).valor > (*carta3).valor){
        cartaAux = (*carta1);
        *carta1 = *carta3;
        *carta3 = cartaAux;
    }

    if ((*carta2).valor > (*carta3).valor){
        cartaAux = (*carta2);
        *carta2 = *carta3;
        *carta3 = cartaAux;
    }

}

int main(){
    t_carta carta1, carta2,carta3;

    carta1.numero = 1;
    carta1.valor = 14;
    carta1.palo = 'e';

    carta2.numero = 7;
    carta2.valor = 12;
    carta2.palo = 'e';

    carta3.numero = 7;
    carta3.valor = 11;
    carta3.palo = 'o';

    printf("Sin orden: \n");
    printf("Carta 1: %d %d %c\n", carta1.numero, carta1.valor, carta1.palo);
    printf("Carta 2: %d %d %c\n", carta2.numero, carta2.valor, carta2.palo);
    printf("Carta 3: %d %d %c\n", carta3.numero, carta3.valor, carta3.palo);

    ordenarCartas(&carta1,&carta2,&carta3);

    printf("Ordenadas: \n");
    printf("Carta 1: %d %d %c\n", carta1.numero, carta1.valor, carta1.palo);
    printf("Carta 2: %d %d %c\n", carta2.numero, carta2.valor, carta2.palo);
    printf("Carta 3: %d %d %c\n", carta3.numero, carta3.valor, carta3.palo);

    return 0;
}