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

bool eshojaArbol(TipoArbol *arbol){
	if (arbol==NULL)
	  return false;
	else
	  return (arbol->hizq==NULL && arbol->hder==NULL);
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

void insertarArbol(TipoArbol **arbol, int valor){
   
   if (*arbol == NULL){
   	   TipoArbol *p;
       p=(TipoArbol *)malloc(sizeof(TipoArbol));
       p->valor=valor;
       p->hizq=p->hder=NULL;
   	   *arbol=p;
   }
   else {
   	  if (valor<(*arbol)->valor) 
   	  	  insertarArbol(&((*arbol)->hizq),valor);
		else 
		  insertarArbol(&((*arbol)->hder),valor);
   }	
}

void entreOrden(TipoArbol *arbol){
	if (arbol!=NULL) {
		entreOrden(arbol->hizq);
		printf("%d ",arbol->valor);
		entreOrden(arbol->hder);
	}
}

void preOrden(TipoArbol *arbol){
	if (arbol!=NULL) {
		printf("%d ",arbol->valor);
		preOrden(arbol->hizq);
		preOrden(arbol->hder);
	}
}

void posOrden(TipoArbol *arbol){
	if (arbol!=NULL) {
	
		posOrden(arbol->hizq);
		posOrden(arbol->hder);
		printf("%d ",arbol->valor);
	}
}

int sumaArbol(TipoArbol *arbol){
	if (arbol==NULL)
	  return 0;
	else
	  return arbol->valor+
	         sumaArbol(arbol->hizq)+
	         sumaArbol(arbol->hder);
}

int sumahojasArbol(TipoArbol *arbol){
	if (arbol==NULL)
	  return 0;
	else
	 if (eshojaArbol(arbol))
	    return arbol->valor;
	  else
	    return sumahojasArbol(arbol->hizq)+
	           sumahojasArbol(arbol->hder);
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

bool buscarArbol(TipoArbol *arbol, int valor){
	if (arbol==NULL)
	  return false;
	else
	  if (arbol->valor==valor)
	    return true;
	  else
	    if (arbol->valor>valor)
		  return buscarArbol(arbol->hizq,valor);
		else
		   return buscarArbol(arbol->hder,valor); 
}

bool completoArbol(TipoArbol *arbol){
	if (arbol==NULL)
	   return true;
	else
	  if (alturaArbol(arbol->hizq)==alturaArbol(arbol->hder)&&
	       completoArbol(arbol->hizq)&&completoArbol(arbol->hder))
	       return true;
	    else
	      return false;
}

bool balanceadoArbol(TipoArbol *arbol){
	if (arbol==NULL)
	   return true;
	else {
		int resta=abs(alturaArbol(arbol->hizq)-
		              alturaArbol(arbol->hder));
	  if (resta<=1 && balanceadoArbol(arbol->hizq)&&
	      balanceadoArbol(arbol->hder))
	       return true;
	    else
	      return false;
    }
}

TipoArbol *menorArbol(TipoArbol *arbol) {
     if (arbol==NULL)
        return NULL;
      else
        if (arbol->hizq==NULL)
           return arbol;
        else
           return menorArbol(arbol->hizq);       
}

TipoArbol *menorArbolIter(TipoArbol *arbol) {
     if (arbol==NULL)
        return NULL;
      else {
        while (arbol->hizq!=NULL) {
            arbol=arbol->hizq;
        }
        return arbol;       
      }
}

TipoArbol *mayorArbol(TipoArbol *arbol) {
     if (arbol==NULL)
        return NULL;
      else
        if (arbol->hder==NULL)
           return arbol;
        else
           return mayorArbol(arbol->hder);       
}

void eliminarArbol(TipoArbol **arbol, int valor) {
     TipoArbol *p;
     if (*arbol != NULL) {
        if ((*arbol)->valor == valor) {
           if (eshojaArbol(*arbol)) {
                p=*arbol;
                *arbol=NULL;
                free(p);
           } 
           else {
              if ((*arbol)->hder!=NULL) {
                 p=menorArbol((*arbol)->hder);
                 if (p==NULL) {
                     printf("\nERROR apuntador en NULL No existe el hijo derecho");
                     return;
                 }
                 (*arbol)->valor=p->valor;
                 eliminarArbol(&((*arbol)->hder), p->valor);
              }
              else {
                 p=mayorArbol((*arbol)->hizq);
                 if (p==NULL) {
                     printf("\nERROR apuntador en NULL No existe el hijo izquierdo");
                     return;
                 }
                 (*arbol)->valor=p->valor;
                 eliminarArbol(&((*arbol)->hizq), p->valor);
              }
           }
        }
        else {
           if ((*arbol)->valor < valor)
             eliminarArbol(&((*arbol)->hder) ,valor);
           else
             eliminarArbol(&((*arbol)->hizq) ,valor);
        }
     }
}
