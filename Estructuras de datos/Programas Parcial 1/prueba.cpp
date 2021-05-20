#include <stdio.h>
#include <stdlib.h>

typedef struct str_nodo{
	int valor;
	struct str_nodo *sgte,*ante;
}TipoNodo;

typedef struct{
	TipoNodo *cabeza,*cola;
}TipoNodo1;

void crear(TipoNodo1 *lista, int valor){
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	p->valor=valor;
	p->sgte=p->ante=NULL;
	if (lista->cabeza==NULL){
		lista->cabeza=lista->cola=p;
	}
	else{
		p->ante=lista->cola;
		lista->cola->sgte=p;
		lista->cola=p;				
	}
}

void mostrar(TipoNodo1 lista){
	TipoNodo *q;
	q=lista.cabeza;
	while (q!=NULL){
		printf("%d ", q->valor);
		q=q->sgte;
	}
}

void organizar(TipoNodo1 lista1,TipoNodo1 lista2,TipoNodo1 *lista3){
	TipoNodo *q,*p,*r;
	q=lista1.cabeza;
	while (q!=NULL){
		p=(TipoNodo*)malloc(sizeof(TipoNodo));
		if(p==NULL){
			printf("No hay memoria");
			exit(1);
		}
		p->ante=p->sgte=NULL;
		p->valor=q->valor;
		if (lista3->cabeza==NULL){
			lista3->cabeza=lista3->cola=p;
		}
		else{
			p->ante=lista3->cola;
			lista3->cola->sgte=p;
			lista3->cola=p;		
		}		
		q=q->sgte;
	}
	r=lista2.cabeza;
	while (r!=NULL){
		printf("\nEntra al while r");getchar();
		p=(TipoNodo*)malloc(sizeof(TipoNodo));
		if (p==NULL){
			printf("No hay memoria");
			exit(1);
		}
		p->valor=r->valor;
		p->ante=p->sgte=NULL;
		if(p->valor<lista3->cabeza->valor){
			p->sgte=lista3->cabeza;
			lista3->cabeza->ante=p;
			lista3->cabeza=p;
		}
		else{
			q=lista3->cabeza;
			while(q!=NULL && q->valor<p->valor){
				q=q->sgte;
			}
			if (q!=NULL){
				printf("Entra al if");getchar();
				p->sgte=q;
				p->ante=q->ante;
				q->ante=p;
				q->ante->sgte=p;
			}
			else{
				printf("Entra al else");getchar();
				p->ante=lista3->cola;
				lista3->cola->sgte=p;
				lista3->cola=p;
			}
		}	
		r=r->sgte;
	}
}

int main(void){
	TipoNodo1 lista1,lista2,lista3;
	lista1.cabeza=lista1.cola=NULL;
	lista2.cabeza=lista2.cola=NULL;
	lista3.cabeza=lista3.cola=NULL;
	
	for (int i=0;i<10;i++){
		crear(&lista1, 2*i+1);
		crear(&lista2, 2*i);
	}
	printf("\nLista1\n");
	mostrar(lista1);
	printf("\nLista2\n");
	mostrar(lista2);
	
	organizar(lista1,lista2,&lista3);
	printf("\nLista3\n");
	mostrar(lista3);
}
