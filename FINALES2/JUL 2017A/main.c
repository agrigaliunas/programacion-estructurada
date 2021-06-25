#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_nodo
{
    int id;
    char nombre[20];
    double prom;
    int max, min;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void agregar(t_nodo* nodo, int id, char nombre[20], double alt, double cotmin, double cotmax)
{
    t_nodo aux = NULL;
    if(*nodo==NULL || alt > (*nodo)->prom)
    {
        aux = (t_nodo) malloc(sizeof(struct s_nodo));
        aux->id = id;
        strcpy(aux->nombre,nombre);
        aux->prom = alt;
        aux->min = cotmin;
        aux->max = cotmax;
        aux->sig = *nodo;
        *nodo = aux;
    }
    else
    {
        agregar(&(*nodo)->sig,id,nombre,alt,cotmin,cotmax);
    }

}

t_nodo maxCinco(int n, int anio)
{
    t_nodo lista = NULL;
    t_nodo aux = NULL;
    FILE* alturas;
    FILE* cotas;
    FILE* localidades;
    alturas = fopen("alturas.txt","r");
    int id,r;
    double alt,cot1,cot2;
    unsigned int an;
    r = fscanf(alturas,"%d,%lf,%d\n",&id,&alt,&an);
    
    while(r!=EOF){
            an = an>>2;
            unsigned int mask = 4095;
            an = an&mask;
            if(anio == an){
                int id2,r2,cont=0;
                char nombre[20]={0};
                char l;
                localidades = fopen("localidades.txt","r");
                r2 = fscanf(localidades,"%d,",&id2);
                while(r2!=EOF)
                {
                    l = fgetc(localidades);
                    if(id2==id)
                    {
                        while(l!='\n')
                        {
                            nombre[cont] = l;
                            cont++;
                            l = fgetc(localidades);
                        }
                    }
                    else
                    {
                        while(l!='\n')
                        {
                            l = fgetc(localidades);
                        }
                    }
                    r2 = fscanf(localidades,"%d,",&id2);
                }
                cotas = fopen("cotas.txt","r");
                int y,id3;
                double  cotmax,cotmin;
                y = fscanf(cotas,"%d,%lf,%lf\n",&id3,&cotmin,&cotmax);
                while(y!=EOF)
                {
                    if(id3==id)
                    {
                        cot1 = cotmin;
                        cot2 = cotmax;
                    }
                    y = fscanf(cotas,"%d,%lf,%lf\n",&id3,&cotmin,&cotmax);
                }
                agregar(&aux,id,nombre,alt,cot1,cot2);
            }
            r = fscanf(alturas,"%d,%lf,%d\n",&id,&alt,&an);
    }

    int contador=1;
    while(contador!= n+1 && aux!=NULL)
    {
        agregar(&lista,aux->id,aux->nombre,aux->prom,aux->min,aux->max);
        aux = aux->sig;
        contador++;
    }
    return lista;

}

void insertarOrdenado(t_nodo* nodo, int id, char nombre[20], double alt, double cotmin, double cotmax, double dif)
{
    t_nodo aux = NULL;
    if((*nodo)==NULL || dif > (((*nodo)->max)-((*nodo)->prom)))
    {
        aux = (t_nodo)malloc(sizeof(struct s_nodo));
        aux->id = id;
        strcpy(aux->nombre,nombre);
        aux->prom = alt;
        aux->max = cotmax;
        aux->min= cotmin;
        aux->sig = *nodo;
        *nodo = aux;
    }
    else
    {
        insertarOrdenado(&(*nodo)->sig,(*nodo)->id,(*nodo)->nombre,(*nodo)->prom,(*nodo)->min,(*nodo)->max,dif);
    }

}

t_nodo ordenarPorCota(t_nodo lista)
{
    t_nodo lista_aux = NULL;
    int dif;
    while(lista!=NULL)
    {
        dif = (lista->max) - (lista->prom);
        if(dif>0)
        {
            insertarOrdenado(&lista_aux,lista->id,lista->nombre,lista->prom,lista->min,lista->max,dif);
        }
        lista = lista->sig;
    }
    return lista_aux;
}

void imprimirLista(t_nodo lista)
{
    if(lista!=NULL)
    {
        printf("%d %s %.2lf %d %d \n",lista->id,lista->nombre,lista->prom,lista->min,lista->max);
        imprimirLista(lista->sig);
    }
}


int main()
{
    t_nodo h;
    t_nodo p;
    h = maxCinco(3,691);
    p = ordenarPorCota(h);
    printf("Imprimir Lista 1\n");
    imprimirLista(h);
    printf("\nImprimir Lista 2\n");
    imprimirLista(p);
    return 0;
}