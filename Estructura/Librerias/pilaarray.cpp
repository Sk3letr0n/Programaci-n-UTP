// Hecho por Steven Grisales L�pez.

#include "pilaarray.h"	
#include <stdio.h>
#include <stdlib.h>
//crearPila inicializa una pila sin elementos, vac�a, pone el �ndice cima a -1.

void crearPila (Pila* pila)
{
pila -> cima = -1;
}


void insertar (Pila* pila, TipoDato elemento)
{
/* si la pila est� llena, termina el programa */
	if (pilaLlena (*pila) )
	{
		puts ("Desbordamiento pila");
		exit (1);
	}
pila -> cima++;
pila -> listaPila[pila->cima] = elemento;
}

/* Quitar un elemento de la pila */
TipoDato quitar (Pila* pila)
{
	TipoDato tem;
	/* si la pila est� vac�a, termina el programa */
	if (pilaVacia (*pila) )
	{
	puts (" Se intenta sacar un elemento en pila vac�a");
	exit (1);
	}
tem = pila -> listaPila[pila->cima];
pila -> cima--;
return tem;
}

//La operaci�n cima devuelve el elemento que se encuentra en la cima de la pila, no se modifica la pila.
TipoDato cima (Pila pila)
{
if (pilaVacia (pila) )
{
puts (" Error de ejecuci�n, pila vac�a");
exit (1);
}
return pila.listaPila[pila.cima];
}

/*La funci�n pilaVacia comprueba si la pila no tiene elementos; para que eso ocurra, la cima de
la pila debe ser -1.*/
int pilaVacia (Pila pila)
{
return pila.cima == -1;
}

/*La funci�n pilaLlena comprueba si la pila est� llena, seg�n el tama�o del arreglo donde se
guardan sus elementos.*/
int pilaLlena (Pila pila)
{
return pila.cima == TAMPILA - 1;
}

/*Por �ltimo, la operaci�n limpiarPila vac�a �ntegramente la pila, para lo que pone cima al valor
que se corresponde con pila vac�a (-1)*/
void limpiarPila (Pila* pila)
{
pila -> cima = -1;
}

int main(){
	Pila pila;
	int x;
	crearPila(&pila);     /* Crea una pila vacía */
	puts("\n La pila crece con numeros enteros, terminar con 0");

	do {
		scanf("%i", &x);
		if(x != 0){
			if(!pilaLlena(pila)){
				insertar(&pila,x);
			} else {
				puts("\n La pila se ha llenado. \n");
				x = 0;
			}
		}
	} while (x != 0);
	puts("Visualiza los elementos de la pila hasta que quede vacia");
	while(!pilaVacia(pila)){
		printf("\n \t %i ", cima(pila));
		quitar(&pila);
	}
}
