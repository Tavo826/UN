#include <stdio.h>
#include <malloc.h>

void crearMat(int ***mat, int m, int n) {
	*mat=(int **) malloc(sizeof(int *)*m);
	for (int x=0;x<m;x++)
	   (*mat)[x]=(int *) malloc (sizeof(int)*n);
}

void llenarMat(int **mat, int m, int n) {
	int cont=0;
	for (int x=0;x<m;x++)
	   for (int y=0;y<n;y++)
	      mat[x][y]=cont++;
	
}

void mostrarMat(int **mat, int m, int n) {
	for (int x=0;x<m;x++) {
	   for (int y=0;y<n;y++) 
	      printf("%4d",mat[x][y]);
	    printf("\n");
   }	    
}

int main(void) {
	int **mat;
	int m,n;
	m=3;
	n=4;

	crearMat(&mat,m,n);
	llenarMat(mat,m,n);
	mostrarMat(mat,m,n);
}
