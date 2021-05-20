#include <stdio.h>
#include <stdlib.h>


typedef struct lista {
	int valor;
	struct lista *sgte, *ante;
}TipoLista;

typedef struct {
	TipoLista *primero, *ultimo;
}TipoCola;

void crearCola(TipoCola *cola){
	cola->primero=cola->ultimo=NULL;
}

bool vaciaCola(TipoCola *cola){
	return cola->primero==NULL;
}

void insertarCola(TipoCola *cola, int valor){
	TipoLista *p;
	p=(TipoLista *)malloc(sizeof(TipoLista));
	if (p==NULL){
		printf("\nNo hay memoria");
		return;
	}
	p->valor=valor;
	p->ante=NULL;
	p->sgte=cola->ultimo;
	if (cola->ultimo==NULL) {
		cola->ultimo=cola->primero=p;
	}
	else {
	  cola->ultimo->ante=p;
	  cola->ultimo=p;
    }
}

int retirarCola(TipoCola *cola){
	TipoLista *p;
	int valor;
	if (vaciaCola(cola))
	  return -1;
	p=cola->primero;
	valor=p->valor;
	if (cola->primero==cola->ultimo){
	   cola->primero=cola->ultimo=NULL;
	   free(p);
	}
	else {
	   p->ante->sgte=NULL;
	   cola->primero=p->ante;
	   free(p);
    }
    return valor;
}

int consultarCola(TipoCola *cola){
	TipoLista *p;
	int valor;
	if (vaciaCola(cola))
	  return -1;
	p=cola->primero;
	valor=p->valor;
	return valor;
}

void destruirCola(TipoCola *cola){
	while(!vaciaCola(cola)){
		retirarCola(cola);
	}
	//cola->primero=cola->ultimo=NULL;
}
