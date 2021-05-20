#include <stdio.h>
#include <stdlib.h>

typedef struct str_lista{
	float valor;
	struct str_lista *sgte;
}TipoLista;

void mostrarLista(TipoLista *lista){
	TipoLista *q;
	q=lista;
	while (q!=NULL){
		printf("%.2f ",q->valor);
		q=q->sgte;
	}
}

void intercambiar(TipoLista *lista){
	TipoLista *q,*p;
	int temporal=0;
	p=lista;
	while (p->sgte!=NULL){
		for (q=p->sgte;q!=NULL;q=q->sgte){
			temporal=q->valor;
			q->valor=p->valor;
			p->valor=temporal;
		}
		p=p->sgte;
	}
}

int main(void){
	TipoLista *lista=NULL;
	
	for (int i=1;i<=10;i++){
		TipoLista *p,*q;
		p=(TipoLista*)malloc(sizeof(TipoLista));
		if (p==NULL){
			printf("No hay memoria");
			exit(1);
		}
		p->valor=i;
		p->sgte=NULL;
		if (lista==NULL){
			lista=p;
		}
		else{
			q=lista;
			while (q->sgte!=NULL){
				q=q->sgte;	
			}
			q->sgte=p;
		}
				
	}
	printf("Lista inicial: \n");
	mostrarLista(lista);
	intercambiar(lista);
	printf("\nLista final: \n");
	mostrarLista(lista);
}
