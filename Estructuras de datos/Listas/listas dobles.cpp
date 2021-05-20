#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct lista {
	int valor;
	struct lista *sgte, *ante;
}TipoLista;

typedef struct {
        TipoLista *cabeza, *cola;
}TipoLista2;

void crearLista(TipoLista2 *lista) {
     lista->cabeza=lista->cola=NULL;
}

void eliminar(TipoLista2 *lista, int valor){
	TipoLista *p, *q, *r, *s;
	p=lista->cabeza;
	if (lista->cabeza != NULL){
		if (lista->cabeza==lista->cola){
		   if (p->valor==valor){
		   	  lista->cabeza=lista->cola=NULL;
		   	  free(p);
		   }
	    }
	    else {
	    	if (lista->cabeza->valor==valor) {
	    		q=p->sgte;
	    		q->ante=NULL;
	    		lista->cabeza=q;
	    		free(p);
			}
			else {
			  if (lista->cola->valor==valor) {
			  	p=lista->cola;
	    		q=p->ante;
	    		q->sgte=NULL;
	    		lista->cola=q;
	    		free(p);
			  }
			  else {
			  	while (p!=NULL && p->valor != valor)
			  		p=p->sgte;
			  		
			  	if (p!=NULL) {
			  		r=p->ante;
			  		s=p->sgte;
			  		r->sgte=p->sgte;
			  		s->ante=p->ante;
			  		free(p);
				}
			  }	
			}
		}
	}
}

void ordenar(TipoLista2 lista) {
	TipoLista *x, *y;
	int temp;
	for (x=lista.cabeza; x->sgte!=NULL; x=x->sgte) {
		for (y=x->sgte; y!=NULL; y=y->sgte) {
			if (x->valor > y->valor) {
				temp=x->valor;
				x->valor=y->valor;
				y->valor=temp;
			}
		}
	}
}

void mostrarCabeza(TipoLista2 lista){
	TipoLista *p;
	printf("\nLa lista es : ");
	for (p=lista.cabeza;p!=NULL; p=p->sgte)
	   printf("%4d",p->valor);
}

void mostrarCola(TipoLista2 lista){
	TipoLista *p;
	printf("\nLa lista es : ");
	for (p=lista.cola;p!=NULL; p=p->ante)
	   printf("%4d",p->valor);
}

void mostrarCola1(TipoLista2 lista){
	TipoLista p;
	printf("\nLa lista es : ");
	p=*(lista.cola);
	printf("%4d",p.valor);
	do {
		p=*(p.ante);
		printf("%4d",p.valor);
		
	}while(p.ante!=NULL);
}

void insertarCabeza(TipoLista2 *lista, int num) {
	TipoLista *p;
	p=(TipoLista *) malloc(sizeof(TipoLista));
	if (p==NULL) {
       printf("\nNo hay memoria");
       return;
	}
	p->valor=num;
	if (lista->cabeza==NULL) {
    	p->sgte=p->ante=NULL;
	    lista->cabeza=lista->cola=p;
    }
    else {
         p->sgte=lista->cabeza;
         lista->cabeza->ante=p;
         p->ante=NULL;
         lista->cabeza=p;
    }
}

void insertarCola(TipoLista2 *lista, int num) {
	TipoLista *p;
	p=(TipoLista *) malloc(sizeof(TipoLista));
	if (p==NULL) {
         printf("\nNo hay memoria");
         return;
	}
	p->valor=num;
	if (lista->cola==NULL) {
    	p->sgte=p->ante=NULL;
	    lista->cabeza=lista->cola=p;
    }
    else {
         p->ante=lista->cola;
         lista->cola->sgte=p;
         p->sgte=NULL;
         lista->cola=p;
    }
}

void insertarOrd(TipoLista2 *lista, int valor) {
   TipoLista *p, *q, *r;
   p=(TipoLista *)malloc(sizeof(TipoLista));
   if (p==NULL) {
         printf("\nNo hay memoria");
         return;
   }
   p->valor=valor;
   if (lista->cola==NULL) {
    	p->sgte=p->ante=NULL;
	    lista->cabeza=lista->cola=p;
   }
   else {
     if (p->valor < lista->cabeza->valor) {
        p->sgte=lista->cabeza;
        lista->cabeza->ante=p;
        p->ante=NULL;
        lista->cabeza=p;          
     }
     else { 
       q=lista->cabeza;
       while (q!=NULL && q->valor < valor) {
         q=q->sgte;
       }
       if (q!=NULL) { // Caso 3
          r=q->ante;
          r->sgte=p;
          p->sgte=q;
          q->ante=p;
          p->ante=r;
	   }
	   else {	// Caso 4
         p->ante=lista->cola;
         lista->cola->sgte=p;
         p->sgte=NULL;
         lista->cola=p;
       }
     }
   }
}

void buscarUno(TipoLista2  lista, int valor) {
     TipoLista *p;
     for (p=lista.cabeza;p!=NULL;p=p->sgte) {
         if (p->valor==valor) {
            printf("\nEl valor %d, SI esta en la lista",valor);
            return;
         }  
     }
     printf("\nEl valor %d, NO esta en la lista",valor);
}

void numNodos(TipoLista2 lista){
	int cont=1;
	TipoLista *q;
	if (lista.cabeza==NULL){
		printf("Lista vacia");
		return;
	}
	else{
		q=lista.cabeza;
		while(q->sgte!=NULL){
			q=q->sgte;
			cont=cont+1;
		}
	}
	
	printf("\nLa lista tiene %d nodos", cont);
	
}

int main(int argc, char *argv[]) {
    TipoLista2 lista;
    int x,n;
    crearLista(&lista);
    for (x=1;x<=10;x++)
       insertarOrd(&lista, 100-x);
    //mostrarCabeza(lista);
    
    mostrarCabeza(lista);
    numNodos(lista);
    
    /*ordenar(lista);
    mostrarCabeza(lista);
    mostrarCola(lista);
    eliminar(&lista,99);
    eliminar(&lista,80);
    mostrarCola(lista);*/
    
    getchar();
    return 0;
}
