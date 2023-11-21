//Hecho por Steven Grisales L�pez el 12/04/2023

#include <stdio.h>
#include <stdlib.h>

// definici�n de la estructura de un elemento de la lista
typedef struct elemento {
    double dato;               // �rea de datos
    struct elemento *siguiente; // puntero al siguiente elemento
} Elemento;

// funci�n para mostrar un mensaje de error y abortar el programa
void error() {
    printf("Insuficiente memoria\n");
    exit(1);
}

// funci�n para crear un nuevo elemento
Elemento *nuevoElemento() {
    Elemento *q = (Elemento *)malloc(sizeof(Elemento)); // reservar memoria
    if (!q) error(); // comprobar si se pudo reservar memoria
    return q;
}

// funci�n para a�adir un elemento al principio de la lista
void anyadirAlPrincipio(double n, Elemento **lista) {
    Elemento *p = *lista; // guardar el puntero al primer elemento
    Elemento *q = nuevoElemento(); // crear un nuevo elemento
    q->dato = n; // asignar el valor al nuevo elemento
    q->siguiente = p; // hacer que el nuevo elemento apunte al primer elemento
    p = q; // hacer que el primer elemento sea el nuevo elemento
    *lista = p; // actualizar el puntero a la lista
}

// funci�n para mostrar todos los elementos de la lista
void mostrarTodos(Elemento *p) {
    // Recorrer la lista
    Elemento *q = p; // puntero al primer elemento
    while (q != NULL) {
        printf("%g ", q->dato); // imprimir el valor del elemento
        q = q->siguiente; // avanzar al siguiente elemento
    }
}

// funci�n para borrar todos los elementos de la lista
void borrarTodos(Elemento *p) {
    Elemento *q = NULL;
    // Recorrer la lista
    while (p != NULL) {
        q = p; // guardar el puntero al elemento a borrar
        p = p->siguiente; // avanzar al siguiente elemento
        free(q); // liberar la memoria del elemento borrado
    }
}

// funci�n principal
int main() {
    // Lista lineal vac�a
    Elemento *llse = NULL;
    // Leer los datos y a�adirlos a la lista
    double n;
    printf("Introducir datos. Finalizar con eof(control + z).\n");
    printf("dato: ");
    while (scanf("%lf", &n) != EOF) {
        anyadirAlPrincipio(n, &llse);
        printf("dato: ");
    }
    // Mostrar la lista de datos
    printf("\n");
    mostrarTodos(llse);
    // Borrar la lista
    borrarTodos(llse);
    return 0;
}

