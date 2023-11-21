/* Hecho por Steven Grisales López. Este programa nos permite ver unas cuantas operaciones de arboles avl. */

// Librerías.
#include "libreriaArbolesAVL.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define TOPE 555 // Tope para generar números aleatorios.
#define MAX(x,y) ((x > y) ? (x) : (y)) // Macro para obtener el máximo de dos números.

// Prototipo de funciones.
int visualizar(Nodo* r); 
int altura(Nodo* r);

int main() {
    int numNodos; // Número de nodos.
    int creceAltura; // Variable para saber si crece la altura.
    Nodo* raiz; // Raíz del árbol.
    int elemento; // Elemento a eliminar.

    system("cls"); // Limpiar pantalla.
    srand(time(NULL)); // Semilla para generar números aleatorios.
    raiz = NULL; // Inicializar la raíz.

    while (altura(raiz) < 5) { // Mientras la altura del árbol sea menor a 5.
        insertarEquilibrado(&raiz, rand() % TOPE, &creceAltura);  // Insertar un nodo en el árbol.
    }

    numNodos = visualizar(raiz); // Visualizar el árbol.
    printf("\n Numero de nodos: %d \n", numNodos); 

    printf("Ingrese el elemento que desea eliminar: "); 
    scanf("%d", &elemento);
 
    eliminarNodoAVL(&raiz, elemento, &creceAltura); // Eliminar un nodo del árbol.

    numNodos = visualizar(raiz); // Visualizar el árbol.
    printf("\n Numero de nodos: %d \n", numNodos);

    return 0;
}

// Función para visualizar el árbol.
int visualizar(Nodo* r) {
    if (r) { // Si el nodo no es nulo.
        int cuantosIzquierda, cuantosDerecha; // Variables para saber cuántos nodos hay a la izquierda y derecha.

        cuantosIzquierda = visualizar(r -> izdo); // Visualizar los nodos de la izquierda.
        printf(" %d ", r -> dato);
        cuantosDerecha = visualizar(r -> dcho); // Visualizar los nodos de la derecha.
        return cuantosIzquierda + cuantosDerecha + 1; // Retornar el número de nodos.
    } else {
        return 0;
    }
}

// Función para obtener la altura del árbol.
int altura(Nodo* r) {
    if (r) { // Si el nodo no es nulo.
        return MAX(altura(r->izdo), altura(r->dcho)) + 1; // Retornar la altura del árbol.
    } else {
        return 0;
    }
}