#include "arbolesapu.h"
#include <string.h>

//TipoArbol

/*
	void crearArbol(TipoArbol **arbol)
	bool eshojaArbol(TipoArbol *arbol)
	int alturaArbol(TipoArbol *arbol)
	void insertarArbol(TipoArbol **arbol, int valor)
	void entreOrden(TipoArbol *arbol)
	void preOrden(TipoArbol *arbol)
	void posOrden(TipoArbol *arbol)
	int sumaArbol(TipoArbol *arbol)
	int sumahojasArbol(TipoArbol *arbol)
	void escribirnivelArbol(TipoArbol *arbol, int nivel)
	void recorrernivelesArbol(TipoArbol *arbol)
	bool buscarArbol(TipoArbol *arbol, int valor)
	bool completoArbol(TipoArbol *arbol)
	bool balanceadoArbol(TipoArbol *arbol)
	TipoArbol *menorArbol(TipoArbol *arbol)
	TipoArbol *menorArbolIter(TipoArbol *arbol)
	TipoArbol *mayorArbol(TipoArbol *arbol)
	void eliminarArbol(TipoArbol **arbol, int valor)
*/


/*
	((2+3)*(5+(20/3)))
*/

typedef char String[100];

void leerExpresion(String expresion){
	printf("Ingrese expresion: ");
	gets(expresion);	
}

/*void mostrarExpresion(String expresion){
	printf("%s",expresion);
}*/


/*bool verificarParentesis(String expresion){
	int contador=0;
	int i=0;
	try{	
		do{
			if (expresion[i] == '('){
				contador = contador + 1;
			}
			else if (expresion[i] == ')'){
				contador = contador - 1; 
			}
			i=i+1;
		}while (contador > 0);
	}
	catch(...){
		printf("La expresion no tiene parentesis balanceados");
	}
	
	if (contador == 0){
		return true;
	}
	else{
		return false;
	}
}*/

bool esSimbolo(char elemento){
	bool pertenece = false;
	char simbolos[] = {'+','-','*','/'};
	for (int i=0;i<4;i++){
		if (elemento == simbolos[i]){
			pertenece = true;
		}
	}
	return pertenece;
}

bool esNumero(char elemento){
	bool pertenece = false;
	char numeros[] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i=0;i<10;i++){
		if (elemento == numeros[i]){
			pertenece = true;
		}
	}
	return pertenece;
}

void crearArbol(TipoArbol **arbol, String expresion, int inicio, int final, int contador){
	
	int n_inicio = inicio;
	int n_final = final;
	
	for (int i=inicio;i<final;i++){
		
		if (expresion[i]=='('){
			contador ++;
		}
		else if (expresion[i]==')'){
			contador --;
		}
		
		TipoArbol *p;
		p=(TipoArbol*)malloc(sizeof(TipoArbol));
		p->hder=p->hizq=NULL;
		
		if(esSimbolo(expresion[i] && contador==1)){
			n_inicio = i+1;
			n_final = i-1;
			p->elemento = expresion[i];
			*arbol = p;
		}
		else if(esNumero(expresion[inicio]) && esNumero(expresion[final])){
			if (inicio-final == 0){
				p->elemento = expresion[i];
			}
			else if (inicio-final == 1){
				p->elemento = expresion[inicio] + expresion[final];
			}
		}
	}
	
	crearArbol(&((*arbol)->hizq), expresion, inicio, n_final, contador);
	crearArbol(&((*arbol)->hder), expresion, n_inicio, final, contador);	
}

void evaluarArbol(TipoArbol *arbol){
	
}

int main(void){
	
	String expresion;
	leerExpresion(expresion);
	
	TipoArbol *arbol;
	crearArbol(&arbol);
	
	printf("\nEl arbol es:\n");
	entreOrden(arbol);
	
	
	return 0;
}
