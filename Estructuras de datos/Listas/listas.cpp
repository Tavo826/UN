#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char String[25];

typedef struct apersona{
        String nombre;
        int edad;
        float peso;
        struct apersona *sgte;
}Persona;

void leerUno(Persona **lista) {
     Persona *p;
     p=(Persona *)malloc(sizeof(Persona));
     printf("Nombre : ");
     gets(p->nombre);
     printf("Edad : ");
     scanf("%d",&p->edad);getchar();
     printf("Peso : ");
     scanf("%f",&p->peso);getchar();
     p->sgte=*lista;
     *lista=p;
}

void mostrarLista(Persona *lista) {
     Persona *p;
     p=lista;
     while (p!=NULL) {
        printf("\nPersona es : \n");
        printf("\nNombre : %s",p->nombre);
        printf("\nEdad : %d",p->edad);
        printf("\nPeso : %.1f", p->peso);
        p=p->sgte;
     }
}

void buscarUno(Persona salon[], int n, String nombre) {
     int x;
     printf("\nPersonas del gupo son : \n");
     for (x=0;x<n;x++) {
         if (strcmp(salon[x].nombre,nombre)==0) {
            printf("\nNombre : %s",salon[x].nombre);
            printf("\nEdad : %d",salon[x].edad);
            printf("\nPeso : %.1f", salon[x].peso);
            return;
         }  
     }
}


void mostrarGrupo(Persona *salon, int n) {
     int x;
     printf("\nPersonas del gupo son : \n");
     for (x=0;x<n;x++) {
         printf("\nNombre : %s",salon[x].nombre);
         //scanf("%s",salon[x].nombre);
         printf("\nEdad : %d",salon[x].edad);
         printf("\nPeso : %.1f", salon[x].peso);
     }
}

void leerdos(Persona **per) {
     *per=(Persona *)malloc(sizeof(Persona));
     printf("\nNombre : ");
     gets((*per)->nombre);
     printf("\nEdad : ");
     scanf("%d",&(*per)->edad);getchar();
     printf("\nPeso : ");
     scanf("%f",&(*per)->peso);getchar();
}

void leerGrupo(Persona salon[], int *n) {
     int x;
     printf("\nCuantos son :  ");
     scanf("%d",n);getchar();
     for (x=0;x<*n;x++) {
         printf("\nNombre : ");
         gets(salon[x].nombre);
         //scanf("%s",salon[x].nombre);
         printf("\nEdad : ");
         scanf("%d",&salon[x].edad);getchar();
         printf("\nPeso : ");
         scanf("%f",&salon[x].peso);getchar();
     }
}

void eliminarPosicion(Persona **lista){
	Persona *p,*q;
	int nodo, band=0;
	printf("\nNodo a eliminar: ");
	scanf("%d", &nodo);
	while (band==0){
		if (nodo<3){
			band=1;
			p=*lista;
			if (nodo==0){
				*lista=p->sgte;
				free(p);
			}
			else{
				for (int i=1;i<3;i++){
					if(nodo==i){
						q=p->sgte;
						p->sgte=q->sgte;
						free(q);
					}
					p=p->sgte;
				}
				
			}
		}
		else{
			printf("Nodo no valido");			
		}
	}
	
	
}

int main(void) {
    Persona *lista;
    int x;
    lista=NULL;
    for (x=1;x<=3;x++)
       leerUno(&lista);
    mostrarLista(lista);
    eliminarPosicion(&lista);
    mostrarLista(lista);
    getchar();
}
