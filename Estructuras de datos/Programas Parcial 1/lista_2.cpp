#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct numero{
	int valor;
	struct numero *sgte;
}TipoLista;

void ingresarLista(TipoLista **lista,int r){
	
	TipoLista *p,*q;
	p=(TipoLista*)malloc(sizeof(TipoLista));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	p->valor=rand()%r;
	p->sgte=NULL;
	if (*lista==NULL){
		*lista=p;
	}
	else{
		q=*lista;
		while(q->sgte!=NULL){
			q=q->sgte;
		}
		q->sgte=p;
	}	
}

void imprimir(TipoLista *lista){
	TipoLista *q;
	q=lista;
	while (q!=NULL){
		printf("%d ",q->valor);
		q=q->sgte;
	}
}

void eliminar(TipoLista **lista,int valor){
	if ((*lista)==NULL){
		printf("Lista vacia");
		return;
	}
	else{
		TipoLista *p,*q;
		p=*lista;
		while (p->sgte!=NULL){
			if ((*lista)->valor > valor){
				q=*lista;
				*lista=(*lista)->sgte;
				p=*lista;
				free(q);
			}
			else{				
				if (p->sgte->valor > valor){
					q=p->sgte;
					p->sgte=q->sgte;
					free(q);
				}
				else{
					p=p->sgte;
				}
			}
		}		
	}
}

int main(void){
	int rango,m,elim;
	TipoLista *lista=NULL;
	printf("Ingrese rango maximo: ");
	scanf("%d", &rango);
	srand(time(NULL));

	for (int i=0;i<10;i++){
		ingresarLista(&lista,rango);
	}
	imprimir(lista);
	printf("\nValor a superar: ");
	scanf("%d", &elim);
	eliminar(&lista,elim);
	imprimir(lista);
	
	return 0;
}
