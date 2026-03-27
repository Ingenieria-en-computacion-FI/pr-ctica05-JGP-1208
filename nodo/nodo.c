#include <stdlib.h>
#include "nodo.h"


Nodo* nodo_crear(int dato){


   Nodo *n;
   n = (Nodo*)malloc(sizeof(Nodo));
   n -> next = NULL;
   n -> dato = dato;
   return n;
}


void nodo_destruir(Nodo* nodo){


   if(n -> next == NULL){
       free(n);
   }
}
