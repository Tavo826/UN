#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
	int valor;
	struct nodo *der, *izq;
} TipoNodo;

typedef struct {
	TipoNodo *cabeza, *cola;
} TipoLista;


int listaVacia(TipoLista lista) {
	if (lista.cabeza==NULL) {
		return 1;
	} else {
		return 0;
	}
}

void insertarOrdenado(TipoLista *lista){
	
	int elem;
	
	printf("Deme el elemento a ingresar: ");
	scanf("%d", &elem);
	
	TipoNodo *p,*q;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}	
	
	p->valor=elem;
	
	if (lista->cabeza==NULL){
		//Lista Vacia
		p->der=p->izq=NULL;
		lista->cabeza=lista->cola=p;
	}
	else{
		
		if (p->valor < lista->cabeza->valor){
			//Elemento menor al primero
			p->der=lista->cabeza;
			p->izq=NULL;
			lista->cabeza->izq=p;
			lista->cabeza=p;
		}
		else{			
			q=lista->cabeza;
			
			while (q!=NULL && q->valor<p->valor){
				q=q->der;
			}
			if(q!=NULL){
				//Elemento intemedio
				q->izq->der=p;
				q->izq=p;
				p->izq=q->izq;
				p->der=q;
			}
			else{
				//Elemento mayor al final
				p->der=NULL;
				lista->cola->der=p;
				p->izq=lista->cola;
				lista->cola=p;
			}			
		}	
	}	
}

void insertarCabeza(TipoLista *lista) {

	int elem;

	printf("Deme elemento a ingresar: ");
	scanf("%d", &elem);

	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL) {
		printf("\nNo hay epacio en memoria");
		exit(1);
	}

	p->valor=elem;
	p->der=p->izq=NULL;

	if(lista->cabeza==NULL || lista->cola==NULL) {
		lista->cabeza=lista->cola=p;
	} else {
		p->der=lista->cabeza;
		lista->cabeza->izq=p;
		lista->cabeza=p;
	}
}

void insertarCola(TipoLista *lista) {
	int elem;
	
	printf("Deme elemento a ingresar: ");
	scanf("%d", &elem);
	
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL){
		printf("\nNo hay espacio en memoria");
		exit(1);
	}
	
	p->valor=elem;
	p->der=p->izq=NULL;
	
	if (lista->cabeza==NULL || lista->cola==NULL){
		lista->cabeza=lista->cola=p;
	}
	else{
		p->izq=lista->cola;
		lista->cola->der=p;
		lista->cola=p;
	}
}

void buscarElemento(TipoLista *lista){	
	int buscar,contador=0;
	
	printf("Deme elemento a buscar: ");
	scanf("%d", &buscar);
	
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL) {
		printf("No hay espacio en memoria");
		exit(1);
	}
	
	if (lista->cabeza->valor==buscar){
		contador=contador+1;
	}
	else{
		p=lista->cabeza;
		while(p->der!=NULL){
			p=p->der;		
			if(p->valor==buscar){			
				contador=contador+1;
			}
		}
	}
	
	printf("El elemento se encuentra %d veces", contador);
}

void invertir(TipoLista lista){
	TipoNodo *p,*q;
	int aux=0;
	
	p=lista.cabeza;
	q=lista.cola;
	if (lista.cabeza==lista.cola){
		printf("Lista vacia");
		return;
	}
	while (p!=NULL && p->izq!=q){
		aux=p->valor;
		p->valor=q->valor;
		q->valor=aux;		
		p=p->der;
		q=q->izq;
	}
}

void eliminarNodo(TipoLista *lista) {

	int elemento;

	printf("Deme elemento a eliminar: ");
	scanf("%d", &elemento);

	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL) {
		printf("No hay espacio en memoria");
		exit(1);
	}

	if (lista->cabeza->valor==elemento) {
		//Primer elemento de la lista

		if (lista->cabeza==lista->cola) {
			//Solo hay un elemento en la lista

			p=lista->cabeza;
			lista->cabeza=lista->cola=NULL;
			free(p);
		} else {
			//Más de un elemento en la lista

			p=lista->cabeza;
			lista->cabeza->der->izq=NULL;
			lista->cabeza=lista->cabeza->der;
			free(p);
		}
	} else {
		p=lista->cabeza;

		while (p!=NULL && p->valor!=elemento) {
			p=p->der;
		}
		if (p!=NULL) {
			if (p->der==NULL) {
				//Ultimo valor de la lista

				lista->cola=p->izq;
				p->izq->der=NULL;
				free(p);
			} else {
				//Elemento intermedio

				p->der->izq=p->izq;
				p->izq->der=p->der;
				free(p);
			}
		}
	}
}

void mostrarLista(TipoLista *lista) {
	TipoNodo *p;
	for(p=lista->cabeza; p!=NULL; p=p->der) {
		printf("%d", p->valor);
	}
}

int main(void) {
	TipoLista lista;
	lista.cabeza=NULL;
	lista.cola=NULL;
	
	int opc;

	for (int i=1; i<=4; i++) {
		insertarOrdenado(&lista);
	}
	mostrarLista(&lista);
	
	
	printf("\n\nBuscar elemento (y/n)\n");
	scanf("%s", &opc);
	if (opc=='y'){
		buscarElemento(&lista);
	}
	
	invertir(lista);
	mostrarLista(&lista);
}

