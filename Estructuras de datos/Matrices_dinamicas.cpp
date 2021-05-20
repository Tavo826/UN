#include <stdio.h>
#include <stdlib.h>

void menu(int *opcion){
		
	printf("Escoja el tipo de dato: \n\n");
	printf("1. Entero (4 bytes) \n");
	printf("2. Flotante (8 bytes) \n");
	printf("3. Doble (16 bytes) \n");		
	printf("4. Caracter (1 byte) \n");
	printf("5. Salir \n\n");
	printf("Digite su opcion: ");
	scanf("%d",&*opcion);
}

void filas_columnas(int *m, int *n){
	int band=0;
	while(band==0){
		
		printf("\n\nIngrese el numero de filas de la matriz: ");
		scanf("%d",&*m);
		printf("Ingrese el numero de columnas de la matriz: ");
		scanf("%d",&*n);
		
		if (*n>0 && *m>0){
			band=1;
		}
		else{
			printf("Cantidad no valida");
		}
	}
}

void matriz_entera(int **&matriz,int *m,int *n){
	
	printf("\n\nMATRIZ DE ENTEROS");
	
	filas_columnas(&*m, &*n);
	
	matriz=(int**)malloc(sizeof(int*)**m);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<*m;x++){
		matriz[x]=(int*)malloc(sizeof(int)**n);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	printf("\n\nIngresando Elementos:\n\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("Deme el valor a ubicar en la posicion (%d,%d):  ", i+1,j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n\nMatriz Ingresada:\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
}

void multiplicacion_entera(int **&matriz_1, int **&matriz_2, int **&matriz, int m1, int n1, int m2, int n2){
	
	matriz=(int**)malloc(sizeof(int*)*m1);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<m1;x++){
		matriz[x]=(int*)malloc(sizeof(int)*n2);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			matriz[i][j]=0;
			for (int k=0;k<m2;k++){
				matriz[i][j]=(matriz[i][j]+(matriz_1[i][k]*matriz_2[k][j]));
			}
		}
	}
	
	printf("\n\nImpimiendo operacion:\n\n");
	
	printf("Matriz 1\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n1;j++){
			printf("%d ", matriz_1[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz 2\n");
	
	for (int i=0;i<m2;i++){
		for (int j=0;j<n2;j++){
			printf("%d ", matriz_2[i][j]);
		}
		printf("\n");
	}
	
	printf("\nResultado\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}		
}

void matriz_flotante(float **&matriz,int *m,int *n){
	
	printf("\n\nMATRIZ DE FLOTANTES");
	
	filas_columnas(&*m, &*n);
	
	matriz=(float**)malloc(sizeof(float*)**m);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<*m;x++){
		matriz[x]=(float*)malloc(sizeof(float)**n);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	printf("\n\nIngresando Elementos:\n\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("Deme el valor a ubicar en la posicion (%d,%d):  ", i+1,j+1);
			scanf("%f", &matriz[i][j]);
		}
	}
	
	printf("\n\nMatriz Ingresada:\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("%.2f ", matriz[i][j]);
		}
		printf("\n");
	}	
}

void multiplicacion_flotante(float **&matriz_1, float **&matriz_2, float **&matriz, int m1, int n1, int m2, int n2){
	
	matriz=(float**)malloc(sizeof(float*)*m1);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<m1;x++){
		matriz[x]=(float*)malloc(sizeof(float)*n2);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			matriz[i][j]=0;
			for (int k=0;k<m2;k++){
				matriz[i][j]=(matriz[i][j]+(matriz_1[i][k]*matriz_2[k][j]));
			}
		}
	}
	
	printf("\n\nImpimiendo operacion:\n\n");
	
	printf("Matriz 1\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n1;j++){
			printf("%.2f ", matriz_1[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz 2\n");
	
	for (int i=0;i<m2;i++){
		for (int j=0;j<n2;j++){
			printf("%.2f ", matriz_2[i][j]);
		}
		printf("\n");
	}
	
	printf("\nResultado\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			printf("%.2f ", matriz[i][j]);
		}
		printf("\n");
	}		
}

void matriz_doble(double **&matriz,int *m,int *n){
	
	printf("\n\nMATRIZ DE DOBLES");
	
	filas_columnas(&*m, &*n);
	
	matriz=(double**)malloc(sizeof(double*)**m);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<*m;x++){
		matriz[x]=(double*)malloc(sizeof(double)**n);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	printf("\n\nIngresando Elementos:\n\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("Deme el valor a ubicar en la posicion (%d,%d):  ", i+1,j+1);
			scanf("%lf", &matriz[i][j]);
		}
	}
	
	printf("\n\nMatriz Ingresada:\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("%.2lf ", matriz[i][j]);
		}
		printf("\n");
	}	
}

