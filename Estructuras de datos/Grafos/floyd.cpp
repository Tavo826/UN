
/* ----------------------------------------------------------------------------
  algoritmo de Floyd, que calcula el camino mas corto entre el primer nodo
   y todos los demás en un grafo representado por su matriz de adyacencia
---------------------------------------------------------------------------- */

#include <stdio.h>
#include <conio.h>


#define MAX           30
#define INFINITO  60000

typedef int Matriz[MAX][MAX];  //es la matriz de adyacencia


// Prototipos de las funciones

/*************************************************************************
  Funcion que inicializa la matriz de adyacencia
**************************************************************************/
void inicializarMat(Matriz mat, int tipo)
{
   int x, y;
   for (x=0;x<MAX;x++)
      for (y=0;y<MAX;y++)
        if (tipo==1) {
           if (x==y)
             mat[x][y]=0;
           else
             mat[x][y]=INFINITO;
        }
        else
           mat[x][y]=-1;
}  

/*************************************************************************
  Funcion que muestra el grafo o matriz de adyacencia
**************************************************************************/
void mostrarMat(Matriz L, int n)
{
   int x,y;
   printf("\nLa Matriz de adyacencia queda : \n");
   for (x=1;x<=n;x++) {
     for (y=1;y<=n;y++)
     {
         /*if (L[x][y]!= INFINITO)
             printf("\n%d  -->  %d  = %d", x, y, L[x][y]);*/
         printf("%5d",L[x][y]);
     }
     printf("\n");
   }
   getchar();
}

/*************************************************************************
  Funcion que llena la matriz de adyacencia
**************************************************************************/
void llenarMat(Matriz L, int *n)
{
  /* *n=5;
   inicializarMat(L,1);
   L[1][2]=50;
   L[1][3]=30;
   L[1][4]=100;
   L[1][5]=10;
   L[3][2]=5;
   L[4][2]=20;
   L[4][3]=50;
   L[5][4]=10; */

/* *n=5;
   inicializarMat(L,1);
   L[1][2]=10;
   L[2][3]=15;
   L[3][4]=20;
   L[4][5]=25;
*/
  *n=6;
   inicializarMat(L,1);
   L[1][2]=15;
   L[1][3]=10;
   L[2][1]=15;
   L[2][4]=5;
   L[3][1]=10;
   L[3][4]=8;
   L[3][5]=12;
   L[4][2]=5;
   L[4][3]=8;
   L[4][5]=2;
   L[4][6]=4;
   L[5][3]=12;
   L[5][4]=2; 
   L[6][4]=4;
}


/*************************************************************************
  Funcion que implementa el algoritmo Dijkstra
**************************************************************************/
void floyd(Matriz L, int n, Matriz P)
{
  int i,j,k,v;

  for(k=1;k<=n;k++)
     for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
	        if(L[i][j]>L[i][k]+ L[k][j])
	        {
	           L[i][j]=L[i][k]+ L[k][j];
	           P[i][j]=k;
	        }
}


/*************************************************************************
  Funcion que muestra una ruta entre 1 y fin
**************************************************************************/
void ruta1(Matriz camino,int inicio, int fin)
{
  int v;

  if (inicio != fin)
  {
     v=camino[inicio][fin];
     if(v!= -1)
     {
       ruta1(camino,inicio,v);
       printf("%d, ",v);
       ruta1(camino,v,fin);
     }
  }
}

/*************************************************************************
  Funcion que muestra una ruta entre 1 y fin
**************************************************************************/
void mostrarRuta1(Matriz camino,int inicio, int final)
{
   printf(" [ %d, ",inicio);
   ruta1(camino,inicio,final);
   printf("%d]\n",final);
}

/*************************************************************************
  Funcion que muestra una ruta entre 1 y fin
**************************************************************************/
void ruta2(Matriz camino,int inicio, int fin)
{
  int v;

  if (fin>=0)
  {
     v=camino[inicio][fin];
     if(v!= -1)
     {
       ruta2(camino,inicio,v);
       //printf("%d, ",v);
       ruta2(camino,v,fin);
     }
     else
       printf("%d, ",fin);
  }
}

/*************************************************************************
  Funcion que muestra una ruta entre 1 y fin
**************************************************************************/
void mostrarRuta2(Matriz camino,int inicio, int final)
{
   printf(" [ %d, ",inicio);
   ruta2(camino,inicio,final);
   //printf("%d]\n",final);
}
/*************************************************************************
  Funcion principal del algoritmo de Dijstra
**************************************************************************/
int main(void) //programa principal
{
  Matriz L,P;
  int n,ini,fin, opcion;
  
  llenarMat(L, &n);
  //mostrarMat(L, n);
  inicializarMat(P,0);
  //floyd(L, n, P);
  do {
     printf("\nAlgoritmo de Floyd - Warshall\n");
     printf("\nMostrar el grafo ....................... 1");
     printf("\nMostrar la matriz de caminos P ......... 2");
     printf("\nCalcular Floyd  ........................ 3");
     printf("\nMostrar el camino hasta un nodo ........ 4");
     printf("\nSalir del programa ..................... 0");
     printf("\nTeclee su opcion : ");
     scanf("%d",&opcion);
     switch (opcion) {
       case 1: mostrarMat(L, n);
               break;
       case 2: printf("\nEl vector P queda : \n");
			   mostrarMat(P,n);
       			break;
	   case 3:  floyd(L, n, P);
               break; 	
       case 4: printf("\nDesde cual nodo desea ver la ruta : ");
       		   scanf("%d",&ini);
       		   printf("\nHasta cual nodo desea ver la ruta : ");
       		   scanf("%d",&fin);
       		   printf("\n\nLa ruta 1 para ir entre %d y %d con costo %d es :",ini, fin, L[ini][fin]);
   			   mostrarRuta1(P,ini,fin);
   			   printf("\n\nLa ruta 2 para ir entre %d y %d con costo %d es :",ini, fin, L[ini][fin]);
   			   mostrarRuta2(P,ini,fin);
       		   printf("\nTeclee <Return> para continuar ");
       		   getch();
       		   break;
     }
  }while (opcion !=0);
}

