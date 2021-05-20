#include <stdio.h>


typedef struct arbol {
   char oper;
   float valor;
   struct arbol *hizq, *hder;
} TipoArbol;

bool eshojaArbol(TipoArbol *arbol){
	if (arbol==NULL)
	  return false;
	else
	  return (arbol->hizq==NULL && arbol->hder==NULL);
}

float evaluar(TipoArbol *arbol) {
      if (arbol==NULL)
         return 0;
      else {
        if (eshojaArbol(arbol))
           return arbol->valor;
        else {
           switch(arbol->oper) {
             case '+':
                  return evaluar(arbol->hizq)+evaluar(arbol->hder);                 
                  break;
             case '*':
                  return evaluar(arbol->hizq)*evaluar(arbol->hder);                 
                  break;
             case '-':
                  return evaluar(arbol->hizq)-evaluar(arbol->hder);                 
                  break;
             case '/':
                  return evaluar(arbol->hizq)/evaluar(arbol->hder);                 
                  break;
           }
        }
      }
}   

int main(void) {
}  

