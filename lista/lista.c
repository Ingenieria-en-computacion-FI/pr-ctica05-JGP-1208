#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"


Lista* lista_crear(){
   
    Lista *lista;
    lista = (Lista*)malloc(sizeof(lista));
    lista -> head = NULL;
    lista ->  tail = NULL;
    return lista;
}


bool lista_vacia(Lista* lista){
   if(lista -> head == NULL){
       return true;
   }else{
       return false;
   }
}




void lista_insertar_head(Lista* lista, int dato){
Nodo *newnode = nodo_crear(dato);
newnode -> next = lista -> head;
if(lista -> head == NULL){
    lista -> tail = newnode;
}
    lista -> head = newnode;
}


void lista_insertar_tail(Lista* lista, int dato){
Nodo *newnode = nodo_crear(dato);
   if(lista_vacia(lista)){
      lista -> head = newnode;
      lista -> tail = newnode;
   }else{
       lista -> tail -> next = newnode;
       lista -> tail = newnode;
       lista -> tail -> next = NULL;
   }
}


int lista_eliminar_head(Lista* lista){
    if(lista_vacia(lista)){
        return -1;
    }
    Nodo *tmp = lista -> head;
    lista -> head = lista -> head -> next;
    if(lista_vacia(lista)){
        lista -> tail = NULL;
    }
    int dato = tmp -> dato;
    nodo_destruir(tmp);
    return dato;
}


int lista_eliminar_tail(Lista* lista){
int dato;
Nodo* tmp1 = NULL;
if(lista_vacia(lista)){
    return -1;
}
if(lista -> head == lista -> tail){
    dato = lista -> tail -> dato;
    nodo_destruir(lista -> tail);
    lista -> head = NULL;
    lista -> tail = NULL;
}else{
    Nodo* tmp2 = lista -> head;
    tmp1 = lista -> tail;
    while(tmp2 != tmp1){
        tmp2 = tmp2 -> next;
    }
    lista -> tail = tmp2;
}
lista -> tail -> next = NULL;
dato = tmp1 -> dato;
nodo_destruir(tmp1);
return dato;
}




void lista_imprimir(Lista* lista){
    Nodo* actual = lista->head;
    while(actual != NULL){
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


void lista_destruir(Lista* lista){
        if(!lista_vacia(lista)){
            nodo_destruir(lista -> tail);
        }
    lista = NULL;
}
