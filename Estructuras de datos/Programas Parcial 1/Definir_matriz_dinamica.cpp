#include<stdio.h>
#include<stdlib.h>

void filasColumnas(int *m, int *n){
	int band=0;
	while (band==0){
		printf("Deme el numero de filas: ");
		scanf("%d",m);
		printf("Deme el numero de columnas: ");
		scanf("%d",n);
		
		if (m>0 && n>0){
			band=1;
		}
		else{
			printf("Cantidad no valida\n");
		}
	}
	printf("m1=%p n1=%p\n",m,n);
}

void crearMatriz(int ***matriz,int m,int n){
	*matriz=(int**)malloc(sizeof(int*)*m);
	if (*matriz==NULL){
		printf("1. No hay espacio en memoria");
		exit(1);
	}
	for (int i=0;i<n;i++){
		(*matriz)[i]=(int*)malloc(sizeof(int)*n);
		if ((*matriz)[i]==NULL){
			printf("2. No hay espacio en memoria");
			exit(1);
		}
	}	
}

void llenarMatriz(int **matriz,int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Ingrese el valor %d,%d: ", i+1,j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
}

void imprimirMatriz(int **matriz, int m, int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int m,n;
	int **matriz;
	filasColumnas(&m,&n);
	printf("m=%p n=%p\n",&m,&n);
	crearMatriz(&matriz,m,n);
	llenarMatriz(matriz,m,n);
	imprimirMatriz(matriz,m,n);
	
	return 0;
}
