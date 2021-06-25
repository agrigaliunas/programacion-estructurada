#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

struct s_personas{
	int dni;
	char ape[TAM];
	char nom[TAM];
	int edad;
};

struct s_data {
	/** COMPLETAR los miembros de la estructura*/
	struct s_personas persona;
	struct s_data* sigNodo;
};
typedef struct s_data* t_data;


void agregarALista(t_data* nodo, int dni, char ape[TAM], char nom[TAM], int edad){
	t_data aux = NULL;
	if(*nodo == NULL || (*nodo)->persona.dni > dni){									
		// *nodo = (t_data) malloc(sizeof(struct s_data));  // Si la lista esta vacia, creo un nodo
		// (*nodo)->persona.dni = dni;			// Agrego el DNI a la estructura de persona
		// strcpy((*nodo)->persona.ape,ape);	// Agrego el apellido a la estructura de persona
		// strcpy((*nodo)->persona.nom,nom);	// Agrego el nombre a la estructura de persona
		// (*nodo)->persona.edad = edad;	// Agrego la edad a la estructura de persona
		// (*nodo)->sigNodo = NULL;		// Pongo en NULL la direccion del proximo nodo
		aux = (t_data) malloc(sizeof(struct s_data));
		strcpy(aux->persona.ape,ape);
		strcpy(aux->persona.nom,nom);
		aux->persona.edad = edad;
		aux->persona.dni = dni;
		aux->sigNodo = *nodo;
		*nodo = aux;
	}

	else{
		agregarALista(&(*nodo)->sigNodo, dni, ape, nom, edad);	 // Si no esta vacia la lista, de forma recursiva paso al siguiente nodo
	}
}

void ordernarPorDni(t_data* lista){
	t_data aux = NULL;
}



void cargarListaO(t_data* lista, char* nomArch){	
	/** CODIFICAR FUNCION **/

	FILE* archivo = fopen(nomArch,"r"); // Abro archivo
	int r, i;						// Declaro r (donde se almacena fscanf) ; i (indice)
	int dni, edad;
	char nombre[TAM];
	char apellido[TAM]; 
	char letra;	
	r = fscanf(archivo,"%d,",&dni); // Tomo el dni 

	while (r != EOF){
		i = 0;
		letra = fgetc(archivo);			// Empiezo a leer letras
		
		while(letra != ',' && letra != EOF){
			if(letra != ','){
				apellido[i] = letra;
				i++;
				letra = fgetc(archivo);
			}
			apellido[i] = '\0';
		} 

		i = 0;

		letra = fgetc(archivo);
		while(letra != ',' && letra != EOF){
			if(letra != ','){
				nombre[i] = letra;
				i++;
				letra = fgetc(archivo);
			}
			nombre[i] = '\0';
		}

		r = fscanf(archivo,"%d,",&edad); // Tomo la edad

		agregarALista(lista,dni,apellido,nombre,edad);	// Agrego a la lista los parametros tomados
		//ordernarPorDni(lista);

		r = fscanf(archivo,"%d,",&dni);	// Tomo el dni de la proxima persona
	}
	
	fclose(archivo);			// Cierro el archivo
}		
	

void imprimirListaR(t_data lista){	
 	/** CODIFICAR FUNCION **/	
	if(lista != NULL){
		printf("%-20s %-20s %-20s %-20s\n","DNI","APELLIDO","NOMBRE","EDAD");
        printf("%-20d %-20s %-20s %-20d\n",lista->persona.dni,lista->persona.ape,lista->persona.nom,lista->persona.edad);
        printf("*******************************************************************\n");
		imprimirListaR(lista->sigNodo);
    }
}
	
int letraEsVocal(char letra){
	int esVocal = 0;
	if(letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u'){
		esVocal = 1;
	}
	else{
		esVocal = 0;
	}
	return esVocal;
}



int cantidadDe(t_data lista){		// Recorro el campo nombre, y me fijo si tiene al menos 2 vocales 
	/** CODIFICAR FUNCION */	
	int i;
	int contadorVocales = 0;
	char nombre[TAM] = {0};
	int cantNodos = 0;

	if(lista != NULL){
		strcpy(nombre,lista->persona.nom);

		for(i = 0 ; nombre[i] != '\0' ; i++){
				// Recorro el nombre
			if(letraEsVocal(nombre[i]) == 1){ 
				contadorVocales++;				// Cuento cantidad de vocales
			}
		}
	}
	
	if(lista->sigNodo != NULL){
		cantNodos = cantidadDe(lista->sigNodo);
	}

	if(contadorVocales >= 2){
		return cantNodos+1;
	}
	else{
		return cantNodos;
	}
	

}


int main() {
	/**NO SE PUEDE CAMBIAR EL CÓDIGO DE main*/
	printf("TEMA_01\n\n");
	t_data lista = NULL;
	char nomArch[TAM] = "datos_t1.txt";
	
	cargarListaO(&lista,nomArch);
	imprimirListaR(lista);
	printf("\n");
	printf("La cantidad segun condicion es: %d", cantidadDe(lista));
	
	return 0;
}
	





