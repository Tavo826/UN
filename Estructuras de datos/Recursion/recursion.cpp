#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int Matriz[MAX][MAX];

void mostrarMat(int mat[][MAX], int m, int n, int i, int j){
	if (i<m){
		if (j<n){
			printf("%4d",mat[i][j]);
			mostrarMat(mat,m,n,i,j+1);
		}
		else {
		   printf("\n");	
		   mostrarMat(mat,m,n,i+1,0);
	    }       
	}
}

bool buscar(int *vector, int inicio, int fin, int valor){
	int medio;
	if (inicio>fin)
	   return false;
	else {
		medio=(int) (inicio+fin)/2;
		if (vector[medio]==valor) {
		   return true;
	   }
		else {	
		  if (vector[medio]>valor)
		    return buscar(vector,inicio,medio-1, valor);
		  else
		    return buscar(vector,medio+1, fin,valor);
	    }
	}
}

bool buscar(int *vector, int n, int valor){
	if (n==0)
	    return false;
	else
	  if (vector[n-1]==valor)
	     return true;
	else
         return buscar(vector,n-1,valor);	
}

int suma(int vector[], int n){
	if (n==0)
	   return 0;
	else
	   return vector[n-1]+suma(vector,n-1);
}

int suma(int vector[], int n, int i){
	if (i==n)
	   return 0;
	else
	   return vector[i]+suma(vector,n, i+1);
}

void suma(int vector[], int n, int i, int *resp){
	if (i<n) {
	   (*resp)+=vector[i];
	   suma(vector,n, i+1, resp);
    }
}

void mostrar(int vector[], int n){
	if (n>0) {
		//printf("%d ", vector[n-1]);
		mostrar(vector,n-1);
		printf("%d ", vector[n-1]);
	}
}

void mostrar(int vector[], int n, int i){
	if (i<n) {
		printf("%d ", vector[i]);
		mostrar(vector,n, i+1);
	}
}

int potenciaRec(int x, int n){
	if (n==0)
	   return 1;
	else
	   if (n==1)
	      return x;
	   else
	      return x* potenciaRec(x,n-1);
}

int potencia(int x, int n){
	if (x==0)
	   return 0;
	else
	  if (n<0)
	    return -potenciaRec(x,-n);
	  else 
	     return potenciaRec(x,n);
}


float fiboRec(int n) {
	if (n==1 || n==2)
	   return 1.0;
	else
	   return fiboRec(n-1)+fiboRec(n-2);
}

float fibo(int n) {
  float p,s,t;
  p=s=t=1.0;
  while (n>2) {
  	t=p+s;
  	s=p;
  	p=t;
  	n--;
  }	
  return t;
}


void iniciar1(int mat[][MAX]){
	for (int i=0;i<MAX;i++)
	  for (int j=0;j<MAX;j++)
	    mat[i][j]=rand()%20;
}

void iniciar2(int mat[][MAX]){
	for (int i=0;i<MAX;i++)
	  for (int j=0;j<MAX;j++)
	    mat[i][j]=rand()%20;
}

//---------------------

bool ordenado(int vector[], int n){
	if(n==0 || n==1){
		return true;
	}
	else{
		if (vector[n-1]<vector[n-2]){
			return false;
		}
		else{
			//printf("%d",vector[n-1]);
			return ordenado(vector,n-1);
		}
	}
}

int ordenar(int vector[],int n){
	int temp=0;
	while(!ordenado(vector,n)){
		if (n>=0){		
		
			if (vector[n-1]<vector[n-2]){
				temp=vector[n-1];
				vector[n-1]=vector[n-2];
				vector[n-2]=temp;
			}
			else{
				ordenar(vector,n-1);
			}
		}
	}
}

int prod(int vector1[], int vector2[], int n){
	if (n==0){
		return 0;
	}
	else{
		return vector1[n-1]*vector2[n-1]+prod(vector1, vector2, n-1);
	}
}

bool ordenada(int mat[][MAX], int n, int i){
	if(n==0 || n==1){
		return true;
	}
	else{
		if (mat[i][n]<mat[i][n-1]){
			return false;
		}
		else{
			return ordenada(mat,n-1,i);
		}
	}
}

void ordenarFilas(int mat[][MAX], int m, int n){
	int temp=0;
	if (m>0){
		
		printf("entra1");
		
		if (!ordenada(mat,n,m)){
			
			printf("entra2");
				
			if (n>0){
			
				if(mat[m][n-1] > mat[m][n]){
					temp = mat[m][n-1];
					mat[m][n-1] = mat[m][n];
					mat[m][n] = temp;
				}
			
				ordenarFilas(mat,m,n-1);
			
			}		
		}
		else{
			ordenarFilas(mat,m-1,n);
		}
		
	}
}

//---------------------

int main(void) {
	int n=10;
	int vec[]= {1,2,3,4,5,6,7,8,9,10};
	int vec1[]={9,3,4,7,5,6,8,1,2,0};
	int mat1[MAX][MAX];
	int mat2[MAX][MAX];
	iniciar1(mat1);
	mostrarMat(mat1,MAX,MAX,0,0);
	printf("\n");
	iniciar2(mat2);
	mostrarMat(mat2,MAX,MAX,0,0);
	/*
	mostrar(vec,n,0);
	printf("\nLa suma es : %d",suma(vec,n));
	int respuesta=0;
	suma(vec,n,0,&respuesta);
	printf("\nLa respuesta es : %d",respuesta);
	if (buscar(vec,0,n-1,20))
	   printf("\nSi esta");
	else
	   printf("\nNo esta");
	/*printf("El fibonacci es : %.0f ",fibo(n));
	printf("El fibonacci Rec es : %.0f",fiboRec(n));*/
	
	/*
	if(ordenado(vec,n)){
		printf("\nEl vector esta ordenado");
	}
	else{
		printf("\nEl vector esta desordenado");
	}
	
	printf("\nOrdenado: \n");
	ordenar(vec1,n);
	for (int i=0;i<n;i++){
		printf("%d",vec1[i]);
	}
	*/
	printf("\nProducto Punto: \n");
	printf("%d",prod(vec,vec1,n));
	
	ordenarFilas(mat1,MAX,MAX);
	printf("\nMatriz Ordenada:\n");
	mostrarMat(mat1,MAX,MAX,0,0);
	
	
}
