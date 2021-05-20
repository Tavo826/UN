#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef char String[25];

typedef struct {
        String nombre;
        int edad;
        float peso;
}Persona;

void mostrarUno(Persona **cual) {
     int x;
     printf("\nPersona es : \n");
     printf("\nNombre : %s",(*cual)->nombre);
     printf("\nEdad : %d",(*(*cual)).edad);
     printf("\nPeso : %.1f", (*cual)->peso);
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

void leerUno(Persona **per) {
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



int main(void) {
    Persona salon[30];
    Persona *per;
    String cual;
    int num;
    //per=(Persona *)malloc(sizeof(Persona));
    /*
    leerGrupo(clase, &num);
    mostrarGrupo(clase, num);
    strcpy(cual, "carolina");
    buscarUno(clase, num, cual);
    */
    leerUno(&per);
    mostrarUno(&per);
    getchar();
}
