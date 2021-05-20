#include <stdio.h>
#include <stdlib.h>

typedef struct pila {
	int valor;
	struct pila *sgte;
}TipoPila;

void crearPila(TipoPila **pila){
	*pila=NULL;
}

bool vaciaPila(TipoPila *pila) {
	if (pila==NULL)
	  return true;
	else
	  return false;
	//return pila==NULL;
}

void insertarPila(TipoPila **pila, int valor){
	TipoPila *p;
	p=(TipoPila *)malloc(sizeof(TipoPila));
	if (p==NULL){
		printf("\nSin memoria");
		return;
	}
	p->valor=valor;
	p->sgte=*pila;
	*pila=p;
}

int retirarPila(TipoPila **pila) {
   int valor;
   TipoPila *p;
   if (!vaciaPila(*pila)) {
   	  p=*pila;
   	  valor=p->valor;
   	  *pila=(*pila)->sgte;
   	  free(p);
   	  return valor;
   }	
   else
     return -1;
}

int consultarPila(TipoPila *pila) {
   int valor;
   TipoPila *p;
   if (!vaciaPila(pila)) {
   	  p=pila;
   	  valor=p->valor;
   	  return valor;
   }	
   else
     return -1;
}

/*---------------------------------------*/

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
/*---------------------------------------*/

int main(void){
	TipoPila *lapila;
	crearPila(&lapila);
	for (int x=50;x>=0;x-=10)
	   insertarPila(&lapila,x);
	mostrarPila(&lapila);
	mostrarPila(&lapila);
	printf("\nEl mayor de la pila es : %d",mayorPila(&lapila));
	if (pertenecePila(&lapila,80))
	   printf("\nSi esta");
	else
	  printf("\nNo esta");
	mostrarPila(&lapila);
	if (ordenadaPila(&lapila))
	   printf("\nSi esta ordenada");
	else
	  printf("\nNo esta ordenada");
}
