#include <stdlib.h>
#include <stdio.h>

typedef struct str_nodo{
	int valor;
	struct str_nodo *sgte;
}TipoNodo;

void crear(TipoNodo **lista){
	TipoNodo *p,*q;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	int valor;
	printf("Ingrese valor: ");
	scanf("%d",&valor);
	p->valor=valor;
	p->sgte=NULL;
	if(*lista==NULL){
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

void conteo(TipoNodo *lista){
	printf("\nFuncion");
	TipoNodo *q;
	int cont=0,ref=0;
	q=lista;
	while(q->sgte!=NULL){
		printf("\nwhile");getchar();
		if (q->valor=q->sgte->valor){
			printf("\nif");
			printf("\nq -> %d",q->valor);
			printf("\nq -> sgte %d", q->sgte->valor);
			cont+=cont;
		}
		else{
			printf("\nelse");
			if (cont>0){
				printf("\nelse if");
				printf("%d ",q->valor);
			}
		}
		q=q->sgte;getchar();
	}
	
}

void mostrar(TipoNodo *lista){
	TipoNodo *q;
	q=lista;
	while(q!=NULL){
		printf("%d ",q->valor);
		q=q->sgte;
	}
}

int main(void){
	TipoNodo *lista=NULL;
	for (int i=0;i<10;i++){
		crear(&lista);
	}
	printf("Lista:\n");
	mostrar(lista);
	printf("sale mostrar");
	conteo(lista);
	
	return 0;
}
