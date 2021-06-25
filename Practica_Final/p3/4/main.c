#include <stdio.h>
#include <stdlib.h>

struct s_carta{
    int numero,valor;
    char palo;
};
typedef struct s_carta t_carta;


int main(){
    t_carta carta1;
    t_carta carta2;
    t_carta carta3;
    carta1.numero = 1; carta1.palo = "espada"; carta1.valor = 10;
    carta2.numero = 1; carta2.palo = "basto"; carta2.valor = 8;
    carta3.numero = 2; carta3.palo = "oro"; carta3.valor = 6;
    return 0;
}
