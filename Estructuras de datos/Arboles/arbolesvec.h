#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int hijoizq(int n){
	return 2*n+1;
}

int hijoder(int n){
	return 2*n+2;
}

bool vacioArbol(int arbol[], int raiz){
	return arbol[raiz]==-1;
}

bool eshoja(int arbol[], int raiz){
	if (vacioArbol(arbol,raiz))
	  return false;
	else
	  if (vacioArbol(arbol,hijoizq(raiz)) &&
	      vacioArbol(arbol,hijoder(raiz)))
	      return true;
	 else
	      return false;
}

bool buscar(int arbol[], int raiz, int valor){
	if (vacioArbol(arbol,raiz))
	   return false;
	else {
		if (arbol[raiz]==valor)
		   return true;
		else
		  if (arbol[raiz]>valor)
		    return buscar(arbol, hijoizq(raiz), valor);
		  else
		    return buscar(arbol, hijoder(raiz), valor);
	}
}

int altura(int arbol[], int raiz){
	int izq, der;
	if (vacioArbol(arbol,raiz))
	  return 0;
	else {
		izq=altura(arbol,hijoizq(raiz));
		der=altura(arbol,hijoder(raiz));
		if (izq>der)
		   return izq+1;
		else
		   return der+1;
	}
}

bool balanceado(int arbol[], int raiz) {
	if (vacioArbol(arbol,raiz))
	  return true;
	else {
		int izq,der;
		izq=altura(arbol,hijoizq(raiz));
		der=altura(arbol,hijoder(raiz));
		return  (abs(izq-der) <= 1 &&
		  		balanceado(arbol,hijoizq(raiz)) &&
		  		balanceado(arbol,hijoder(raiz)));
	}
}

bool completo(int arbol[], int raiz) {
	if (vacioArbol(arbol,raiz))
	  return true;
	else {
		int izq,der;
		izq=altura(arbol,hijoizq(raiz));
		der=altura(arbol,hijoder(raiz));
		return  (izq==der &&
		  		completo(arbol,hijoizq(raiz)) &&
		  		completo(arbol,hijoder(raiz)));
	}
}

void entreOrden(int arbol[], int raiz){
	if (!vacioArbol(arbol,raiz)) {
	  entreOrden(arbol,hijoizq(raiz));
	  printf("%d ",arbol[raiz]);
	  entreOrden(arbol,hijoder(raiz));
    }
}

void preOrden(int arbol[], int raiz){
	if (!vacioArbol(arbol,raiz)) {
      printf("%d ",arbol[raiz]);
	  preOrden(arbol,hijoizq(raiz));
	  preOrden(arbol,hijoder(raiz));
    }
}

void posOrden(int arbol[], int raiz){
	if (!vacioArbol(arbol,raiz)) {
	  posOrden(arbol,hijoizq(raiz));
	  posOrden(arbol,hijoder(raiz));
	  printf("%d ",arbol[raiz]);
    }
}

void escribirnivelArbol(int arbol[], int raiz, int nivel){
	if (!vacioArbol(arbol,raiz)){
		if (nivel==1)
		   printf("%d ",arbol[raiz]);
		else {
			escribirnivelArbol(arbol,hijoizq(raiz),nivel-1);
			escribirnivelArbol(arbol,hijoder(raiz),nivel-1);
		}
	}
}

void recorrernivelesArbol(int arbol[], int raiz) {
	int n=altura(arbol,raiz);
	for (int x=1;x<=n;x++) {
	   printf("\n");	
	   escribirnivelArbol(arbol,raiz,x);
    }
}

void eliminarMon(int monticulo[], int raiz){
	if (!vacioArbol(monticulo,raiz)){
		if (vacioArbol(monticulo,hijoizq(raiz)) &&
	  	    vacioArbol(monticulo,hijoder(raiz))) {
	  	    	monticulo[raiz]=-1;
	  	    	return;
			  }
	  	if (!vacioArbol(monticulo,hijoizq(raiz)) &&
	  	    !vacioArbol(monticulo,hijoder(raiz))) {
	  	    	if (monticulo[hijoizq(raiz)] > 
	  	    	    monticulo[hijoder(raiz)]) {
	  	    	    monticulo[raiz]=monticulo[hijoizq(raiz)];
	  	    	    eliminarMon(monticulo,hijoizq(raiz));
	  	         }
	  	         else {
	  	         	monticulo[raiz]=monticulo[hijoder(raiz)];
	  	    	    eliminarMon(monticulo,hijoder(raiz));
				  }
	  	    	    
		}
		else {
			if (vacioArbol(monticulo,hijoizq(raiz))) {
				monticulo[raiz]=monticulo[hijoder(raiz)];
	  	    	eliminarMon(monticulo,hijoder(raiz));
			}
			else {
				monticulo[raiz]=monticulo[hijoizq(raiz)];
	  	    	eliminarMon(monticulo,hijoizq(raiz));
			}
		}
	}
	
}

