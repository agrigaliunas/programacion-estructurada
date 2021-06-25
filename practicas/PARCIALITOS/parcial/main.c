#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 20

struct s_fecha{
	unsigned int anio, mes, dia;
};
typedef struct s_fecha t_fecha;

struct sdata{
	char nom[TAM];
	t_fecha fecha;
};
typedef struct sdata t_data;		// Estructura contiene arreglo con NOMBRE y una estructura con FECHA (t_fecha)



void imprimirArch (char* nomArch);
t_data* cargarArr(char* nomArch);
void imprimirArr(t_data* arr);
void decode (t_fecha* fechaS, unsigned int fechaI);


int main() {
	/**NO SE PUEDE CAMBIAR EL C�DIGO DE main*/
	
	t_data* arr = NULL;
	char nomArch[TAM] = "datos_t1.txt";
	imprimirArch(nomArch);
	printf("\n");
	arr = cargarArr(nomArch);
	imprimirArr(arr);
	
	return 0;
}

void imprimirArch(char* nomArch){	
	/**NO SE PUEDE CAMBIAR EL C�DIGO .. */
	FILE* arch = fopen(nomArch,"r");
	char c;
	printf("El archivo %s contiene:\n",nomArch);
	c = fgetc(arch);
	while(!feof(arch)){
		printf("%c",c);
		c = fgetc(arch);
	}	
	fclose(arch);
}

void decode (t_fecha* fechaS, unsigned int fechaI){
	unsigned int maskDia = 496;	// 5 bits maximo
	unsigned int maskMes = 7680; // 4 bits maximo
	unsigned int maskAnio = 1073676288; // 14 bits maximo

	(*fechaS).dia = (maskDia&fechaI)>>4;
	(*fechaS).mes = (maskMes&fechaI)>>9;
	(*fechaS).anio = (maskAnio&fechaI)>>16;

}

t_data* cargarArr(char* nomArch){	// Retorna puntero a t_data
	t_data* arr = NULL;
	FILE* archivo = fopen(nomArch,"r");
	int indiceArr = 0;
	int indiceLetra;
	int fecha;
	char letra;
	arr = (t_data*) malloc(sizeof(t_data));
	letra = fgetc(archivo);
	while (letra != EOF){

		for(indiceLetra = 0 ; letra !=',' && indiceLetra < TAM ; indiceLetra++){
			arr[indiceArr].nom[indiceLetra] = letra;
			letra = fgetc(archivo);
		}

		arr[indiceArr].nom[indiceLetra] = '\0';
		arr[indiceArr].fecha.anio = 0;
		fscanf(archivo,"%d",&fecha);
		decode(&arr[indiceArr].fecha,fecha);
		indiceArr++;
		letra = fgetc(archivo);
		if(letra!=EOF){
			arr = (t_data*) realloc(arr, (indiceArr+1)*sizeof(t_data));
			decode(&arr[indiceArr].fecha,fecha);
		}
	}

	fclose(archivo);
	return arr;
}	

void imprimirArr(t_data* arr){
	/* CODIFICAR FUNCION */
	int i;
	if(arr != NULL){
		printf("\nContenido decodificado del archivo es:\n");
		printf("\nNOMBRE\t DIA\t MES\t ANIO\n");
		for(i = 0 ; arr[i].fecha.anio != 0; i++){
			printf("%s\t%d\t%d\t%d",arr[i].nom,arr[i].fecha.dia,arr[i].fecha.mes,arr[i].fecha.anio);
		}
	}
}
