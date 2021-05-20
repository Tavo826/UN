#include <stdio.h>

int orale(int vector1[],int n,int vector2[],int m,int vector3[]){
	int temp=0;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (vector1[i]>vector1[j]){
				temp=vector1[i];
				vector1[i]=vector1[j];
				vector1[j]=temp;						
			}
		}
	}
	for (int i=0;i<m-1;i++){
		for (int j=i+1;j<m;j++){
			if (vector2[i]>vector2[j]){
				temp=vector2[i];
				vector2[i]=vector2[j];
				vector2[j]=temp;						
			}
		}
	}
	q=0;
	if (n>m){
		while
	}
	else{
		//n<m
	}
	
}

int main(void){
	int vector1[7], vector2[8], vector3[15];
	int tam;
	
	for (int i=0;i<=7;i++){
		vector1[i]=7-i;
	}
	for (int j=0;j<=8;j++){
		vector2[j]=11-j;
	}
	
	tam=orale(vector1,7,vector2,8,vector3);
	
	printf("Mostrando vectores: \n\n");
	printf("Vector 1\n");
	for (int i=0;i<7;i++){
		printf("%d ",vector1[i]);
	}
	printf("\nVector 2\n");
	for (int j=0;j<8;j++){
		printf("%d ",vector2[j]);
	}
	printf("\nVector 3\n");
	for (int k=0;k<tam;k++){
		printf("%d ",vector3[k]);
	}
	
	return 0;
}
