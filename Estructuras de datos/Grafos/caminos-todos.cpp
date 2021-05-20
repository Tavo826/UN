#include <stdio.h>

#define MAX 10
#define INF 9999

typedef int Matriz[MAX][MAX];

void mostrar(int cam[], int n){
	printf("\nEl camino es :\n");
	for (int x=0;x<n;x++)
	   printf("%4d - ",cam[x]);
	printf("\n");
	getchar();
}

int longcamino(int cam[], int m, Matriz mat, int n) {
	int suma=0;
	if (m==0)
	   return INF;
	for (int i=0;i<m-1;i++)
	   suma += mat[cam[i]][cam[i+1]];
	return suma;
}

bool noesta(int x, int cam[], int n){
	for (int i=0;i<n;i++) {
	   if (cam[i]==x)
	      return false;
    }
	return true;
}

void copiarVector(int origen[], int n, int destino[], int &m) {
	for (int x=0;x<n;x++)
	   destino[x]=origen[x];
	m=n;
}

void camino(Matriz mat, int n, int ini, int fin, int ruta[], int nr, int mejor[], int &lm) {
	if (ini==fin) {
	   int tam=longcamino(ruta,nr,mat,n);
	   printf("\nLa longitud es : %d",tam);
	   mostrar(ruta,nr);
	   int tam1=longcamino(mejor,lm,mat,n);
	   if (tam<tam1)
	      copiarVector(ruta,nr,mejor,lm);
   }
	else {
       for (int x=0;x<n;x++){
       	  if (mat[ini][x]!=INF &&  noesta(x,ruta,nr)){
       	  	   ruta[nr]=x;
       	  	   camino(mat,n,x,fin,ruta,nr+1,mejor,lm);
       	  	   ruta[nr]=-1;
			}
	   }
	}
}

void LeerGrafo(Matriz grafo, int &n){
	for (int x=0;x<MAX;x++)
	   for (int y=0;y<MAX;y++)
	      grafo[x][y]=INF;
	grafo[0][1]=grafo[1][0]=10;
	grafo[0][2]=grafo[2][0]=5;
	grafo[1][3]=grafo[3][1]=4;
	grafo[1][4]=grafo[4][1]=12;
	grafo[2][4]=grafo[4][2]=8;
	grafo[4][3]=grafo[3][4]=3;
	grafo[4][5]=grafo[5][4]=2;
	grafo[3][5]=grafo[5][3]=4;
	n=6;
}

int main(void){
	Matriz grafo;
	int n;
	LeerGrafo(grafo, n);
	int ruta[n], nr=0, ini, fin;
	int mejor[n], lm=0;
	ini=0; fin=5;
	ruta[nr++]=ini;
	camino(grafo,n,ini,fin,ruta,nr,mejor,lm);
	printf("\nEl mejor camino es :\n");
	mostrar(mejor,lm);
	getchar();
}