void multiplicacion_doble(double **&matriz_1, double **&matriz_2, double **&matriz, int m1, int n1, int m2, int n2){
	
	matriz=(double**)malloc(sizeof(double*)*m1);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<m1;x++){
		matriz[x]=(double*)malloc(sizeof(double)*n2);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			matriz[i][j]=0;
			for (int k=0;k<m2;k++){
				matriz[i][j]=(matriz[i][j]+(matriz_1[i][k]*matriz_2[k][j]));
			}
		}
	}
	
	printf("\n\nImpimiendo operacion:\n\n");
	
	printf("Matriz 1\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n1;j++){
			printf("%.2lf ", matriz_1[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz 2\n");
	
	for (int i=0;i<m2;i++){
		for (int j=0;j<n2;j++){
			printf("%.2lf ", matriz_2[i][j]);
		}
		printf("\n");
	}
	
	printf("\nResultado\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			printf("%.2lf ", matriz[i][j]);
		}
		printf("\n");
	}		
}

void matriz_caracter(char **&matriz,int *m,int *n){
	
	printf("\n\nMATRIZ DE CARACTERES");
	
	filas_columnas(&*m, &*n);
	
	matriz=(char**)malloc(sizeof(char*)**m);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<*m;x++){
		matriz[x]=(char*)malloc(sizeof(char)**n);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	printf("\n\nIngresando Elementos:\n\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("Deme el valor a ubicar en la posicion (%d,%d):  ", i+1,j+1);
			scanf(" %c", &matriz[i][j]);
		}
	}
	
	printf("\n\nMatriz Ingresada:\n");
	
	for (int i=0;i<*m;i++){
		for (int j=0;j<*n;j++){
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
	
}

/*void multiplicacion_caracter(char **&matriz_1, char **&matriz_2, char **&matriz, int m1, int n1, int m2, int n2){
	
	matriz=(char**)malloc(sizeof(char*)*m1);
	
	if (matriz==NULL){
		printf("No hay espacio en memoria\n");
		exit(1);
	}
	
	for (int x=0;x<m1;x++){
		matriz[x]=(char*)malloc(sizeof(char)*n2);
		
		if (matriz[x]==NULL){
			printf("No hay espacio en memoria\n");
			exit(1);
		}
	}
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			matriz[i][j]=0;
			for (int k=0;k<m2;k++){
				matriz[i][j]=(matriz[i][j]+(matriz_1[i][k]*matriz_2[k][j]));
			}
		}
	}
	
	printf("\n\nImpimiendo operacion:\n\n");
	
	printf("Matriz 1\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n1;j++){
			printf("%c ", matriz_1[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz 2\n");
	
	for (int i=0;i<m2;i++){
		for (int j=0;j<n2;j++){
			printf("%c ", matriz_2[i][j]);
		}
		printf("\n");
	}
	
	printf("\nResultado\n");
	
	for (int i=0;i<m1;i++){
		for (int j=0;j<n2;j++){
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}		
}*/

int main (void){
	char opc_mult;
	int opc_menu, m1, n1, m2, n2;
	int band_menu=0, band_mult=0;
	
	int **matriz_ent_1;
	int **matriz_ent_2;
	int **matriz_ent;
	
	float **matriz_float_1;
	float **matriz_float_2;
	float **matriz_float;
	
	double **matriz_doble_1;
	double **matriz_doble_2;
	double **matriz_doble_res;
	
	char **matriz_char_1;
	
	while (band_menu==0){	
		menu(&opc_menu);
		
		switch(opc_menu){
			
			case 1:
				matriz_entera(matriz_ent_1, &m1, &n1);
				band_menu=1;				
			break;
			
			case 2:				
				matriz_flotante(matriz_float_1, &m1, &n1);
				band_menu=1;				
			break;
			
			case 3:
				matriz_doble(matriz_doble_1, &m1, &n1);
				band_menu=1;
			break;
			
			case 4:
				matriz_caracter(matriz_char_1, &m1, &n1);
				band_menu=1;
			break;
				
			case 5:
				exit(1);
			break;
			
			default:
				printf("\nOpcion no valida");
				exit(1);
			break;
						
		}		
	}
	
	printf("\n\nQuiere hacer una multiplicacion?: (y/n)");
	
	while (band_mult==0){
		
		printf("\nDigite una opcion: ");
		scanf(" %c", &opc_mult);
		
		if (opc_mult=='y' || opc_mult=='n'){
			band_mult=1;	  				
		}		
	}
	
	if (opc_mult=='y'){
		
		switch(opc_menu){
			
			case 1:
				matriz_entera(matriz_ent_2, &m2, &n2);
				multiplicacion_entera(matriz_ent_1, matriz_ent_2, matriz_ent, m1, n1, m2, n2);
				
				for (int i=0;i<m1;i++){
					free(matriz_ent_1[i]);
				}
				free(matriz_ent_1);
	
				for (int i=0;i<m2;i++){
					free(matriz_ent_2[i]);
				}
				free(matriz_ent_2);
	
				for (int i=0;i<m1;i++){
					free(matriz_ent[i]);
				}
				free(matriz_ent);
				
			break;
			
			case 2:
				matriz_flotante(matriz_float_2, &m2, &n2);
				multiplicacion_flotante(matriz_float_1, matriz_float_2, matriz_float, m1, n1, m2, n2);
				
				for (int i=0;i<m1;i++){
					free(matriz_float_1[i]);
				}
				free(matriz_float_1);
	
				for (int i=0;i<m2;i++){
					free(matriz_float_2[i]);
				}
				free(matriz_float_2);
	
				for (int i=0;i<m1;i++){
					free(matriz_float[i]);
				}
				free(matriz_float);
				
			break;
			
			case 3:
				matriz_doble(matriz_doble_2, &m2, &n2);
				multiplicacion_doble(matriz_doble_1, matriz_doble_2, matriz_doble_res, m1, n1, m2, n2);
				
				for (int i=0;i<m1;i++){
					free(matriz_doble_1[i]);
				}
				free(matriz_doble_1);
	
				for (int i=0;i<m2;i++){
					free(matriz_doble_2[i]);
				}
				free(matriz_doble_2);
	
				for (int i=0;i<m1;i++){
					free(matriz_doble_res[i]);
				}
				free(matriz_doble_res);
				
			break;
			
			case 4:
				
				printf("\n\nNo es posible realizar multiplicacion de caracteres");
				exit(1);
				
				/*matriz_caracter(matriz_char_2, &m2, &n2);
				multiplicacion_caracter(matriz_char_1, matriz_char_2, matriz_char, m1, n1, m2, n2);
				
				for (int i=0;i<m1;i++){
					free(matriz_char_1[i]);
				}
				free(matriz_char_1);
	
				for (int i=0;i<m2;i++){
					free(matriz_char_2[i]);
				}
				free(matriz_char_2);
	
				for (int i=0;i<m1;i++){
					free(matriz_char[i]);
				}
				free(matriz_char);*/
				
			break;
						
		}				
	}
	else{
		
		switch (opc_menu){
			
			case 1:
				for (int i=0;i<m1;i++){
					free(matriz_ent_1[i]);
				}
				free(matriz_ent_1);
			break;
			
			case 2:
				for (int i=0;i<m1;i++){
					free(matriz_float_1[i]);
				}
				free(matriz_float_1);				
			break;
			
			case 3:
				for (int i=0;i<m1;i++){
					free(matriz_doble_1[i]);
				}
				free(matriz_doble_1);
			break;
			
			case 4:
				for (int i=0;i<m1;i++){
					free(matriz_char_1[i]);
				}
				free(matriz_char_1);
			break;
			
		}
		
		exit(1);
	}
	
	matriz_ent_1=NULL;
	matriz_ent_2=NULL;
	matriz_ent=NULL;
	
	matriz_float_1=NULL;
	matriz_float_2=NULL;
	matriz_float=NULL;
	
	matriz_doble_1=NULL;
	matriz_doble_2=NULL;
	matriz_doble_res=NULL;
		
	return 0;
}
