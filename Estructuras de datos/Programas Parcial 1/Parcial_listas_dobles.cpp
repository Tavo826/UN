#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct str_producto{
	char nombre[30];
	int codigo;
	float valor;
	int cantidad;
	struct str_producto *sgte,*ante;
}TipoProducto;

typedef struct{
	TipoProducto *cabeza,*cola;
}TipoProducto1;

typedef struct str_nodo{
	int valor;
	struct str_nodo *sgte,*ante;
}TipoNodo;

typedef struct{
	TipoNodo *cabeza,*cola;
}TipoNodo2;

void crear_lista1(TipoProducto1 *lista){
	TipoProducto *p;
	p=(TipoProducto*)malloc(sizeof(TipoProducto));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	printf("Nombre: ");
	gets(p->nombre);
	printf("Codigo: ");
	scanf("%d",p->codigo);
	printf("Valor: ");
	scanf("%f", &p->valor);
	printf("Cantidad: ");
	scanf("%d", &p->cantidad);
	
	p->sgte=NULL;
	
	if (lista->cabeza==NULL){
		lista->cabeza=lista->cola=p;
	}
	if (lista->cabeza==lista->cola){
		p->ante=lista->cola;
		lista->cola->sgte=p;
		lista->cola=p;		
	}
}

void calcular_inventario(TipoProducto1 lista,int ran1,int ran2){
	TipoProducto *p;
	float inventario=0;
	p=lista.cabeza;	
	while (p!=NULL){
		if (p->codigo>ran1 && p->codigo<ran2){
			inventario+=p->valor;
		}
		p=p->sgte;
	}
	printf("EL valor total del inventario es %.3f", inventario);	
}

void crearLista2(TipoNodo2 *lista){
	TipoNodo *p;
	p=(TipoNodo*)malloc(sizeof(TipoNodo));
	if (p==NULL){
		printf("No hay memoria");
		exit(1);
	}
	p->valor=rand()%10;
	p->sgte=p->ante=NULL;

	if(lista->cabeza==NULL || lista->cola==NULL) {
		lista->cabeza=lista->cola=p;
	} else {
		p->sgte=lista->cabeza;
		lista->cabeza->ante=p;
		lista->cabeza=p;
	}	
}

void lista_double(TipoNodo2 lista){
	TipoNodo *q;
	q=lista.cabeza;
	double num=0;
	int cont=0;
	while (q!=NULL){
		cont+=1;
		q=q->sgte;
	}
	q=lista.cabeza;
	for (int i=cont-1;i>=0;i--){
		num=num+q->valor*pow(10,i);
		q=q->sgte;
	}
	printf("\nNumero: ");
	printf("%.1f",num);
}

void mostrar(TipoNodo2 lista){
	TipoNodo *p;
	p=lista.cabeza;
	while(p!=NULL){
		printf("%d",p->valor);
		p=p->sgte;
	}
}

int main(void){
	/*TipoProducto1 lista1;
	lista1.cabeza=lista1.cola=NULL;
	int rango_inf=2;
	int rango_sup=4;
	for (int i=0;i<5;i++){
		crear_lista1(&lista1);
	}
	calcular_inventario(lista1,rango_inf,rango_sup);*/
	
	TipoNodo2 lista2;
	lista2.cabeza=lista2.cola=NULL;
	srand(time(NULL));
	for (int i=0;i<10;i++){
		crearLista2(&lista2);
	}
	mostrar(lista2);
	lista_double(lista2);
}
