#include "arbolesvec.h"

int main(void){
    int arbolito[MAX];
    int raiz=0, n=20;
    inicializar(arbolito,MAX);
    //leerdatosArbol(arbol,raiz,n);
    insertarArbol(arbolito,raiz,50);
	insertarArbol(arbolito,raiz,30);
	insertarArbol(arbolito,raiz,80);
	insertarArbol(arbolito,raiz,10);
	insertarArbol(arbolito,raiz,40);
	insertarArbol(arbolito,raiz,60);
	insertarArbol(arbolito,raiz,90);
	insertarArbol(arbolito,raiz,5);
	printf("\nEl arbol entreOrden queda : \n");
	entreOrden(arbolito,raiz);
	printf("\nEl arbol preOrden queda : \n");
	preOrden(arbolito,raiz);
	printf("\nEl arbol posOrden queda : \n");
	posOrden(arbolito,raiz);
	printf("\nEl arbol por niveles queda : \n");
	recorrernivelesArbol(arbolito,raiz);
	if (completo(arbolito,raiz))
	  printf("\nEs completo");
	else
	  printf("\nNO Es completo");
	eliminarArbol(arbolito,raiz,50);
    eliminarArbol(arbolito,raiz,30);
	eliminarArbol(arbolito,raiz,80);
	eliminarArbol(arbolito,raiz,10);
	printf("\nEl arbol por niveles queda : \n");
	recorrernivelesArbol(arbolito,raiz);
	eliminarArbol(arbolito,raiz,40);
	eliminarArbol(arbolito,raiz,60);
	eliminarArbol(arbolito,raiz,90);
	eliminarArbol(arbolito,raiz,5);
	printf("\nEl arbol por niveles queda : \n");
	recorrernivelesArbol(arbolito,raiz);
    getchar();
}
