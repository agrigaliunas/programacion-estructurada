#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

struct s_datos
{
    int DNI;
    char nombre[TAM];
    char apellido[TAM];
};
typedef struct s_datos t_datos;

struct s_nodo
{
    t_datos info;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

void agregar(t_nodo* nodo, int DNI, char nom[TAM], char ape[TAM])
{
    if(*nodo==NULL)
    {
        *nodo = (t_nodo) malloc(sizeof(struct s_nodo));
        (*nodo)->info.DNI = DNI;
        strcpy((*nodo)->info.nombre,nom);
        strcpy((*nodo)->info.apellido,ape);
        (*nodo)->sig = NULL;
    }
    else
    {
        agregar(&(*nodo)->sig, DNI, nom, ape);
    }
}


void insertarOrdenadoNom(t_nodo* lista_aux, int DNI, char nom[TAM],char ape[TAM])
{
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));
    if(*lista_aux == NULL || strcmp((*lista_aux)->info.nombre,nom)== 1)
    {
        aux->info.DNI = DNI;
        strcpy(aux->info.apellido,ape);
        strcpy(aux->info.nombre,nom);
        aux->sig = *lista_aux;
        *lista_aux = aux;
    }
    else
    {
        insertarOrdenadoNom(&(*lista_aux)->sig,DNI,nom,ape);
    }
}

void insertarOrdenadoApe(t_nodo* lista_aux, int DNI, char nom[TAM],char ape[TAM])
{
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));
    if(*lista_aux == NULL || strcmp((*lista_aux)->info.apellido,ape)== 1)
    {
        aux->info.DNI = DNI;
        strcpy(aux->info.apellido,ape);
        strcpy(aux->info.nombre,nom);
        aux->sig = *lista_aux;
        *lista_aux = aux;
    }
    else
    {
        insertarOrdenadoApe(&(*lista_aux)->sig,DNI,nom,ape);
    }
}

void insertarOrdenadoDNI(t_nodo* lista_aux, int DNI, char nom[TAM], char ape[TAM])
{
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));
    if(*lista_aux == NULL || DNI < (*lista_aux)->info.DNI)
    {
        aux->info.DNI =  DNI;
        strcpy(aux->info.nombre,nom);
        strcpy(aux->info.apellido,ape);
        aux->sig = *lista_aux;
        *lista_aux = aux;
    }
    else{
        insertarOrdenadoDNI(&(*lista_aux)->sig,DNI,nom,ape);
    }
}

void ordenar(t_nodo* nodo, int val)
{
    t_nodo aux = NULL;
    while(*nodo!=NULL)
    {
        if(val == 1)
        {
            insertarOrdenadoDNI(&aux,(*nodo)->info.DNI,(*nodo)->info.nombre,(*nodo)->info.apellido);
            *nodo = (*nodo)->sig;
        }
        else if (val == 2)
        {
            insertarOrdenadoNom(&aux,(*nodo)->info.DNI,(*nodo)->info.nombre,(*nodo)->info.apellido);
             *nodo = (*nodo)->sig;
        }
        else
        {
            insertarOrdenadoApe(&aux,(*nodo)->info.DNI,(*nodo)->info.nombre,(*nodo)->info.apellido);
            *nodo = (*nodo)->sig;
        }
    }
    *nodo = aux;
}



void cargarLista(t_nodo* lista, char nomArch[TAM])
{
    FILE* arch;
    arch = fopen(nomArch,"r");
    int num,h;
    h = fscanf(arch,"%d,",&num);
    printf("%d",h);
    while (h!=EOF)
    {
        char l;
        int i = 0;
        char nom[TAM] = {0};
        char ape[TAM] = {0};
        l = fgetc(arch);
        while(l!=',')
        {
            nom[i] = l;
            i++;
            l = fgetc(arch);
        }
        i = 0;
        l = fgetc(arch);
        while(l!='\n')
        {
            ape[i] = l;
            i++;
            l = fgetc(arch);
        }
        agregar(lista,num,nom,ape);
        h = fscanf(arch,"%d,",&num);
    }
}


void imprimirLista(t_nodo lista)
{
    if(lista!=NULL)
    {
        printf("%-10d %-10s %-10s\n",lista->info.DNI,lista->info.nombre,lista->info.apellido);
        imprimirLista(lista->sig);
    }
}



void main()
{
    t_nodo lista = NULL;
    char nombre[TAM] = "informacion.csv";
    cargarLista(&lista,nombre);
    printf("LISTA:\n");
    imprimirLista(lista);
    printf("Ingrese numero de campo por el cual desea ordenar:\n");
    printf("1 = DNI  2 = NOMBRE  3 = APELLIDO\n");
    int j;
    scanf("%d",&j);
    ordenar(&lista,j);
    imprimirLista(lista);
}