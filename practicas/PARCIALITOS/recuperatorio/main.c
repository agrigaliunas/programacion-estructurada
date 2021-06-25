/** SECCI�N[0] ---------------- G E N E R A L -------------------------------*/
///////////////////////////////////////////////////////  V E R S I O N   //////
// P R O G R A M A C I � N   E S T R U C T U R A D A //  20200427 19:30  //////
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[1]----- D A T O S   E S T U D I A N T E --------- */
/** ------ C O M P L E T A R    O B L I G A T O R I O ------ */
///////////////////////////////////////////////////////////////////////////////
// FECHA        :  29 / 06 / 2020
// COMISI�N     : FM
// EXAMEN Nro   : 3
// EXAMEN [P|R] : R
// TEMA Nro     : 3
// APELLIDO     : Grigaliunas
// NOMBRE       : Agustin
// LEGAJO       : 151902721
// DNI          : 42996646
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
//  No esta terminado maximoDe
//
///////////////////////////////////////////////////////////////////////////////

/** SECCI�N[5]-- S O L U C I � N   A  L A  C O N S I G N A --*/
// ||||| ///////////////////////////////////////////////////////// ||||| //////
// |||||  ESCRIBA su c�digo de la Soluci�n a partir de AQUI ABAJO  ||||| //////
// vvvvv ///////////////////////////////////////////////////////// vvvvv //////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

struct s_data {
	/** COMPLETAR los miembros de la estructura*/
	char articulo[70];
	double precio;    
	int cantidad;
	int id;
	struct s_data* sigNodo;
};
typedef struct s_data* t_data;

void agregarALista(t_data* nodo, char articulo[70], double precio, int cantidad, int id){
	
	if(*nodo == NULL){
		*nodo = (t_data) malloc(sizeof(struct s_data));
		strcpy((*nodo)->articulo,articulo);
		(*nodo)->precio = precio;
		(*nodo)->cantidad = cantidad;
		(*nodo)->id = id;
		(*nodo)->sigNodo = NULL;
	}
	else{
		agregarALista(&(*nodo)->sigNodo, articulo, precio, cantidad, id);
	}
}

void cargarListaFrente(t_data* lista, char* nomArch){	
	FILE* archivo = fopen(nomArch,"r");
	int i,r;
	char letra;
	char articulo[70];
	int id;
	int cantidad;
	double precio;

	letra = fgetc(archivo);

	while(letra != EOF){
		i = 0;		
		while(letra != EOF && letra != ','){
			articulo[i] = letra;
			i++;
			letra = fgetc(archivo);
		}
		articulo[i] = '\0';

		r = fscanf(archivo,"%lf,%d,%d\n",&precio,&cantidad,&id);
		agregarALista(lista,articulo,precio,cantidad,id);
		letra = fgetc(archivo);
	}
	fclose(archivo);
	
}	
	

void imprimirListaR(t_data lista){	
	if(lista != NULL){
		printf("%-20s %-20s %-20s %-20s\n","ARTICULO","PRECIO","CANTIDAD","ID");
		printf("%-20s %-20.2lf %-20d %-20d\n",lista->articulo,lista->precio,lista->cantidad,lista->id);
		printf("*****************************************************************\n");
		imprimirListaR(lista->sigNodo);
	}	
}
	
t_data maximoDe(t_data lista){ // Tomo precio mayor de la lista, y retorno dirMemoria
	/** CODIFICAR FUNCION */


	/* No esta terminada */

	double valorMax = 0;
	double valorActual = lista->precio;
	t_data* dirMemActual = &lista;
	t_data siguienteNodo;
	if(lista != NULL){
		if(valorActual > valorMax){
			valorActual = valorMax;
			
		}
		// if(lista->sigNodo != NULL){
		// 	siguienteNodo = maximoDe(lista->sigNodo);
		// }
		
	}
	return NULL; 
}
	

int main() {
	/**NO SE PUEDE CAMBIAR EL C�DIGO DE main*/
	printf("TEMA_03\n\n");
	t_data lista = NULL;
	t_data maxi = NULL;
	char nomArch[TAM] = "datos_t3.txt";
	
	cargarListaFrente(&lista,nomArch);
	imprimirListaR(lista);
	printf("\n");
	
	maxi = maximoDe(lista);
	if (maxi!=NULL){
		printf("El id de mayor precio es: %d\n", (*maxi).id);
	}else{
	 	printf("El id de mayor precio es:  - - - - - - \n");
	}
	
	return 0;
}
	
