//Hecho por Steven Grisales L�pez el 12/04/2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 3131

typedef int Item;
typedef struct Elemento
{
    Item dato;
    struct Elemento* siguiente;
} Nodo;

void inserPrimero(Nodo** cabeza, Item entrada);
Nodo* crearNodo(Item x);

int main()
{
    Item d;
    Nodo *cabeza, *ptr;
    int k;
    cabeza = NULL; /* lista vac�a */
    srand(time(NULL)); /* inicializar generador de n�meros aleatorios */
    /* El bucle termina cuando se genera el n�mero aleatorio 0 */
    for (d = rand() % MX; d; d = rand() % MX)
    {
        inserPrimero(&cabeza, d);
    }
    /* recorre la lista para escribir los pares */
    for (k = 0, ptr = cabeza; ptr; ptr = ptr->siguiente)
    {
        if (ptr->dato % 2 == 0)
        {
            printf("%d ", ptr->dato);
            k++;
            printf("%c", (k % 12 ? ' ' : '\n')); /* 12 datos por l�nea */
        }
    }
    printf("\n\n");
    return 0;
}

void inserPrimero(Nodo** cabeza, Item entrada)
{
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

Nodo* crearNodo(Item x)
{
    Nodo *a;
    a = (Nodo*)malloc(sizeof(Nodo)); /* asigna nuevo nodo */
    a->dato = x;
    a->siguiente = NULL;
    return a;
}

