#include "colas.h"

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

void ordenarCola(TipoCola *cola){
	TipoCola aux;
	int valor1,valor2;
	bool ordenada;
	
	do{
		ordenada = true;
		valor1=retirarCola(cola);
		while (!vaciaCola(cola)){
			valor2 = retirarCola(cola);
			if (valor1>=valor2){
				insertarCola(&aux,valor2);
				ordenada=false;
			}
			else{
				insertarCola(&aux,valor1);
				valor1=valor2;
			}
			while(!vaciaCola(&aux)){
				insertarCola(cola,retirarCola(&aux));
			}
		}
	}
	while(!ordenada);
}

void invertirCola(TipoCola *cola){
	int valor;
	if (!vaciaCola(cola)){
		valor=retirarCola(cola);
		invertirCola(cola);
		insertarCola(cola,valor);
	}
}

int main(void) {
	TipoCola lacola;
	crearCola(&lacola);
	for (int x=10;x>0;x--){
		insertarCola(&lacola,x);
	}	   
	mostrarCola(&lacola);

	if (ordenadaCola(&lacola)){
		printf("\nSi esta ordenada");
	}
	else{
		printf("\nNo esta ordenada");
	}
	
	//ordenarCola(&lacola);
	//mostrarCola(&lacola);	 
	invertirCola(&lacola);
	mostrarCola(&lacola);
}
