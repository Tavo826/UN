#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[25];

typedef struct persona{

	String nombre;
	int edad;
	float peso;
	struct persona *sgte;
	
}Persona;

void agregarGrupo(Persona **lista){
	
	Persona *p;
	p=(Persona*)malloc(sizeof(Persona));
	
	if (p == NULL){
		printf("\nNo hay espacio en memoria");
		exit(1);
	}
	
	printf("Nombre: ");
	gets(p->nombre);
	printf("Edad: ");
	scanf("%d", &p->edad);getchar();
	printf("Peso: ");
	scanf("%f", &p->peso);getchar();
	printf("\n");
	
	p->sgte = *lista;
	*lista = p;
		
}

void agregar_ordenarGrupo_porEdad(Persona **lista){
	
	Persona *p, *q, *r;
	p=(Persona*)malloc(sizeof(Persona));
	
	if (p == NULL){
		printf("\nNo hay espacio en memoria");
		exit(1);
	}
	
	printf("Nombre: ");
	gets(p->nombre);
	printf("Edad: ");
	scanf("%d", &p->edad);getchar();
	printf("Peso: ");	
	scanf("%f", &p->peso);getchar();
	printf("\n");
	
	//Caso 1 (Lista vacía)
	if (*lista == NULL){		
		*lista = p;
		p->sgte = NULL;		
	}
	else{		
		if (p->edad < (*lista)->edad){ //Caso 2 (Elemento menor al primero)			
			p->sgte = *lista;
			*lista = p;			
		}
		else{			
			q = *lista;
			while (q!=NULL && q->edad < p->edad){				
				r=q;
				q=q->sgte;			
			}				
			if (q!=NULL){ //Caso 3 (Elemento intermedio)					
				r->sgte = p;
				p->sgte = q;					
			}
			else{ //Caso 4 (Elemento mayor al último)			
				r->sgte = p;
				p->sgte = NULL;					
			}			
		}
	}	
}

void agregar_cabeza(Persona **lista){
	
	Persona *p;
	p=(Persona*)malloc(sizeof(Persona));
	
	if (p==NULL){
		printf("\nNo hay espacio en memoria");
		exit(1);
	}
	
	printf("Nombre: ");
	gets(p->nombre);
	printf("Edad: ");
	scanf("%d", &p->edad);
	printf("Peso: ");
	scanf("%f", &p->peso);
	printf("\n");
	
	p->sgte=*lista;
	*lista=p;
	
}

void agregar_cola(Persona **lista){
	
	Persona *p, *q;
	p=(Persona*)malloc(sizeof(Persona));
	
	if (p==NULL){
		printf("\nNo hay memoria");
		exit(1);
	}
	
	printf("Nombre: ");
	gets(p->nombre);
	printf("Edad: ");
	scanf("%d", &p->edad);
	printf("Peso: ");
	scanf("%f", &p->peso);
	printf("\n");
	
	p->sgte=NULL;
	
	if(*lista==NULL){
		*lista=p;
	}
	else{
		q=*lista;
		while (q->sgte!=NULL){
			q=q->sgte;
		}
		q->sgte=p;
	}	
}

void eliminar_elemento(Persona **lista,int valor){
		
	Persona *p, *q, *r;
	
	if (*lista==NULL){
		printf("\nNo hay elementos");
		exit(1);
	}
	else{		
		p=*lista;
		if (p->edad == valor){
			*lista=(*lista)->sgte;
			free(p);
		}
		else{
			while(p!=NULL && p->edad!=valor){
				q=p;
				p=p->sgte;
			}
			if (p!=NULL){
				r=p;
				p=p->sgte;
				q->sgte=p;
				free(r);
			}			
		}		
	}	
}

void mostrarLista(Persona *lista) {
    
	Persona *p;
    p=lista;
    printf("\n\nPersonas : \n");
    while (p!=NULL) {       
       printf("\nNombre : %s",p->nombre);
       printf("\nEdad : %d",p->edad);
       printf("\nPeso : %.1f", p->peso);
       p=p->sgte;
       printf("\n");
    }
}

int main(void){
	
	Persona *lista;
	lista = NULL;
	int eliminar;
	
	for (int i=1;i<=3;i++){
		agregar_ordenarGrupo_porEdad(&lista);
	}
	mostrarLista(lista);
	printf("\n\nDeme edad a eliminar: ");
	scanf("%d", &eliminar);
	eliminar_elemento(&lista, eliminar);
	mostrarLista(lista);
	
	return 0;
}
