#include <stdlib.h>
#include <stdio.h>

void mostrar(int vector[], int n){
	if (n>0) {
		//printf("%d ", vector[n-1]);
		mostrar(vector,n-1);
		printf("%d ", vector[n-1]);
	}
}

int main(void){
	int n=10;
	int vec[]={1,2,3,4,5,6,7,8,9,10};
	
	mostrar(vec,n);
}
