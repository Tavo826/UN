#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct str_lista{
	int valor;
	struct str_lista *sgte;
}TipoLista;

typedef struct estudiante{
	char nombre[30];
	char direccion[50];
	float nota;
	int edad;
	struct estudiante *sgte;
}TipoEstudiante;

typedef struct str_nodo{
	int valor;
	struct str_nodo *sgte;
}TipoNodo;

void crear(TipoLista **lista){
	TipoLista *p;
	p=(TipoLista*)malloc(sizeof(TipoLista));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	p->valor=rand()%20;
	p->sgte=*lista;
	*lista=p;	
}

void may_men(TipoLista *lista){
	TipoLista *p,*q;
	p=lista;
	q=lista->sgte;
	int menor=p->valor;
	int mayor=p->valor;
	while (q!=NULL){
		if (q->valor<menor){
			menor=q->valor;
		}
		if (q->valor>mayor){
			mayor=q->valor;
		}
		q=q->sgte;
	}
	printf("\nEl menor es: %d", menor);
	printf("\nEl mayor es: %d", mayor);
}

void crear_estudiante(TipoEstudiante **lista){
	TipoEstudiante *p;
	p=(TipoEstudiante*)malloc(sizeof(TipoEstudiante));
	if (p=NULL){
		printf("No hay memoria");
		exit(1);
	}
	printf("\nNombre: ");getchar();
	gets(p->nombre);
	printf("Direccion: ");getchar();
	gets(p->direccion);
	printf("Nota: ");
	scanf("%f", &p->nota);
	printf("Edad: ");
	scanf("%d", &p->edad);
	p->sgte=*lista;
	*lista=p;
}

void estudiante(TipoEstudiante *lista,int  valor){
	TipoEstudiante *p;
	while (p!=NULL){
		if (p->nota>=3.5 && p->nota<=5.0 && p->edad<valor){
			printf("Nombre: %s", p->nombre);
			printf("Direccion: %s", p->direccion);
		}
		p=p->sgte;
	}
}

void crear_nodo(TipoNodo **lista, int valor){
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	p->valor=valor;
	p->sgte=*lista;
	*lista=p;
}

void diferencia(TipoNodo *lista1, TipoNodo *lista2, TipoNodo **lista3){
	TipoNodo *p,*q,*r;
	p=lista1;
	while (p!=NULL){
		int cont=0;
		for(q=lista2;q!=NULL;q=q->sgte){
			if (p->valor==q->valor){
				cont=cont+1;
			}
		}
		if (cont==0){
			r=(TipoNodo*)malloc(sizeof(TipoNodo));
			if (r==NULL){
				printf("No hay memoria");
				exit(1);
			}
			r->valor=p->valor;
			r->sgte=*lista3;
			*lista3=r;
		}		
		p=p->sgte;
	}	
}

void mostrar_lista(TipoLista *lista){
	TipoLista *q;
	while (q!=NULL){
		printf("%d ", q->valor);
		q=q->sgte;
	}
}

void mostrar_nodo(TipoNodo *lista){
	TipoNodo *q;
	q=lista;
	while (q!=NULL){
		printf("%d ", q->valor);
		q=q->sgte;
	}
}

int main(void){
	TipoLista *lista1=NULL;
	TipoEstudiante *lista2=NULL;
	TipoNodo *lista3=NULL,*lista4=NULL, *lista5=NULL;
	srand(time(NULL));
	for (int i=0;i<10;i++){
		crear(&lista1);
	}
	mostrar_lista(lista1);
	may_men(lista1);
	for (int i=0;i<5;i++){
		crear_estudiante(&lista2);
	}
	/*for (int i=0;i<10;i++){
		crear_nodo(&lista3,i+1);
		crear_nodo(&lista4,15-i);
	}

	printf("\nNodos\n");
	mostrar_nodo(lista3);
	printf("\n");
	mostrar_nodo(lista4);
	printf("\nDiferencia conjunto:\n");
	diferencia(lista3,lista4,&lista5);
	mostrar_nodo(lista5);*/
	
	return 0;
}
