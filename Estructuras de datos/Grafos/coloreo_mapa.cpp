#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 9999

void crearGrafo(int grafo[MAX][MAX], int n){
	for (int x=0;x<n;x++){
		for (int y=0;y<n;y++){
			grafo[x][y]=0;
		}
	}
	grafo[0][1]=1;
	grafo[0][2]=1;
	grafo[1][0]=1;
	grafo[1][2]=1;
	grafo[1][3]=1;
	grafo[2][0]=1;
	grafo[2][1]=1;
	grafo[2][3]=1;
	grafo[2][4]=1;
	grafo[3][1]=1;
	grafo[3][2]=1;
	grafo[3][4]=1;
	grafo[4][2]=1;
	grafo[4][3]=1;
}

void mostrarGrafo(int grafo[MAX][MAX], int n){
	for (int x=0;x<n;x++){
		for (int y=0;y<n;y++){
			printf("%d", grafo[x][y]);
		}
		printf("\n");
	}
}

void pintarMapa(int grafo[MAX][MAX], int n, int colores[], int nr){
	colores[0]=1;
	int color;
	for (int x=0;x<n;x++){
		color=colores[x];
		for (int pos=0; pos<v;pos++){
			if (grafo[x][pos] == 0){
				colores[pos]
			}
		}
	}
}

bool confirmarColoreado(int grafo[MAX][MAX], int n, int colores[]){
	for(int x=0;x<n;x++){
		int color=colres[x];
		for(int vecino=0;vecino<n;vecino++){
			if(grafo[x][vecino] && colores[vecino]==color){
				return false;
			}
		}
	}
	return true;
}

int main(void){
	int grafo[MAX][MAX], n=5, colores[MAX];
	crearGrafo(grafo,n);
	mostrarGrafo(grafo,n);
}
