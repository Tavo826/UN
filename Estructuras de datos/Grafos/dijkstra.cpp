
/* ----------------------------------------------------------------------------
  algoritmo de Dijkstra, que calcula el camino mas corto entre el primer nodo
   y todos los demás en un grafo representado por su matriz de adyacencia
---------------------------------------------------------------------------- */

#include <stdio.h>
#include <conio.h>


#define MAX           30
#define INFINITO   60000

typedef int Matriz[MAX][MAX];  //es la matriz de adyacencia
typedef int Vector[MAX];

// Prototipos de las funciones

/*************************************************************************
  Funcion que inicializa la matriz de adyacencia
**************************************************************************/
void inicializarMat(Matriz mat)
{
   int x, y;
   for (x=0;x<MAX;x++)
      for (y=0;y<MAX;y++)
        mat[x][y]=INFINITO;
}

/*************************************************************************
  Funcion que inicializa un conjunto o vector
**************************************************************************/
void inicializarVec(Vector vec)
{
   int x;
   for (x=0;x<MAX;x++)
        vec[x]=0;
}

/*************************************************************************
  Funcion que determina si un elemento pertenece a un conjunto
**************************************************************************/
int perteneceVec(int w, Vector C)
{
   if (C[w]==1)
      return 1;
   else
      return 0;
}

/*************************************************************************
  Funcion que adiciona un elemento de un conjunto
**************************************************************************/
void adicionarVec(int w, Vector C)
{
  C[w]=1;
}

/*************************************************************************
  Funcion que elimina un elemento de un conjunto
**************************************************************************/
void eliminarVec(int w, Vector C)
{
  C[w]=0;
}

/*************************************************************************
  Funcion que muestra un vector o conjunto de 2 a n
**************************************************************************/
void mostrarVec(Vector vec, int tam)
{
   int x;
   printf("\nEl vector es : [ ");
   for (x=2;x<=tam;x++)
      printf("%3d, ",vec[x]);
   printf("]\n");
}


/*************************************************************************
  Funcion que muestra el grafo o matriz de adyacencia
**************************************************************************/
void mostrarMat1(Matriz L, int n)
{
   int x,y;
   printf("\nLa Matriz de adyacencia queda : \n");
   for (x=1;x<=n;x++)
     for (y=1;y<=n;y++)
     {
         if (L[x][y]!= INFINITO)
             printf("\n%d  -->  %d  = %d", x, y, L[x][y]);
     }
   printf("\n");
}

/*************************************************************************
  Funcion que muestra el grafo o matriz de adyacencia completa
**************************************************************************/
void mostrarMat2(Matriz L, int n)
{
   int x,y;
   printf("\nLa Matriz de adyacencia queda : \n");
   for (x=1;x<=n;x++) {
     for (y=1;y<=n;y++)
     {
         if (L[x][y]!= INFINITO)
           printf("%3d ", L[x][y]);
         else 
           printf("INF ", L[x][y]);
     }
     printf("\n");
   }
}

/*************************************************************************
  Funcion que llena la matriz de adyacencia
**************************************************************************/
void llenarMat(Matriz L, int *n)
{
  /* *n=5;
   inicializarMat(L);
   L[1][2]=5;
   L[2][3]=10;
   L[3][4]=15;
   L[4][5]=20;
   L[1][5]=8;
   */

   /* *n=5;
   L[1][2]=50;
   L[1][3]=30;
   L[1][4]=100;
   L[1][5]=10;
   L[3][2]=5;
   //L[4][2]=20;
   L[4][2]=10;
   L[4][3]=50;
   L[5][4]=10; 
   */
   
   /* *n=5;
   inicializarMat(L);
   L[1][2]=10;
   L[2][3]=15;
   L[3][4]=20;
   L[4][5]=25;*/
   
  *n=11; 
  inicializarMat(L);
  L[1][7]=2;     L[1][4]=13;   L[2][1]=1;     L[3][2]=2;
  L[3][5]= 30;   L[5][2]=5;    L[5][5]=4;     L[5][8]=14;
  L[6][3]=11;    L[6][9]=9;    L[7][4]=12;    L[7][6]=17;
  L[7][10]=8;    L[8][9]=3;    L[8][11]=6;    L[9][5]=15;    
  L[10][9]=8;    L[11][10]=7;

   
  /*n=9;
   inicializarMat(L);
   L[1][2]=10;
   L[1][8]=12;
   L[2][3]=6;
   L[3][1]=8;
   L[3][5]= 9;
   L[3][9]=3;
   L[4][7]=2;
   L[5][4]=8;
   L[5][7]=10;
   L[5][8]=2;
   L[7][6]=5;
   L[8][4]=7;
   L[9][7]=5; */
}

