#include "cola.h"
#include <stdbool.h>

Cola* cola_crear()
{
    return lista_crear();
}

bool cola_vacia(Cola* cola){
    if(lista_vacia(cola))
    return true;
    return false;	
}

void cola_enqueue(Cola* cola, int dato){
    lista_insertar_tail(cola, dato);
}

int cola_dequeue(Cola* cola){
    int dato_eliminado = lista_eliminar_head(cola);
    return dato_eliminado;
}

int cola_frente(Cola* cola){
    int frente = cola->head->dato;
    return frente;
}

void cola_destruir(Cola* cola){
    lista_destruir(cola);
}
