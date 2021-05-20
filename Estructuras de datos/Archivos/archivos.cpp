#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void palabras(char cadena[]){
	char *pal;
	char separadores[]=",.;:| ()#$%";
	pal=strtok(cadena,separadores);
	while (pal!=NULL){
		printf("\nLa palabra es : %s",strrev(pal));
		int num=atoi(pal);
		printf("\nEl numero es : %d",num+1);
		pal=strtok(NULL,separadores);
	}
	
	
}

void mostrar(int n){
	int x,y;
	float cont=0;
	FILE *arch;
	arch=fopen("d:\\matriz.xls","w");
	for (x=0;x<n;x++) {
	   for (y=0;y<n;y++) {
	      fprintf(arch,"%.2f\t",cont);
	      cont += 0.3;
	   }
	   fprintf(arch,"\n");
   }
	fclose(arch);
}

int main(void) {
	int vect[]={1,2,3,4,5,6,7,8,9,10};
	mostrar(40);
	//char cadena[]="12  1234, 89  77 9 ; 12345 8754 $ % 2198";
	//char cadena[]="la casa es ; verde   $ % y 2198";
	//palabras(cadena);
	/*int n=10;
	mostrar(vect,n);*/
}