/*************************************************************************
  Funcion que minimiza el vector y regresa que valor lo hace
**************************************************************************/
int minimiza(Vector D, int n, Vector C)
{
   int menor, pos, x;
   menor=INFINITO;
   pos=0;
   for (x=2; x<=n; x++)
   {
      if (perteneceVec(x,C))
      {
         if (D[x]<menor)
         {
            menor=D[x];
            pos=x;
         }
      }
   }
   return pos;
}


/*************************************************************************
  Funcion que implementa el algoritmo Dijkstra
**************************************************************************/
void dijkstra(Matriz L, int n, Vector D, Vector P)
{
  int i,v,w;
  Vector C;

  inicializarVec(C);
  for (i=2;i<=n;i++)
      adicionarVec(i,C);

  for(i=2;i<=n;i++)
  {
     D[i]=L[1][i];
     P[i]= -1;
  }

  for(i=3;i<=n;i++)
    {
      v=minimiza(D,n,C);
      eliminarVec(v,C);
      for(w=1;w<=n;w++)
      {
	       if(perteneceVec(w,C))
	       {
	          if(D[w]>D[v]+ L[v][w])
	          {
	            D[w]=D[v]+L[v][w];
	            P[w]=v;
	          }
	        }
      }
    }
}


/*************************************************************************
  Funcion que muestra una ruta entre 1 y fin
**************************************************************************/
void ruta(Vector camino,int fin)
{
  int v;

  if (fin>=0)
  {
     v=camino[fin];
     if(v!= -1)
     {
       ruta(camino,v);
       printf("%d, ",v);
     }
  }
}

/*************************************************************************
  Funcion que muestra una ruta entre 1 y fin
**************************************************************************/
void mostrarRuta(int camino[],int final)
{
   printf(" [ 1, ");
   ruta(camino,final);
   printf("%d]\n",final);
}

/*************************************************************************
  Funcion principal del algoritmo de Dijstra
**************************************************************************/
int main(void) //programa principal
{
  Matriz L;
  Vector D, P;
  int n,x, opcion;

  llenarMat(L, &n);
  dijkstra(L,n, D, P);
  do {
     printf("\nAlgoritmo de Dijstra\n");
     printf("\nMostrar el grafo ....................... 1");
     printf("\nMostrar el Vector de costos D .......... 2");
     printf("\nMostrar el Vector de caminos P ......... 3");
     printf("\nMostrar el camino hasta un nodo ........ 4");
     printf("\nSalir del programa ..................... 0");
     printf("\nTeclee su opcion : ");
     scanf("%d",&opcion);
     switch (opcion) {
       case 1: mostrarMat1(L, n);
               mostrarMat2(L, n);
               break;
       case 2: printf("\nEl vector D queda : \n");
  			   mostrarVec(D,n);
       		   break;
       case 3: printf("\nEl vector P queda : \n");
			   mostrarVec(P,n);
       		   break;
       case 4: printf("\nPara cual nodo desea ver la ruta : ");
       		   scanf("%d",&x);
       		   printf("\n\nLa ruta para ir entre 1 y %d con costo %d es :",x, D[x]);
       		   mostrarRuta(P,x);
       		   printf("\nTeclee <Return> para continuar ");
       		   getch();
       		   break;
     }
  }while (opcion !=0);
}

