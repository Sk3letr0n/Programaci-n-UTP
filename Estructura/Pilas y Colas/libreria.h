// Hecho por: Steven Grisales L�pez el 29/03/2023.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definimos una estructura de nodo para la pila
typedef struct Nodo {
    char dato;
    struct Nodo *siguiente;
} Nodo;

// Definimos una estructura para la pila
typedef struct {
    Nodo *tope;
} Pila;

// Funci�n para inicializar la pila
void inicializar_pila(Pila *pila) {
    pila->tope = NULL;
}

// Funci�n para verificar si la pila est� vac�a
bool pila_vacia(Pila *pila) {
    return pila->tope == NULL;
}

// Funci�n para agregar un elemento a la pila
void push(Pila *pila, char c) {
    Nodo *nuevo_nodo = (Nodo *) malloc(sizeof(Nodo));
    nuevo_nodo->dato = c;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;
}

// Funci�n para eliminar un elemento de la pila
char pop(Pila *pila) {
    char c = '\0';
    if (!pila_vacia(pila)) {
        Nodo *nodo_a_eliminar = pila->tope;
        c = nodo_a_eliminar->dato;
        pila->tope = nodo_a_eliminar->siguiente;
        free(nodo_a_eliminar);
    }
    return c;
}
