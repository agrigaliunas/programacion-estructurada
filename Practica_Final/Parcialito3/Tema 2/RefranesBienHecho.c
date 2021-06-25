/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :   09 / 11 / 2020
// COMISI�N     :	FM
// EXAMEN Nro   :	3
// EXAMEN [P|R] :	Parcialito
// TEMA Nro     :   2
// APELLIDO     : 	Jimenez
// NOMBRE       : 	Lautaro
// LEGAJO       : 	15-190261-5
// DNI          : 	42658906
//
// COMENTARIOS o OBSERVACIONES del estudiante:
// <Usar si desea comunicar algo al profesor corrector>
//
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[2] ---- N O M B R E   D E L   A R C H I V O ------ */
///////////////////////////////////////////////////////////////////////////////
// �Como confeccionar el nombre del archivo ?
// [Apellido].PE.[Anio].[Cuatrimestre].[Comisi�n][NroExamen][TipoExamen][NroTema].c
//
// [Apellido]    -> REEMPLAZAR por tu apellido y nombre, con
//                  la forma apellidoNombre.
//  PE           -> NO se reemplaza, signifa Programaci�n Estructurada.
// [Anio]        -> REEMPLAZAR con dos d�gitos del a�o actual. Ej: 20
// [Cuatrimestre]-> REEMPLAZAR con un d�gito 1 =  1� Cuatr | 2 = 2� Cuatr.
// [Comisi�n]    -> REEMPLAZAR por las dos letras de su comisi�n Ejemplo: BM.
// [NroExamen]   -> REEMPLAZAR por el n�mero (entero) de examen ej: 1.
// [TipoExamen]  -> REEMPLAZAR con P  = Parcial | R = Recuperatorio |
//                  E = Extraordinario.
// [NroTema]     -> REEMPLAZAR por en n�mero(entero) de tema ej: 2.
//  c            -> NO se reemplaza, es la extensi�n del archivo.
//
//
// Un ejemplo del "nombre de un archivo" podria ser:
//
//     Ej ->   alvarezMartin.PE.20.1C.BM.1.P.2.c
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[3]--- E N V � O   D E L   A R C H I V O --------- */
///////////////////////////////////////////////////////////////////////////////
// El archivo .c con la soluci�n deber� ser entregado
// a trav�s de la plataforma EVA UCA
// Dentro de la pagina de la materia en EVA, IR a la
// solapa EVALUACIONES o bien copiar el siguiente link
//
// https://eva.uca.edu.ar/course/view.php?id=1360&section=4
//
// Ah� podr�n encontrar una tarea de entrega de parcialito
// Deber�n hacer click sobre ella y se abrir� una ventana
// donde aparecer� el bot�n 'Agregar Entrega'  en el cual deber�n hacer click
// sobre �l para desplegar una nueva ventana donde podr�n realizar la carga del
// archivo
//
// IMPORTANTE: La tarea ser� abierta pasados los 15 minutos
// del horario del comiezo de la clase y estar� disponible 90 minuto
// Ejemplo: Si tu clase es de 7:45 a 10:15 => la tarea se
//          abrir� a las 8:00 y se cerrar� 9:30
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[4]----- P A R A   E L   P R O F E S O R --------- */
///////////////////////////////////////////////////////////////////////////////
// COMENTARIOS o OBSERVACIONES del PROFESOR:
// <Reservado para uso del profesor>
//
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[5]-- S O L U C I � N   A  L A  C O N S I G N A --*/
// ||||| ///////////////////////////////////////////////////////// ||||| //////
// |||||  ESCRIBA su c�digo de la Soluci�n a partir de AQUI ABAJO  ||||| //////
// vvvvv ///////////////////////////////////////////////////////// vvvvv //////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char txt[100];
	char car;
	int cantidad_caracter;
}t_refran;

struct s_nodo
{
	t_refran def;
	struct s_nodo *sig;
};
typedef struct s_nodo * t_nodo;

void agregar(t_nodo*, t_refran val);
void imprimir(t_nodo lista);
void cargarLista(t_nodo *l);
int cantidad(char* texto,char caracter);


void cargarLista(t_nodo * l)
{
	int i=0;
	char texto[100];
	char letra;
	char caracter;
	t_refran aux;

	FILE* arch=fopen("refranes.txt","r");
    letra = fgetc(arch);
	if(arch==NULL)
		printf("Error en la apertura del archivo");

	else{
		while(letra != EOF){
            if (letra!='\n'){
                while(letra != ','){
                    texto[i] = letra;
                    i++;
                    letra = fgetc(arch);
                }

                texto[i]='\0';
                strcpy(aux.txt,texto);
                caracter = fgetc(arch);
                //printf("%c",caracter);
                aux.car=caracter;
                aux.cantidad_caracter = cantidad(aux.txt,caracter);

                agregar(l,aux);
                i=0;
                letra = fgetc(arch);
                //printf("--hola");
            }else{
                letra=fgetc(arch);
            }
		}
	}
	fclose(arch);

}


void agregar(t_nodo *nodo, t_refran val)
{
	if ((*nodo)==NULL)
	{
		*nodo=malloc(sizeof(struct s_nodo));
		(*nodo)->def=val;
		(*nodo)->sig=NULL;
	}
	else
	{
		agregar(&(*nodo)->sig, val);
	}
}

void imprimir(t_nodo lista){

	if (lista!=NULL){
		printf("%-100s %c %8d\n",  lista->def.txt, lista->def.car, lista->def.cantidad_caracter);
		imprimir(lista->sig);
	}
}

int cantidad(char * texto, char caracter){
	if(*(texto) != '\0'){
		if(*(texto) == caracter){
			return 1 + cantidad((texto+1),caracter);
		}
		else{
			return 0+cantidad((texto+1),caracter);
		}
	}
}

int main()
{

	t_nodo lista= NULL;
	cargarLista(&lista);
	printf("%-100s %s %s\n","Refran", "Caracter", "Cantidad");
	imprimir(lista);

	return 0;
}
