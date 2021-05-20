#include <stdio.h>
#include <stdlib.h>

typedef struct arbol {
	char elemento;	
	int valor;
	struct arbol *hizq, *hder;
}TipoArbol;

void crearArbol(TipoArbol **arbol){
	*arbol=NULL;
}

void insertarArbol(TipoArbol **arbol, int valor){
	if (*arbol == NULL){
   		TipoArbol *p;
        p=(TipoArbol *)malloc(sizeof(TipoArbol));
        p->valor=valor;
        p->hizq=p->hder=NULL;
   	    *arbol=p;
    }
    else {
    	if (valor<=(*arbol)->valor){    		
   	   		insertarArbol(&((*arbol)->hizq),valor);
		}   	    	
		else{
			insertarArbol(&((*arbol)->hder),valor);
		}
		  
   }	
}

int alturaArbol(TipoArbol *arbol){
	if (arbol==NULL)
	   return 0;
	else{
		int izq=alturaArbol(arbol->hizq);
		int der=alturaArbol(arbol->hder);
		if (izq>der)
		  return izq+1;
		else
		  return der+1;
	}
}

void escribirnivelArbol(TipoArbol *arbol, int nivel){
	if (arbol !=NULL){
		if (nivel==1)
		   printf("%d ",arbol->valor);
		else {
			escribirnivelArbol(arbol->hizq,nivel-1);
			escribirnivelArbol(arbol->hder,nivel-1);
		}
	}
}

void recorrernivelesArbol(TipoArbol *arbol) {
	int n=alturaArbol(arbol);
	for (int x=1;x<=n;x++) {
	   printf("\n");	
	   escribirnivelArbol(arbol,x);
    }
}

bool neutroArbol(TipoArbol *arbol, int raiz){
	if (arbol==NULL){
		return 0;
	}
	else{
		int der=neutroArbol(arbol->hder, arbol->valor);
		int izq=neutroArbol(arbol->hder, arbol->valor);
		if(der+izq==arbol->valor)
			return true;
	}
	return false;	
}

int main(void){
	TipoArbol *arbol;
	crearArbol(&arbol);
	/*
	insertarArbol(&arbol,50);
	insertarArbol(&arbol,30);
	insertarArbol(&arbol,80);
	insertarArbol(&arbol,10);
	insertarArbol(&arbol,40);
	insertarArbol(&arbol,60);
	insertarArbol(&arbol,90);
	insertarArbol(&arbol,5);
	*/
	
	
	insertarArbol(&arbol,80);
	insertarArbol(&arbol,30);
	insertarArbol(&arbol,50);
	insertarArbol(&arbol,10);
	insertarArbol(&arbol,20);
	insertarArbol(&arbol,25);
	insertarArbol(&arbol,25);
	insertarArbol(&arbol,5);
	
	
	printf("\nEl arbol por niveles queda : \n");	
	recorrernivelesArbol(arbol);
	
	if (neutroArbol(arbol, 50)){
		printf("\nEave que belleza ome");
	}
	else{
		printf("\nYa valio verga");
	}
	
	getchar();
}
