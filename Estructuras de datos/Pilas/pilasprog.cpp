#include "pilas.h"
/*
	crearPila
	vaciaPila
	insertarPila
	retirarPila
	consutarPila
*/

void  mostrarPila(TipoPila **pila){
	TipoPila *aux;
	int valor;
	crearPila(&aux);
	printf("\nLa pila contiene :\n");
	while (!vaciaPila(*pila)){
		valor=retirarPila(pila);
		insertarPila(&aux,valor);
		printf("%d ",valor);
	}
	while (!vaciaPila(aux)) {
		insertarPila(pila,retirarPila(&aux));
	}
}

int mayorPila(TipoPila **pila){
	TipoPila *aux;
	int valor,mayor;
	if (vaciaPila(*pila))
	  return -1;
	mayor=consultarPila(*pila);
	crearPila(&aux);
	while (!vaciaPila(*pila)){
		valor=retirarPila(pila);
		if (valor > mayor)
		  mayor=valor;
		insertarPila(&aux,valor);
	}
	while (!vaciaPila(aux)) {
		insertarPila(pila,retirarPila(&aux));
	}
	return mayor;
}

bool pertenecePila(TipoPila **pila, int numero){
	TipoPila *aux;
	int valor;
	bool pertenece=false;
	if (vaciaPila(*pila))
	  return pertenece;
	crearPila(&aux);
	while (!vaciaPila(*pila) && !pertenece){
		valor=retirarPila(pila);
		if (valor == numero)
		  pertenece=true;
		insertarPila(&aux,valor);
	}
	while (!vaciaPila(aux)) {
		insertarPila(pila,retirarPila(&aux));
	}
	return pertenece;
}

bool ordenadaPila(TipoPila **pila){
	TipoPila *aux;
	int anterior, siguiente;
	bool ordenada=true;
	if (vaciaPila(*pila))
	  return ordenada;
	crearPila(&aux);
	anterior=consultarPila(*pila);
	while (!vaciaPila(*pila) && ordenada){
		siguiente=retirarPila(pila);
		if (anterior > siguiente)
		  ordenada=false;
		anterior=siguiente;
		insertarPila(&aux,siguiente);
	}
	while (!vaciaPila(aux)) {
		insertarPila(pila,retirarPila(&aux));
	}
	return ordenada;
}

void invertirPila(TipoPila **pila){
	TipoPila *aux1, *aux2;
	crearPila(&aux1);
	crearPila(&aux2);
	while(!vaciaPila(*pila)){
		insertarPila(&aux1,retirarPila(pila));
	}
	while(!vaciaPila(aux1)){
		insertarPila(&aux2,retirarPila(&aux1));
	}
	while(!vaciaPila(aux2)){
		insertarPila(pila,retirarPila(&aux2));
	}
}
/*---------------------------------------*/

int main(void){
	TipoPila *lapila;
	crearPila(&lapila);
	for (int x=50;x>=0;x-=10)
	   insertarPila(&lapila,x);
	mostrarPila(&lapila);
	/*mostrarPila(&lapila);
	printf("\nEl mayor de la pila es : %d",mayorPila(&lapila));
	if (pertenecePila(&lapila,80))
	   printf("\nSi esta");
	else
	  printf("\nNo esta");
	mostrarPila(&lapila);
	if (ordenadaPila(&lapila))
	   printf("\nSi esta ordenada");
	else
	  printf("\nNo esta ordenada");*/
	invertirPila(&lapila);
	printf("\nPila invertida:\n");
	mostrarPila(&lapila);
}
