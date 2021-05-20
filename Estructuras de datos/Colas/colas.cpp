#include "colas.h"

/*
	crearCola
	vaciaCola
	insertarCola
	retirarCola
	consultarCola
	destruirCola
*/

void mostrarCola(TipoCola *lacola){
	TipoCola aux;
	int valor;
	printf("\n La cola es : \n");
	if (!vaciaCola(lacola)) {
		crearCola(&aux);
		while (!vaciaCola(lacola)){
			valor=retirarCola(lacola);
			printf("\nvalor : %d", valor);
			insertarCola(&aux,valor);
		}
	   	
		while (!vaciaCola(&aux)){
			insertarCola(lacola,retirarCola(&aux));
		}
    }
}

bool buscarCola(TipoCola *lacola, int numero){
	TipoCola aux;
	int valor;
	bool encontro = false;
	if (!vaciaCola(lacola)){
		crearCola(&aux);
		while (!vaciaCola(lacola)){
			valor=retirarCola(lacola);
			if (valor==numero){
				encontro = true;
			}
			insertarCola(&aux,valor);
		}
		while (!vaciaCola(&aux)){
			insertarCola(lacola,retirarCola(&aux));
		}
	}
}

bool ordenadaCola(TipoCola *lacola){
	TipoCola aux;
	int valor1, valor2;
	bool ordenada = true;
	if (!vaciaCola(lacola)){
		crearCola(&aux);
		valor1 = consultarCola(lacola);
		while(!vaciaCola(lacola)){
			valor2=retirarCola(lacola);
			if (valor1<valor2){
				ordenada=false;
			}
			insertarCola(&aux,valor2);
			valor1=valor2;
		}
		while (!vaciaCola(&aux)){
			insertarCola(lacola,retirarCola(&aux));
		}
	}
}

void eliminar_ele_Cola(TipoCola *lacola, int elim){
	TipoCola aux;
	int valor;
	if (!vaciaCola(lacola)){
		crearCola(&aux);
		while(!vaciaCola(lacola)){
			valor=retirarCola(lacola);
			if (valor!=elim){
				insertarCola(&aux,valor);
			}
		}
		while (!vaciaCola(&aux)){
			insertarCola(lacola,retirarCola(&aux));
		}
	}
}

void eliminar_pos_Cola(TipoCola *lacola, int pos){
	TipoCola aux;
	int valor,cont=0;
	if (!vaciaCola(lacola)){
		crearCola(&aux);
		while (!vaciaCola(lacola)){
			valor=retirarCola(lacola);
			cont=cont+1;
			if (cont != pos){
				insertarCola(&aux,valor);
			}
		}
		while (!vaciaCola(&aux)){
			insertarCola(lacola,retirarCola(&aux));
		}
	}
}

void invertirCola(TipoCola *cola, int n){
	
	if (n!=0){
		mostrarCola(cola);
	}
	else{
		invertirCola(cola,n-1);
	}
}

void interseccion(TipoCola *cola1, TipoCola *cola2, TipoCola *cola3, int n){
	TipoCola aux1;
	TipoCola aux2;
	int contador=0;
	int valor1, valor2;
	crearCola(&aux1);
	crearCola(&aux2);
	while(!vaciaCola(cola1)){		
		valor1=retirarCola(cola1);
		while(!vaciaCola(cola2)){			
			valor2=retirarCola(cola2);
			if (valor1==valor2){
				contador+=1;
			}
			insertarCola(&aux2,valor2);
		}
		if (contador!=0){
			insertarCola(cola3,valor1);
		}
		while(!vaciaCola(&aux2)){
			insertarCola(cola2, retirarCola(&aux2));
		}
		insertarCola(&aux1,valor1);
	}
	while(!vaciaCola(&aux1)){
		insertarCola(cola1, retirarCola(&aux1));
	}
}

int main(void) {
	TipoCola lacola;
	TipoCola lacola1;
	TipoCola lacola2;
	crearCola(&lacola);
	crearCola(&lacola1);
	crearCola(&lacola2);
	for (int x=10;x>0;x--){
		insertarCola(&lacola,x);
	}
	for (int x=5;x<15;x++){
		insertarCola(&lacola1,x);
	}
	mostrarCola(&lacola);
	mostrarCola(&lacola1);
	/*
	mostrarCola(&lacola);
	if (ordenadaCola(&lacola)){
		printf("\nSi esta ordenada");
	}
	else{
		printf("\nNo esta ordenada");
	}
	eliminar_ele_Cola(&lacola,5);
	mostrarCola(&lacola);
	eliminar_pos_Cola(&lacola,3);
	mostrarCola(&lacola);
	*/
	//printf("\n\nCola invertida\n");
	//invertirCola(&lacola,9);
	interseccion(&lacola,&lacola1,&lacola2,10);
	mostrarCola(&lacola2);
}
