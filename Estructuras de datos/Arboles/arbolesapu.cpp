#include "arbolesapu.h" 

int main(void){
	TipoArbol *arbolito;
	crearArbol(&arbolito);
	insertarArbol(&arbolito,50);
	insertarArbol(&arbolito,30);
	insertarArbol(&arbolito,80);
	insertarArbol(&arbolito,10);
	insertarArbol(&arbolito,40);
	insertarArbol(&arbolito,60);
	insertarArbol(&arbolito,90);
	insertarArbol(&arbolito,5);
	printf("\nEl arbol entreOrden queda : \n");
	entreOrden(arbolito);
	printf("\nEl arbol preOrden queda : \n");
	preOrden(arbolito);
	printf("\nEl arbol posOrden queda : \n");
	posOrden(arbolito);
	printf("\nEl arbol por niveles queda : \n");
	recorrernivelesArbol(arbolito);
	/*if (completoArbol(arbolito))
	  printf("\nEs completo");
	else
	  printf("\nNO Es completo");
	eliminarArbol(&arbolito,50);
	eliminarArbol(&arbolito,30);
	eliminarArbol(&arbolito,80);
	eliminarArbol(&arbolito,10);
	printf("\nEl arbol por niveles queda : \n");
	recorrernivelesArbol(arbolito);
	eliminarArbol(&arbolito,40);
	eliminarArbol(&arbolito,60);
	eliminarArbol(&arbolito,90);
	eliminarArbol(&arbolito,5);
	printf("\nEl arbol por niveles queda : \n");
	recorrernivelesArbol(arbolito);*/
    getchar();
}
