#include <stdio.h>
#include <stdlib.h>

//-----------Lista Simple------------------

typedef struct str_lista{
	float valor;
	struct str_lista *sgte;
}TipoLista;

void crearLista(TipoLista **lista,float num){
	TipoLista *p,*q;
	p=(TipoLista*)malloc(sizeof(TipoLista));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	p->valor=num;
	p->sgte=NULL;
	if (*lista==NULL){
		*lista=p;
	}
	else{
		q=*lista;
		while (q->sgte!=NULL){
			q=q->sgte;
		}
		q->sgte=p;
	}
}

void mostrarLista(TipoLista *lista){
	TipoLista *q;
	q=lista;
	while (q!=NULL){
		printf("%.2f ",q->valor);
		q=q->sgte;
	}
}

//--------------Fin Lista Simple------------

//-------------Lista Doble---------------

typedef struct str_lista2{
	float valor;
	struct str_lista2 *sgte, *ante;
}TipoNodo;

typedef struct{
	TipoNodo *cabeza, *cola;
}TipoLista2;

void crearLista2(TipoLista2 *lista2, TipoLista *lista){
	TipoNodo *p,*r;
	TipoLista *q;

	if (lista==NULL){
		printf("Lista 1 vacia");
		exit(1);
	}
	else{
		q=lista;
		while (q!=NULL){
			p=(TipoNodo*)malloc(sizeof(TipoNodo));
	        if (p==NULL){
				printf("No hay memoria");
				exit(1);
			}	
			p->valor=q->valor;
			if (lista2->cabeza==NULL){
				//Lista2 vacía
				p->sgte=p->ante=NULL;
				lista2->cabeza=lista2->cola=p;
			}
			else{
				if (p->valor <= lista2->cabeza->valor){					
					//Elemento menor al primero
					p->ante=NULL;
					p->sgte=lista2->cabeza;
					lista2->cabeza->ante=p;
					lista2->cabeza=p;
				}
				else{
					r=lista2->cabeza;
					while (r->sgte!=NULL && p->valor > r->valor){
						r=r->sgte;
					}
					if(r->sgte!=NULL){
						
						//Elemento intermedio
						r->ante=p;
						r->ante->sgte=p;
						p->ante=r->ante;
						p->sgte=r;
					}
					else{
						//Elemenot mayor al ultimo
						lista2->cola->sgte=p;
						p->ante=lista2->cola;
						p->sgte=NULL;
						lista2->cola=p;
					}
				}
				
			}
			q=q->sgte;
		}
	}
}

void mostrarLista2(TipoLista2 lista2){
	TipoNodo *q;
	q=lista2.cabeza;
	while (q!=NULL){
		printf("%.2f ",q->valor);
		q=q->sgte;
	}
}

int main(void){
	TipoLista *lista=NULL;
	TipoLista2 lista2;
	lista2.cabeza=lista2.cola=NULL;
	
	for (int i=1;i<=10;i++){
		crearLista(&lista,10-(i));
	}
	printf("La lista inicial es :\n");
	mostrarLista(lista);
	
	crearLista2(&lista2, lista);
	printf("\nLa lista ordenada es :\n");
	mostrarLista2(lista2);
}
