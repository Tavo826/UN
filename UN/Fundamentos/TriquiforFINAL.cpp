#include <conio.h>
#include <stdio.h>

int A[3][3],turn=9;;

void llenar(){
	int q,w;
	for(q=0;q<3;q++){
		for(w=0;w<3;w++){
			A[q][w]=8;
		}
	}
}

void imprimirmat(){
	int i,j;
	printf("La matriz del juego es: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}



void jug(int numjugador){
	int m,n,band=1,band1=1;
		printf("        JUGADOR %d\n", numjugador+1);
		while(band==1){
			printf("Ingrese la fila donde desea ubicar el %d \n", numjugador);
		    scanf("%d", &n);
		    if(n>0){
		    	if(n<=3){
		    		band=0;
		    	}
		    	else{
		    		printf("Fila no valida\n");
		    	}
		    }
		    else{
		    	printf("Fila no valida\n");
		    }
		}	
		
		while(band1==1){
			printf("Ingrese la columna donde desea ubicar el %d \n", numjugador);
		    scanf("%d", &m);
		    if(m>0){
		    	if(m<=3){
		    		band1=0;
		    	}
		    	else{
		    		printf("Columna no valida\n");
		    	}
		    }
		    else{
		    	printf("Columna no valida\n");
		    }
		}	
		
		if(A[n-1][m-1]==1){
			printf("Casilla llena\n");
		    getch();
		    jug(numjugador);
		}
		else{
			if(A[n-1][m-1]==0){
			printf("Casilla llena\n");
			getch();
			jug(numjugador);
		    }
		    else{
		    	A[n-1][m-1]=numjugador;
			    imprimirmat();
			    getch();
			    printf("\n");
		    }
		}
}

void comprobarfila(int nrojug, int numfil,int &tam){
	int r,contf=0;
	
	for(r=0;r<3;r++){
		if(A[numfil][r]==nrojug){
			contf=contf+1;
		}
	}
	if(contf==3){
		printf("Hay triqui\n");
		printf("El ganador es el jugador %d \n", nrojug+1);
		tam=10;
		getch();
	}	
}

void comprobarcolumna(int nrojug,int numcol,int &tam){
	int h,contc=0;
	
	for(h=0;h<3;h++){
		if(A[h][numcol]==nrojug){
			contc=contc+1;
		}
	}
	if(contc==3){
		printf("Hay triqui\n");
		printf("El ganador es el jugador %d \n", nrojug+1);
		tam=10;
		getch();
	}	
}

void comprobartriqui(int num, int &tam){
	
	int e,y;
	int cont1=0; 
	int cont2=0;
	
	for (e=0;e<3;e++) 
	{
		if (A[e][e]==num) 
		{
			cont1=cont1+1;
		}
	}
	
	if(cont1==3){		
		printf("Hay triqui\n");
		printf("El ganador es el jugador %d\n", num+1);
		tam=10;
		getch();
	}
	
    e=0;
	for(y=2;y>=0;y--){
			
		if(A[e][y]==num){
			cont2=cont2+1;
		}
	  e++;	  
	}	
	if(cont2==3){		
		printf("Hay triqui\n");
		printf("El ganador es el jugador %d\n", num+1);
		tam=10;
		getch();
	}
	
	comprobarfila(num,0,tam);
	comprobarfila(num,1,tam);
	comprobarfila(num,2,tam);
	
	comprobarcolumna(num,0,tam);
	comprobarcolumna(num,1,tam);
	comprobarcolumna(num,2,tam);
		
}

int main(void){
	
	int k;
	
	printf("          TRIQUI \n");
	printf("Jugador 1 juega con 0\n");
	printf("Jugador 2 juega con 1\n");
	printf("REGLAS:\n");
	printf("Habra triqui si se llena con el mismo numero cualquier fila, columna, la diagonal principal o la diagonal invertida\n");
	
	llenar();
	imprimirmat();
	getch();
	
	for(k=0;k<turn;k++){
		if(k%2==0){
			jug(0);
			if (k>=4){
				if(k<9){
					comprobartriqui(0,k);
				}			
		    }
		}
		
		else{
			jug(1);
			if(k>=5){
				if(k<=turn){
					comprobartriqui(1,k);
				}			
		    }
		}
	}
	if (k==9){
		printf("Empate, no hubo ganador\n");
	}
	
	
	getch();
	return 0;
}
