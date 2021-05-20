#include <stdio.h>
#include <stdlib.h>

typedef char String[50];

typedef struct texto{
	String palabra;
	struct texto *sgte;
}TipoTexto;

void iniciarLista(TipoTexto **lista, FILE **archivo){
	TipoTexto *p,*q;
	p=(TipoTexto*)malloc(sizeof(TipoTexto));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	
	fscanf(*archivo, "%s", p->palabra);
	printf("%s ",p->palabra);	
	
	while (!feof(*archivo)) {
	
	    fscanf(*archivo, "%s", p->palabra);
		
		printf("\n%s ",p->palabra);
		/*p->sgte=NULL;
		if (*lista==NULL){
			*lista=p;
		}
		else{
			q=*lista;
			while(q->sgte!=NULL){
				q=q->sgte;
			}			
			q->sgte=p;
		}*/
	}	
}

void ingresarPalabra(TipoTexto **lista){
	TipoTexto *p,*q;
	p=(TipoTexto*)malloc(sizeof(TipoTexto));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	printf("Ingrese palabra: ");
	gets(p->palabra);
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

void mostrar(TipoTexto *lista){
	TipoTexto *q;
	q=lista;
	while (q!=NULL){
		printf("%s ",q->palabra);
		q=q->sgte;
	}
}


int main(void){
	
	FILE *archivo;
	archivo=fopen("texto.txt", "r+");
	if (archivo==NULL){
		printf("Error al abrir. El archivo debe existir");
		exit(1);
	}
	
	TipoTexto *lista=NULL;
	
	iniciarLista(&lista,&archivo);
	
	/*for (int i=0;i<4;i++){
		ingresarPalabra(&lista);
	}*/	
	mostrar(lista);
	return 0;
}