void insertarMon(int monticulo[], int raiz, int valor){
	int temp;
	if (vacioArbol(monticulo,raiz)){
		monticulo[raiz]=valor;
		monticulo[hijoizq(raiz)]=monticulo[hijoder(raiz)]=-1;
	}
	else {
		if (valor>monticulo[raiz]){
			temp=monticulo[raiz];
			monticulo[raiz]=valor;
			insertarMon(monticulo, raiz, temp);
		}
		else {
			if (altura(monticulo, hijoizq(raiz))>
			    altura(monticulo, hijoder(raiz))) 
				insertarMon(monticulo, hijoder(raiz), valor);
			else
			    insertarMon(monticulo, hijoizq(raiz), valor);
		}
	}
}

int menorArbol(int arbol[], int raiz) {
    if (vacioArbol(arbol,raiz))
       return -1;
    else
      if (vacioArbol(arbol, hijoizq(raiz)))
         return raiz;
      else
         return menorArbol(arbol,hijoizq(raiz));
}

int mayorArbol(int arbol[], int raiz) {
    if (vacioArbol(arbol,raiz))
       return -1;
    else
      if (vacioArbol(arbol, hijoder(raiz)))
         return raiz;
      else
         return mayorArbol(arbol,hijoder(raiz));
}

void eliminarArbol(int arbol[], int raiz, int valor){
    int p;
	if (!vacioArbol(arbol,raiz)){
        if (arbol[raiz]==valor) {
    		if (eshoja(arbol,raiz)) {
	  	    	arbol[raiz]=-1;
			}
			else {
  	  	      if (!vacioArbol(arbol,hijoder(raiz))) {
                   p=menorArbol(arbol, hijoder(raiz));
                   arbol[raiz]=arbol[p];
                   eliminarArbol(arbol,hijoder(raiz),arbol[p]);
              }
              else {
                   p=mayorArbol(arbol, hijoizq(raiz));
                   arbol[raiz]=arbol[p];
                   eliminarArbol(arbol,hijoizq(raiz),arbol[p]);
              } 	    
		   }
        }   
		else {
		  if (arbol[raiz] < valor)
	  	   	eliminarArbol(arbol,hijoder(raiz),valor);
		  else 
           	eliminarArbol(arbol,hijoizq(raiz),valor);
		}
	}
}

void insertarArbol(int arbol[], int raiz, int valor){
	int temp;
	if (vacioArbol(arbol,raiz)){
		arbol[raiz]=valor;
		arbol[hijoizq(raiz)]=arbol[hijoder(raiz)]=-1;
	}
	else {
		if (valor<arbol[raiz])
			insertarArbol(arbol, hijoizq(raiz), valor);
		else
			insertarArbol(arbol, hijoder(raiz), valor);
	}
}

void inicializar(int vector[], int n) {
    for (int x=0;x<n;x++)
      vector[x]=-1;
}

void leerdatosMon(int vector[], int n) {
    for (int x=0;x<n;x++)
      vector[x]=rand()%100;
}

void leerdatosArbol(int arbol[], int raiz, int n) {
    for (int x=0;x<n;x++)
      insertarArbol(arbol,raiz,rand()%100);
}

void mostrar(int vector[], int n) {
    printf("\nEl vector queda : \n");
    for (int x=0;x<n;x++)
      printf("%d ",vector[x]);
}

void heapsort(void){
	int monticulo[MAX], vector[MAX];
	int valor, raiz=0, n=100;
	
	inicializar(monticulo,MAX);
	leerdatosMon(vector,n);
	mostrar(vector, n);
        
    for (int x=0;x<n;x++) {
	   insertarMon(monticulo,raiz,vector[x]);
    }

    for (int x=n-1;x>=0;x--){
    	vector[x]=monticulo[raiz];
    	eliminarMon(monticulo,raiz);
	}

	mostrar(vector, n);
	getchar();
}
