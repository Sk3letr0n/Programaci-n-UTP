/* archivo pilaarray.h */
#include <stdio.h>
#include <stdlib.h>
typedef int TipoDato; /* Tipo de los elementos de la pila */
#define TAMPILA 100
typedef struct
{
TipoDato listaPila[TAMPILA];
int cima;
} Pila;
/* Operaciones sobre la pila */
void crearPila (Pila* pila);
void insertar (Pila* pila, TipoDato elemento);
TipoDato quitar (Pila* pila);
void limpiarPila (Pila* pila);
/* Operación de acceso a pila */
TipoDato cima (Pila pila);
/* Verificación estado de la pila */
int pilaVacia (Pila pila);
int pilaLlena (Pila pila);
