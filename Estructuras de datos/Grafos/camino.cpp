#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 99999

void mostrarGrafo(int g[MAX][MAX], int n){
	printf("\nLa matriz de adyacencia es :\n");
	for (int x=0;x<n;x++) {
	  for (int y=0;y<n;y++)
	    if (g[x][y]==INF)
	      printf("   INF ");
	    else
	      printf("%5d",g[x][y]);
	  printf("\n");
    }
}

void mostrarCamino(int cam[], int n){
	printf("\nEl camino es :\n");
	for (int x=0;x<n;x++) 
	    printf("%4d",cam[x]);
	  printf("\n");
}

bool noesta(int vector[], int n, int quien){
	for (int i=0;i<n;i++)
	   if (vector[i]==quien)
	      return false;
	return true;
}

int cualmejor(int g[MAX][MAX], int n, int i, int f, int ruta[], int nr) {
	int menor=INF, pos=-1;
	for (int x=0;x<n;x++){
		if (g[i][x]<menor && noesta(ruta,nr,x)) {
			pos=x;
			menor=g[i][x];
		}
	}
	return pos;
}

void camino(int grafo[MAX][MAX], int n, int ini, int fin, int ruta[], int &nr){
	int sgte;
	ruta[0]=ini;
	nr=1;
	while (ini!=fin) {
		sgte=cualmejor(grafo,n,ini,fin,ruta,nr);
		if (sgte!=-1) {
			ruta[nr++]=sgte;
			ini=sgte;
		}
		else {
			printf("\n_No hay camino");
			return;
		}
	}
}

void crearGrafo(int grafo[MAX][MAX], int &n){
	n=5;
	for (int x=0;x<n;x++)
	  for (int y=0;y<n;y++)
	    grafo[x][y]=INF;
	grafo[0][1]=grafo[1][0]=10;
	grafo[0][2]=grafo[2][0]=15;
	grafo[1][2]=grafo[2][1]=5;
	grafo[1][3]=grafo[3][1]=20;
	grafo[2][4]=grafo[4][2]=4;
	grafo[3][4]=grafo[4][3]=15;
}

int main(void){
  int grafo[MAX][MAX], n, ruta[MAX], nr;
  int ini=0;
  int fin=4;
  crearGrafo(grafo,n);
  mostrarGrafo(grafo,n);
  camino(grafo, n, ini, fin, ruta,  nr);
  mostrarCamino(ruta,nr);
  getchar();	
}
