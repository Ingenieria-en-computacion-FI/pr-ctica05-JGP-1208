#include "pila.h"
#include <stdbool.h>

Pila* pila_crear(){
    Lista* newLista = lista_crear();
    return newLista;
}

bool pila_vacia(Pila* pila){
    if(lista_vacia(pila))
    return true;
    return false;
}

void pila_push(Pila* pila, int dato){
    lista_insertar_tail(pila, dato);
}

int pila_pop(Pila* pila){
    int dato_eliminado = lista_eliminar_tail(pila);
    return dato_eliminado;
}

int pila_top(Pila* pila){
    int top = pila->tail->dato;
    return top;
}

void pila_destruir(Pila* pila){
    lista_destruir(pila);
}
