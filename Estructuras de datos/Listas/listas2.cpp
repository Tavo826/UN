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

typedef struct lista {
	int valor;
	struct lista *sgte;
}TipoLista;

void ordenar(TipoLista *lista) {
	TipoLista *x, *y;
	int temp;
	for (x=lista; x->sgte!=NULL; x=x->sgte) {
		for (y=x->sgte; y!=NULL; y=y->sgte) {
			if (x->valor > y->valor) {
				temp=x->valor;
				x->valor=y->valor;
				y->valor=temp;
			}
		}
	}
}

void mostrar(TipoLista *lista){
	TipoLista *p;
	printf("\nLa lista es : ");
	for (p=lista;p!=NULL; p=p->sgte)
	   printf("%4d",p->valor);
}

void insertar(TipoLista **lista, int num) {
	TipoLista *p;
	p=(TipoLista *) malloc(sizeof(TipoLista));
	p->valor=num;
	p->sgte=*lista;
	*lista=p;
}

void insertarCabeza(Persona **lista) {
     Persona *p;
     p=(Persona *)malloc(sizeof(Persona));
     if (p==NULL) {
         printf("\nNo hay memoria");
         return;
	 }
     printf("\nNombre : ");
     gets(p->nombre);
     printf("\nEdad : ");
     scanf("%d",&p->edad);getchar();
     printf("\nPeso : ");
     scanf("%f",&p->peso);getchar();
     p->sgte=*lista;
     *lista=p;
}

void insertarCola(Persona **lista) {
     Persona *p, *q;
     p=(Persona *)malloc(sizeof(Persona));
     if (p==NULL) {
         printf("\nNo hay memoria");
         return;
	 }
     printf("\nNombre : ");
     gets(p->nombre);
     printf("\nEdad : ");
     scanf("%d",&p->edad);getchar();
     printf("\nPeso : ");
     scanf("%f",&p->peso);getchar();
     p->sgte=NULL;
     if (*lista == NULL)
        *lista=p;
    else {
      q=*lista;
      while (q->sgte!=NULL)
          q=q->sgte;
      q->sgte=p;
    }
}

void insertarOrd(Persona **lista) {
    Persona *p, *q, *r;
    p=(Persona *)malloc(sizeof(Persona));
    if (p==NULL) {
        printf("\nNo hay memoria");
        return;
	}
    printf("\nNombre : ");
    gets(p->nombre);
    printf("\nEdad : ");
    scanf("%d",&p->edad);getchar();
    printf("\nPeso : ");
    scanf("%f",&p->peso);getchar();
    p->sgte=NULL;
    if (*lista == NULL) // caso 1
       *lista=p;
    else {
        if (p->edad < (*lista)->edad)	{ //Segundo caso
      		p->sgte=*lista;
      		*lista=p;
		}
	  else {
        q=*lista;
        while (q!=NULL && q->edad < p->edad) {
           r=q;	
           q=q->sgte;
        }
        if (q!=NULL) { // Caso 3
           r->sgte=p;
           p->sgte=q;
		}
		else {	// Caso 4
           r->sgte=p;
           p->sgte=NULL;
        }
      }
    }
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


int main(int argc, char *argv[]) {
    TipoLista *lista;
    int x,n;
    lista=NULL;
    for (x=1;x<=20;x++)
       insertar(&lista, x);
    mostrar(lista);
    ordenar(lista);
    mostrar(lista);
    
    /*
    Persona *lista;
    
    printf("\nEste programa se llama : %s",argv[0]);
    lista=NULL;
    printf("\nCuantos desea insertar : ");
    scanf("%d",&n);getchar();
    for (x=1;x<=n;x++)
       insertarOrd(&lista);
    mostrarLista(lista);
    */
    getchar();
    return 0;
}
