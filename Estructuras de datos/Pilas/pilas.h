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

